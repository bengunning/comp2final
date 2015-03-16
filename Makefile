CC = g++
CFLAGS = -lSDL
PROGRAM = sheepHerder
OBJECTS = main.o Sheep.o Graphics.o Herd.o

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM) $(CFLAGS)

%.o : %.cpp
	$(CC) -c $<

clean : 
	rm -f $(OBJECTS) $(PROGRAM)
