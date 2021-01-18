#include "../loader.h"

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define BUFFER_SIZE 100



static char has_error = 0;
static char* error_string = NULL;

char* sgd_loader_load_resource(char* resource_file_path, size_t* resource_size)
{
    //prepare file path
    int final_res_file_path_len = strlen(resource_file_path) + sizeof(SGD_RESOURCE_DIRECTORY);
    char* final_res_file_path = (char*) malloc(final_res_file_path_len);

    //fill path_str_buffer to zeros
    memset(final_res_file_path,0,final_res_file_path_len);

    // res_dir + / + path
    strcpy(final_res_file_path,SGD_RESOURCE_DIRECTORY);
    strcat(final_res_file_path,"/");
    strcat(final_res_file_path,resource_file_path);

    
    //read file

    


    FILE* resource_file = fopen(final_res_file_path,"rb");

    if (resource_file == NULL)
    {
        char* file_open_error_string = "Could not open file ";

        error_string = realloc(error_string,strlen(file_open_error_string) + strlen(final_res_file_path) + 1);
        memset(error_string,0,strlen(file_open_error_string) + strlen(final_res_file_path) + 1);

        strcpy(error_string,file_open_error_string);
        strcat(error_string,final_res_file_path);
        has_error = 1;
        
        free(final_res_file_path);

        return NULL;
    }
    
    char* buffer = malloc(BUFFER_SIZE);
    char* resource_content = malloc(BUFFER_SIZE);


    char is_file_end = 0;

    for (int read_iteration = 0; !is_file_end; read_iteration++)
    {
        int readed_cnt = fread(buffer,sizeof(char),BUFFER_SIZE,resource_file);

        if (readed_cnt < BUFFER_SIZE) 
        {
            is_file_end = 1;
            *resource_size = read_iteration * BUFFER_SIZE + readed_cnt;
        }
    
        resource_content = realloc(resource_content, read_iteration * BUFFER_SIZE + readed_cnt);
        memcpy(resource_content + read_iteration * BUFFER_SIZE,buffer,readed_cnt);
    }
    


    fclose(resource_file);

    free(final_res_file_path);
    free(buffer);

    return resource_content;
}

char* sgd_loader_load_string_resource(char* resource_string_file_path)
{
    size_t string_resourse_size;
    char* string_resourse = sgd_loader_load_resource(resource_string_file_path,&string_resourse_size);

    realloc(string_resourse,string_resourse_size + 1);
    
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
