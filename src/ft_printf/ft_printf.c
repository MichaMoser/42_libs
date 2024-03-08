/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 16:04:17 by mmoser        #+#    #+#                 */
/*   Updated: 2023/11/30 12:05:21 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BUFFER_SIZE 1024

int	ft_buffered_putchar(const char c, int amount)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	count;
	static size_t	i;
	size_t			temp;

	if (amount == RESET)
	{
		count += write(1, buffer, i);
		ft_bzero(buffer, i);
		i = 0;
		return (temp = count, count = 0, temp);
	}
	while (amount > 0)
	{
		if (i == BUFFER_SIZE - 1)
		{
			count += write(1, buffer, i);
			ft_bzero(buffer, i);
			i = 0;
		}
		buffer[i++] = c;
		amount--;
	}
	return (count);
}

void	arg_to_str(t_arg *fdetails, va_list *args)
{
	const char	*str;
	long		n;

	if (fdetails->fspec == 's')
	{
		str = va_arg(*args, const char *);
		if (!str)
			fdetails->str = ft_strdup("(null)");
		else
			fdetails->str = ft_strdup(str);
	}
	else if (fdetails->fspec == 'c')
		fdetails->str = ft_strdup((char []){(char)va_arg(*args, int), '\0'});
	else
	{
		if (fdetails->fspec == 'i' || fdetails->fspec == 'd')
			n = (long)va_arg(*args, int);
		else if (fdetails->fspec == 'p')
			n = (long)va_arg(*args, unsigned long);
		else
			n = (long)va_arg(*args, unsigned int);
		fill_num_prefix(fdetails, n);
		fdetails->str = ft_ntoa_base(fdetails, n);
	}
}

int	unvalid_fspec(const char *s, int prev_flen)
{
	if (prev_flen != 0 && !*s)
		return (-1);
	else
	{
		ft_buffered_putchar('%', true);
		return (0);
	}
}

int	ft_display_arg(const char *s, va_list *args, int prev_flen)
{
	t_arg		fdetails;
	const char	*s_og;

	s_og = s;
	if (s[1] == '%')
	{
		ft_buffered_putchar('%', 1);
		return (1);
	}
	ft_bzero(&fdetails, sizeof(fdetails));
	fill_members(&s, &fdetails);
	fdetails.fspec = *s;
	if (*s && ft_strchr("cspdiuxX", fdetails.fspec))
	{
		arg_to_str(&fdetails, args);
		if (fdetails.str == NULL)
			return (-1);
		solve_flag_conflicts(&fdetails);
		write_formatted_arg(&fdetails);
		free(fdetails.str);
		return (s - s_og);
	}
	else
		return (unvalid_fspec(s, prev_flen));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		flen;

	flen = 1;
	va_start(args, s);
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s != '%')
			ft_buffered_putchar(*s, true);
		else
		{
			flen = ft_display_arg(s, &args, flen);
			if (flen < 0)
			{
				va_end(args);
				return (ft_buffered_putchar(0, RESET), -1);
			}
			s += flen;
		}
		s++;
	}
	va_end(args);
	return (ft_buffered_putchar(0, RESET));
}
