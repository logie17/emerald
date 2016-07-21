lex: lexer.c
	clang -o lexer -g lexer.c

list_test: list_test.c
	clang `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -g -Wall -std=gnu99 -o list_test list_test.c list.c
	./list_test
	rm list_test

hash_test: hash_test.c
	clang `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -g -Wall -std=gnu99 -o hash_test hash_test.c hash.c list.c
	./hash_test
	rm hash_test

darray_test: darray_test.c
	clang `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -g -Wall -std=gnu99 -o darray_test darray_test.c darray.c list.c
	./darray_test
	rm darray_test
