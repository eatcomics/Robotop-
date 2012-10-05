CC = g++
CFLAGS = -lSDL -lSDL_image -lGL -lGLU
OBJ = *.o
FILENAME = RobotopEngine
SOURCEFILES = main.cpp headers.cpp Init.cpp Gfx.cpp Tile.cpp Game.cpp Input.cpp Arena.cpp Player.cpp Particles.cpp

Debug:   $(DEPS) $(FILES)
	 $(CC) -g -w -fpermissive -c $(SOURCEFILES)
	 $(CC) -w -fpermissive -o $(FILENAME) $(OBJ) $(CFLAGS)
	 notify-send "Project Build" "Build of "$(FILENAME)" is done."
target:   $(DEPS) $(FILES)
	 $(CC) -g -w -fpermissive -c $(SOURCEFILES)
	 $(CC) -w -fpermissive -o $(FILENAME) $(OBJ) $(CFLAGS)
	 notify-send "Project Build" "Build of "$(FILENAME)" is done." 

Linux:   $(DEPS) $(FILES)
	 $(CC) -w -fpermissive -c $(SOURCEFILES)
	 $(CC) -w -fpermissive -o $(FILENAME) $(OBJ) $(CFLAGS)
	 notify-send "Project Build" "Build of "$(FILENAME)" is done."

#cleanup
.PHONY: clean
clean:
	rm -f *.o *~ core $(INCDIR)/*~

run:     $(DEPS) $(FILES)
	 $(CC) -g -w -fpermissive -c $(SOURCEFILES)
	 $(CC) -w -fpermissive -o $(FILENAME) $(OBJ) $(CFLAGS)
	 clear
	 ./$(FILENAME)
