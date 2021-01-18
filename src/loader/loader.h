#ifndef _SGD_LOADER_H
#define _SGD_LOADER_H

#define SGD_RESOURCE_DIRECTORY "res"

/**
 * @return the pointer to NEW MEMORY BLOCK
**/

char* sgd_loader_load_resource(char* resource_file_path);

/**
 * @return 
 *  0x0 if no any error
 *  0x1 if any error is
**/
char sgd_loader_has_error();

/**
 * @return the pointer to NEW MEMORY BLOCK contains error description
**/

char* sgd_loader_get_error_string();

#endif