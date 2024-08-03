/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 16:04:26 by mmoser        #+#    #+#                 */
/*   Updated: 2023/11/29 10:47:09 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define RESET -1

typedef struct argument
{
	char	*str;
	char	num_prefix[3];
	char	fspec;
	int		width;
	bool	hash;
	bool	zero;
	bool	dash;
	bool	space;
	bool	sign;
	bool	dot;
	int		prec;
}	t_arg;

// output
void	ft_putstr(const char *s);
void	write_formatted_c(t_arg	*fdetails);
void	write_formatted_str(t_arg *fdetails);
void	write_formatted_n(t_arg *fdetails);
void	write_formatted_arg(t_arg *fdetails);

// numconv.c
size_t	get_str_len(long n, int base_len);
void	fill_string(char *result, unsigned long n, size_t strl, char fspec);
void	fill_num_prefix(t_arg *fdetails, long n);
char	*ft_ntoa_base(t_arg *fdetails, unsigned long n);

// flags.c
void	solve_flag_conflicts(t_arg *fdetails);
void	parse_flags(const char **s, t_arg *fdetails);
int		get_width(const char **s);
int		get_prec(const char **s);
void	fill_members(const char **s, t_arg *fdetails);

// printf.c
int		unvalid_fspec(const char *s, int prev_flen);
int		ft_printf(const char *s, ...);
int		ft_printf_fd(int fd, const char *s, ...);
int		ft_putarg(const char *s, va_list *args, int prev_flen);
void	arg_to_str(t_arg *fdetails, va_list *args);

// write_buffer.c
int		ft_buffered_putchar(const char c, int amount);
void	set_fd(int fd);

#endif
