NAME       = rr
RM         = rm -f
CC         = cc
CXX        = c++
ARCH       = x86_64
OSXVERSION = 10.6
PROG       = $(NAME)
APPBUNDLE  = rRootage.app
STATICLIBS = bulletml/libbulletml_d.a /usr/local/lib/libSDL.a /usr/local/lib/libSDLmain.a /usr/local/lib/libSDL_mixer.a /usr/local/lib/libvorbis.a /usr/local/lib/libogg.a

CFLAGS     = -Os -arch $(ARCH) -mmacosx-version-min=$(OSXVERSION) -I. -Ibulletml -DMACOSX -I/usr/local/include/SDL
CXXFLAGS   = $(CFLAGS)
LDFLAGS    = $(CFLAGS) -Wl,-arch,$(ARCH),-macosx_version_min,$(OSXVERSION) $(STATICLIBS) -lstdc++.6 -framework Cocoa -framework OpenGL -framework AudioToolbox -framework AudioUnit -framework Carbon -framework IOKit

OBJS       = rr.o foe.o foecommand.o barragemanager.o boss.o ship.o laser.o frag.o background.o letterrender.o shot.o screen.o vector.o degutil.o rand.o mt19937int.o soundmanager.o attractmanager.o

$(APPBUNDLE): $(PROG)
	mkdir -p $(APPBUNDLE)/Contents/MacOS $(APPBUNDLE)/Contents/Resources $(APPBUNDLE)/Contents/Frameworks
	cp -fp  $(PROG) $(APPBUNDLE)/Contents/MacOS/
	cp -fpR rr.icns ../images ../morph ../morph_heavy ../normal ../psy ../reversible ../simple ../sounds $(APPBUNDLE)/Contents/Resources/
	cp -fp  Info.plist PkgInfo $(APPBUNDLE)/Contents/
	codesign -s 'Developer ID Application: Kazuya Watanabe' -i com.workram.$(PROG) -f $(APPBUNDLE)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(PROG) *.o
	$(RM) -r $(APPBUNDLE)
