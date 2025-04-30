#include "hash_table.h"
#include <stdio.h>

int main(void) {
  puts("This is Hash Table Test");
  ht_hash_table *ht = ht_new();
  printf("Capacity of hash table is %d and currently there are %d elements in "
         "it\n",
         ht->size, ht->count);
  ht_del_hash_table(ht);
  puts("Hash Table Deleted");
}
