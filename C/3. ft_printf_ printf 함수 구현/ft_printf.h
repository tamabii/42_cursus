/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:44:19 by seobaek           #+#    #+#             */
/*   Updated: 2020/08/10 20:59:40 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>
# include "libft/libft.h"

# define FLAG "-+ 0#"
# define LEN_MODIFIER "hl"
# define CONVERSION "cspdiuxXn%"

# define DIGIT "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# define H_ENABLED 2
# define H_DISABLED 0
# define ENABLED 1
# define DISABLED -1
# define ERROR -1
# define UNDEFINED_BEHAVIOR -1
# define EQUAL 0
# define SKIP 0
# define FALSE 0

typedef struct	s_tag
{
	int		nbyte;
	int		left_aligned;
	int		width;
	int		prcs;
	int		zero_fill;
	int		plus;
	int		space;
	int		hexa;
	int		len_mod;
	char	padding;
	char	sign;
}				t_tag;

typedef struct	s_box
{
	char *prcs;
	char *width;
}				t_box;

/*
*****************************   MAIN FUNCTION   *******************************
*/

int				ft_printf(const char *format, ...);
int				parse_symbols(char **form, va_list ap, t_tag *tag);

/*
*****************************   WRITE ON CONDITION   ***********************
*/

int				pre_process_char(va_list ap, t_tag *tag);
int				pre_process_string(va_list ap, t_tag *tag);
int				pre_process_int(va_list ap, t_tag *tag);
int				pre_process_unsigned_int(va_list ap, t_tag *tag);
int				pre_process_hexa(va_list ap, t_tag *tag, char *base, char conv);

int				print_char(t_tag *tag, char c);
int				print_string(t_tag *tag, char *res);
int				print_int(t_tag *tag, char *res);
int				print_unsigned_int(t_tag *tag, char *res);
int				print_hexa(t_tag *tag, char *res, char conv);
int				print_pointer(va_list ap, t_tag *tag);
int				print_percent(t_tag *tag);
int				store_nbyte(va_list ap, t_tag *tag);

/*
*****************************   MANAGE BOX   ***********************************
*/

t_box			*prepare_box(void);
char			*fill_box(int size, char tag_padding);
void			free_box(t_box *box);

/*
*****************************   MANAGE SIGN   **********************************
*/

char			*prepare_sign(t_tag *tag, char *s);
char			*process_sign(t_tag *tag, char *box, int s_len);

int				is_set(char c, char *set);
char			*ft_uitoa(unsigned int n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_atouni(wchar_t w);
char			*ft_itoa(int n);
char			*ft_itoa_base(unsigned int n, const char *base);
char			*ft_lltoa_base(long long n, const char *base);
char			*ft_lltoa(long long n);
int				ft_putchar_n(char c, int n);
int				ft_putstr_n(char *s, int n);
int				get_atouni_width(wchar_t wc);

#endif
