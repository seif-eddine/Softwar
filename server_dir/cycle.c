/*
** cycle.c for cycle.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:05:31 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:05:33 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"
#define SUBSCRIBERS_EXPECTED  2
//au début de chaque cycle chauqe joueure perd 2 unités d'énergie
// au dessus de 100 d'énergie le processus s'auto détruit


static const t_command	commandRFC[] =
  {
  	{"forward", forward},
  	{"backward", backward},
  	{"leftfwd", leftfwd},
  	{"rightfwd", rightfwd},
  	{"right", right},
  	{"left", left},
  	{"looking", looking},
  	{"gather", gather},
  	{"watch", watch},
    {"attack",attack},
    {"selfid",selfid},
    {"jump", jump},
    {"selfstats", selfstats},
    //{"inspect", inspect},
    {"next", next},
    {NULL, NULL}
  };

//void  game(t_setting *current_setting, t_NotificationType notif)
void  *game(void *setting)
{
  t_setting * current_setting = (t_setting *) setting;
  openlog(current_setting->logfile, LOG_PID|LOG_CONS, LOG_USER);
  syslog(LOG_INFO, "A different kind of Hello world ... ");

  //char *message_pub;
  //char  *words;

  //char m[80];
//char final[150];

printf("1\n");
  while (current_setting->gameInfo->game_status != 2)
  {
    printf("2\n");
    if (current_setting->gameInfo->game_status == 0)
    {
        printf("3\n");
          /*sprintf(m, "Map Size = %i", 6);
          if (current_setting->gameInfo->game_status == 0)
            words = "Waiting";
          else if (current_setting->gameInfo->game_status == 1)
            words = "Stated";
          else
            words = "Finished";
          sprintf(final, "\nGame status =  %s", words);
          message_pub = final; */

          waiting_for_players(current_setting);
          current_setting->gameInfo->game_status = 1;
	  sleep(4);
          s_send (current_setting->gameSockets->publisher, "GAME START");
          printf("game start envoyé\n");
          //s_send(current_setting->gameSockets->router, "GAME START");
          //&current_setting->notif = game_started;
      }
      else
      {
          //message_pub = "The game will start";
          //s_send (current_setting->gameSockets->publisher, "GAME START");
          cycle(current_setting);
          current_setting->gameInfo->game_status = 2;
      }
    //(int)current_setting->notif = 2;
    //int i;
    /*for (i = 0; i < 50; i++)
      s_send (current_setting->gameSockets->publisher, message_pub);*/
   // if (current_setting->gameInfo->game_status == 0)
    //  waiting_for_players(current_setting, router);
    //threadserver -> analyse la notif
      sleep(1);
  }

  printf(" DEAD4\n");
  printf(current_setting->logfile, KRED);
  return NULL;
}

