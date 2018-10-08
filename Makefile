S_SRCS = main_stack.c stack.c
S_EXEC = stack

Q_SRCS = main_queue.c queue.c
Q_EXEC = queue


CC = gcc
CCFLAG = -g -Wall

all:
	${CC} ${CCFLAG} ${S_SRCS} -o ${S_EXEC}
	${CC} ${CCFLAG} ${Q_SRCS} -o ${Q_EXEC}

