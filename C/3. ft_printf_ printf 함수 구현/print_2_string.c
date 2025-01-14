/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:08:34 by seobaek           #+#    #+#             */
/*   Updated: 2020/08/10 20:05:14 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_tag *tag, char *box, char *s)
{
	if (tag->prcs == DISABLED ||
			(tag->prcs != 0 && tag->prcs >= (int)ft_strlen(s)))
		return (s);
	box = malloc(sizeof(char) * (tag->prcs + 1));
	if (box == NULL)
		return (NULL);
	ft_strncpy(box, s, tag->prcs);
	box[tag->prcs] = '\0';
	return (box);
}

static char	*process_width(t_tag *tag, char *box, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (tag->width <= s_len)
		return (s);
	box = fill_box(tag->width, tag->padding);
	if (box == NULL)
		return (NULL);
	if (tag->left_aligned == ENABLED)
		ft_strncpy(box, s, s_len);
	else
		ft_strncpy(&box[tag->width - s_len], s, s_len);
	return (box);
}

int			print_string(t_tag *tag, char *res)
{
	t_box	*box;
	int		flag;

	flag = DISABLED;
	if (res == NULL)
	{
		res = ft_strndup("(null)", 6);
		flag = ENABLED;
	}
	box = prepare_box();
	if ((res = process_precision(tag, box->prcs, res)) == NULL
		|| (res = process_width(tag, box->width, res)) == NULL)
	{
		free_box(box);
		return (ERROR);
	}
	tag->nbyte += ft_putstr_n(res, ft_strlen(res));
	free_box(box);
	if (flag == ENABLED)
		free(res);
	return (0);
}
