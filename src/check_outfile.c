/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:37 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/15 18:15:56 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	check_outfile(t_pipd *pipd)
{
	if (access(pipd->outfile, F_OK) == 0 && access(pipd->outfile, W_OK) == -1)
		return (0);
	else
		return (1);
}
