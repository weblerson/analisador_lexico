#include "checkers.h"
#include <ctype.h>
#include <stdio.h>

#define MAX_FILE_SIZE 16384

int main() {
  int i;
  char c;

  FILE *fp;
  char filename[128];
  char content[MAX_FILE_SIZE];

  int j;
  char token[64];

  printf("Digite o nome do arquivo: ");
  scanf("%s128", filename);

  fp = fopen(filename, "r");

  if (fp) {
    printf("\nTokens:\n");

    while (fgets(content, MAX_FILE_SIZE, fp)) {
      i = 0;
      while (content[i] != '\0') {
        j = 0;
        c = (unsigned char)content[i];
        if (isalnum(c) || c == '_' || c == '.') {
          while ((isalnum(c) || c == '_' || c == '.') && j < 63) {
            token[j++] = c;
            c = (unsigned char)content[++i];
          }
          token[j] = '\0';

          if (check_reserved_word(token)) {
            printf("%s -> PALAVRA RESERVADA\n", token);
          } else if (check_float(token)) {
            printf("%s -> NUMERO DECIMAL\n", token);
          } else if (check_integer(token)) {
            printf("%s -> NUMERO INTEIRO\n", token);
          } else {
            printf("%s -> IDENTIFICADOR\n", token);
          }
        } else {
          token[0] = content[i];
          token[1] = content[i + 1];
          token[2] = '\0';

          if (check_relational_operator(token)) {
            printf("%s -> OPERADOR RELACIONAL\n", token);
            i = i + 2;
          } else if (check_assignment(c)) {
            printf("%c -> ATRIBUICAO\n", c);
            i++;
          } else if (check_arithmetic_operator(c)) {
            printf("%c -> OPERADOR ARITMETICO\n", c);
            i++;
          } else if (check_delimiter(c)) {
            printf("%c -> DELIMITADOR\n", c);
            i++;
          } else {
            i++;
          }
        }
      }
      printf("\n");
    }
  } else {
    printf("O arquivo não existe.");
  }

  return 0;
}
