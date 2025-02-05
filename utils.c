/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:10:16 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/05 14:56:55 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	char			*s;
	unsigned char	ch;

	s = (char *)str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s[i] = ch;
		i++;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		str_len;
	char		*ptr;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	count_numbers(int n)
{
	int				count;
	unsigned int	num;

	num = n;
	count = 0;
	if (n < 0)
	{
		num = -n;
		count++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static char	*fill_ptr(int num, char *ptr)
{
	if (num == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	size_t			num_len;
	unsigned int	num;
	char			*ptr;

	num_len = count_numbers(n);
	ptr = malloc(sizeof(char) * (num_len + 1));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		num = -n;
		ptr[0] = '-';
	}
	else
		num = n;
	fill_ptr(num, ptr);
	if (num > 0)
		ptr[num_len] = '\0';
	while (num > 0)
	{
		ptr[--num_len] = (num % 10) + '0';
		num = num / 10;
	}
	return (ptr);
}
