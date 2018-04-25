/*
** publisher.c for publisher.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:09:22 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:09:24 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"
//#include "../zhelpers.h"

int		publish(t_setting *current_setting)
{ 
  
  char *message_pub;
  //char *adr_pub;
  //char  *port;
//printf("%sTest\n");
  //sprintf(port, "%d", current_setting->pub_port);
/*printf("%sThest\n", KMAG);
  adr_pub = "tcp://127.0.0.1:";
  printf("%sThest2\n", KMAG);
  strcat(adr_pub, current_setting->pub_port);
  printf("%sThest3\n", KMAG);
  printf(adr_pub);*/
  //adr_pub = strcat(adr_pub, port);
  //printf("%sTest2\n");
  void *context = zmq_ctx_new ();
  void *publisher = zmq_socket (context, ZMQ_PUB);
  //zmq_bind(publisher, adr_pub);
  zmq_bind(publisher, "tcp://*:4242");
  while (current_setting->gameInfo->players->nb_elem < 4)
  {
    switch (current_setting->gameInfo->players->nb_elem)
    {
      case 0:
          printf("%sThe server is waiting for 3 players\n", KMAG);
          message_pub = "The server is waiting for 3 players";
      break;
      case 1:
          printf("%sThe server is waiting for 2 players\n", KMAG);
          message_pub = "The server is waiting for 2 players";
      break;
      case 2:
          printf("%sThe server is waiting for 1 players\n", KMAG);
          message_pub = "The server is waiting for 1 players";
      break;
      case 3:
          printf("%sThe game will start\n", KGRN);
          message_pub = "The game will start";
      break;
    }
    // printf("%sInitial server settings were successfully loaded \n", KGRN);
      //il faut que je trouve un moyen de mettre le server en attente tant qu'il n'y a pas 4 utilisateurs
    //  Prepare our context and publisher
    

    //while (1) {
        //  Write two messages, each with an envelope and content
        zmq_msg_t message;
        zmq_msg_init_size (&message, strlen (message_pub));
        memcpy (zmq_msg_data (&message), message_pub, strlen (message_pub));
        //int rc = zmq_msg_send (publisher, &message, 0);
        zmq_msg_send (publisher, &message, 0);
        zmq_msg_close (&message);
        sleep(10);
        //current_setting->user_connect++;
   // }
  
  }
    //  We never get here, but clean up anyhow
    zmq_close (publisher);
    zmq_ctx_destroy (context);
    return 0;
  /*else
  {

    //  Socket to talk to clients
    
  //  Prepare our context and publisher
    void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    //zmq_bind (publisher, "tcp://127.0.0.1:%s", current_setting->pub_port);

    while (1) {
        //  Write two messages, each with an envelope and content
        s_sendmore (publisher, "A");
        s_send (publisher, "We don't want to see this");
        s_sendmore (publisher, "B");
        s_send (publisher, "We would like to see this");
        sleep (1);


        zmq_msg_t message;
        zmq_msg_init_size (&message, strlen (message_pub));
        memcpy (zmq_msg_data (&message), message_pub, strlen (message_pub));
        int rc = zmq_msg_send (publisher, &message, 0);
        zmq_msg_close (&message);
    }
    //  We never get here, but clean up anyhow
    zmq_close (publisher);
    zmq_ctx_destroy (context);
    return 0;
  }*/
}

