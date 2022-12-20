/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_stl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjaecho <minjaecho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:09:05 by minjaecho         #+#    #+#             */
/*   Updated: 2022/10/09 20:34:00 by minjaecho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_STL_H
# define C_STL_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_swap(int *a, int *b);
void	print_arr(int arr[], int c);
void	same_permutation(int arr[], int n, int depth, int **perms);

#endif