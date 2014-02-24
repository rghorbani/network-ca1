CC = g++
CFLAGS = -g -O2
OBJECTS = client.o defines.o func_lib.o

main.out : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o client

%.o : %.c
	$(CC) $(CFLAGS) -c $<
