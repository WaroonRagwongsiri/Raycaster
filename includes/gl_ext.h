#ifndef GL_EXT_H
# define GL_EXT_H

# include <GL/gl.h>
# include <GL/glext.h>
# include <stdbool.h>

extern PFNGLGENVERTEXARRAYSPROC		glGenVertexArrays;
extern PFNGLBINDVERTEXARRAYPROC		glBindVertexArray;
extern PFNGLDELETEVERTEXARRAYSPROC		glDeleteVertexArrays;
extern PFNGLGENBUFFERSPROC				glGenBuffers;
extern PFNGLBINDBUFFERPROC				glBindBuffer;
extern PFNGLBUFFERDATAPROC				glBufferData;
extern PFNGLDELETEBUFFERSPROC			glDeleteBuffers;
extern PFNGLVERTEXATTRIBPOINTERPROC	glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray;
extern PFNGLCREATESHADERPROC			glCreateShader;
extern PFNGLSHADERSOURCEPROC			glShaderSource;
extern PFNGLCOMPILESHADERPROC			glCompileShader;
extern PFNGLGETSHADERIVPROC			glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC		glGetShaderInfoLog;
extern PFNGLDELETESHADERPROC			glDeleteShader;
extern PFNGLCREATEPROGRAMPROC			glCreateProgram;
extern PFNGLATTACHSHADERPROC			glAttachShader;
extern PFNGLLINKPROGRAMPROC			glLinkProgram;
extern PFNGLGETPROGRAMIVPROC			glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC		glGetProgramInfoLog;
extern PFNGLUSEPROGRAMPROC				glUseProgram;
extern PFNGLDELETEPROGRAMPROC			glDeleteProgram;
extern PFNGLGETUNIFORMLOCATIONPROC		glGetUniformLocation;
extern PFNGLUNIFORM1IPROC				glUniform1i;

bool	gl_load_extensions(void);

#endif
