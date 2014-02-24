CC = g++
CFLAGS = -g -O2
OBJECTS = main.o client.o

main.out : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o client

%.o : %.c
	$(CC) $(CFLAGS) -c $<
