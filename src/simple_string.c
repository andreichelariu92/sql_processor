#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <errno.h>

#include "simple_string.h"

struct simple_string
{
        char* buffer;
        size_t size;
        size_t capacity;
};
/************************ Private functions ************************************/
struct simple_string* allocateMemory(size_t bufferSize)
{
        struct simple_string* output = malloc(sizeof(struct simple_string));
        if (output == NULL) {
                return NULL;
        }

        output->buffer = malloc(sizeof(char) * bufferSize);
        if (output->buffer == NULL) {
                return NULL;
        }

        return output;

}

/************************ Public functions *************************************/
struct simple_string* SS_Create(const char* buffer)
{
        const int size = strlen(buffer) + 1;
        struct simple_string* output = allocateMemory(size);

        if (output != NULL) {
                strcpy(output->buffer, buffer);
                output->size = size;
                output->capacity = size;

                return output;
        }
        else {
                fprintf(stderr, "Eror creating string %d\n", errno);
                return NULL;
        }

}

const char* SS_Get(struct simple_string* s)
{
        if (s) {
                return s->buffer;
        }
        else {
                return NULL;
        }
}

int SS_Append(struct simple_string* s1,
              struct simple_string* s2)
{
        const int totalSize = strlen(s1->buffer) +
                              strlen(s2->buffer) +
                              1; /* null terminator */

        char* newBuff = malloc(totalSize * sizeof(char));

        if (newBuff) {
                strcpy(newBuff, s1->buffer);
                strcat(newBuff, s2->buffer);
                free(s1->buffer);

                s1->buffer = newBuff;
                s1->capacity = totalSize;
                s1->size = totalSize;
                return 0;
        }
        else {
                fprintf(stderr, "Error in SS_Append %d\n", errno);
                return -1;
        }
}

int SS_Distroy(struct simple_string* string)
{
        if (string == NULL) {
                return 0;
        }

        free(string->buffer);
        free(string);

        return 0;
}
