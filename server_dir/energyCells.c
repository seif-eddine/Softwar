/*
** energyCells.c for energyCells.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:06:00 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:06:03 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

int		add_energyCell_to_game(t_setting *current_setting)
{
	t_energyCell_list	*energyCells;

  energyCells = malloc(sizeof(*energyCells));
  if (energyCells == NULL)
    {
      printf("Initial energyCells list could not be loaded\n");
      return (1);
    }
  energyCells->first = NULL;
  energyCells->last = NULL;
  energyCells->nb_elem = 0;
  current_setting->gameInfo->energyCells = energyCells;
  printf("EnergyCells list was succeful adding\n");
  return (0);
}

int   add_energyCell_to_energyCell_list(t_setting *current_setting, t_energyCell *energyCell)
{
  if (current_setting->gameInfo->energyCells->first == NULL)
    {
      current_setting->gameInfo->energyCells->first = energyCell;
      current_setting->gameInfo->energyCells->last = energyCell;
      current_setting->gameInfo->energyCells->first->next = NULL;
      current_setting->gameInfo->energyCells->first->prev = NULL;
    }
  else
    {
      energyCell->next = NULL;
      energyCell->prev = current_setting->gameInfo->energyCells->last;
      current_setting->gameInfo->energyCells->last->next = energyCell;
      current_setting->gameInfo->energyCells->last = energyCell;
    }
  current_setting->gameInfo->energyCells->nb_elem = current_setting->gameInfo->energyCells->nb_elem + 1;
  return (0);
}

int   del_energyCell_from_energieCell_list(t_setting *current_setting, t_energyCell *energyCell)
{
  if (energyCell == current_setting->gameInfo->energyCells->first || energyCell == current_setting->gameInfo->energyCells->last)
    {
      if (energyCell == current_setting->gameInfo->energyCells->first)
  {
    current_setting->gameInfo->energyCells->first = NULL;
    current_setting->gameInfo->energyCells->last = NULL;
  }
      else
  {
    current_setting->gameInfo->energyCells->last = energyCell->prev;
    current_setting->gameInfo->energyCells->last->next = NULL;
  }
    }
  else
    {
      energyCell->prev->next = energyCell->next;
      energyCell->next->prev = energyCell->prev;
    }
  free(energyCell);
  current_setting->gameInfo->energyCells->nb_elem = current_setting->gameInfo->energyCells->nb_elem - 1;
  return (0);
}

///FUNCTION CELLS GENERATE
int   generate_energieCell(t_setting *current_setting)
{
  //int           i;
  t_energyCell *energyCell;

  if ((energyCell = malloc(sizeof(*energyCell))) == NULL)
    return (1);
  while(1)
  {
    energyCell->x = rand() % (current_setting->gameInfo->map_size + 1 - 0) + 0;
    energyCell->y = rand() % (current_setting->gameInfo->map_size + 1 - 0) + 0;
    if (strcmp(foundPresentCellWithXY(current_setting, energyCell->x, energyCell->y), "empty") == 0)
      exit(0);
  }
  energyCell->value = rand() % (15 + 1 - 5) + 5;
  add_energyCell_to_energyCell_list(current_setting, energyCell);
  return (0);
}