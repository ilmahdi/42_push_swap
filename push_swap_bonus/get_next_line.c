/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:01:35 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/17 17:01:41 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	hol[2];
	char	hhol[10000];
	int		i;
	int		rt;

	i = 0;
	while (1)
	{
		rt = read(fd, hol, 1);
		if (rt <= 0)
			break ;
		hol[1] = '\0';
		hhol[i] = hol[0];
		i++;
		hhol[i] = '\0';
		if (hol[0] == '\n' || hol[0] == '\0')
			break ;
	}
	if (i == 0 || rt == -1)
		return (NULL);
	line = (char *)ft_calloc((size_t)(i + 1), sizeof(char));
	if (!line)
		return (NULL);
	return (ft_strlcpy(line, hhol, (ft_strlen(hhol)) + 1), line);
}
