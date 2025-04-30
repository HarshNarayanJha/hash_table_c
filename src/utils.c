#include <stdio.h>
#include <string.h>

#include "utils.h"

int is_insert(const char *input) {
  const int n = strlen(input);
  for (int i = 0; i < n; i++) {
    if (input[i] == '=') {
      return 1;
    }
  }
  return 0;
}

int is_search(const char *input) {
  const int n = strlen(input);
  if (input[n - 1] == '?') {
    return 1;
  }
  return 0;
}

int is_delete(const char *input) {
  if (input[0] == '-') {
    return 1;
  }
  return 0;
}

void print_help_message(void) {
  printf("Available commands:\n");
  printf("  help - display this help message\n");
  printf("  quit - exit the program\n");
  printf("  <key>=<value> - insert a key-value pair into the hash table\n");
  printf("  <key>? - search for a key in the hash table\n");
  printf("  -<key> - delete a key from the hash table\n");
  printf("  print - print all key-value pairs in the hash table\n");
}
