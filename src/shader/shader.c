#include "shader.h"
#include <stdlib.h>
#include <stdio.h>
#include <glew.h>
#include <gl_error_wrapper.h>


/*local*/ check_compile_status(int shader_id);

ShaderProgramm create_shader_programm(char* vertex_source, char* fragment_source)
{
    ShaderProgramm programm;

    programm.programm_id = GL(glCreateProgram());
    programm.vertex_shader_id = GL(glCreateShader(GL_VERTEX_SHADER));
    programm.fragment_shader_id = GL(glCreateShader(GL_FRAGMENT_SHADER));
    

    // int vertex_src_length = strlen(vertex_source);
    // int fragment_src_length = strlen(fragment_source);
    GL(glShaderSource(programm.vertex_shader_id,1,&vertex_source,(void*)0));
    GL(glShaderSource(programm.fragment_shader_id,1,&fragment_source,(void*)0));

    GL(glCompileShader(programm.vertex_shader_id));
    check_compile_status(programm.vertex_shader_id);
    GL(glCompileShader(programm.fragment_shader_id));
    check_compile_status(programm.fragment_shader_id);
    GL(glAttachShader(programm.programm_id,programm.fragment_shader_id));
    GL(glAttachShader(programm.programm_id,programm.vertex_shader_id));

    GL(glLinkProgram(programm.programm_id));
    GL(glValidateProgram(programm.programm_id));

    return programm;
}

check_compile_status(int shader_id)
{
    GLint res = GL_FALSE;
	int info_log_size;


    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &res);
	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_size);

    

	if (info_log_size > 0)
    {
        char* error_message = malloc(info_log_size + 1);

		glGetShaderInfoLog(shader_id, info_log_size, (void*) 0, error_message);
		printf("%s\n", error_message);
	}
}