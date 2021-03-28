#include "../loader.h"

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

//TODO: create debug logging system

#define BUFFER_SIZE 1024

static char has_error = 0;
static char* error_string = NULL;


void load_resourse_error_message(char* resourse_file_path) 
{
    fprintf(stderr,"Error load file %s", resourse_file_path);
}

char* sgd_loader_load_resource(char* resource_file_path, size_t* resource_size)
{
    //size of resource for usage in loader function
    size_t* internal_resource_size = NULL;

    //assign internal_resource_size with parameter resource_size if it's not zero
    if (resource_size != NULL)
        internal_resource_size = resource_size;
    else
    {
        size_t internal_resource_size_val = 0;
        internal_resource_size = &internal_resource_size_val;
    }

    //opening file
    FILE* resource_file = fopen(resource_file_path,"rb");

    if (resource_file == NULL)
    {
        char* file_open_error_string = "Could not open file ";

        void* error_string_temp_addr = realloc(error_string,strlen(file_open_error_string) + strlen(resource_file_path) + 1); //with cstring_zero

        if (error_string_temp_addr == NULL)
        {
            #ifdef DEBUG
            fprintf(stderr, "Memory reallocation error in %s:%d for error_string %s\n", __FILE__, __LINE__, resource_file_path);
            #endif
            exit(-1);
        }
        //dont lose pointer
        else error_string = error_string_temp_addr;

        //fill error_string with zeros
        error_string = memset(error_string,0,strlen(file_open_error_string) + 1);

        strcpy(error_string,file_open_error_string);
        strcat(error_string,resource_file_path);
        has_error = 1;
        

        return NULL;
    }
    
    char* buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) 
    {
        #ifdef DEBUG
        fprintf(stderr, "Memory allocation error in %s:%d for buffer loading %s\n", __FILE__, __LINE__, resource_file_path);
        #endif
        exit(-1);
    }
    char* resource_content = malloc(BUFFER_SIZE);
    

    char is_file_end = 0;

    for (int read_iteration = 0; !is_file_end; read_iteration++)
    {
        size_t readed_cnt = fread(buffer,sizeof(char),BUFFER_SIZE,resource_file);

        if (readed_cnt < BUFFER_SIZE) 
        {
            is_file_end = 1;
            *internal_resource_size = read_iteration * (size_t) BUFFER_SIZE + readed_cnt;
        }
    
        char* resource_content_temp_addr = realloc(resource_content, read_iteration * (size_t) BUFFER_SIZE + readed_cnt);
        if (resource_content_temp_addr == NULL) 
        {
            #ifdef DEBUG
            fprintf
            (
                stderr,
                "Memory reallocation error in %s:%d for resource_content loading %s at iteration %d with readed_cnt = %zu\n",
                __FILE__,
                __LINE__,
                resource_file_path,
                read_iteration,
                readed_cnt            
            );
            #endif
            exit(-1);
        } else resource_content = resource_content_temp_addr;


        memcpy(resource_content + read_iteration * (size_t) BUFFER_SIZE,buffer,readed_cnt);
    }
    


    fclose(resource_file);

    free(buffer);

    return resource_content;
}

char* sgd_loader_load_string_resource(char* resource_string_file_path)
{
    size_t string_resourse_size;
    char* string_resourse = sgd_loader_load_resource(resource_string_file_path,&string_resourse_size);

    if (string_resourse == NULL) 
    {
        fprintf(stderr,"%s",sgd_loader_get_error_string());
        exit(-1);
    }

    char* string_resourse_temp_addr = realloc(string_resourse,string_resourse_size + 1);

    if (string_resourse_temp_addr == NULL)
    {
        #ifdef DEBUG
        fprintf
        (
            stderr,
            "Memory reallocation error in %s %d for string_resourse loading %s\n",
            __FILE__,
            __LINE__,
            resource_string_file_path
        );
        #endif
        exit(-1);
    } else string_resourse = string_resourse_temp_addr;
    
    *(string_resourse + string_resourse_size) = (char)0;

    return string_resourse;
}

char sgd_loader_has_error()
{
    return has_error;
}

char* sgd_loader_get_error_string()
{
    return error_string;
}
