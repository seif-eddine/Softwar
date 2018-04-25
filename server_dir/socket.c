/*
** socket.c for socket.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:10:21 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:10:24 2017 TOKPAHOLOU Marvyne
*/

#include "../my.h"

int		create_and_add_socket_to_setting(t_setting *current_setting)
{
	t_sockets	*socket;
	char 		port[12];
	void 		*context;
	void 		*publisher;
	int 		sndhwm;
	void 		*router;


	context = zmq_ctx_new ();
  	publisher = zmq_socket (context, ZMQ_PUB);
  	sndhwm = 1100000;
  	zmq_setsockopt (publisher, ZMQ_SNDHWM, &sndhwm, sizeof (int));
  	sprintf (port, "tcp://*:%01i", (int)atol(current_setting->pub_port));
  	zmq_bind (publisher, port);
  	sleep(1);

  	router = zmq_socket(context, ZMQ_ROUTER);
	sprintf (port, "tcp://*:%01i", (int)atol(current_setting->rep_port));
  	zmq_bind(router, port);
  	if ((socket = malloc(sizeof(*socket))) != NULL)
  	{
	  	socket->context_publisher = context;
	  	socket->publisher = publisher;
	  	socket->router = router;
	  	current_setting->gameSockets = socket;
	}
	return (1);
}
