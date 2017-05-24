/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 13:48:18 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/21 13:48:20 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_liber(t_glob *g)
{
	free(g->path);
}

int	main(int argc, char **argv)
{
	DIR *rep = NULL;
	t_glob g;
	int i;

	i = 0;
	ft_bzero(&g, sizeof(t_glob));
	if(edit(&g, argc, argv) == -1)
		return (0);
	while (i < g.leng_path)
	{
		if(i != 0)
			printf("\n");
		if ((rep = opendir(g.path[i])) == NULL)
		{
			if(ft_strcmp(strerror(errno), "Not a directory") != 0)
			{
    			i++;
    			perror("");
    			continue;
    		}
		}
		else
			closedir(rep);
		if(g.flag_gr == 1)
		{

			ft_R(g.path[i], &g);
		}
		else if(g.flag_gr == 0 && g.flag_l == 0)
		{
			ft_ls(&g, g.path[i]);
		}
		else if(g.flag_gr == 0 && g.flag_l == 1)
			ft_ls_l(g.path[i], &g);
		i++;
	}
	//printf("oui\n");
	ft_liber(&g);
	system("leaks ft_ls");
	return (0);
}
