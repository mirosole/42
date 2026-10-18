/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmirosh <olmirosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:46:01 by olmirosh          #+#    #+#             */
/*   Updated: 2026/10/10 15:46:04 by olmirosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_back(int *array, int *temp,
	size_t left, size_t right)
{
	while (left <= right)
	{
		array[left] = temp[left];
		left++;
	}
}

static void	merge(int *array, int *temp,
	size_t left, size_t right)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	mid;

	mid = left + (right - left) / 2;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];
	copy_back(array, temp, left, right);
}

static void	merge_sort_recursive(int *array, int *temp,
	size_t left, size_t right)
{
	size_t	mid;

	if (left >= right)
		return ;
	mid = left + (right - left) / 2;
	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid + 1, right);
	merge(array, temp, left, right);
}

int	sort_array(int *array, size_t size)
{
	int	*temp;

	if (!array || size < 2)
		return (1);
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return (0);
	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
	return (1);
}
