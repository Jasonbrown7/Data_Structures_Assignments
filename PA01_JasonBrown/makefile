OBJS	= assign2.o
SOURCE	= assign2.cpp
HEADER	=
OUT	= assign2
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

assign2.o: assign2.cpp
	$(CC) $(FLAGS) assign2.cpp


clean:
	rm -f $(OBJS) $(OUT)