void  gameANCIEN(t_setting *current_setting, t_NotificationType notif)
{
  openlog(current_setting->logfile, LOG_PID|LOG_CONS, LOG_USER);
  syslog(LOG_INFO, "A different kind of Hello world ... ");

  char port[12];
  char *message_pub;
  char  *words;
  void *context = zmq_ctx_new ();
  //zsock_t *router = zsock_new(ZMQ_ROUTER);
  void *publisher = zmq_socket (context, ZMQ_PUB);
  
  char m[80];
char final[150];

  
  int sndhwm = 1100000;
  zmq_setsockopt (publisher, ZMQ_SNDHWM, &sndhwm, sizeof (int));
  //zmq_setsockopt (publisher, ZMQ_SUBSCRIBE, "softwar", 0);
  sprintf (port, "tcp://*:%01i", (int)atol(current_setting->pub_port));
  zmq_bind (publisher, port);


  void *router = zmq_socket(context, ZMQ_ROUTER);
  sprintf (port, "tcp://*:%01i", (int)atol(current_setting->rep_port));
  zmq_bind(router, port);
printf("1\n");
  while (notif != 2)
  {
    switch (notif){
       case 0:
          sprintf(m, "Map Size = %i", 6);
          if (current_setting->gameInfo->game_status == 0)
            words = "Waiting";
          else if (current_setting->gameInfo->game_status == 1)
            words = "Stated";
          else
            words = "Finished";
          sprintf(final, "\nGame status =  %s", words);
          message_pub = final;
      break;
      case 1:
          message_pub = "The game will start";
      break;
      case 2:
          message_pub = "The game finished";
      break;
      case 3:
          message_pub = "Enemy was killed";
      break;
      case 4:
          message_pub = "We have our winner";
      break;  
    }
    
    notif = 2;
    int i;
    printf("2\n");
    for (i = 0; i < 50; i++)
      s_send (publisher, message_pub);
    printf("3\n");
   // if (current_setting->gameInfo->game_status == 0)
    //  waiting_for_players(current_setting, router);
    //threadserver -> analyse la notif
      sleep(5);
  }

printf("4\n");
printf(current_setting->logfile, KRED);
  zmq_close (publisher);
  zmq_ctx_destroy (context);
  //zmq_close(router);

printf("5\n");
}
int   cycle(t_setting *current_setting)
//void   *cycle(t_setting *current_setting)
{
	char 	*renvoi;
	char  *name; 
  char  *message;
  char  *nameDemand;
  char  *command;
  char  *content;
  int   good;
  const char *delimiter;
  int	i;

  printf("je suis dans cycle\n");
  delimiter = "|";
  //zmq_bind(current_setting->gameSockets->router, "tcp://:4343");
	while (current_setting->gameInfo->game_status != 2)
	{
         printf("J'attend ici =)\n");
  	 //int c = 0;
  	 //int msg = 0;
    good = 0;
    free(s_recv(current_setting->gameSockets->router));
    free(s_recv(current_setting->gameSockets->router));
     name = s_recv(current_setting->gameSockets->router);
  	 message = s_recv(current_setting->gameSockets->router);
  	 sleep(2);
    	 printf("Le message pété ! est ...%s et l'identité est %s\n", message, name);

    	 if (message != NULL)
    	 {
      	  command = strtok(message, delimiter);
      	  content = strtok(NULL, delimiter);
     	  printf("La commande est : |%s| et le contenu est : |%s|\n", command, content);
  	  i = 0;
  	  while (commandRFC[i].str != NULL && good == 0)
     	{
     	  if ((strcmp(commandRFC[i].str,  command) == 0))
        {
          printf("test\n");
     	    renvoi = commandRFC[i].fonc(current_setting,  name);
          printf("%s\n", renvoi);
          good = 1;
        }
    	  else if ((strcmp("inspect",  content) == 0))
     	  {
          nameDemand = content; //////////////////////////
     	    renvoi = inspect(current_setting,  message, nameDemand);
          good = 1;
     	  }
        else
          renvoi = "ko|null";
  	    i++;
     	}
      printf("La commande est : |%s| et le contenu est : |%s|\n", command, renvoi);
      if (renvoi != NULL)
      {
        //s_sendmore(current_setting->gameSockets->router, message);
        s_sendmore(current_setting->gameSockets->router, name);
        //s_sendmore(current_setting->gameSockets->router, "");
        s_send(current_setting->gameSockets->router, renvoi);
      }
	  }
    free(message);
    free(name);
    free(s_recv(current_setting->gameSockets->router));
    free(s_recv(current_setting->gameSockets->router));
  }
  //pthread_exit((void *) current_setting->gameInfo->game_status);
  return (0);
}

//int   waiting_for_players(t_setting *current_setting)
void   *waiting_for_players(void *setting)
{
  t_setting * current_setting = (t_setting *)setting;
  const char   *delimiter;
  char *message;
  char  *command;
  char  *content;
  char  *command_result;
  int good;

  
  printf ("Waiting for subscribers\n");
  delimiter = "|";
  while (current_setting->gameInfo->players->nb_elem < SUBSCRIBERS_EXPECTED)
  {
    printf("dEBUT DU WHILE\n");
    sleep(1);
    good = 0;
    while (good == 0)
    {
      //char *string = s_recv (current_setting->gameSockets->recev_publisher);
      message = s_recv(current_setting->gameSockets->router);
      //printf("Le message est %s\n", message);
      if (message != NULL)
      {
        command = strtok(message, delimiter);
        content = strtok(NULL, delimiter);
        printf("La commande est : |%s| et le contenu est : |%s|\n", command, content);
        //s_sendmore(current_setting->gameSockets->router, message);


        if (content != NULL)
        {
          s_sendmore(current_setting->gameSockets->router, content);
          s_sendmore(current_setting->gameSockets->router, "");
          printf("resultat de strcmp : |%d|\n", strcmp(command, "identify"));
          if (strcmp(command, "identify") == 0 && content != NULL)
          {
            command_result = identify(current_setting, content);
            //s_sendmore(current_setting->gameSockets->router, "");
            //s_sendmore(current_setting->gameSockets->router, command_result);
            s_send(current_setting->gameSockets->router, command_result);
            create_player(current_setting, content);
            good = 1;
          }
        }
        else
        {
	  sleep(5);
          s_sendmore(current_setting->gameSockets->router, command);
          s_sendmore(current_setting->gameSockets->router, "");
          s_send(current_setting->gameSockets->router, "ko|null");
        }
        free(message);
        free(s_recv(current_setting->gameSockets->router));
        free(s_recv(current_setting->gameSockets->router));
      }
    }   
  }
    return NULL;
}
