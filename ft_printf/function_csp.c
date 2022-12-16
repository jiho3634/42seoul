/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:13:49 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/14 12:15:07 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	function_c(va_list ap)
{
	int		temp1;
	char	temp2;

	temp1 = va_arg(ap, int);
	temp2 = (char) temp1;
	return (write(1, &temp2, 1));
}

int	function_s(va_list ap)
{
	char	*temp;
	size_t	size;

	temp = va_arg(ap, char *);
	if (!temp)
		temp = "(null)";
	size = ft_strlen(temp);
	return (write(1, temp, size));
}

static int	recursive(size_t adrs, size_t size)
{
	char	temp;

	if (!size)
		return (0);
	temp = "0123456789abcdef" [adrs % 16];
	if (recursive (adrs / 16, size - 1) < 0)
		return (-1);
	return (write(1, &temp, 1));
}

int	function_p(va_list ap)
{
	void	*adr;
	size_t	adrs;
	size_t	size;

	adr = va_arg(ap, void *);
	adrs = (size_t) adr;
	if (!adrs)
		return (write(1, "0x0", 3));
	size = 0;
	while (adrs)
	{
		adrs /= 16;
		size++;
	}
	adrs = (size_t) adr;
	if (write(1, "0x", 2) < 0)
		return (-1);
	if (recursive(adrs, size) < 0)
		return (-1);
	return (size + 2);
}
