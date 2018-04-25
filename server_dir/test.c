/*
** test.c for test.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:10:41 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:10:44 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

void	parcours_list_player(t_setting *current_setting)
{
	t_player	*joueur;

	joueur = current_setting->gameInfo->players->first;
	while (joueur != NULL)
	{
		printf("\n%s\n%d\n%d\n%d\n%d\n----------\n\n", joueur->name, joueur->x, joueur->y, joueur->energy, joueur->looking);
		joueur = joueur->next;
	}
}

void 	confirme_setting(t_setting *current_setting)
{
	printf("--------------------------------------\n");
	printf("|         SETTING INFORMATION        |\n");
	printf("--------------------------------------\n");
	printf("Req port : %s\n",current_setting->rep_port);
	printf("Pub port : %s\n", current_setting->pub_port);
	printf("Cycle : %d\n", current_setting->cycle);
	printf("Verbose : %d\n", current_setting->verbose);
	printf("Logfile : %s\n", current_setting->logfile);
	printf("Size : %d\n", current_setting->gameInfo->map_size);
	printf("--------------------------------------\n");
}

void 	create_client_manuel(t_setting *current_setting)
{
	create_player(current_setting, "#0x01");
	create_player(current_setting, "#0x02");
	create_player(current_setting, "#0x03");
	create_player(current_setting, "#0x04");
}

void	test_rfc_command(t_setting *current_setting)
{
	create_client_manuel(current_setting);
    parcours_list_player(current_setting);
    printf("Identité FAUSSE résultat = %s\n", identify(current_setting, "#0x02"));
    printf("Identité BONNE résultat = %s\n", identify(current_setting, "#0x05"));
    printf("----------------DEPLACEMENT---------------\n");
    printf("----------------RECULERn");
    printf("Reculer impossible = %s\n", backward(current_setting, "#0x02"));
    printf("----------------AVANCER\n");
    printf("Avancement possible = %s\n", forward(current_setting, "#0x02"));
    printf("---------------- A DOITE\n");
    printf("Droite possible = %s\n", leftfwd(current_setting, "#0x02"));
    printf("----------------A GAUCHE\n");
    printf("Gauche possible = %s\n", rightfwd(current_setting, "#0x02"));
    printf("----------------JUMP\n");
    printf("JUMP possible = %s\n", jump(current_setting, "#0x02"));

    printf("\n----------------ORIENTATION---------------\n");
    printf("----------------LEFT\n");
    printf("LEFT possible = %s\n", left(current_setting, "#0x02"));
    printf("----------------RIGHT\n");
    printf("RIGHT possible = %s\n", right(current_setting, "#0x02"));
    //printf("%s\n",watch(current_setting, name));
}