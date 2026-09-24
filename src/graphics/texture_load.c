#include "../../includes/cub3d.h"
#include "stb_image.h"

static t_texture	*load_one(char *path)
{
	t_texture	*texture;
	int			width;
	int			height;
	int			channels;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->pixels = stbi_load(path, &width, &height, &channels,
			STBI_rgb_alpha);
	if (!texture->pixels)
		return (free(texture), NULL);
	texture->width = (uint32_t)width;
	texture->height = (uint32_t)height;
	texture->bytes_per_pixel = 4;
	return (texture);
}

bool	texture_load_all(t_game *game)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		game->texture[i] = load_one(game->scene.texture_path[i]);
		if (!game->texture[i])
			return (false);
		i++;
	}
	return (true);
}
