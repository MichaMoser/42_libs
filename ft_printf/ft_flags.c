/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 16:04:03 by mmoser        #+#    #+#                 */
/*   Updated: 2023/11/29 10:46:06 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_flag_conflicts(t_arg *fdetails)
{
	if (fdetails->prec < 0)
		fdetails->dot = false;
	if (fdetails->zero == true && fdetails->dash == true)
		fdetails->zero = false;
	if (fdetails->sign == true && fdetails->space == true)
		fdetails->space = false;
	if (fdetails->fspec != 'i' && fdetails->fspec != 'd')
	{
		fdetails->space = false;
		fdetails->sign = false;
	}
	if (fdetails->fspec != 'x' && fdetails->fspec != 'X')
		fdetails->hash = false;
	if (fdetails->fspec == 'c' || fdetails->fspec == 'p')
		fdetails->dot = false;
	if (fdetails->fspec == 'c' || fdetails->fspec == 'p'
		|| fdetails->fspec == 's')
		fdetails->zero = false;
	if (fdetails->dot == true
		&& (int) ft_strlen(fdetails->str) > fdetails->prec)
		fdetails->zero = false;
}

void	parse_flags(const char **s, t_arg *fdetails)
{
	char	c;

	while (!ft_strchr("cspdiuxX%", **s))
	{
		if (**s == '#' && fdetails->hash == false)
			fdetails->hash = true;
		else if (**s == '0' && fdetails->zero == false)
			fdetails->zero = true;
		else if (**s == '-' && fdetails->dash == false)
			fdetails->dash = true;
		else if (**s == '+' && fdetails->sign == false)
			fdetails->sign = true;
		else if (**s == ' ' && fdetails->space == false)
			fdetails->space = true;
		else
			break ;
		c = **s;
		while (**s == c)
			(*s)++;
	}
}

int	get_width(const char **s)
{
	int	width;

	while (**s == '0')
		(*s)++;
	width = ft_atoi(*s);
	*s += get_str_len((long)width, 10);
	return (width);
}

int	get_prec(const char **s)
{
	int	prec;

	while (**s == '0')
		(*s)++;
	prec = ft_atoi(*s);
	if (prec != 0)
		*s += get_str_len((long)prec, 10);
	return (prec);
}

void	fill_members(const char **s, t_arg *fdetails)
{
	(*s)++;
	parse_flags(s, fdetails);
	if (**s > '0' && **s <= '9')
		fdetails->width = get_width(s);
	if (**s == '.')
	{
		(*s)++;
		fdetails->dot = true;
		fdetails->prec = get_prec(s);
	}
}
