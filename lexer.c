#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char * type;
  char * content;
} token;

int main(void) {
  
printf("Begin lexing!\n");

 static const char filename[] = "src.e";
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
