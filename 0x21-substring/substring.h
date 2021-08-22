#ifndef __SS__
#define __SS__

#include <stdio.h>
#include <stdlib.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
void reset(int *found, int size);
int donecheck(int *found, int nb_words);
int string_cmp(char const **w, char const *s, int b, int found[100]);
int processer(char const *, int, char const **, int, int, int *);

#endif
