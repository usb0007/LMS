CC = g++
CFLAGS = -g  -Wall -std=c++11 -Wextra 

INCLUDES = -I header/

run: lms.o
	${CC} ${CFLAGS} lms.o -o run

lms.o: lms.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c lms.cpp


clean:
	echo "Cleaning....."
	rm  *.o run
