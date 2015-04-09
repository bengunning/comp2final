CC = g++
CFLAGS = -lSDL -lSDL_image -lSDL_ttf
PROGRAM = sheepHerder
OBJECTS = main.o Sheep.o SheepHerder.o SheepGraphics.o Graphics.o Herd.o

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM) $(CFLAGS)

%.o : %.cpp
	$(CC) -c $<

clean : 
	rm -f $(OBJECTS) $(PROGRAM)
