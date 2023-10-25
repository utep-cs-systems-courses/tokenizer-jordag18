#include "stdio.h"

#include "stdlib.h"

#include "src/tokenizer.h"

#include "src/history.h"




int user_strcmp (char *a, char *b)

{

  while (*a && *b) {

    int diff = *a++ - *b++;

    if (diff) {

      return diff;

    }

  }

  if (!*a && !*b) return 0;

  return (*a) ? 1 : -1;
}
void user_remove_newline (char *str)

{

  while (*str != '\n') {

    str++;

  }

  *str = '\0';

  str--;

 
  if (*str == ' ' || *str == '\t') {

    *str = '\0';

  }

}



int user_bang(char *user)

{

  if(*user == '!') return 1;

  return 0;

}
int get_id(char *user)

{

  user++;

  char *start = user;

  int len = string_len(start);

  char *pNum = copy_str(start,len);

  int num = atoi(pNum);

  free(pNum);

  return num;

}