int   publisher_waiting_for_playersANCIEN(t_setting *current_setting)
{ 
  
  char *message_pub;

  //void *context = zmq_ctx_new ();
  //void *publisher = zmq_socket (context, ZMQ_PUB);
  //zmq_bind(publisher, "tcp://*:4242");
  zmq_bind(current_setting->gameSockets->publisher, "tcp://*:4242");

  //void *syncservice = zmq_socket (context, ZMQ_REP);
  //zmq_bind (current_setting->gameSockets->recev_publisher, "tcp://*:4343");


//s_send (publisher, "The server is waiting for players");
//s_send (current_setting->gameSockets->recev_publisher, "");
s_send (current_setting->gameSockets->publisher, "The server is waiting for players");

  while (current_setting->gameInfo->players->nb_elem < 4)
  {
        message_pub = "Gamer come to connect";
        //char *string = s_recv (syncservice);
        //char *string = s_recv (current_setting->gameSockets->recev_publisher);
        /*if (string != NULL)
        {
          printf("RECEVE : %s\n", string);

          create_player(current_setting, string);
          printf("NB connecter :%d \n", current_setting->gameInfo->players->nb_elem);
          free (string);
          //s_send (publisher, message_pub);
          s_send (current_setting->gameSockets->recev_publisher, "");
          s_send (current_setting->gameSockets->publisher, message_pub);
          //printf("%sThe game will start\n", KGRN);
          printf("\n1111111111111111111\n");
        }
        else
          printf("\nPROBLEME RECEVE");*/
        
  }
  message_pub = "The game will start";
  //s_send (current_setting->gameSockets->recev_publisher, "");
  //s_send (publisher, message_pub);
  //s_send (publisher, "GAME START");
    //zmq_close (publisher);
    //zmq_ctx_destroy (context);
  s_send (current_setting->gameSockets->publisher, message_pub);
  s_send (current_setting->gameSockets->publisher, "GAME START");
    //zmq_close (current_setting->gameSockets->publisher);
    //zmq_ctx_destroy (context);
    return 0;
}

int   publisher_waiting_for_players(t_setting *current_setting)
{ 
  char port[12];
  char *message_pub;
  //void *context;
//context = zmq_ctx_new ();
  //char  *command;
  //char  *content;
  //const char   *delimiter;

  sprintf (port, "tcp://*:%01i", (int)atol(current_setting->pub_port));
  zmq_bind(current_setting->gameSockets->publisher, port);
  printf("%s\n", port);
  //zmq_bind(current_setting->gameSockets->publisher, "tcp://*:4242");
  //zmq_bind (current_setting->gameSockets->recev_publisher, "tcp://*:4343");
   // zmq_bind (current_setting->gameSockets->router, "tcp://*:4343");

  sprintf (port, "tcp://*:%01i", (int)atol(current_setting->rep_port));
  //zmq_bind(current_setting->gameSockets->recev_publisher, port);
   printf("%s\n", port);
  //delimiter = "|";

//s_send (publisher, "The server is waiting for players");
//s_send (current_setting->gameSockets->recev_publisher, "");
s_send (current_setting->gameSockets->publisher, "The server is waiting for players");
//s_send (current_setting->gameSockets->recev_publisher, "");

  while (current_setting->gameInfo->players->nb_elem < 4)
  {
        message_pub = "Gamer come to connect";
        //char *string = s_recv (syncservice);
        //char *string = s_recv (current_setting->gameSockets->recev_publisher);
        //char *string = s_recv (current_setting->gameSockets->recev_publisher);

        //command = strtok(string, delimiter);
        //content = strtok(NULL, delimiter);

        //printf("La commande est :%s et le contenu est : %s\n", command, content);
        /*if (string != NULL)
        {
          printf("RECEVE : %s\n", string);

          create_player(current_setting, string);
          printf("NB connecter :%d \n", current_setting->gameInfo->players->nb_elem);
          free (string);
          //s_send (publisher, message_pub);
          s_send (current_setting->gameSockets->recev_publisher, "BONJOUR");
          s_send (current_setting->gameSockets->publisher, message_pub);
          //printf("%sThe game will start\n", KGRN);
          printf("\n1111111111111111111\n");
        }
        //else
          //printf("\nPROBLEME RECEVE");*/
        
  }
  message_pub = "The game will start";
  //s_send (current_setting->gameSockets->recev_publisher, "");
  //s_send (publisher, message_pub);
  //s_send (publisher, "GAME START");
  //zmq_close (publisher);
  //zmq_ctx_destroy (context);
  s_send (current_setting->gameSockets->publisher, message_pub);
  s_send (current_setting->gameSockets->publisher, "START GAME");
    //zmq_close (current_setting->gameSockets->publisher);
    //zmq_ctx_destroy (context);
    return 0;
}

int   send_publication(t_setting *current_setting, char *message)
{
  s_send (current_setting->gameSockets->publisher, message);
  return (0);
}
