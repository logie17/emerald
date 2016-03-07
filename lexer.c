#include "lexer.h"

Lexer * lexer_new() {
  return (Lexer *)calloc(1, sizeof(Lexer));
}

// List_insert This will insert a new item in the list.
void skipWhiteSpace(Lexer * l) {
  while (l->currentChar != NULL && l.currentChar == ' ') {
    advance(l);
  }
}

// Advance this will advance the token
void Advance(Lexer *l) {
  l->post = l->pos + 1;
  if (l->pos == (len(l->text) - 1 )) {
    l->currentChar = NULL;
  } else {
    l->currentChar = l->text[l->pos];
  }
}

Token * GetNextToken(Lexer *l) {
  if (l->currentChar != NULL) {
    if (l->currentChar == ' ') {
      skipWhiteSace(l);
    }
  }
}

int main(void) {
  
  printf("Begin lexing!\n");

  static const char filename[] = "./examples/src.e";
  FILE * file = fopen(filename, "r");
  char * code;
  size_t n = 0;
  int c;

  if (file) {
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    code = malloc(f_size);
    
    while((c = fgetc(file)) != EOF) {
      code[n++] = (char)c;
      printf("%c\n", (char)c);
    }
    
    code[n] = '\0';
  }
  exit(1);
}


