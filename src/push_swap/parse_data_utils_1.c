/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:37:47 by erde-la-          #+#    #+#             */
/*   Updated: 2025/01/13 12:53:15 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char	*ft_paste_word(const char *src)
{
	size_t	i;
	char	*dest;

	dest = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**fill_arr(int argc, char *args[], char ***arr)
{
	int		i;
	int		j;
	int		k;
	char	**temp_arr;

	i = 1;
	k = 0;
	while (i < argc)
	{
		temp_arr = ft_split(args[i], ' ');
		if (!temp_arr)
			return (ft_free_strs_arr(arr));
		j = 0;
		while (temp_arr[j])
		{
			(*arr)[k] = ft_paste_word(temp_arr[j]);
			j++;
			k++;
		}
		ft_free_strs_arr(&temp_arr);
		i++;
	}
	return (*arr);
}

int	allow_char(char *s)
{
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || *s == '-' || *s == '+'))
		{
			ft_puterror();
			return (0);
		}
		s++;
	}
	return (1);
}

//Case 1: double symbol
//Case 2: symbol at end of str
//Case 3: symbol between two numbers
int	check_symbols(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if ((s[i + 1] == '-' || s[i + 1] == '+'))
			{
				ft_puterror();
				return (0);
			}
			if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
			{
				ft_puterror();
				return (0);
			}
			if (i != 0 && (s[i - 1] >= '0' && s[i - 1] <= '9'))
			{
				ft_puterror();
				return (0);
			}
		}
	}
	return (1);
}

int	check_limits(char *str)
{
	long	int_min;
	long	int_max;
	long	result;

	int_min = -2147483648;
	int_max = 2147483647;
	result = ft_atol(str);
	if (result < int_min || result > int_max)
	{
		ft_puterror();
		return (0);
	}
	return (1);
}
