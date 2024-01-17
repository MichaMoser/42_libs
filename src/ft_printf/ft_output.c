/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_output.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 16:04:13 by mmoser        #+#    #+#                 */
/*   Updated: 2023/11/23 16:04:15 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_buffered_putchar(s[i], 1);
		i++;
	}
}

void	write_formatted_c(t_arg	*fdetails)
{
	if (fdetails->dash == false && fdetails->width > 1)
		ft_buffered_putchar(' ', fdetails->width - 1);
	ft_buffered_putchar(fdetails->str[0], 1);
	if (fdetails->dash == true && fdetails->width > 1)
		ft_buffered_putchar(' ', fdetails->width - 1);
}

void	write_formatted_str(t_arg *fdetails)
{
	int	strlen;
	int	i;

	strlen = (int) ft_strlen(fdetails->str);
	if (fdetails->dot == true && fdetails->prec < strlen)
		strlen = fdetails->prec;
	if (fdetails->dash == false && fdetails->width > strlen)
		ft_buffered_putchar(' ', fdetails->width - strlen);
	i = 0;
	while (strlen > i)
	{
		ft_buffered_putchar(fdetails->str[i], 1);
		i++;
	}
	if (fdetails->dash == true && fdetails->width > strlen)
		ft_buffered_putchar(' ', fdetails->width - strlen);
}

void	write_formatted_n(t_arg *fdetails)
{
	int	zeros;
	int	diglen;
	int	numlen;

	zeros = 0;
	diglen = ft_strlen(fdetails->str);
	numlen = diglen + ft_strlen(fdetails->num_prefix);
	if (fdetails->dot == true && fdetails->prec > diglen)
		zeros = fdetails->prec - diglen;
	if (fdetails->zero == true && fdetails->width > numlen + zeros)
		zeros = fdetails->width - numlen;
	numlen += zeros;
	if (fdetails->dash == false && fdetails->width > numlen)
		ft_buffered_putchar(' ', fdetails->width - numlen);
	ft_putstr(fdetails->num_prefix);
	if (zeros > 0)
		ft_buffered_putchar('0', zeros);
	ft_putstr(fdetails->str);
	if (fdetails->dash == true && fdetails->width > numlen)
		ft_buffered_putchar(' ', fdetails->width - numlen);
}

void	write_formatted_arg(t_arg *fdetails)
{
	if (fdetails->fspec == 's')
		write_formatted_str(fdetails);
	else if (fdetails->fspec == 'c')
		write_formatted_c(fdetails);
	else
		write_formatted_n(fdetails);
}
