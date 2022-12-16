/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:30:59 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/14 15:31:09 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	subway(va_list ap, const char *format)
{
	if (*format == 'c')
		return (function_c(ap));
	else if (*format == 's')
		return (function_s(ap));
	else if (*format == 'p')
		return (function_p(ap));
	else if (*format == 'd')
		return (function_id(ap));
	else if (*format == 'i')
		return (function_id(ap));
	else if (*format == 'u')
		return (function_u(ap));
	else if (*format == 'x')
		return (function_x(ap));
	else if (*format == 'X')
		return (function_xx(ap));
	else if (*format == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		temp;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			temp = subway(ap, (format + 1));
			format += 2;
		}
		else
		{
			temp = write(1, format, 1);
			format++;
		}
		if (temp < 0)
			return (-1);
		ret += temp;
	}
	va_end(ap);
	return (ret);
}
