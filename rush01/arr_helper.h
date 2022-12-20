/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjaecho <minjaecho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:09:05 by minjaecho         #+#    #+#             */
/*   Updated: 2022/10/09 20:36:50 by minjaecho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_HELPER_H
# define ARR_HELPER_H
# include <stdlib.h>

int		checker(int i0, int i2, int target);
void	get_index_arrupdate(int arr[], int s_i, int i_i, int i_j);
int		*get_index(int ind);
int		check_str(char *str, int *arr);

#endif