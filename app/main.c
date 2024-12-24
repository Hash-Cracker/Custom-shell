#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Uncomment this block to pass the first stage
  //printf("$ ");

  // Wait for user input
  char input[100];
  
  // Remove the newline character if present
  input[strlen(input) - 1] = '\0';
  
  //printf("%s: command not found\n", input);

  while(1) {
    printf("$ ");
    fgets(input, 100, stdin);
    
    // Remove the newline character if present
    input[strcspn(input, "\n")] = '\0';

    if(!strcmp(input, "exit 0")) {
      return 0;
    }

    // Check if input starts with "echo"
    if(strncmp(input, "echo", strlen("echo")) == 0) {
      // Print the part of the string after "echo " (5 characters forward)
      printf("%s\n", input + 5); 
      continue;
    }

    // If command not found
    printf("%s: command not found\n", input);
  }

  return 0;
}

