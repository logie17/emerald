lex: lexer.c
	clang -o lexer -g lexer.c

list_test: list_test.c
	clang `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -g -Wall -std=gnu99 -o list_test list_test.c list.c
	./list_test
	rm list_test
