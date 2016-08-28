/**
 * File: File.h
 * Author: Sam Caulfield
 * Date: 29.08.2016
 * Description: File utility functions
 */

#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

/**
 * fileRead - Read a file into a string.
 * Parameters:
 * - fileName: The name of the file to open.
 * Return value:
 * - On success a pointer to a new, NULL-terminated, heap-allocated string
 *   containing the file contents is returned. On failure, a NULL-pointer is
 *   returned. Failure occurs if there is an error opening the file or a memory
 *   allocation error.
 */
char *fileRead(char *fileName);

#endif

