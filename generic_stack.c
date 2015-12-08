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

typedef struct my_stack_s
{
    void *elems;              //pointer to array of elements
    int elem_size;            //size of each element
    int current_stack_elems;  //current num of elements in stack
    int max_stack_size;       //max size of stack
} my_stack_t;

static void
stack_init(my_stack_t *s,
           int        elem_size)
{
    s->max_stack_size = 4;
    s->elem_size = elem_size;
    s->current_stack_elems = 0;
    s->elems = malloc(elem_size * s->max_stack_size);

    assert(s->elems != NULL);
}

static void
stack_destroy(my_stack_t *s)
{
    free(s->elems);
}

static void
stack_push(my_stack_t *s,
           const void *elem_addr)
{
    void *dest;
    if (s->current_stack_elems == s->max_stack_size) {
        s->max_stack_size *= 2;
        s->elems = realloc(s->elems, s->elem_size * s->max_stack_size);
        assert(s->elems != NULL);
    }

    dest = (char*)s->elems + ((s->current_stack_elems) * s->elem_size);

    memcpy(dest, elem_addr, s->elem_size);
    s->current_stack_elems++;

}

static bool
is_stack_empty(const my_stack_t *s)
{
    return (s->current_stack_elems == 0);
}

static void
stack_pop(my_stack_t *s,
          void       *elem_addr)
{
    void *src;

    assert (!is_stack_empty(s));

    s->current_stack_elems--;
    src = (char*)s->elems + ((s->current_stack_elems) * s->elem_size);

    memcpy(elem_addr, src, s->elem_size);
}

int
main(int  argc,
     char **argv)
{
    int        val;
    my_stack_t int_stack;

    stack_init(&int_stack, sizeof(int));

    for(val = 0; val < 6; val++) {
        stack_push(&int_stack, &val);
    }

    while (!is_stack_empty(&int_stack)) {
        stack_pop(&int_stack, &val);
        printf("This just popped: %d\n", val);
    }

    stack_destroy(&int_stack);

    return 0;
}
