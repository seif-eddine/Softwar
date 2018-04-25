/*
** move_command.c for move_command.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:08:05 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:08:10 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

char   *forward(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;
	//int			nb_player;

	//nb_player = 0;
	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	printf("lancement de la commande");
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			printf("X = %d, Y = %d\n", player->x, player->y);
			switch(player->looking)
			{
				case (0):
					if (player->y + 1 >= 0 && player->y + 1 <= current_setting->gameInfo->map_size)
					{
						player->y++;
						result = "ok|null";
					}
				break;
				case (1):
					if (player->x + 1 >= 0 && player->x + 1 <= current_setting->gameInfo->map_size)
					{
						player->x++;
						result = "ok|null";
					}
				break;
				case (2):
					if (player->y - 1 >= 0 && player->y - 1 <= current_setting->gameInfo->map_size)
					{
						player->y--;
						result = "ok|null";
					}
				break;
				case (3):
					if (player->x - 1 >= 0 && player->x - 1 <= current_setting->gameInfo->map_size)
					{
						player->x--;
						result = "ok|null";
					}
				break;
			}
			
			player->action = player->action - 0.5;
			printf("X = %d, Y = %d\n", player->x, player->y);
			player = NULL;
		}
		else
			player = player->next;
	}
  return (result);
}

char   *backward(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;
	//int			nb_player;

	//nb_player = 0;
	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			printf("X = %d, Y = %d\n", player->x, player->y);
			switch(player->looking)
			{
				case (0):
					if (player->y - 1 >= 0 && player->y - 1 <= current_setting->gameInfo->map_size)
					{
						player->y--;
						result = "ok|null";
					}
				break;
				case (1):
					if (player->x - 1 >= 0 && player->x - 1 <= current_setting->gameInfo->map_size)
					{
						player->x--;
						result = "ok|null";
					}
				break;
				case (2):
					if (player->y + 1 >= 0 && player->y + 1 <= current_setting->gameInfo->map_size)
					{
						player->y++;
						result = "ok|null";
					}
				break;
				case (3):
					if (player->x + 1 >= 0 && player->x + 1 <= current_setting->gameInfo->map_size)
					{
						player->x++;
						result = "ok|null";
					}
				break;
			}
			printf("X = %d, Y = %d\n", player->x, player->y);
			player->action = player->action - 1;
			player = NULL;
		}
		else
			player = player->next;
	}
  return (result);
}

char   *leftfwd(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;
	//int			nb_player;

	//nb_player = 0;
	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			printf("X = %d, Y = %d\n", player->x, player->y);
			switch(player->looking)
			{
				case (0):
					if (player->y - 1 >= 0 && player->y - 1 <= current_setting->gameInfo->map_size)
					{
						player->y--;
						result = "ok|null";
					}
				break;
				case (1):
					if (player->x + 1 >= 0 && player->x + 1 <= current_setting->gameInfo->map_size)
					{
						player->x++;
						result = "ok|null";
					}
				break;
				case (2):
					if (player->y + 1 >= 0 && player->y + 1 <= current_setting->gameInfo->map_size)
					{
						player->y++;
						result = "ok|null";
					}
				break;
				case (3):
					if (player->x - 1 >= 0 && player->x - 1 <= current_setting->gameInfo->map_size)
					{
						player->x--;
						result = "ok|null";
					}
				break;
			}
			player->action = player->action - 1;
			printf("X = %d, Y = %d\n", player->x, player->y);
			player = NULL;
		}
		else
			player = player->next;
	}
  return (result);
}

char   *rightfwd(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;
	//int			nb_player;

	//nb_player = 0;
	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			printf("X = %d, Y = %d\n", player->x, player->y);
			switch(player->looking)
			{
				case (0):
					if (player->x + 1 >= 0 && player->x + 1 <= current_setting->gameInfo->map_size)
					{
						player->x++;
						result = "ok|null";
					}
				break;
				case (1):
					if (player->y - 1 >= 0 && player->y - 1 <= current_setting->gameInfo->map_size)
					{
						player->y--;
						result = "ok|null";
					}
				break;
				case (2):
					if (player->x - 1 >= 0 && player->x - 1 <= current_setting->gameInfo->map_size)
					{
						player->x--;
						result = "ok|null";
					}
				break;
				case (3):
					if (player->y + 1 >= 0 && player->y + 1 <= current_setting->gameInfo->map_size)
					{
						player->y++;
						result = "ok|null";
					}
				break;
			}
			player->action = player->action - 1;
			printf("X = %d, Y = %d\n", player->x, player->y);
			player = NULL;
		}
		else
			player = player->next;
	}
  return (result);
}

char   *jump(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;
	//int			nb_player;

	//nb_player = 0;
	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			printf("X = %d, Y = %d\n", player->x, player->y);
			switch(player->looking)
			{
				case (0):
				if (player->y + 1 >= 0 && player->y + 1 <= current_setting->gameInfo->map_size)
					{
						player->y = player->y + 2;
						result = "ok|null";
					}
					
				break;
				case (1):
				if (player->x + 2 >= 0 && player->x + 2 <= current_setting->gameInfo->map_size)
					{
						player->x = player->x + 2;
						result = "ok|null";
					}
					
				break;
				case (2):
				if (player->y - 2 >= 0 && player->y - 2 <= current_setting->gameInfo->map_size)
					{
						player->y = player->y - 2;
						result = "ok|null";
					}
					//player->y = player->y - 2;
				break;
				case (3):
					if (player->x - 2 >= 0 && player->x - 2 <= current_setting->gameInfo->map_size)
					{
						player->x = player->x - 2;
						result = "ok|null";
					}
					
				break;
				printf("il a trouvé\n");
			}
			player->energy = player->energy - 2;
			printf("X = %d, Y = %d\n", player->x, player->y);
			player = NULL;
		}
		else
			player = player->next;
	}
  return (result);
}


char   *right(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;

	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			switch(player->looking)
			{
				case (0):
					player->looking = 3;
				break;
				case (1):
					player->looking = 0;
				break;
				case (2):
					player->looking = 1;
				break;
				case (3):
					player->looking = 2;
				break;
			}
			result = "ok|null";
			player->action = player->action - 0.5;
		}
		player = player->next;
	}
  return (result);
}

char   *left(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;

	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			switch(player->looking)
			{
				case (0):
					player->looking = 1;
				break;
				case (1):
					player->looking = 2;
				break;
				case (2):
					player->looking = 3;
				break;
				case (3):
					player->looking = 0;
				break;
			}
			result = "ok|null";
			player->action = player->action - 0.5;
		}
		player = player->next;
	}
  return (result);
}
