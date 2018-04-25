/*
** map.c for map.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:07:45 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:07:48 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

int   initialize_position_x(t_setting *current_setting)
{
  int   position_x;

  position_x = 0;
  if (current_setting->gameInfo->players->nb_elem == 2 || current_setting->gameInfo->players->nb_elem == 4)
    {
      position_x = current_setting->gameInfo->map_size++;
    }
  return (position_x);
}

int   initialize_position_y(t_setting *current_setting)
{
  int   position_y;
  printf("Je suis le joueur %s\n", current_setting->gameInfo->players->nb_elem);
  position_y = 0;
  if (current_setting->gameInfo->players->nb_elem == 3 || current_setting->gameInfo->players->nb_elem == 4)
    position_y = current_setting->gameInfo->map_size++;
  return (position_y);
}

int   initialize_map(t_setting *current_setting)
{
  
}
