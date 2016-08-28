/**
 * File: Shader.c
 * Author: Sam Caulfield
 * Date: 29.08.2016
 * Description: GLSL shader utility functions
 */

#include <stdlib.h>
#include "File.h"
#include "Shader.h"

struct Shader *shaderNew(char *fileName, GLenum type, char **log)
{
	struct Shader *shader = malloc(sizeof(*shader));
	if (!shader) {
		return NULL;
	}
	shader->type = type;
	shader->id = glCreateShader(type);
	if (!shader->id) {
		free(shader);
		return NULL;
	}
	shader->source = fileRead(fileName);
	if (!shader->source) {
		glDeleteShader(shader->id);
		free(shader);
		return NULL;
	}
	glShaderSource(shader->id, 1, (const GLchar **) &shader->source, NULL);
	glCompileShader(shader->id);
	GLint compileStatus;
	glGetShaderiv(shader->id, GL_COMPILE_STATUS, &compileStatus);
	if (!compileStatus) {
		GLint logLength;
		glGetShaderiv(shader->id, GL_INFO_LOG_LENGTH, &logLength);
		*log = malloc(logLength * sizeof(**log));
		if (!log) {
			glDeleteShader(shader->id);
			free(shader->source);
			free(shader);
			return NULL;
		}
		glGetShaderInfoLog(shader->id, logLength, NULL, *log);
	}
	return shader;
}

void shaderFree(struct Shader *shader)
{
	glDeleteShader(shader->id);
	if (shader->source) {
		free(shader->source);
	}
	free(shader);
}

