#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

static ht_item *ht_new_item(const char *k, const char *v) {
  ht_item *i = malloc(sizeof(ht_item));
  i->key = strdup(k);
  i->value = strdup(v);
  return i;
}

static void ht_del_item(ht_item *i) {
  free(i->key);
  free(i->value);
  free(i);
}

ht_hash_table *ht_new(void) {
  ht_hash_table *ht = malloc(sizeof(ht_hash_table));
  ht->size = 64;
  ht->count = 0;
  ht->items = calloc((size_t)ht->size, sizeof(ht_item));
  return ht;
}

void ht_del_hash_table(ht_hash_table *ht) {
  for (int i = 0; i < ht->size; i++) {
    ht_item *item = ht->items[i];
    if (item != NULL) {
      ht_del_item(item);
    }
  }
  free(ht->items);
  free(ht);
}

int ht_hash(const char *s, const int a, const int m) {
  long hash = 0;
  const int s_len = strlen(s);
  for (int i = 0; i < s_len; i++) {
    hash += (long)pow(a, (s_len - i + 1)) * s[i];
    hash %= m;
  }
  return (int)hash;
}
