#include "stdio.h"
#include "user.h"
#include "src/tokenizer.h"
#include "src/history.h"

int main(int argc, char **argv)
{
  printf("The program name is <%s>\n", *(argv+0));
  puts("--Welcome to the Tokenizer--");
  fputs("Enter a string to be tokenized\n--COMMANDS--\nEnter history to see previous inputs\nEnter !(history ID) to re tokenize a previous input\nEnter exit to end the program\n",stdout);

  
  char userString[MAX];
 
  List *linkList = init_history();

  while (1) {
    fputs("> ",stdout);
    fgets(userString,sizeof(userString),stdin);

    
    char *pUser = userString;
    user_remove_newline(pUser);

    
    if (user_strcmp(pUser,pHis) == 0) {
      print_history(linkList);
    }
    
    else if (user_bang(pUser)) {
      if (linkList->root == NULL) {

	puts("History is empty");

      }

      else {

	int id = get_id(pUser);

	printf("The id inputed is %d\n",id);

	char *hisStr = get_history(linkList,id);

	if (hisStr != NULL) {

	  printf("The string with that id is %s\n",hisStr);

	  printf("The number of tokens in the input is %d\n", count_tokens(hisStr));

	  add_history(linkList,hisStr);

	  char **tokens = tokenize(hisStr);

	  print_tokens(tokens);

	  free_tokens(tokens);

	}

	else {

	  puts("Not a history id");

	}

      }

    }
    else if (user_strcmp(pUser,pExit) == 0) {

      puts("Thanks for using the program");

      free_history(linkList);

      goto done;

    }





    else {

      printf("The number of tokens in the input is %d\n", count_tokens(pUser));

      add_history(linkList,pUser);

      char **tokens = tokenize(pUser);

      print_tokens(tokens);

      free_tokens(tokens);

    }

  }

 done:

  return 0;

}
