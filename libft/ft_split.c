/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:02 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/21 18:20:46 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	freearray(char **array, int wordnbr)
{
	int	i;

	i = 0;
	while (i < wordnbr)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static int	countwords(char const *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			n++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (n);
}

static char	*stringdup(char const *src, char c)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len] != c && src[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*findstring(char const *s, int *ptr_i_string, char c)
{
	int		i;
	char	*dest;

	i = *ptr_i_string;
	while (s[i] != '\0' && s[i] == c)
		i++;
	if (s[i] != '\0')
		dest = stringdup(s + i, c);
	while (s[i] != c && s[i] != '\0')
		i++;
	*ptr_i_string = i;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		wordsnbr;
	int		i_string;
	int		i_array;
	int		*ptr_i_string;

	if (s == 0)
		return (0);
	i_array = 0;
	i_string = 0;
	ptr_i_string = &i_string;
	wordsnbr = countwords(s, c);
	array = (char **)malloc(sizeof(char *) * (wordsnbr + 1));
	if (array == NULL)
		return (NULL);
	while (i_array < wordsnbr)
	{
		array[i_array] = findstring(s, ptr_i_string, c);
		if (array[i_array] == NULL)
			freearray(array, wordsnbr);
		i_array++;
	}
	array[i_array] = NULL;
	return (array);
}

/* if (array[i_array] == NULL)
{
	freearray(array, wordsnbr);
	return (NULL);
} */

/* int	main()
{
	char	*str;
	char	c;
	char	**array;
	int		i;
	int		words;

	str = "paris,rome";
	i = 0;
	c = ',';
	array = ft_split(str,c);
	words = 2;
	while (i <= words)
	{
		printf("%s\n",array[i]);
		i++;
	}
	freearray(array, words);
} */

/* int	countwords(char const *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			n++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (n);
}

void	freearray(char **array, int wordnbr)
{
	int	i;

	i = 0;
	while (i < wordnbr)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*stralloc(char const *src, char c)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[len] != c && src[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	arrayalloc(char **array, char const *string, char c)
{
	int		i;
	int		counter;
	int		wordsnb;

	counter = 0;
	i = 0;
	wordsnb = countwords(string, c);
	while (counter < wordsnb)
	{
		while (string[i] != '\0' && string[i] == c)
			i++;
		if (string[i] != '\0')
		{
			array[counter] = stralloc(string + i, c);
			if (array[counter] == NULL)
				freearray(array, wordsnb);
			counter++;
		}
		while (string[i] != '\0' && string[i] != c)
			i++;
	}
	array[counter] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (array == NULL)
		return (NULL);
	arrayalloc(array, s, c);
	return (array);
} */