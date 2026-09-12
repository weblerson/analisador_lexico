#include "checkers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 16384

int main() {
  FILE *fp;
  char filename[100];
  char content[MAX_FILE_SIZE];
  long filesize;
  char *token;

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
      token = strtok(content, " \t\n");
      while (token) {
        if (check_reserved_word(token)) {
          printf("%s -> PALAVRA RESERVADA\n", token);
        }

        token = strtok(NULL, " \t\n");
      }
    }

    fclose(fp);
  } else {
    printf("Nome de arquivo inválido.\n");
  }

  return 0;
}
