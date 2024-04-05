#include "AKVector/AKVector.h"
#include <stdlib.h>
#include<stdio.h>
int main(){
    AKVector *myVec = akvector_init(1);

    akvector_push_back(myVec, "hi");
    akvector_push_back(myVec, "hi");
    printf("%s %d %d\n", myVec->items[2], myVec->size, myVec->total);
    return 0;
}