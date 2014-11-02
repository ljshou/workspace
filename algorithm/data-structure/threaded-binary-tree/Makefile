# makefile for thrbitree
# Copyright 2011 by wuwennongdao 
# Email: liuy0711@foxmail.com
# Blog: blog.csdn.net/algorithm_only

CC = gcc
RM = rm -f

SRC = main.c thrbitree.c
OBJ := $(SRC:.c=.o)
PROGRAM = thrbitree
CFLAGS = -Wall -g

all : $(PROGRAM)

$(PROGRAM) : $(OBJ)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : all clean
clean :
	$(RM)  $(OBJ)
