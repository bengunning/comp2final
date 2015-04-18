CC = g++
CFLAGS = -lSDL -O3 -Ofast -lSDL_image -lSDL_ttf
PROGRAM = sheepHerder
OBJECTS = main.o Obstacle.o MainMenu.o Stone.o Sheep.o SheepHerder.o SheepGraphics.o Graphics.o Herd.o

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM) $(CFLAGS)

%.o : %.cpp
	$(CC) -c $<

clean : 
	rm -f $(OBJECTS) $(PROGRAM)
