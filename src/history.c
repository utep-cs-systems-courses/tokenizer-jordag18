#include <stdio.h>
#include <stdlib.h>
#include "src/history.h"
#include "src/tokenizer.h"

List *init_history(){
  List *list = (List*) malloc(sizeof(List));
  return list;
}

void add_history(List *list, char *str){
  Item *newItem = (Item*) malloc(sizeof(Item));
  char *newPointer = str;
  if(newPointer == NULL)
    exit(-1);

  while(*newPointer != '\0'){
    newPointer++;
}
  

