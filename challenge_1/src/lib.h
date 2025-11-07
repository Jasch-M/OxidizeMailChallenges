#ifndef CHALLENGE_1_H
#define CHALLENGE_1_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {

#endif


/// Rotates left by one space all the elements in the \p array.
/// The first element becomes the last element.
///
/// If NULL is passed to the array (not the pointers in the array of pointers themselves), nothing will be done.
///
/// The pointers are void pointers, so they can be completely generic and even point to different underlying elements.
/// The function will rotate the pointers but will not touch the content
/// pointed by the pointers in any way.
/// @param array the array of elements. If NULL is passed, nothing will be done.
/// @param size the size of the array
void rotate_left_ptrs(void **array, size_t size);

/// Rotates left by one space all the elements in the \p array.
/// The first element becomes the last element.
///
/// If NULL is passed, nothing will be done.
/// @param array the array of elements. If NULL is passed, nothing will be done.
/// @param size the size of the array
void rotate_left_inplace(int *array, size_t size);

/// Rotates left by one space all the elements in the \p array.
/// The first element becomes the last element.
///
/// If NULL is passed to the array, nothing will be done.
///
/// This function handles elements of an arbitrary size in bytes passed to the function as a parameter.
///
/// A heap allocation will occur of the size of size_of_element. If it fails,
/// the function will print a message out on the standard error stream and cancel the rotation.
/// It will also return 1 should this occur.
///
/// The function returns 0 in all other cases.
///
/// @param array the array of elements. If NULL is passed, nothing will be done.
/// @param size_of_element the size of the elements pointed to by the array in bytes. If the size is 0, no rotations will occur.
/// @param size the size of the array
/// @return 1 if the function failed to allocate memory on the heap. 0 in all other cases.
int rotate_left_inplace_generic(void *array, size_t size_of_element, size_t size);

#ifdef __cplusplus
}
#endif

#endif //CHALLENGE_1_H
