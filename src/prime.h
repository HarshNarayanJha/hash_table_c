#ifndef PRIME_H
#define PRIME_H

#ifdef __clang__
#pragma clang diagnostic ignored                                               \
    "-Wempty-translation-unit" // bug?
                               // https://github.com/clangd/clangd/issues/2358
#endif

int is_prime(const int x);
int next_prime(int x);

#endif
