/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_fail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:45:48 by erde-la-          #+#    #+#             */
/*   Updated: 2024/11/25 10:36:22 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Wrong interpretation of requirements.
Leaving it here in case it is needed in the future
Has a small issue.
Test it passing *s1 = " Hola" and *set = "Ho"
-> result is "ola" but should be "Hola"
*/
#include "libft.h"

size_t	ft_check_coincidence(char const *s1, char const *set, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == set[j])
		{
			j++;
			if (set[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

size_t	ft_count_end_coinc(char const *s1, char const *set)
{
	size_t	toggler;
	size_t	set_len;
	size_t	s1_len;
	size_t	end_coincidence_counter;
	char	*ptr_s1;

	ptr_s1 = (char *)s1;
	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	ptr_s1 += (s1_len - set_len);
	end_coincidence_counter = 0;
	toggler = 1;
	while (toggler == 1)
	{
		if (ft_check_coincidence(ptr_s1, set, set_len))
		{
			ptr_s1 -= set_len;
			end_coincidence_counter++;
		}
		else
			toggler = 0;
	}
	return (end_coincidence_counter);
}

char	*ft_get_starting_ptr(char const *s1, char const *set, size_t set_len)
{
	size_t	toggler;
	char	*ptr_s1;

	ptr_s1 = (char *)s1;
	toggler = 1;
	while (toggler == 1)
	{
		if (ft_check_coincidence(ptr_s1, set, set_len))
			ptr_s1 += set_len;
		else
			toggler = 0;
	}
	return (ptr_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	end_coinc_count;
	char	*ptr_s1;
	char	*new_str;
	size_t	stop_value;

	ptr_s1 = (char *)s1;
	set_len = ft_strlen(set);
	end_coinc_count = ft_count_end_coinc(ptr_s1, set);
	ptr_s1 = ft_get_starting_ptr(ptr_s1, set, set_len);
	stop_value = ft_strlen(ptr_s1) - (set_len * end_coinc_count);
	new_str = (char *)ft_calloc(stop_value, sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, ptr_s1, stop_value);
	return (new_str);
}
