#include "checkers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 16384

/*
int main() {
  FILE *fp;
  char filename[100];
  char content[MAX_FILE_SIZE];
  long filesize;
  int line_index;
  int linesize;
  char current;

  printf("Digite o nome do arquivo: ");
  scanf("%s", filename);

  printf("Arquivo: %s\n", filename);

  fp = fopen(filename, "r");
  if (fp) {
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    printf("Tamanho: %d\n", (int)filesize);

    printf("Tokens:\n");
    while (fgets(content, MAX_FILE_SIZE, fp)) {
      linesize = (int)strlen(content);
      for (line_index = 0; line_index < linesize; line_index++) {
        current = (char)content[line_index];
        if (check_delimiter(current)) {
          printf("%c -> DELIMITADOR\n", current);
        } else if (isalnum(current)) {
          while (!isblank(current)) {

            current = (char)content[line_index];
            line_index++;
          }
        }
      }

      token = strtok(content, " \t\n");
      while (token) {
        if (check_reserved_word(token)) {
          printf("%s -> PALAVRA RESERVADA\n", token);
        } else if (check_integer(token)) {
          printf("%s -> NUMERO INTEIRO\n", token);
        }

        token = strtok(NULL, " \t\n");
      }
}

fclose(fp);
}
else {
  printf("Nome de arquivo inválido.\n");
}

return 0;
}
*/

int main() {
  int i;
  char c;
  char *content;

  int j;
  char token[64];

  content = "int numero = 25;";
  printf("Código:\n%s\n", content);

  printf("\nTokens:\n");

  i = 0;
  while (content[i] != '\0') {
    j = 0;
    c = (unsigned char)content[i];
    if (isalnum(c)) {
      while (isalnum(c) && j < 63) {
        token[j++] = c;
        c = (unsigned char)content[++i];
      }
      token[j] = '\0';

      if (check_reserved_word(token)) {
        printf("%s -> PALAVRA RESERVADA\n", token);
      } else if (check_integer(token)) {
        printf("%s -> NUMERO INTEIRO\n", token);
      } else {
        printf("%s\n", token);
      }
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

  return 0;
}
