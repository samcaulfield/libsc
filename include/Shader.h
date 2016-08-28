/**
 * File: Shader.h
 * Author: Sam Caulfield
 * Date: 29.08.2016
 * Description: GLSL shader utility functions
 */

#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <GL/glew.h>

/**
 * Shader - Structure encapsulating the state of a GLSL shader.
 * Members:
 * - type: One of GL_COMPUTE_SHADER, GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
 *   GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER, GL_FRAGMENT_SHADER.
 * - id: The value used by OpenGL to identify this shader.
 * - source: The source code string of the shader. This can be deallocated if
 *   desired.
 */
struct Shader {
	GLenum type;
	GLuint id;
	char *source;
};

/**
 * shaderNew - Shader constructor.
 * Parameters:
 * - fileName: The name of the file containing the source code of the shader.
 * - type: The type of the shader. This is one of the types listed in the
 *   description of the Shader structure.
 * - log: If there is an error compiling the shader then log will be pointed to
 *   a heap-allocated string containing the GLSL compiler's error log.
 * Return value:
 * - On success a pointer to a new heap-allocated Shader structure is returned,
 *   with all its members assigned values as described in the description of the
 *   Shader structure. On failure a NULL-pointer is returned. If the failure was
 *   caused by an error compiling the shader then log will point to a
 *   heap-allocated string containing the GLSL compiler's error log. If log is
 *   NULL then the failure was due to an error either allocating or creating the
 *   shader.
 */
struct Shader *shaderNew(char *fileName, GLenum type, char **log);

/**
 * shaderFree - Shader destructor.
 * Parameters:
 * - shader: The shader to free. All of the shader's members that have not
 *   already been deallocated will be freed.
 */
void shaderFree(struct Shader *shader);

#endif

