#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "hash_table.h"
#include "utils.h"

int main(void) {
  ht_hash_table *ht = ht_new();

  printf("Welcome to Interactive Hash Table written in C\n");
  printf("Type 'help' to get some help\n\n");

  char input[128];

  while (1) {
    printf("> ");
    if (fgets(input, 128, stdin) == NULL) {
      break;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strcasecmp(input, "help") == 0) {
      print_help_message();

    } else if (strcasecmp(input, "quit") == 0) {
      break;

    } else if (is_insert(input)) {
      char *key = strtok(input, "=");
      char *value = strtok(NULL, "=");
      if (key != NULL && value != NULL) {
        ht_insert(ht, key, value);
        printf("Inserted key %s value %s\n", key, value);
      } else {
        printf("Usage: key=value\n");
      }

    } else if (is_search(input)) {
      char *key = strtok(input, "?");
      if (key != NULL) {
        char *value = ht_search(ht, key);
        if (value != NULL) {
          printf("Found key %s value %s\n", key, value);
        } else {
          printf("Key %s not found\n", key);
        }
      } else {
        printf("Usage: key?\n");
      }

    } else if (is_delete(input)) {
      strtok(input, "-");
      char *key = strtok(input, "-");
      if (key != NULL) {
        char *value = strdup(ht_search(ht, key));
        if (value != NULL) {
          ht_delete(ht, key);
          printf("Deleted key %s with value %s\n", key, value);
        } else {
          printf("Key %s not found\n", key);
        }
      } else {
        printf("Usage: -key\n");
      }
    } else if (strcasecmp(input, "print") == 0) {
      ht_print(ht);
    } else {
      printf("Unknown command. Please see 'help'\n");
    }
  }

  ht_del_hash_table(ht);

  return 0;
}

void test(void) {
  ht_hash_table *ht = ht_new();

  char key[100], value[100];

  for (int i = 0; i < 183; i++) {
    sprintf(key, "%d", i);
    sprintf(value, "%d", i * i);
    ht_insert(ht, key, value);
  }

  printf("Hashmap max size is %d\n", ht->size);
  printf("Hashmap contains %d values\n", ht->count);

  puts("Delete Key 4\n");
  ht_delete(ht, "4");

  puts("Searching for keys\n");
  printf("Key 3: %s\n", ht_search(ht, "3"));
  printf("Key 2: %s\n", ht_search(ht, "2"));
  printf("Key 50: %s\n", ht_search(ht, "50"));
  printf("Key 25: %s\n", ht_search(ht, "25"));
  printf("Key 19: %s\n", ht_search(ht, "19"));
  printf("Key 4: %s\n", ht_search(ht, "4"));

  puts("\nUpdating key 3 to be 300\n");
  ht_insert(ht, "3", "300");

  printf("Key 3: %s\n", ht_search(ht, "3"));

  ht_del_hash_table(ht);
}
