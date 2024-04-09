#ifndef AKON_VEC_LOADED
#define AKON_VEC_LOADED
#include <stdlib.h>
#include <stdio.h>

// A heap-managed container that represents Arrays. Unlike arrays, Vecs start at 1 index rather than 0.
typedef struct Vec
{
    void **items;
    float capacity;
    int elements_saved;
} Vec;

// Creates a new Vec with a capacity of `float capacity`
Vec *vec_create(float capacity)
{
    Vec *vec = (Vec *)malloc(sizeof(Vec));
    vec->capacity = capacity;
    vec->elements_saved = 0;
    vec->items = malloc(capacity * sizeof(void *));

    return vec;
}

// Resizes an existing Vec with a new capacity.
void vec_resize(Vec *vec, float capacity)
{
    void **items = realloc(vec->items, capacity * sizeof(void *));

    if (items)
    {
        vec->capacity = capacity;
        vec->items = items;
    }
}

// Pushes an item at the end of the Vec. If the Vec's capacity isn't enough
// the capacity will grow by a growth factor of 1.7
void vec_push_back(Vec *vec, void *item)
{
    if (vec->capacity < (vec->elements_saved + 1))
    {
        vec_resize(vec, vec->capacity * 1.7);
    }
    vec->items[++vec->elements_saved] = item;
}

// Sets an item at the specificed index.
void vec_set_at(Vec *vec, int index, void *item)
{
    if (index <= vec->elements_saved && index > 0)
        vec->items[index] = item;
}

// Gets an item from the specificed index. 
// Returns NULL if the index is out of range.
void *vec_get_at(Vec *vec, int index)
{
    if (index > vec->elements_saved || index <= 0)
        return NULL;

    return vec->items[index];
}
// Cleans the Vec from the memory.
void vec_free(Vec *vec)
{
    free(vec->items);
    free(vec);
}

#endif