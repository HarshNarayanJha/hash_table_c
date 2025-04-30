#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#ifdef __clang__
#pragma clang diagnostic ignored                                               \
    "-Wempty-translation-unit" // bug?
                               // https://github.com/clangd/clangd/issues/2358
#endif

typedef struct {
  char *key;
  char *value;
} ht_item;

typedef struct {
  int size;
  int count;
  ht_item **items;
} ht_hash_table;

ht_hash_table *ht_new(void);
void ht_del_hash_table(ht_hash_table *ht);
int ht_hash(const char *s, const int a, const int m);

#endif
