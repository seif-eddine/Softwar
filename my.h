#ifndef			_MY_H_
# define		_MY_H_

#include    <czmq.h>
#include    <unistd.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <getopt.h> 
#include    <sys/types.h>
#include    <sys/uio.h>
#include    <string.h>
#include    <assert.h>
#include    <pthread.h>

#include <zmq.h>


//pthread_cond_t condition = PTHREAD_COND_INITIALISER;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/*
#if (!defined (WIN32))
#   include <sys/time.h>
#endif

#if (defined (WIN32))
#   include <windows.h>
#   include <time.h>
#endif
*/
/*#include "zhelpers.h"*/

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m]"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


/************
    printf("%sred\n", KRED);
    printf("%sgreen\n", KGRN);
    printf("%syellow\n", KYEL);
    printf("%sblue\n", KBLU);
    printf("%smagenta\n", KMAG);
    printf("%scyan\n", KCYN);
    printf("%swhite\n", KWHT);
    printf("%snormal\n", KNRM);
*************/




typedef struct s_setting   t_setting;
typedef struct s_gameInfo   t_gameInfo;
typedef struct s_player   t_player;
typedef struct s_player_list   t_player_list;
typedef struct s_energyCell   t_energyCell;
typedef struct s_energyCell_list   t_energyCell_list;
typedef struct s_sockets   t_sockets;
typedef struct s_notification   t_notification;
typedef enum   NotificationType t_NotificationType;
typedef struct s_command   t_command;
//void  send_message_router(zsock_t *router, zmsg_t *message);
//void  read_message_router(zmsg_t *message);
int   parse(int argc, char **argv, t_setting *current_setting);
void  confirme_setting(t_setting *current_setting);
t_setting *initialize_setting();
t_gameInfo  *initialize_gameInfo(int size_map);
int   publish(t_setting *current_setting);
int   router(t_setting *current_setting);
//int   nb_client_connect(t_setting *current_setting);
int   add_players_to_game(t_setting *current_setting);
int   add_energyCell_to_game(t_setting *current_setting);
int   add_player_to_player_list(t_setting *current_setting, t_player *player);
int   add_energyCell_to_energyCell_list(t_setting *current_setting, t_energyCell *energyCell);
int   del_player_from_player_list(t_setting *current_setting, t_player *player);
int   del_energyCell_from_energieCell_list(t_setting *current_setting, t_energyCell *energyCell);
int   check_name_player(t_setting *current_setting, char *name);
int   publisher_waiting_for_players(t_setting *current_setting);
int   create_player(t_setting *current_setting, char *name);
int   initialize_position_x(t_setting *current_setting);
int   initialize_position_y(t_setting *current_setting);
int   check_identity(t_setting *current_setting, char *name);
int   create_and_add_socket_to_setting(t_setting *current_setting);
int   s_send (void *socket, char *string);
char *s_recv (void *socket);
int   s_sendmore (void *socket, char *string);
void s_set_id (void *socket);
char   *forward(t_setting *current_setting, char *name);
char   *backward(t_setting *current_setting, char *name);
char   *leftfwd(t_setting *current_setting, char *name);
char   *rightfwd(t_setting *current_setting, char *name);
char   *jump(t_setting *current_setting, char *name);
char   *right(t_setting *current_setting, char *name);
char   *left(t_setting *current_setting, char *name);

char  *identify(t_setting *current_setting, char *name);
char  *selfid(t_setting *current_setting, char *name);
char   *looking(t_setting *current_setting, char *name);
char  *selfstats(t_setting *current_setting, char *name);
char  *inspect(t_setting *current_setting, char *name, char *nameDemand);
char  *next(t_setting *current_setting, char *name);
char  *gather(t_setting *current_setting, char *name);
char  *attack(t_setting *current_setting, char *name);
char  *watch(t_setting *current_setting, char *name);
char  *foundPresentCell(t_setting *current_setting, t_player  *playerFound, int i);

////////////////FONCTION DE TEST A RETIRER POUR LE RENDU
void  parcours_list_player(t_setting *current_setting);
int   cycle(t_setting *current_setting);
//void   *cycle(t_setting *current_setting);



//void  game(t_setting *current_setting, t_NotificationType notif);
void  *game(void *setting);
//int   waiting_for_players(t_setting *current_setting);
void   *waiting_for_players(void *setting);
int   send_publication(t_setting *current_setting, char *message);
char  *foundPresentCellWithXY(t_setting *current_setting, int x, int y);


/***************TEST COMMANDE *****************/
void  create_client_manuel(t_setting *current_setting);
void  test_rfc_command(t_setting *current_setting);


typedef struct s_setting
{
  char   *rep_port;
  char   *pub_port;
  int   cycle;
  int   verbose;
  char  *logfile;
  //int    size;
  //int     user_connect;
  struct s_gameInfo *gameInfo;
  struct s_sockets *gameSockets;
}       t_setting;

typedef struct s_sockets
{
  void   *context_publisher;
  void   *publisher;
  zsock_t *router;
}       t_sockets;

typedef struct    s_gameInfo
{
  int     map_size;
  int     game_status;
  struct s_player_list *players;
  struct s_energyCell_list *energyCells;
}     t_gameInfo;

typedef struct    s_player
{
  char     *name;
  int      x;
  int      y;
  int      energy;
  int      wait_cycle;
  int      action;
  int      looking; //(left = 0, up = 1, right = 2, down = 3)
  struct s_player    *next;
  struct s_player    *prev;
}     t_player;

typedef struct    s_player_list
{
  int     nb_elem;
  struct s_player *first;
  struct s_player *last;
}     t_player_list;

typedef struct    s_energyCell_list
{
  int     nb_elem;
  struct s_energyCell *first;
  struct s_energyCell *last;
}     t_energyCell_list;

typedef struct    s_energyCell
{
  int     x;
  int     y;
  int     value;
  struct s_energyCell    *next;
  struct s_energyCell    *prev;
}     t_energyCell;
/*
typedef	struct		s_friend
{
  int			nb_elem;
  struct s_creature	*first;
  struct s_creature	*last;
}			t_friend;


*/
typedef enum NotificationType 
{
  cycle_info = 0,
  game_started = 1,
  game_finished = 2,
  client_dead = 3,
  client_win = 4
}   t_NotificationType;

typedef struct    s_notification
{
  enum  t_NotificationType *notification; 
  // entier représentant le type de notification
  char  *data; // type variable en fonction de la notification
}   t_notification;

typedef struct      s_command
{
  char        *str;
  char       *(*fonc)(t_setting *current_setting, char *name);
}       t_command;

#endif			/* ! MY_H_ !*/
 