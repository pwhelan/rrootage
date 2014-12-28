NAME       = rr
RM         = rm -f
CC         = cc
CXX        = c++
ARCH       = x86_64
OSXVERSION = 10.9
PROG       = $(NAME)
APPBUNDLE  = rRootage.app
STATICLIBS = bulletml/libbulletml.a /usr/local/lib/libSDL2.a /usr/local/lib/libSDL2main.a /usr/local/lib/libSDL2_mixer.a /usr/local/lib/libvorbis.a /usr/local/lib/libogg.a -liconv

CFLAGS     = -Os -arch $(ARCH) -mmacosx-version-min=$(OSXVERSION) -I. -Ibulletml -DMACOSX -I/usr/local/include/SDL
CXXFLAGS   = $(CFLAGS)
LDFLAGS    = $(CFLAGS) -Wl,-arch,$(ARCH),-macosx_version_min,$(OSXVERSION) $(STATICLIBS) -framework Cocoa -framework OpenGL -framework AudioToolbox -framework AudioUnit -framework Carbon -framework IOKit -framework CoreFoundation -framework CoreAudio -framework ForceFeedback -lstdc++.6

OBJS       = rr.o foe.o foecommand.o barragemanager.o boss.o ship.o laser.o frag.o background.o letterrender.o shot.o screen.o vector.o degutil.o rand.o mt19937int.o soundmanager.o attractmanager.o

$(APPBUNDLE): $(PROG)
	mkdir -p $(APPBUNDLE)/Contents/MacOS $(APPBUNDLE)/Contents/Resources $(APPBUNDLE)/Contents/Frameworks
	cp -fp  $(PROG) $(APPBUNDLE)/Contents/MacOS/
	cp -fpR rr.icns ../images ../morph ../morph_heavy ../normal ../psy ../reversible ../simple ../sounds $(APPBUNDLE)/Contents/Resources/
	cp -fp  Info.plist PkgInfo $(APPBUNDLE)/Contents/
	codesign -s 'Developer ID Application: Kazuya Watanabe' -i com.workram.$(PROG) -f $(APPBUNDLE)

$(PROG): $(OBJS)
	$(CXX) $(CFLAGS) -o $(PROG) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(PROG) *.o
	$(RM) -r $(APPBUNDLE)
