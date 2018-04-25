/*
** setting.c for setting.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:10:02 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:10:05 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

/******
** There is a setting file for data of parsing. It's the master structure
** Fonction :
** 			- initialize_setting => Done
**			- delete_setting
*******/

t_setting	  *initialize_setting()
{
  	t_gameInfo *gameInfo;
  	t_setting	 *current_setting;

  	//gameInfo = NULL;
  	gameInfo = initialize_gameInfo(5);
    if ((current_setting = malloc(sizeof(*current_setting))) == NULL)
  	{
      printf("Initial server settings could not be loaded\n");
  		return (NULL);
    }
      current_setting->rep_port = "4242";

      current_setting->pub_port = "4343";
      current_setting->cycle = 500;
      current_setting->verbose = 0;
      current_setting->logfile = "log/softwar.log";
      //current_setting->size = 5;
      //current_setting->user_connect = 0;
      current_setting->gameInfo = gameInfo;
      printf("Initial server settings were successfully loaded \n");
      printf("rep port = %s\n", current_setting->rep_port );
      confirme_setting(current_setting);
      printf("aaaaaaaaa\n");
      if (add_energyCell_to_game(current_setting) == 0)
  		{
        printf("bbbbbbbbb\n");
        printf("Initial server settings were successfully loaded \n");
        printf("rep port = %s\n", current_setting->rep_port );
        if (add_players_to_game(current_setting) == 0)
          return (current_setting);
        else
          return (NULL);
      }
      else
        return (NULL);
}

t_gameInfo  *initialize_gameInfo(int size_map)
{
  t_gameInfo *gameInfo;
  t_player_list *player_list;
  t_energyCell_list *energyCell_list;

  player_list = NULL;
  energyCell_list = NULL;
  if ((gameInfo = malloc(sizeof(*gameInfo))) == NULL)
    {
      printf("Initial server info could not be loaded\n");
      return (NULL);
    } 
    else
    {
      gameInfo->map_size = size_map;
      gameInfo->game_status = 0;
      gameInfo->players = player_list;
      gameInfo->energyCells = energyCell_list;
      printf("Initial gameInfo settings were successfully loaded \n");
      return (gameInfo);
    }
}

