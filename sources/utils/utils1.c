/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:19:39 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/01 15:33:28 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

bool	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' 
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}


//Removes all leading whitespaces
char *trim_elements(char *str, char **chars)
{
    char 	*substring;
    char 	*new;
    int 	i;

	i = 0;
    while (chars[i])
    {
        substring = ft_strstr(str, chars[i]);
        if (substring)
        {
            new = ft_substr(substring, 0, ft_strlen(substring));
            return (new);
        }
        i++;
    }
    return (str);
}

//cleans the string that will be stored in the array
char *cleaner(char *str)
{
	int		i;
	int		j;
	char	*new;
	
	if (!str && !*str)
		return (NULL);
	i = 0;
	while(ft_isspace(str[i]))
		i++;
	j = ft_strlen(str) - 1;
	while(ft_isspace(str[j]))
		j--;
	if (str[j] == '\n')
		j--;
	new = ft_substr(str, i, j - i + 1);
	return (new);
}

void order_check(char *str)
{
    if (game()->map->arr[0] != NULL) {
        if ((game()->map->no == NULL || game()->map->no[0] == '\0') &&
            (game()->map->so == NULL || game()->map->so[0] == '\0') &&
            (game()->map->we == NULL || game()->map->we[0] == '\0') &&
            (game()->map->ea == NULL || game()->map->ea[0] == '\0') &&
            (game()->map->f == NULL || game()->map->f[0] == '\0') &&
            (game()->map->c == NULL || game()->map->c[0] == '\0')) {
            exit_error(MAP_FIRST, str);
        }
    }
	return ;
}