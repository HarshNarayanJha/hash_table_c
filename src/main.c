#include "hash_table.h"
#include <stdio.h>

int main(void) {
  puts("This is Hash Table Test");
  ht_hash_table *ht = ht_new();
  printf("Capacity of hash table is %d and currently there are %d elements in "
         "it\n",
         ht->size, ht->count);
  ht_del_hash_table(ht);
  puts("Hash Table Deleted\n");

  puts("\nNow Will check the hash function\n");
  int a = ht_hash("Hello", 151, 64);
  int b = ht_hash("Hello", 1510, 24);
  int c = ht_hash("This is a very long sentence", 100, 64);

  printf("Hello\t->\t%d\nHello\t->\t%d\nLong\t->\t%d\n", a, b, c);
}
