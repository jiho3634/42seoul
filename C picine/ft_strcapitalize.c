/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:16:18 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/08 21:22:08 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	button;
	int	i;

	strlowcase(str);
	i = 0;
	button = 1;
	while (str[i])
	{
		if (button == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			button = 0;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
			button = 0;
		else if (str[i] >= '0' && str[i] <= '9')
			button = 0;
		else
			button = 1;
	i++;
	}
	return (str);
}
