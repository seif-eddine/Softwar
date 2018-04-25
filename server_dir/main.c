/*
** main.c for main.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:04:14 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:04:18 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

int main(int argc, char **argv)
//int main()
{
	pthread_t 	threadCycle;
	t_setting	*current_setting;
	//t_NotificationType notif;
	//int ret;

	//ret = 0;
	//notif = 0;
	srand(time(NULL));
	current_setting = initialize_setting();
	if (current_setting == NULL)
		return (1);
	//confirme_setting(current_setting);
	
	if (parse(argc, argv, current_setting) != 0)
	{
		free(current_setting);
		return (0);
	}
	
	
	openlog(current_setting->logfile, LOG_PID|LOG_CONS,LOG_DAEMON);
 	syslog(LOG_INFO, "A different kind of Hello world ... ");
	printf("\n---------------------------------------\n");
	//router(current_setting);
	create_and_add_socket_to_setting(current_setting); //attend que les clients se connect mais avec la pub
	confirme_setting(current_setting);
	printf("\n+++++++++++++++++++++++++++++++\n");
	//game(current_setting, notif);
	//printf("%s\n", "sortie de game");
	//printf(current_setting->logfile, KRED);
	

	
    //pthread_create(&threadCycle, NULL, waiting_for_players, (void *)current_setting);
    pthread_create(&threadCycle, NULL, game, (void *)current_setting);
    pthread_join(threadCycle, NULL);
	

    
    //test_rfc_command(current_setting);
    

    //pthread_create(&threadCycle, NULL, waiting_for_players, (t_setting *)current_setting);
	//waiting_for_players(current_setting);
	/*printf ("Thread server create !\n");
	ret = pthread_create (&threadCycle, NULL, threadCycle, (t_setting*)current_setting);
	//thread seversert de noitification et les thread client font l'échange?
	if (!ret)
	{
		printf ("Thread client create !\n");
		for (i = 0; i < 4; i++)
        {
	        ret = pthread_create (
	            & store.thread_clients [i], NULL,
	            fn_clients, (void *) i);
	 
	        if (ret)
	        {
	            fprintf (stderr, "%s", strerror (ret));
	        }
      	}
	}
	else
    {
    	fprintf (stderr, "%s", strerror (ret));
    }
	pthread_join(threadCycle, NULL);*/


	//publish(current_setting);
	
	/*printf("\n5555555555555555555555555555\n");
	printf("LES 4 JOUEURS SONT REUNIT\n");
	printf("\nFin publish , rentre dans router");
	printf("Number players : -------------%d\n", current_setting->gameInfo->players->nb_elem);
	parcours_list_player(current_setting);*/


	//router(current_setting);
	/*cycle(current_setting);
	printf(current_setting->logfile, KRED);
	free(current_setting);
	//closelog();*/
	return (0);
}
