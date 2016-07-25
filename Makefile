CC=clang
PKG_CONFIG=pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0
CFLAGS=-g -Wall -std=gnu99

lex: lexer.c
	clang -o lexer -g lexer.c

test_all: list_test hash_test darray_test

list_test: list_test.c
	$(CC) `$(PKG_CONFIG)` $(CFLAGS) -o $@ $@.c list.c
	./$@
	rm $@

hash_test: hash_test.c
	$(CC) `$(PKG_CONFIG)` $(CFLAGS) -o $@ $@.c hash.c list.c
	./$@
	rm $@

darray_test: darray_test.c
	$(CC) `$(PKG_CONFIG)` $(CFLAGS) -o $@ darray.c $@.c
	./$@
	rm $@
