/*
** other_command.c for other_command.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:08:26 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:08:29 2017 TOKPAHOLOU Marvyne
*/
#include "../my.h"

char	*next(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;

	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			player->wait_cycle = 1;
			result = "ok|null";
		}
		player = player->next;
	}
	return (result);
}

char	*gather(t_setting *current_setting, char *name)
{
	t_player	*player;
	t_energyCell *energyCells;
	char		*result;

	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		energyCells = current_setting->gameInfo->energyCells->first;
		while (energyCells != NULL)
		{
			if (strcmp(player->name, name) == 0)
			{
				if (player->x == energyCells->x && player->y == energyCells->y)
					player->energy = player->energy + energyCells->value;
				//player->wait_cycle = 1;
				result = "ok|null";
			}
			player = player->next;
		}
	}
	player->action = player->action - 1;
	return (result);
}

char	*attack(t_setting *current_setting, char *name)
{
	t_player	*player;
	char		*result;

	result = "ko|null";
	player = current_setting->gameInfo->players->first;
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			player->wait_cycle = 2;
			result = "ok|null";
		}
		player = player->next;
	}
	return (result);
}


char	*watch(t_setting *current_setting, char *name)
{
	printf("0");
	t_player	*player;
	char		*result;
	char		*cell[4];
	int			i;

	i = 0;
	result = "ok|[";
	player = current_setting->gameInfo->players->first;
	printf("1");
	while (player != NULL)
	{
		if (strcmp(player->name, name) == 0)
		{
			printf("2");
			while(i < 4)
			{
				printf("3");
				sprintf(result, "'");
				cell[i] = foundPresentCell(current_setting ,player, i);
				i++;
				sprintf(result, cell[i]);
				sprintf(result, "'");
			}
		}
		player = player->next;
	}
	sprintf(result, "]");
	printf("%s\n", result);
	printf("%s %s\n", name, current_setting->logfile);
	//result = "[e, 5, e, #0x01]";
	return (result);
}


char	*foundPresentCell(t_setting *current_setting, t_player	*playerFound, int i)
{
	t_player	*player;
	t_energyCell *energyC;
	char		*result;

	energyC = current_setting->gameInfo->energyCells->first;
	player = current_setting->gameInfo->players->first;
	result = "e";
	while (energyC != NULL)
	{
		switch (player->looking)
			{
				case (3):
					switch(i)
					{
						case(0):
							if (energyC->x == playerFound->x || energyC->y == playerFound->y - 1) 
								//result = (char)energyC->value;
								sprintf(result, "%01X", energyC->value);
						break;
						case(1):
							if (energyC->x == playerFound->x + 1 || energyC->y == playerFound->y - 2) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(2):
							if (energyC->x == playerFound->x || energyC->y == playerFound->y - 2) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(3):
							if (energyC->x == playerFound->x - 1 || energyC->y == playerFound->y - 2) 
								sprintf(result, "%01X", energyC->value);
						break;
					}
				break;
				case (2):
					switch(i)
					{
						case(0):
							if (energyC->x == playerFound->x - 1|| energyC->y == playerFound->y) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(1):
							if (energyC->x == playerFound->x - 2 || energyC->y == playerFound->y - 1) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(2):
							if (energyC->x == playerFound->x - 2 || energyC->y == playerFound->y) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(3):
							if (energyC->x == playerFound->x - 2  || energyC->y == playerFound->y + 1) 
								sprintf(result, "%01X", energyC->value);
						break;
					}
				break;
				case (1):
					switch(i)
					{
						case(0):
							if (energyC->x == playerFound->x || energyC->y == playerFound->y + 1) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(1):
							if (energyC->x == playerFound->x - 1 || energyC->y == playerFound->y + 2) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(2):
							if (energyC->x == playerFound->x || energyC->y == playerFound->y + 2) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(3):
							if (energyC->x == playerFound->x + 1 || energyC->y == playerFound->y + 2) 
								sprintf(result, "%01X", energyC->value);
						break;
					}
				break;
				case (0):
					switch(i)
					{
						case(0):
							if (energyC->x == playerFound->x + 1|| energyC->y == playerFound->y) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(1):
							if (energyC->x == playerFound->x + 2 || energyC->y == playerFound->y + 1) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(2):
							if (energyC->x == playerFound->x + 2 || energyC->y == playerFound->y) 
								sprintf(result, "%01X", energyC->value);
						break;
						case(3):
							if (energyC->x == playerFound->x + 2  || energyC->y == playerFound->y - 1) 
								sprintf(result, "%01X", energyC->value);
						break;
					}
				break;
			}
	}
	while (player != NULL)
		{
			switch (player->looking)
			{
				case (3):
					switch(i)
					{
						case(0):
							if (player->x == playerFound->x || player->y == playerFound->y - 1) 
								result = player->name;
						break;
						case(1):
							if (player->x == playerFound->x + 1 || player->y == playerFound->y - 2) 
								result = player->name;
						break;
						case(2):
							if (player->x == playerFound->x || player->y == playerFound->y - 2) 
								result = player->name;
						break;
						case(3):
							if (player->x == playerFound->x - 1 || player->y == playerFound->y - 2) 
								result = player->name;
						break;
					}
				break;
				case (2):
					switch(i)
					{
						case(0):
							if (player->x == playerFound->x - 1 || player->y == playerFound->y) 
								result = player->name;
						break;
						case(1):
							if (player->x == playerFound->x - 2 || player->y == playerFound->y - 1) 
								result = player->name;
						break;
						case(2):
							if (player->x == playerFound->x - 2 || player->y == playerFound->y) 
								result = player->name;
						break;
						case(3):
							if (player->x == playerFound->x - 2 || player->y == playerFound->y - 1) 
								result = player->name;
						break;
					}
				break;
				case (1):
					switch(i)
					{
						case(0):
							if (player->x == playerFound->x || player->y == playerFound->y + 1) 
								result = player->name;
						break;
						case(1):
							if (player->x == playerFound->x - 1 || player->y == playerFound->y + 2) 
								result = player->name;
						break;
						case(2):
							if (player->x == playerFound->x || player->y == playerFound->y + 2) 
								result = player->name;
						break;
						case(3):
							if (player->x == playerFound->x + 1 || player->y == playerFound->y + 2) 
								result = player->name;
						break;
					}
				break;
				case (0):
					switch(i)
					{
						case(0):
							if (player->x == playerFound->x + 1 || player->y == playerFound->y) 
								result = player->name;
						break;
						case(1):
							if (player->x == playerFound->x + 2 || player->y == playerFound->y + 1) 
								result = player->name;
						break;
						case(2):
							if (player->x == playerFound->x + 2 || player->y == playerFound->y) 
								result = player->name;
						break;
						case(3):
							if (player->x == playerFound->x + 2 || player->y == playerFound->y + 1) 
								result = player->name;
						break;
					}
				break;
			}
		}
	return (result);
}

char	*foundPresentCellWithXY(t_setting *current_setting, int x, int y)
{
	t_player	*player;
	t_energyCell *energyC;
	char		*result;
	int 	size;

	energyC = current_setting->gameInfo->energyCells->first;
	player = current_setting->gameInfo->players->first;
	result = "e";
	while (energyC != NULL)
	{
		if (((energyC->x) == x) && ((energyC->y) == y))
		{
			size = sizeof(result);
			snprintf(result, size, "%01d", energyC->value);
			exit (0);
		}
		energyC = energyC->next;
	}
	while (player != NULL)
	{
		if (((player->x) == x) && ((player->y) == y))
		{
			result = player->name;
			exit (0);
		}	
		player = player->next;
	}
	return (result);
}
//watch
