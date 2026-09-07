/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksejmirosnicenko <aleksejmirosnicenk    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:34:25 by aleksejmiro       #+#    #+#             */
/*   Updated: 2026/09/04 15:37:26 by aleksejmiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int	fd = open("text.txt", O_RDONLY);
	char *line;

	if(fd < 0){
		printf("ERROR");
		return (1);
	}
	
	line = get_next_line(fd);

	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}