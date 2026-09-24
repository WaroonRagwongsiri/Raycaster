#include "../../includes/cub3d.h"

void	graphics_present(t_game *game)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, game->gl_texture);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, WIDTH, HEIGHT,
		GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, game->framebuffer);
	glUseProgram(game->shader_program);
	glUniform1i(game->sampler_uniform, 0);
	glBindVertexArray(game->vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glfwSwapBuffers(game->window);
}
