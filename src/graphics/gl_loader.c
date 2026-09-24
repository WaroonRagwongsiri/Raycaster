#include "../../includes/cub3d.h"

PFNGLGENVERTEXARRAYSPROC			glGenVertexArrays;
PFNGLBINDVERTEXARRAYPROC			glBindVertexArray;
PFNGLDELETEVERTEXARRAYSPROC		glDeleteVertexArrays;
PFNGLGENBUFFERSPROC				glGenBuffers;
PFNGLBINDBUFFERPROC				glBindBuffer;
PFNGLBUFFERDATAPROC				glBufferData;
PFNGLDELETEBUFFERSPROC				glDeleteBuffers;
PFNGLVERTEXATTRIBPOINTERPROC		glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray;
PFNGLCREATESHADERPROC				glCreateShader;
PFNGLSHADERSOURCEPROC				glShaderSource;
PFNGLCOMPILESHADERPROC				glCompileShader;
PFNGLGETSHADERIVPROC				glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog;
PFNGLDELETESHADERPROC				glDeleteShader;
PFNGLCREATEPROGRAMPROC				glCreateProgram;
PFNGLATTACHSHADERPROC				glAttachShader;
PFNGLLINKPROGRAMPROC				glLinkProgram;
PFNGLGETPROGRAMIVPROC				glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC			glGetProgramInfoLog;
PFNGLUSEPROGRAMPROC				glUseProgram;
PFNGLDELETEPROGRAMPROC				glDeleteProgram;
PFNGLGETUNIFORMLOCATIONPROC		glGetUniformLocation;
PFNGLUNIFORM1IPROC					glUniform1i;

static void	*load(char const *name)
{
	return ((void *)glfwGetProcAddress(name));
}

bool	gl_load_extensions(void)
{
	glGenVertexArrays = load("glGenVertexArrays");
	glBindVertexArray = load("glBindVertexArray");
	glDeleteVertexArrays = load("glDeleteVertexArrays");
	glGenBuffers = load("glGenBuffers");
	glBindBuffer = load("glBindBuffer");
	glBufferData = load("glBufferData");
	glDeleteBuffers = load("glDeleteBuffers");
	glVertexAttribPointer = load("glVertexAttribPointer");
	glEnableVertexAttribArray = load("glEnableVertexAttribArray");
	glCreateShader = load("glCreateShader");
	glShaderSource = load("glShaderSource");
	glCompileShader = load("glCompileShader");
	glGetShaderiv = load("glGetShaderiv");
	glGetShaderInfoLog = load("glGetShaderInfoLog");
	glDeleteShader = load("glDeleteShader");
	glCreateProgram = load("glCreateProgram");
	glAttachShader = load("glAttachShader");
	glLinkProgram = load("glLinkProgram");
	glGetProgramiv = load("glGetProgramiv");
	glGetProgramInfoLog = load("glGetProgramInfoLog");
	glUseProgram = load("glUseProgram");
	glDeleteProgram = load("glDeleteProgram");
	glGetUniformLocation = load("glGetUniformLocation");
	glUniform1i = load("glUniform1i");
	return (glGenVertexArrays && glBindVertexArray && glGenBuffers
		&& glBindBuffer && glBufferData && glVertexAttribPointer
		&& glEnableVertexAttribArray && glCreateShader && glShaderSource
		&& glCompileShader && glGetShaderiv && glGetShaderInfoLog
		&& glCreateProgram && glAttachShader && glLinkProgram
		&& glGetProgramiv && glGetProgramInfoLog && glUseProgram
		&& glGetUniformLocation && glUniform1i);
}
