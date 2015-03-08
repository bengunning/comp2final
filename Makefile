CC = g++
PROGRAM = sheepHerder
OBJECTS = main.o Sheep.o

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM)

%.o : %.cpp
	$(CC) -c $<

clean : 
	rm -f $(OBJECTS) $(PROGRAM)
