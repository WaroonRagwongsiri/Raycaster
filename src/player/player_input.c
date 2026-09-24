/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroon <waroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:13:48 by waroon            #+#    #+#             */
/*   Updated: 2026/09/24 12:13:50 by waroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	key_down(GLFWwindow *window, int key)
{
	return (glfwGetKey(window, key) == GLFW_PRESS);
}

static void	move_forward(t_game *game, double speed)
{
	player_try_move(game, game->player.dir_x * speed,
		game->player.dir_y * speed);
}

static void	move_sideways(t_game *game, double speed)
{
	player_try_move(game, -game->player.dir_y * speed,
		game->player.dir_x * speed);
}

void	player_input(t_game *game)
{
	double	move;
	double	rotation;

	move = game->delta_time * MOVE_SPEED;
	rotation = game->delta_time * ROT_SPEED;
	if (key_down(game->window, GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(game->window, GLFW_TRUE);
	if (key_down(game->window, GLFW_KEY_W))
		move_forward(game, move);
	if (key_down(game->window, GLFW_KEY_S))
		move_forward(game, -move);
	if (key_down(game->window, GLFW_KEY_D))
		move_sideways(game, move);
	if (key_down(game->window, GLFW_KEY_A))
		move_sideways(game, -move);
	if (key_down(game->window, GLFW_KEY_RIGHT))
		player_rotate(game, rotation);
	if (key_down(game->window, GLFW_KEY_LEFT))
		player_rotate(game, -rotation);
	if (key_down(game->window, GLFW_KEY_E))
		player_rotate(game, rotation);
	if (key_down(game->window, GLFW_KEY_Q))
		player_rotate(game, -rotation);
}
