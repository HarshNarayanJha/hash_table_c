#ifndef UTILS_H
#define UTILS_H

#ifdef __clang__
#pragma clang diagnostic ignored "-Wempty-translation-unit" // bug?
#endif

int is_insert(const char *input);
int is_search(const char *input);
int is_delete(const char *input);
void print_help_message(void);

#endif
