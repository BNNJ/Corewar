/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:26:43 by pfragnou          #+#    #+#             */
/*   Updated: 2019/06/16 18:26:44 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"
#include "libft.h"

int		viewer_pause(t_viewer *vw)
{
	vw->status = STATUS_PAUSE;
	mvwprintw(vw->info_win, STAT_OFFSET + 3, COLUMN_OFFSET, "paused ");
	wrefresh(vw->info_win);
	while (vw->status == STATUS_PAUSE)
	{
		if (viewer_control(vw) == 0)
			return (0);
	}
	mvwprintw(vw->info_win, STAT_OFFSET + 3, COLUMN_OFFSET, "running");
	return (1);
}

int		viewer_control(t_viewer *vw)
{
	char	c;

	if (ft_findchar(CONTROL_QUIT, (c = getch())) >= 0)
		return (0);
	else if (ft_findchar(CONTROL_PAUSE, c) >= 0)
	{
		if (vw->status == STATUS_PAUSE)
			vw->status = STATUS_RUN;
		else
			return (viewer_pause(vw));
	}
	else if (ft_findchar(CONTROL_FAST, c) >= 0)
		vw->delay = 0;
	else if (ft_findchar(CONTROL_MEDIUM, c) >= 0)
		vw->delay = 2500;
	else if (ft_findchar(CONTROL_SLOW, c) >= 0)
		vw->delay = 10000;
	else if (ft_findchar(CONTROL_FASTER, c) >= 0)
		vw->delay = vw->delay > 50 ? vw->delay - 30 : 0;
	else if (ft_findchar(CONTROL_SLOWER, c) >= 0)
		vw->delay += 30;
	mvwprintw(vw->info_win, STAT_OFFSET + 4, COLUMN_OFFSET, "%dms\t\t",
		vw->delay);
	wrefresh(vw->info_win);
	return (1);
}
