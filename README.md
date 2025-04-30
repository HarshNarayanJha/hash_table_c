# Hash Table in C

An interactive hash table written in C.

Supports simple operations, can't resize above 183 entries due to some weird logic issue causing segfault in `strcmp`.

This can do these operations:

- Create a new hash table
- Delete a hash table
- Get the hash value of a string
- Insert a key-value pair into the hash table
- Search for a value given a key
- Delete a key-value pair from the hash table

```c
ht_hash_table *ht_new(void);
void ht_del_hash_table(ht_hash_table *ht);
int ht_get_hash(const char *s, const int num_buckets, const int attempt);
void ht_insert(ht_hash_table *ht, const char *key, const char *value);
char *ht_search(ht_hash_table *ht, const char *key);
void ht_delete(ht_hash_table *ht, const char *key);
```

### Roadmap

[ ] Implement `save` and `load`, preferably using a binary format
