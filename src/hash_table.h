#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#ifdef __clang__
#pragma clang diagnostic ignored                                               \
    "-Wempty-translation-unit" // bug?
                               // https://github.com/clangd/clangd/issues/2358
#endif

#define HT_PRIME_1 1099511
#define HT_PRIME_2 8959529

typedef struct {
  char *key;
  char *value;
} ht_item;

typedef struct {
  int size;
  int base_size;
  int count;
  ht_item **items;
} ht_hash_table;

ht_hash_table *ht_new(void);
void ht_del_hash_table(ht_hash_table *ht);
int ht_get_hash(const char *s, const int num_buckets, const int attempt);

void ht_insert(ht_hash_table *ht, const char *key, const char *value);
char *ht_search(ht_hash_table *ht, const char *key);
void ht_delete(ht_hash_table *ht, const char *key);

#endif
