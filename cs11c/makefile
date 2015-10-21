#
# CS 11: Makefile for C track, assignment 2.
#

#
# NOTE: When pasting this file from a browser window into a text editor,
#       the tab characters at the beginning of the command lines will
#       almost always be replaced by e.g. eight spaces.  You MUST convert
#       them back into a single tab or this file will not work!  "make"
#       is _extremely_ picky about this: command lines must start with one
#       tab and no spaces, no more and no less.  You're better off saving
#       this file directly (e.g. by typing control-S in mozilla or firefox).
#       Also, remove this comment in your submitted Makefile.
#

CC              = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic


all: 1dcarray 1dcpointer
	
memcheck.o: memcheck.c memcheck.h
	$(CC) $(CFLAGS) -c memcheck.c

1dcarray: 1dcarray.o memcheck.o
	$(CC) 1dcarray.o memcheck.o -o 1dcarray 

1dcpointer: 1dcpointer.o memcheck.o
	$(CC) 1dcpointer.o memcheck.o -o 1dcpointer

1dcarray.o: 1dcarray.c memcheck.o 
	$(CC) $(CFLAGS) -c 1dcarray.c

1dcpointer.o: 1dcpointer.c memcheck.o 
	$(CC) $(CFLAGS) -c 1dcpointer.c


check:
	c_style_check 1dcarray.c 1dcpointer.c

clean: 
	rm -f 1dcpointer.o 1dcpointer  memcheck.o 1dcarray.o 1dcarray 


