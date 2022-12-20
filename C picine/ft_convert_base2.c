/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:01:51 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/20 16:02:48 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	base_validation(char *base)
{
	int	left;
	int	right;

	if (!base[0] || !base[1])
		return (0);
	left = 0;
	while (base[left])
	{	
		if (base[left] == '+' || base[left] == '-')
			return (0);
		else if ((base[left] >= 9 && base[left] <= 13) || base[left] == 32)
			return (0);
		right = left + 1;
		while (base[right])
		{
			if (base[left] == base[right])
				return (0);
			right++;
		}
		left++;
	}
	return (left);
}

int	sign_decision(char *str, int *point)
{
	int	sign;
	int	count;

	sign = 1;
	count = 0;
	*point = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
		count++;
		*point = count;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
		count++;
		*point = count;
	}
	return (sign);
}

int	str_base(char *str, char *base, int point, int jinsoo)
{
	int	str_index;
	int	base_index;
	int	answer;

	answer = 0;
	str_index = point;
	while (str[str_index])
	{
		base_index = 0;
		while (base[base_index])
		{
			if (str[str_index] == base[base_index])
			{
				answer = answer * jinsoo + base_index;
				break ;
			}
			base_index++;
		}
		if (base[base_index] == 0)
			break ;
		str_index++;
	}
	return (answer);
}

int	ato2(char *str, char *base)
{
	int	jinsoo;	
	int	sign;
	int	answer;
	int	point;

	jinsoo = base_validation(base);
	sign = sign_decision(str, &point);
	answer = sign * str_base(str, base, point, jinsoo);
	return (answer);
}
