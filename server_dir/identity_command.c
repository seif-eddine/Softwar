/*
** identity_command.c for identity_command.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:06:52 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:06:56 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

char	*identify(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;

	result = "ok|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
			result = "ko|null";
		player = player->next;
	}
	return (result);
}

char	*selfid(t_setting *current_setting, char *name)
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
			sprintf (result, name);
		}
		player = player->next;
	}
	return (result);
}
