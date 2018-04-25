/*
** player.c for player.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:09:00 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:09:03 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

int		add_players_to_game(t_setting *current_setting)
{
	t_player_list	*players;

  players = malloc(sizeof(*players));
  if (players == NULL)
    {
      printf("%sInitial players list could not be loaded\n", KRED);
      return (1);
    }
  players->first = NULL;
  players->last = NULL;
  players->nb_elem = 0;
  current_setting->gameInfo->players = players;
  printf("%sPlayers list was succeful adding\n", KGRN);
  printf("%d\n", players->nb_elem);
  return (0);
}

int   initialize_position_x(t_setting *current_setting)
{
  int   position_x;

  position_x = 0;
  if (current_setting->gameInfo->players->nb_elem == 2 || current_setting->gameInfo->players->nb_elem == 3)
    position_x = current_setting->gameInfo->map_size;
  return (position_x);
}

int   initialize_position_y(t_setting *current_setting)
{
  int   position_y;

  position_y = 0;
  if (current_setting->gameInfo->players->nb_elem == 1 || current_setting->gameInfo->players->nb_elem == 3)
    position_y = current_setting->gameInfo->map_size;
  return (position_y);
}

int   create_player(t_setting *current_setting, char *name)
{
  t_player  *new_player;

  printf("Nom du joueur = %s\n", name);
  if ((new_player = malloc(sizeof(*new_player))) != NULL)
  {
    new_player->name = strdup(name);
    new_player->x = initialize_position_x(current_setting);
    new_player->y = initialize_position_y(current_setting);
    new_player->energy = 50;
    new_player->action = 10;
    new_player->wait_cycle = 0;
    if (new_player->x == 0)
      new_player->looking = 1;
    else
      new_player->looking = 3;
    add_player_to_player_list(current_setting, new_player);
    printf("\n Position : %d - %d\n", new_player->x, new_player->y);
  }
  else
    return(0);
  return (1);
}

int		add_player_to_player_list(t_setting *current_setting, t_player *player)
{
  if (current_setting->gameInfo->players->first == NULL)
    {
      current_setting->gameInfo->players->first = player;
      current_setting->gameInfo->players->last = player;
      current_setting->gameInfo->players->first->next = NULL;
      current_setting->gameInfo->players->first->prev = NULL;
    }
  else
    {
      player->next = NULL;
      player->prev = current_setting->gameInfo->players->last;
      current_setting->gameInfo->players->last->next = player;
      current_setting->gameInfo->players->last = player;
    }
  current_setting->gameInfo->players->nb_elem = current_setting->gameInfo->players->nb_elem + 1;
  printf("Je suis dans add player to list ==== %d\n", current_setting->gameInfo->players->nb_elem);
  return (1);
}

int		del_player_from_player_list(t_setting *current_setting, t_player *player)
{
  if (player == current_setting->gameInfo->players->first || player == current_setting->gameInfo->players->last)
    {
      if (player == current_setting->gameInfo->players->first)
	{
	  current_setting->gameInfo->players->first = NULL;
	  current_setting->gameInfo->players->last = NULL;
	}
      else
	{
	  current_setting->gameInfo->players->last = player->prev;
	  current_setting->gameInfo->players->last->next = NULL;
	}
    }
  else
    {
      player->prev->next = player->next;
      player->next->prev = player->prev;
    }
  free(player);
  current_setting->gameInfo->players->nb_elem = current_setting->gameInfo->players->nb_elem - 1;
  return (1);
}
