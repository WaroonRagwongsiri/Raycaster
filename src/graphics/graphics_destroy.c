#include "../../includes/cub3d.h"

void	graphics_destroy(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < TEX_COUNT)
	{
		if (game->texture[i])
		{
			free(game->texture[i]->pixels);
			free(game->texture[i]);
			game->texture[i] = NULL;
		}
		i++;
	}
	if (game->shader_program)
		glDeleteProgram(game->shader_program);
	if (game->vbo)
		glDeleteBuffers(1, &game->vbo);
	if (game->vao)
		glDeleteVertexArrays(1, &game->vao);
	if (game->gl_texture)
		glDeleteTextures(1, &game->gl_texture);
	free(game->framebuffer);
	game->framebuffer = NULL;
	if (game->window)
	{
		glfwDestroyWindow(game->window);
		game->window = NULL;
		glfwTerminate();
	}
}
