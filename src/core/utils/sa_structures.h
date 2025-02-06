#ifndef __SA_STRUCTURES_H
#define __SA_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>

#define DEFINE_DYNAMIC_ARRAY(TYPE, NAME)                                \
    typedef struct                                                      \
    {                                                                   \
        TYPE *data;                                                     \
        size_t size;                                                    \
        size_t capacity;                                                \
    } NAME;                                                             \
\
void NAME##Init(NAME *arr, size_t cap)                                  \
{                                                                       \
    arr->data = malloc(cap * sizeof(TYPE));                             \
    arr->size = 0;                                                      \
    arr->capacity = cap;                                                \
}                                                                       \
\
void NAME##Push(NAME *arr, TYPE value)                                  \
{                                                                       \
    if(arr->size >= arr->capacity)                                      \
    {                                                                   \
        arr->capacity *= 2;                                             \
        arr->data = realloc(arr->data, arr->capacity * sizeof(TYPE));   \
    }                                                                   \
    arr->data[arr->size++] = value;                                     \
}                                                                       \
\
void NAME##Free(NAME *arr)                                              \
{                                                                       \
    free(arr->data);                                                    \
    arr->data = NULL;                                                   \
    arr->size = arr->capacity = 0;                                      \
}                                                                       \

#endif // __SA_STRUCTURES_H