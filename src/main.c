/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	print_error(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (EXIT_FAILURE);
}

static void	how_to_play(void)
{
	ft_putendl_fd("Controls", STDOUT_FILENO);
	ft_putendl_fd("W / S : walk forward / backward", STDOUT_FILENO);
	ft_putendl_fd("A / D : strafe left / right", STDOUT_FILENO);
	ft_putendl_fd("<- / ->, Q / E : turn the camera", STDOUT_FILENO);
	ft_putendl_fd("ESC : quit", STDOUT_FILENO);
}

static void	game_loop(t_game *game)
{
	double	now;

	while (!glfwWindowShouldClose(game->window))
	{
		now = glfwGetTime();
		game->delta_time = now - game->last_frame_time;
		game->last_frame_time = now;
		render_loop(game);
		graphics_present(game);
		glfwPollEvents();
	}
}

static int	run_game(t_game *game)
{
	if (!player_init(game))
		return (print_error("Invalid player configuration"));
	if (!graphics_init(game))
	{
		graphics_destroy(game);
		return (print_error("Graphics initialization failed"));
	}
	how_to_play();
	game_loop(game);
	graphics_destroy(game);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		status;

	if (argc != 2)
		return (print_error("Usage: ./cub3D <map.cub>"));
	if (WIDTH < MIN_WIDTH || HEIGHT < MIN_HEIGHT)
		return (print_error("WIDTH and HEIGHT are below the minimum"));
	ft_bzero(&game, sizeof(game));
	if (!parse_scene(argv[1], &game.scene))
	{
		ft_safe_calloc(0, 0, true);
		return (EXIT_FAILURE);
	}
	status = run_game(&game);
	ft_safe_calloc(0, 0, true);
	return (status);
}
