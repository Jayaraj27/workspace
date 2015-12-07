/*
 * This program implements a generic stack data structure
 * This is picked up from Stanford University
 * https://see.stanford.edu/materials/icsppcs107/stack-implementation.pdf
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    void *elems;           //pointer to array of elements
    int elemSize;          //size of each element
    int logLength;         //current num of elements in stack
    int allocLength;       //max size of stack
} stack;

void StackNew(stack *s,
              int   elemSize)
{
    s->allocLength = 4;
    s->elemSize = elemSize;
    s->logLength = 0;
    s->elems = malloc(elemSize * s->allocLength);

    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
    free(s->elems);
}

void StackPush(stack      *s,
               const void *elemAddr)
{
    void *dest;
    if (s->logLength == s->allocLength) {
        s->allocLength *= 2;
        s->elems = realloc(s->elems, s->elemSize * s->allocLength);
        assert(s->elems != NULL);
    }

    dest = (char*)s->elems + ((s->logLength) * s->elemSize);

    memcpy(dest, elemAddr, s->elemSize);
    s->logLength++;

}

bool StackEmpty(const stack *s)
{
    return (s->logLength == 0);
}

void StackPop(stack *s,
              void *elemAddr)
{
    void *src;

    assert (!StackEmpty(s));


    s->logLength--;
    src = (char*)s->elems + ((s->logLength) * s->elemSize);

    memcpy(elemAddr, src, s->elemSize);



}

int main(int argc, char *argv[])
{
    int val;
    stack intStack;
    StackNew(&intStack, sizeof(int));
    for(val = 0; val < 6; val++)
        StackPush(&intStack, &val);
    while (!StackEmpty(&intStack)){
        StackPop(&intStack, &val);
        printf("This just popped: %d\n", val);
    }
    StackDispose(&intStack);
    return 0;
}
