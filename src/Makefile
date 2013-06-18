NAME       = rr
RM         = rm -f
CC         = cc
CXX        = c++
ARCH       = x86_64
OSXVERSION = 10.6
PROG       = $(NAME)
APPBUNDLE  = rRootage.app
STATICLIBS = bulletml/libbulletml_d.a

CFLAGS     = -Os -arch $(ARCH) -mmacosx-version-min=$(OSXVERSION) -I. -Ibulletml -DMACOSX -I../../sdl/SDL.framework/Versions/A/Headers -I../../sdl/SDL_mixer.framework/Versions/A/Headers -F../../sdl -framework SDL -framework SDL_mixer
CXXFLAGS   = $(CFLAGS)
LDFLAGS    = $(CFLAGS) -Wl,-arch,$(ARCH),-macosx_version_min,$(OSXVERSION) $(STATICLIBS) -lstdc++.6 -framework Cocoa -framework OpenGL

OBJS       = rr.o foe.o foecommand.o barragemanager.o boss.o ship.o laser.o frag.o background.o letterrender.o shot.o screen.o vector.o degutil.o rand.o mt19937int.o soundmanager.o attractmanager.o SDLMain.o

$(APPBUNDLE): $(PROG)
	mkdir -p $(APPBUNDLE)/Contents/MacOS $(APPBUNDLE)/Contents/Resources $(APPBUNDLE)/Contents/Frameworks
	cp -fp  $(PROG) $(APPBUNDLE)/Contents/MacOS/
	cp -fpR rr.icns ../images ../morph ../morph_heavy ../normal ../psy ../reversible ../simple ../sounds $(APPBUNDLE)/Contents/Resources/
	cp -fp  Info.plist PkgInfo $(APPBUNDLE)/Contents/
	cp -fpR ../../sdl/SDL.framework ../../sdl/SDL_mixer.framework $(APPBUNDLE)/Contents/Frameworks/
	install_name_tool -change @rpath/SDL.framework/Versions/A/SDL             @executable_path/../Frameworks/SDL.framework/Versions/A/SDL             $(APPBUNDLE)/Contents/MacOS/rr
	install_name_tool -change @rpath/SDL_mixer.framework/Versions/A/SDL_mixer @executable_path/../Frameworks/SDL_mixer.framework/Versions/A/SDL_mixer $(APPBUNDLE)/Contents/MacOS/rr
	install_name_tool -change @rpath/SDL.framework/Versions/A/SDL             @executable_path/../Frameworks/SDL.framework/Versions/A/SDL             $(APPBUNDLE)/Contents/Frameworks/SDL_mixer.framework/Versions/A/SDL_mixer
	install_name_tool -change @rpath/SDL.framework/Versions/A/SDL             @executable_path/../Frameworks/SDL.framework/Versions/A/SDL             $(APPBUNDLE)/Contents/Frameworks/SDL_mixer.framework/Versions/A/Frameworks/smpeg.framework/Versions/A/smpeg
	codesign -s 'Developer ID Application: Kazuya Watanabe' -i com.workram.$(PROG) -f $(APPBUNDLE)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(PROG) *.o
	$(RM) -r $(APPBUNDLE)
