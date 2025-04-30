#include "hash_table.h"
#include <stdio.h>

int main(void) {
  ht_hash_table *ht = ht_new();

  puts("Inserting 0 to 5 as keys and their squares values into the hash "
       "table\n");

  for (int i = 0; i < 5; i++) {
    char key[2];
    sprintf(key, "%d", i);
    char value[3];
    sprintf(value, "%d", i * i);

    ht_insert(ht, key, value);
  }

  puts("Delete Key 4\n");
  ht_delete(ht, "4");

  puts("Searching for keys\n");
  printf("Key 3: %s\n", ht_search(ht, "3"));
  printf("Key 2: %s\n", ht_search(ht, "2"));
  printf("Key 1: %s\n", ht_search(ht, "1"));
  printf("Key 4: %s\n", ht_search(ht, "4"));

  puts("\nUpdating key 3 to be 300\n");
  ht_insert(ht, "3", "300");

  printf("Key 3: %s\n", ht_search(ht, "3"));

  ht_del_hash_table(ht);
}
