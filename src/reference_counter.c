#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "reference_counter.h"

struct ref_counter
{
        void* addr;
        unsigned int count;
        cleanup_func cleanup;
};

/************************ Public functions *************************************/
struct ref_counter* RC_Create(void* resource, cleanup_func f)
{
        if (!f) {
                fprintf(stderr, "The pointer to cleanup function must be valid\n");
                return NULL;
        }

        struct ref_counter* output = malloc(sizeof(struct ref_counter));
        if (!output) {
                fprintf(stderr, "Error allocating memory %d", errno);
                return NULL;
        }

        output->addr = resource;
        output->count = 1;
        output->cleanup = f;

        return output;
}
