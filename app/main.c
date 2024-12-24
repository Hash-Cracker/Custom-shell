#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Uncomment this block to pass the first stage
  printf("$ ");

  // Wait for user input
  char input[100];
  fgets(input, 100, stdin);
  input[strlen(input) - 1] = '\0';
  printf("%s: command not found\n", input);

  while(1){
    printf("$ ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';
    if(!strcmp(input, "exit 0")){
      return 0;
    }
    if(strncmp(input, "echo", strlen("echo")) == 0){
      printf("%s\n", input + 5);
      continue;
    }
    printf("%s: command not found\n", input);
  }
    
    return 0;
}
