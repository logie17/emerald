#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char * type;
  char * content;
  int position;
} Lexer;

typedef struct {
  char * type;
  char * value;
} Token;

const char* const ops[] = {
  "+",
  "-",
}; // all const

Lexer * lexer_new();


#endif
