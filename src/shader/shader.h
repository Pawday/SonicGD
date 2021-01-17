#ifndef _SGD_SHADER_H
#define _SGD_SHADER_H


typedef struct ShaderProgramm
{
    int programm_id;
    int vertex_shader_id;
    int fragment_shader_id;
} ShaderProgramm;

ShaderProgramm create_shader_programm(char* vertex_source, char* fragment_source);

#endif