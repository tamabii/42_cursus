/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:44:23 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 15:04:16 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		fatal(char *message)
{
	char error_message[100];

	ft_strcpy(error_message, "[!!] Fatal Error ");
	ft_strncat(error_message, message, 83);
	perror(error_message);
	exit(EXIT_FAILURE);
}

void		scene_error(char *message)
{
	char error_message[100];

	ft_strcpy(error_message, "Scene Error: ");
	ft_strncat(error_message, message, 87);
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void		*ec_malloc(unsigned int size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		fatal("in malloc() on memory allocation");
	return (ptr);
}

void		usage(char *program_name)
{
	ft_printf("Usage: %s <scene.rt>\n", program_name);
	exit(EXIT_FAILURE);
}

#ifndef LINUX

int			mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	mlx_ptr = (int*)mlx_ptr;
	sizex = sizey;
	return (0);
}
#endif
