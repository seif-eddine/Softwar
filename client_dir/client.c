#include "../zhelpers.h"
int main()
{
  srand(time(NULL));
  void *context = zmq_ctx_new ();
  //void *context = zctx_new();
  char  identity[10];
  char  real_identity[5];
  int   random_nb;

  void *subscriber = zmq_socket (context, ZMQ_SUB);
  zmq_connect (subscriber, "tcp://localhost:6000");
  zmq_setsockopt (subscriber, ZMQ_SUBSCRIBE, "", 0);
    //zsocket_set_subscribe (subscriber, "softwar");
    printf("1\n");
    sleep (1);
    //////////////////////
  void *dealer = zmq_socket(context, ZMQ_DEALER);
    //s_set_id (dealer);
    //zmq_connect (dealer, "tcp://localhost:7000");


    /////////////////////////
//char *s = s_recv (subscriber);
        //printf("%s\n", s);
    //  0MQ is so fast, we need to wait a while...
    
  //  Second, synchronize with publisher
    //void *syncclient = zmq_socket (context, ZMQ_REQ);
    //zmq_connect (syncclient, "tcp://localhost:4545");

    //  - send a synchronization request
    //s_send (syncclient, identity);
     //zmq_send (syncclient, "", strlen (""), 0);

    //  - wait for synchronization reply
    //char *string = s_recv (syncclient);
    //free (string);

    //  Third, get our updates and report how many we got

    //  - send a synchronization request
    /*s_send (dealer, "");

    //  - wait for synchronization reply
    char *string = s_recv (dealer);
    free (string);
    printf("2\n");
    while (1) {
      printf("3\n");
        char *string = s_recv (subscriber);
        printf("4\n");
        printf("%s\n", string);
        if (strcmp (string, "Waiting") == 0) {
            free (string);
            break;
        }
        free (string);
    }
    printf("%s\n", "J'ai reçu le waiting");
    */
    int update_nbr = 0;
    int findIdentity = 0;
    while (findIdentity == 0) {
      random_nb = rand()%10;
      sprintf (identity, "identity|#0x0%01X", random_nb);
      printf("Identité demandé : %s\n", identity);
      sprintf(real_identity, "#0x0%01X", random_nb);
      zmq_setsockopt (dealer, ZMQ_IDENTITY, real_identity, strlen (real_identity));
      zmq_connect (dealer, "tcp://localhost:7000");
      sleep(1);
       s_sendmore(dealer, "");
       s_sendmore(dealer, identity);
       printf("0\n");
        s_send(dealer, identity);
        printf("1\n");
        //free(s_recv(dealer));     //  Envelope delimiter
        printf("2\n");
        //sleep(2);
        char *string = s_recv (dealer);
        printf("Received ||: |%s|\n", string);
        printf("3\n");
        printf("%s\n", string);
        if (strcmp (string, "ok|null") == 0) {
          printf("4\n");
            free (string);
            printf("5\n");
            //sprintf(real_identity, "#0x0%01X", random_nb);
            //zmq_setsockopt (dealer, ZMQ_IDENTITY, real_identity, strlen (real_identity));
            printf("%s\n", "Identité validé");
            findIdentity = 1;
            break;
        }
        else
          printf("%s\n", "ko");
        //free (string);
        //free(s_recv(dealer)); 
        //free(s_recv(dealer)); 
        update_nbr++;
    }
    printf ("Received %d updates\n", update_nbr);
    
    /*while(!zctx_interrupted) {
        zmsg_t *msg = zmsg_new();
        msg = zmsg_recv (subscriber);
      printf("message size = %d\n" + zmsg_size(msg));
  
        int i;
      for (i = 0; i < zmsg_size(msg); i++) {
          printf("Data frame %d is %s\n", i, zframe_data(zmsg_next(msg)));
      }
      zmsg_destroy (&msg);
    }*/


    zmq_close (subscriber);
    //zmq_close (syncclient);
    zmq_ctx_destroy (context);
    return (0);
}