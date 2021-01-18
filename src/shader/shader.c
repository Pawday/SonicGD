#include "shader.h"
#include <stdlib.h>
#include <stdio.h>
#include <glew.h>
#include <gl_error_wrapper.h>
#include <window.h>


static void check_compile_status(int shader_id);

ShaderProgramm create_shader_programm(char* vertex_source, char* fragment_source)
{
    ShaderProgramm programm;

    programm.programm_id = GL(glCreateProgram());
    programm.vertex_shader_id = GL(glCreateShader(GL_VERTEX_SHADER));
    programm.fragment_shader_id = GL(glCreateShader(GL_FRAGMENT_SHADER));
    
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


void update_ratio_uniform(int programm_id,int uniform_location)
{
    int width;
    int heigth;
    sgd_window_get_size(&width,&heigth);

    GL(glUseProgram(programm_id));
    float win_rat = (float) width / heigth;
    GL(glUniform1f(uniform_location,win_rat));
}

void check_compile_status(int shader_id)
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