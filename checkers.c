#include "checkers.h"
#include <string.h>

static const char *const RESERVED_WORDS[] = {"int",  "float", "char", "if",
                                             "else", "while", "for",  "return"};

#define RESERVED_WORDS_SIZE (sizeof RESERVED_WORDS / sizeof RESERVED_WORDS[0])

int check_reserved_word(const char *word) {
  int i;

  for (i = 0; i < (int)RESERVED_WORDS_SIZE; i++) {
    if (strcmp(RESERVED_WORDS[i], word) == 0) {
      return 1;
    }
  }

  return 0;
}
