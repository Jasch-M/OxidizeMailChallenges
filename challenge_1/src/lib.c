#include "lib.h"

#include <stdio.h>
#include <stdlib.h>

void rotate_left_ptrs(void **array, const size_t size)
{
    if (array == NULL || size < 2)
    {
        return;
    }

    void *new_last_element = array[0];
    const size_t size_target = size - 1;
    size_t index = 0;

    while (index < size_target)
    {
        array[index] = array[index + 1];
        index++;
    }

    array[size - 1] = new_last_element;
}

void rotate_left_inplace(int *array, const size_t size)
{
    if (array == NULL || size < 2)
    {
        return;
    }

    const int new_last_element = array[0];
    const size_t size_target = size - 1;
    size_t index = 0;

    while (index < size_target)
    {
        array[index] = array[index + 1];
        index++;
    }

    array[size - 1] = new_last_element;
}

#define SUCCESS 0
#define FAILURE 1

int rotate_left_inplace_generic(void *array, const size_t size_of_element, const size_t size)
{
    uint8_t *actual_array = array;
    if (array == NULL || size_of_element == 0 || size < 2)
    {
        return SUCCESS;
    }

    uint8_t *new_last_element = malloc(sizeof(uint8_t) * size_of_element);
    if (new_last_element == NULL)
    {
        fprintf(stderr, "Ran out of memory :(\n");
        return FAILURE;
    }

    size_t element_cursor = 0;
    while (element_cursor < size_of_element)
    {
        new_last_element[element_cursor] = actual_array[element_cursor];
        element_cursor++;
    }

    const size_t size_target = size * size_of_element - size_of_element;
    size_t index = 0;

    while (index < size_target)
    {
        actual_array[index] = actual_array[index + size_of_element];
        index++;
    }

    element_cursor = 0;
    while (element_cursor < size_of_element)
    {
        actual_array[index + element_cursor] = new_last_element[element_cursor];
        element_cursor++;
    }

    free(new_last_element);
    return SUCCESS;
}
