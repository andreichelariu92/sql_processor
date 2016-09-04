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

char* appendStrings(const char* s1, const char* s2)
{
        const int totalSize = strlen(s1) +
                              strlen(s2) +
                              1 /*terminator character*/;

        char* newBuff = malloc(totalSize * sizeof(char));

        if (newBuff) {
                strcpy(newBuff, s1);
                strcat(newBuff, s2);
        }

        return newBuff;
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
                fprintf(stderr, "Error creating string %d\n", errno);
                return NULL;
        }

}

const char* SS_GetBuffer(struct simple_string* s)
{
        if (s) {
                return s->buffer;
        }
        else {
                return NULL;
        }
}

const char* SS_CopyBuffer(struct simple_string* s)
{
        return appendStrings(s->buffer, "");
}

int SS_Append(struct simple_string* s1,
              const char* s2)
{
        char* appendBuff = appendStrings(s1->buffer, s2);

        if (appendBuff) {
                /*clear the old value of s1 and put the appended
                 * string into it*/
                free(s1->buffer);
                s1->buffer = appendBuff;
                s1->size = strlen(appendBuff);
                s1->capacity = s1->size;

                return 0;
        }
        else {
                fprintf(stderr, "Error in SS_AppendC %d\n", errno);
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
