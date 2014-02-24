CC = g++
CFLAGS = -g -O2
OBJECTS = server.o defines.o func_lib.o info.o

main.out : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o server

%.o : %.c
	$(CC) $(CFLAGS) -c $<
