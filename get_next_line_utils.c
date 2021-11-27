/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:28:07 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/18 21:34:55 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*str2;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	str2 = (char *)malloc((len + 1) * sizeof(*str));
	if (str2)
	{
		while (i < len)
		{
			str2[i] = str[i];
			i++;
		}
		str2[i] = 0;
		return (str2);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	slen1;
	size_t	slen2;
	size_t	i;

	i = 0;
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	sj = (char *)malloc((slen1 + slen2 + 1) * sizeof(*s1));
	if (sj)
	{
		while (i < slen1)
		{
			sj[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < slen2)
		{
			sj[slen1 + i] = s2[i];
			i++;
		}
	}
	sj[slen1 + slen2] = 0;
	return (sj);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen((char *)s);
	if (!s)
		return (0);
	subs = (char *)malloc((len + 1) * sizeof(char));
	if ((size_t)start > slen || subs == NULL)
		return (ft_strdup(""));
	while (i < len && (start + i) < slen)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[len] = 0;
	return (subs);
}
