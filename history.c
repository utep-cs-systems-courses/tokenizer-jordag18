#include <stdio.h>
#include <stdlib.h>
#include "src/history.h"
#include "src/tokenizer.h"

List *init_history(){
  List *linkList = malloc (sizeof(List));
  linkList->root = NULL;
  return linkList;
}

int string_len(char *str){
  int i = 0;
  while(*str){
    str++;
    i++;
  }
  return i;
}

void add_history(List *list, char *str){
  if (list->root == NULL) {
    Item *root = malloc(sizeof(Item));
    root->id = 1;
    root->str = copy_str(str,string_len(str));
    list->root = root;
    root->next = NULL;
  }
  else {
    Item *copyRoot = list->root;
    Item *newNode = malloc(sizeof(Item));

    while(copyRoot->next != NULL) {
      copyRoot = copyRoot->next;
    }
    newNode->id = copyRoot->id+1;
    newNode->str = copy_str(str,string_len(str));
    newNode->next = NULL;
    copyRoot->next = newNode;
  }
}

char *get_history(List *list, int id){
  Item *copyList = list->root;

  while(copyList){
    if (copyList->id == id){
      return copyList->str;
    }
    copyList = copyList->next;
  }
  return NULL;
}

void print_history(List *list){
  if (list->root == NULL) {
    puts("History is empty");
  }
  else {
    Item *copyList = list->root;
    while (copyList) {
      printf("[%d]: %s\n", copyList->id, copyList->str);
      copyList = copyList->next;
    }
  }
}

void free_history(List *list){
  while (list->root->next) {
    Item *nextNode = list->root->next;
    free(list->root);
    list->root = nextNode;
  }
  free(list->root);
  free(list);
  
}
