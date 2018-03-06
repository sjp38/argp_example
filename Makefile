ALL := main
CLEAN := ${ALL}

CFLAGS := -Wall -g -O2

all: ${ALL}

main: main.c
	${CC} -o main ${CFLAGS} main.c

clean:
	rm -f ${CLEAN}
