CC = g++
CFLAGS = -g -O2
OBJECTS = main.o server.o

main.out : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o server

%.o : %.c
	$(CC) $(CFLAGS) -c $<
