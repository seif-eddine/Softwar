/*
** info_command.c for info_command.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:07:20 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:07:26 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

char   *looking(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;

	result = "ko|";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
			sprintf(result,"%01X", player->looking);
		player = player->next;
	}
  return (result);
}

char	*selfstats(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;

	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			result = "ok|";
			sprintf (result,"%01X",  player->energy);
		}
		player = player->next;
	}
	return (result);
}

char	*inspect(t_setting *current_setting, char *name, char *nameDemand)
{
	t_player	*player;
	char		*result;

	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			result = "ok|";
			sprintf (result,"%01X", player->energy);
		}
		if (strcmp(player->name, nameDemand) == 0)
			player->action = player->action - 0.5;
		player = player->next;
	}
	return (result);
}
