#ifndef AKVECTOR_LOADED
#define AKVECTOR_LOADED
#include <stdlib.h>
#include <stdio.h>

#define AKVECTOR_ERROR NULL

typedef struct AKVector
{
    void **items;
    size_t size;
    size_t total;
} AKVector;

size_t get_size()
{
    return sizeof(void *);
}

AKVector *akvector_init(size_t size)
{
    AKVector *myVec = malloc(sizeof(AKVector));

    myVec->items = malloc(size * get_size());
    myVec->size = size;
    myVec->total = 0;

    return myVec;
}

void akvector_resize(AKVector *myVec, size_t size)
{
    myVec->items = realloc(myVec->items, size);

    myVec->size *= size;
}
void akvector_push_back(AKVector *myVec, void *item)
{

    akvector_resize(myVec, myVec->size * 1.5);
    
    myVec->items[myVec->total] = item;
}
void *akvector_get() {}

#endif