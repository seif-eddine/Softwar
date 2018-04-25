/*
** client_management.c for client_management.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:04:53 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:04:56 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"


int		check_name_player(t_setting *current_setting, char *name)
{
	t_player	*tmp;

	tmp = current_setting->gameInfo->players->first;
	while (tmp != NULL)
	{
		if (strcmp(tmp->name, name) == 0)
		{
			printf("This identifer is already used\n");
			return (0);
		}
	}
	return (1);
}

//int		create_my_player_virtuel_because_server_pub_sub_doesnt_work(t_setting *current_setting)
//{

//}
