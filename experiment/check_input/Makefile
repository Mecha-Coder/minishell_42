CC = gcc
CFLAG = -Wall -Wextra -Werror

ENV = ./env/*.c
RUN = ./run/*.c
SYNTAX_A = ./syntax/after/*.c
SYNTAX_B = ./syntax/before/*.c
TOKEN = ./tokenize/*.c
TREE = ./tree/*.c
UTIL = ./util/*.c
MAIN = main.c


all: 
	$(CC) $(CFLAG) $(ENV) $(RUN) $(SYNTAX_A) $(SYNTAX_B) $(TOKEN) $(TREE) $(UTIL) $(MAIN) 