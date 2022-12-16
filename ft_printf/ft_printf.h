/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:33:03 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/09 16:44:42 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		subway(va_list ap, const char *format);
int		function_c(va_list ap);
int		function_s(va_list ap);
int		function_p(va_list ap);
int		function_id(va_list ap);
int		function_u(va_list ap);
int		function_x(va_list ap);
int		function_xx(va_list ap);

#endif
