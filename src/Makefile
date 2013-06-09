TOOLCHAIN_ROOT = /Developer/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain
SDK_ROOT       = /Developer/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk

NAME       = rr
RM         = rm -f
CC         = $(TOOLCHAIN_ROOT)/usr/bin/cc
CXX        = $(TOOLCHAIN_ROOT)/usr/bin/c++
ARCH       = x86_64
OSXVERSION = 10.6
PROG       = $(NAME)
APPBUNDLE  = rRootage.app
STATICLIBS = bulletml/libbulletml_d.a /usr/local/lib/libSDL_mixer.a /usr/local/lib/libogg.a /usr/local/lib/libvorbis.a

CFLAGS     = -Os -arch $(ARCH) -mmacosx-version-min=$(OSXVERSION) -isysroot $(SDK_ROOT) -I. -Ibulletml -DMACOSX `sdl-config --cflags`
CXXFLAGS   = $(CFLAGS)
LDFLAGS    = -Wl,-arch,$(ARCH),-macosx_version_min,$(OSXVERSION),-syslibroot,$(SDK_ROOT) $(STATICLIBS) -lstdc++.6 `sdl-config --static-libs`

OBJS       = rr.o foe.o foecommand.o barragemanager.o boss.o ship.o laser.o frag.o background.o letterrender.o shot.o screen.o vector.o degutil.o rand.o mt19937int.o soundmanager.o attractmanager.o SDLMain.o

$(APPBUNDLE): $(PROG)
	mkdir -p $(APPBUNDLE)/Contents/MacOS $(APPBUNDLE)/Contents/Resources
	cp -fp  $(PROG) $(APPBUNDLE)/Contents/MacOS/
	cp -fpR rr.icns ../images ../morph ../morph_heavy ../normal ../psy ../reversible ../simple ../sounds $(APPBUNDLE)/Contents/Resources/
	cp -fp  Info.plist PkgInfo $(APPBUNDLE)/Contents/
	codesign -s 'Developer ID Application: Kazuya Watanabe' -i com.workram.$(PROG) -f $(APPBUNDLE)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(PROG) *.o
	$(RM) -r $(APPBUNDLE)
