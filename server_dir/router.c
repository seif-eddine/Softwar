/*
** router.c for router.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:09:40 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:09:48 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

int		router(t_setting *current_setting)
{
	zsock_t *router = zsock_new(ZMQ_ROUTER);
  zsock_t *pub = zsock_new(ZMQ_PUB);
  //zsock_bind(router, "tcp://*:%s", argv[1]);
  //zsock_bind(pub, "tcp://*:%s", argv[1]);
  zsock_bind(router, "tcp://*:%s", current_setting->rep_port);
  zsock_bind(pub, "tcp://*:%s", current_setting->rep_port);

  while (!zsys_interrupted) {    
  	zmsg_t *message = zmsg_recv(router);

    zframe_t *identity = zmsg_pop(message);
    zframe_t *empty = zmsg_pop(message);
    zframe_t *content = zmsg_pop(message);
printf("ttttttttttttttttttttttttttttttttttttttttttt\n");
    zmsg_destroy(&message);
    printf("Identity is : %s\n", zframe_strdup(identity));
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
    printf("Content of message is : %s\n", zframe_strdup(content));
    sleep(1);
    //zmsg_t *message = zmsg_recv(router);
    //read_message_router(message);
    printf("test1\n");
    //send_message_router(router, message);
    zmsg_t *response = zmsg_new();

    zmsg_prepend(response, &identity);
    zmsg_append(response, &empty);
    zmsg_append(response, &content);

    zmsg_send(&response, router);
    zmsg_destroy(&response);

    zframe_destroy(&identity);
    zframe_destroy(&empty);
    zframe_destroy(&content); 
  }
  zsock_destroy(&pub);
  zsock_destroy(&router);
  return 0;
}

/*int   game(t_setting *current_setting)
{

}*/
