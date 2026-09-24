#include "../../includes/cub3d.h"

static char const	*g_vertex_src =
	"#version 330 core\n"
	"layout (location = 0) in vec2 in_pos;\n"
	"layout (location = 1) in vec2 in_uv;\n"
	"out vec2 v_uv;\n"
	"void main()\n"
	"{\n"
	"    v_uv = in_uv;\n"
	"    gl_Position = vec4(in_pos, 0.0, 1.0);\n"
	"}\n";

static char const	*g_fragment_src =
	"#version 330 core\n"
	"in vec2 v_uv;\n"
	"out vec4 frag_color;\n"
	"uniform sampler2D screen_texture;\n"
	"void main()\n"
	"{\n"
	"    frag_color = texture(screen_texture, v_uv);\n"
	"}\n";

static GLuint	compile_stage(GLenum stage, char const *src)
{
	GLuint	shader;
	GLint	success;
	char	log[512];

	shader = glCreateShader(stage);
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, sizeof(log), NULL, log);
		ft_putendl_fd(log, STDERR_FILENO);
		glDeleteShader(shader);
		return (0);
	}
	return (shader);
}

static GLuint	link_program(GLuint vertex, GLuint fragment)
{
	GLuint	program;
	GLint	success;
	char	log[512];

	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, sizeof(log), NULL, log);
		ft_putendl_fd(log, STDERR_FILENO);
		glDeleteProgram(program);
		return (0);
	}
	return (program);
}

bool	build_shader_program(t_game *game)
{
	GLuint	vertex;
	GLuint	fragment;

	vertex = compile_stage(GL_VERTEX_SHADER, g_vertex_src);
	if (!vertex)
		return (false);
	fragment = compile_stage(GL_FRAGMENT_SHADER, g_fragment_src);
	if (!fragment)
		return (glDeleteShader(vertex), false);
	game->shader_program = link_program(vertex, fragment);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (!game->shader_program)
		return (false);
	game->sampler_uniform = glGetUniformLocation(game->shader_program,
			"screen_texture");
	return (true);
}
