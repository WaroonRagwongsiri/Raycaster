#include "../../includes/cub3d.h"

static float const	g_quad[] = {
	-1.0f, -1.0f, 0.0f, 1.0f,
	1.0f, -1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 0.0f,
	-1.0f, 1.0f, 0.0f, 0.0f,
};

static bool	create_window(t_game *game)
{
	if (!glfwInit())
		return (false);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	game->window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
	if (!game->window)
	{
		glfwTerminate();
		return (false);
	}
	glfwMakeContextCurrent(game->window);
	glfwSwapInterval(1);
	return (true);
}

static bool	create_screen_texture(t_game *game)
{
	game->framebuffer = malloc(sizeof(uint32_t) * WIDTH * HEIGHT);
	if (!game->framebuffer)
		return (false);
	glGenTextures(1, &game->gl_texture);
	glBindTexture(GL_TEXTURE_2D, game->gl_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT, 0,
		GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, NULL);
	return (true);
}

static void	create_quad(t_game *game)
{
	glGenVertexArrays(1, &game->vao);
	glGenBuffers(1, &game->vbo);
	glBindVertexArray(game->vao);
	glBindBuffer(GL_ARRAY_BUFFER, game->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_quad), g_quad, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
		4 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
		4 * sizeof(float), (void *)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

bool	graphics_init(t_game *game)
{
	int	fb_width;
	int	fb_height;

	if (!texture_load_all(game))
		return (false);
	if (!create_window(game))
		return (false);
	if (!gl_load_extensions())
		return (false);
	if (!create_screen_texture(game))
		return (false);
	create_quad(game);
	if (!build_shader_program(game))
		return (false);
	glfwGetFramebufferSize(game->window, &fb_width, &fb_height);
	glViewport(0, 0, fb_width, fb_height);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	game->last_frame_time = glfwGetTime();
	return (true);
}
