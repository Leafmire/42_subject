/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:49:42 by gson              #+#    #+#             */
/*   Updated: 2021/08/24 00:59:14 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
typedef struct s_specs
{
	int	zero;
	int	minus;
	int	width;
	int	precision;
}				t_specs;
void	ft_putchar(char c, int *cc);
void	ft_putstr(char *s, int *cc);
void	ft_putnbr(int n, int *cc);
void	ft_putnbr_unsigned(unsigned int n, int *cc);
void	ft_putnbr_hex(unsigned long n, char format, int *cc);
int		ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
void	ft_initspecs(t_specs *specs);
void	create_space_left(t_specs *specs, int len, int *cc);
void	create_space_left_i(t_specs *specs, int len, int *cc, int n);
void	create_space_left_ui(t_specs *specs, int len, int *cc);
void	create_space_right(t_specs *specs, int len, int *cc);
void	manage_format_char(va_list ap, t_specs *specs, char format, int *cc);
void	manage_format_num(va_list ap, t_specs *specs, int *cc);
void	manage_format_u(va_list ap, t_specs *specs, int *cc);
void	manage_format_hex(va_list ap, t_specs *specs, char format, int *cc);
int		is_digit(char a);
char	*ft_strdup(const char *str);
#endif
