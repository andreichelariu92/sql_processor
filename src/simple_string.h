#ifndef SIMPLE_STRING_H
#define SIMPLE_STRING_H

/**
 * \brief
 * Structure that holds a string implementation.
 * All of the functions in this module will receive
 * as their first parameter a pointer to this structure.
 */
struct simple_string;

/**
 * \brief SS_Create
 * Create a simple string structure.
 *
 * \param buffer
 * The buffer that will be in the structure.
 *
 * \return
 * Pointer to a simple_string structure. This pointer
 * can be used to make operations on the string. In
 * case of error, it returns NULL.
 */
struct simple_string* SS_Create(const char* buffer);

/**
 * \brief SS_Get
 * Returns a pointer to the character array of the string.
 * Do not free this memory manually!
 *
 * \param s
 * Pointer to a simple_string structure.
 *
 * \return
 * Pointer to a constant char.
 */
const char* SS_Get(struct simple_string* s);

/**
 * \brief SS_Append
 * Appends to the first string the contents of the
 * second string. If the first string is not big enough,
 * it gets reallocated.
 *
 * \param s1
 * First string.
 *
 * \param s2
 * Second string.
 *
 * \return
 * 0 in case of success.
 */
int SS_Append(struct simple_string* s1,
              struct simple_string* s2);
/**
 * \brief SS_Distroy
 * Distroys the given string and frees up all of the memory
 * used by it.
 *
 * \param string
 * Pointer to a structure created using SS_Create().
 *
 * \return
 * 0 in case of success, otherwise error.
 */
int SS_Distroy(struct simple_string* string);
#endif // SIMPLE_STRING_H
