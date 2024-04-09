#include "Akon/Vec.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
int main(){

    Vec *vec = vec_create(1);
    assert(vec->capacity == 1);
    assert(vec->elements_saved == 0);

    vec_push_back(vec, "hi");
    assert(vec_get_at(vec, 1) == "hi");
    assert(vec->capacity == 1);

    vec_push_back(vec, "sup");
    assert(vec_get_at(vec, 2) == "sup");
    assert(vec->capacity >= 1.7);

    return 0;
}