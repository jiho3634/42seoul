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

#include <stdarg.h>
#include "ft_printf.h"

int	parse(const char *format, t_list *lst)
{
	while (*(format))
	{
		if (*format == '%')
		{
			lst = ft_lstnew(lst);
			fnt0(&format, lst);
		}
		format++;
	}
}

int	alloc(const char *format, va_list ap)
{
	
}

int	print(format, ap);
{

}

int	ft_printf(const char *format, ...)
{
	t_list	lst;
	va_list	ap;
	int		ret;

	va_start(ap, format);
	parse(format, lst);
	alloc(format, ap);
	print(format, ap);
	va_end(ap);
	return (ret);
}
