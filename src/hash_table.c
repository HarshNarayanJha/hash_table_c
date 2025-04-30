#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

static ht_item HT_DELETED_ITEM = {NULL, NULL};

static ht_item *ht_new_item(const char *k, const char *v) {
  ht_item *i = malloc(sizeof(ht_item));
  i->key = strdup(k);
  i->value = strdup(v);
  return i;
}

static void ht_del_item(ht_item *i) {
  if (i == &HT_DELETED_ITEM) {
    return;
  }

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

static int ht_hash(const char *s, const int a, const int m) {
  long hash = 0;
  const int s_len = strlen(s);
  for (int i = 0; i < s_len; i++) {
    hash += (long)pow(a, (s_len - i + 1)) * s[i];
    hash %= m;
  }
  return (int)hash;
}

int ht_get_hash(const char *s, const int num_buckets, const int attempt) {
  const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
  const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void ht_insert(ht_hash_table *ht, const char *key, const char *value) {
  ht_item *item = ht_new_item(key, value);
  int index = ht_get_hash(item->key, ht->size, 0);
  ht_item *curr_item = ht->items[index];

  int i = 1;
  while (curr_item != NULL) {
    if (curr_item != &HT_DELETED_ITEM) {
      if (strcmp(key, curr_item->key) == 0) {
        ht_del_item(curr_item);
        ht->items[index] = item;
        return;
      }
    }
    index = ht_get_hash(item->key, ht->size, i);
    curr_item = ht->items[index];
    i++;
  }

  ht->items[index] = item;
  ht->count++;
}

char *ht_search(ht_hash_table *ht, const char *key) {
  int index = ht_get_hash(key, ht->size, 0);
  ht_item *item = ht->items[index];
  int i = 1;

  while (item != NULL) {
    if (item != &HT_DELETED_ITEM) {
      if (strcmp(key, item->key) == 0) {
        return item->value;
      }
    }
    index = ht_get_hash(key, ht->size, i);
    item = ht->items[index];
    i++;
  }

  return NULL;
}

void ht_delete(ht_hash_table *ht, const char *key) {
  int index = ht_get_hash(key, ht->size, 0);
  ht_item *item = ht->items[index];
  int i = 1;
  while (item != NULL) {
    if (item != &HT_DELETED_ITEM) {
      if (strcmp(key, item->key) == 0) {
        ht_del_item(item);
        ht->items[index] = &HT_DELETED_ITEM;
        ht->count--;
      }
    }
    index = ht_get_hash(key, ht->size, i);
    item = ht->items[index];
    i++;
  }
}
