#ifndef _SGD_LOADER_H
#define _SGD_LOADER_H

#include <stddef.h>

#define SGD_RESOURCE_DIRECTORY "res"

/**
 * @return the pointer to NEW MEMORY BLOCK
 * @return @param resource_size - :)
**/

char* sgd_loader_load_resource(char* resource_file_path, size_t* resource_size);


char* sgd_loader_load_string_resource(char* resource_string_file_path);

/**
 * @return 
 *  0x0 if no any error
 *  0x1 if any error is
**/
char sgd_loader_has_error();

/**
 * @return the pointer to BLOCK OF MEMORY contains error description
 * no need to free
**/

char* sgd_loader_get_error_string();

#endif