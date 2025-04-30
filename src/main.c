#include <stdio.h>

#include "hash_table.h"

int main(void) {
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
