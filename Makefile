CC = g++
CFLAGS = -lSDL -lSDL_image -lSDL_ttf
PROGRAM = sheepHerder
OBJECTS = main1.o Sheep.o Graphics.o Herd.o

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM) $(CFLAGS)

%.o : %.cpp
	$(CC) -c $<

clean : 
	rm -f $(OBJECTS) $(PROGRAM)
