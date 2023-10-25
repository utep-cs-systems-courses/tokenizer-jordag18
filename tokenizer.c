#include <stdio.h>
#include <stdlib.h>
#include "src/tokenizer.h"

int space_char(char c){
  if (c == '\t' || c == ' ' || c == '\n') return 0;
  return 1;
}

int non_space_char(char c){
  if (c == '\0'){
    return 0;
  }
  else {
    return (space_char(c));
  }
}

char *token_start(char *str){
  while(space_char(*str) == 0){
    str++;
  }
  if(*str == '\0'){
    return 0;
  }
  else {
    return str;
  }
}


char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

int count_tokens(char *str){
  if (*str == '\0' || *str == '\t') return 0;

  int count = 0;

  char *start = token_start(str);
  char *end = token_terminator(start);

  while(*end != '\0'){
    count++;
    start = token_start(end);
    end = token_terminator(start);
  }
  if (*end == '\0') count++;

  return count;
}

char *copy_str(char *intStr, short len){
  char *copy = (char*)malloc((len+1)*sizeof(char));
  char *p = copy;

  int i = 0;
  while(i<len){
    *copy = *intStr;
    intStr++;
    copy++;
    i++;
  }
  *copy = '\0';
  return p;
}

char **tokenize(char* str){
  int num_tokens = count_tokens(str);
  char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char*));
  char *start = str;
  int i = 0;
  while(i<num_tokens){
    start = token_start(start);
    char *end = copy_str(start,token_terminator(start)-start);
    *tokens = end;
    start = token_terminator(start);
    tokens++;
    i++;
  }

  *tokens = '\0';
  return tokens - num_tokens;
}

void print_tokens(char **tokens){
  int count = 1;
  while(*tokens) {
    printf("[%d]: %s\n", count, *tokens);
    tokens++;
    count++;
  }
}

void free_tokens(char **tokens){
  char** temp = tokens;
  while(*temp){
    free(*temp);
    temp++;
  }
  free(tokens);
}
