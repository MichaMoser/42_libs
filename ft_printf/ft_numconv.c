/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numconv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 16:04:09 by mmoser        #+#    #+#                 */
/*   Updated: 2023/11/29 10:45:58 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_str_len(long n, int base_len)
{
	size_t	str_len;

	str_len = 1;
	while (n / base_len != 0 && str_len++)
		n /= base_len;
	return (str_len);
}

void	fill_num_prefix(t_arg *fdetails, long n)
{
	if (n != 0 && fdetails->fspec == 'p')
	{
		fdetails->num_prefix[0] = '0';
		fdetails->num_prefix[1] = 'x';
	}
	else if (n > 0 && (fdetails->fspec == 'x' && fdetails->hash == true))
	{
		fdetails->num_prefix[0] = '0';
		fdetails->num_prefix[1] = 'x';
	}
	else if (n > 0 && fdetails->fspec == 'X' && fdetails->hash == true)
	{
		fdetails->num_prefix[0] = '0';
		fdetails->num_prefix[1] = 'X';
	}
	else if (n < 0)
		fdetails->num_prefix[0] = '-';
	else if (n >= 0 && fdetails->space == true)
		fdetails->num_prefix[0] = ' ';
	else if (n >= 0 && fdetails->sign == true)
		fdetails->num_prefix[0] = '+';
}

void	fill_string(char *result, unsigned long n, size_t strl, char fspec)
{
	char	*base;
	size_t	base_len;

	base_len = 10;
	if (fspec == 'X' || fspec == 'x' || fspec == 'p')
		base_len = 16;
	if (fspec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n / base_len == 0)
	{
		result[strl - 1] = base[n % base_len];
		return ;
	}
	fill_string(result, n / base_len, strl - 1, fspec);
	result[strl - 1] = base[n % base_len];
}

char	*ft_ntoa_base(t_arg *fdetails, unsigned long n)
{
	char			*result;
	size_t			str_len;
	int				base_len;
	unsigned long	ntemp;

	str_len = 1;
	base_len = 10;
	if ((fdetails->fspec == 'i' || fdetails->fspec == 'd') && n > INT_MAX)
		n *= -1;
	if (fdetails->fspec == 'p' && n == 0)
		return (ft_strdup("(nil)"));
	if (fdetails->fspec == 'X' || fdetails->fspec == 'x'
		|| fdetails->fspec == 'p')
		base_len = 16;
	ntemp = n;
	while (ntemp / base_len != 0 && str_len++)
		ntemp /= base_len;
	result = malloc((str_len + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	fill_string(result, n, str_len, fdetails->fspec);
	result[str_len] = '\0';
	return (result);
}
