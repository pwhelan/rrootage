/*
 * $Id: barragemanager.cc,v 1.4 2003/04/26 03:24:15 kenta Exp $
 *
 * Copyright 2002 Kenta Cho. All rights reserved.
 */

/**
 * Handle barrages.
 *
 * @version $Revision: 1.4 $
 */
extern "C" {
#include "SDL.h"
#include <sys/types.h>
#include <dirent.h>
#include "genmcr.h"
#include "brgmng_mtd.h"
#ifdef MACOSX
#include <sys/syslimits.h>
#include "rr.h"
#endif
}

#include "barragemanager.h"

Barrage barragePattern[BARRAGE_TYPE_NUM][BARRAGE_PATTERN_MAX];
int barragePatternNum[BARRAGE_TYPE_NUM];

static const char *BARRAGE_DIR_NAME[BARRAGE_TYPE_NUM] = {
  "normal", "reversible", "morph", "simple", "morph_heavy", "psy",
};

static int readBulletMLFiles(const char *dirPath, Barrage brg[]) {
  DIR *dp;
  struct dirent *dir;
  int i = 0;
#ifdef MACOSX
  char dirPath2[PATH_MAX];
  char fileName[PATH_MAX];
  strcpy(dirPath2, pathToResourcesDir);
  strcat(dirPath2, "/");
  strcat(dirPath2, dirPath);
  if ( (dp = opendir(dirPath2)) == NULL ) {
    fprintf(stderr, "Can't open directory: %s\n", dirPath2);
#else
  char fileName[256];
  if ( (dp = opendir(dirPath)) == NULL ) {
    fprintf(stderr, "Can't open directory: %s\n", dirPath);
#endif
    exit(1);
  }
  while ((dir = readdir(dp)) != NULL) {
    if ( strcmp(strrchr(dir->d_name, '.'), ".xml") != 0 ) continue; // Read .xml files.
#ifdef MACOSX
    strcpy(fileName, dirPath2);
#else
    strcpy(fileName, dirPath);
#endif
    strcat(fileName, "/");
    strncat(fileName, dir->d_name, sizeof(fileName)-strlen(fileName)-1);
    brg[i].bulletml = new BulletMLParserTinyXML(fileName);
    brg[i].bulletml->build(); i++;
    printf("%s\n", fileName);
  }
  closedir(dp);
  return i;
}

void initBarragemanager() {
  for ( int i=0 ; i<BARRAGE_TYPE_NUM ; i++ ) {
    barragePatternNum[i] = readBulletMLFiles(BARRAGE_DIR_NAME[i], barragePattern[i]);
    printf("--------\n");
  }
}

void closeBarragemanager() {
  for ( int i=0 ; i<BARRAGE_TYPE_NUM ; i++ ) {
    for ( int j=0 ; j<barragePatternNum[i] ; j++ ) {
      delete barragePattern[i][j].bulletml;
    }
  }
}
