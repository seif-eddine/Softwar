/*
** parse.c for parse.c in /home/marvyne/repertoire_rendu/C/SoftWar/git_repot/Soft_War/final/server_dir
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct  5 14:08:43 2017 TOKPAHOLOU Marvyne
** Last update Thu Oct  5 14:08:46 2017 TOKPAHOLOU Marvyne
*/
#include "../my.h"
static int verbose_flag;
        static struct option long_options[] =
          {
            {"rep-port",  required_argument, 0, 'r'},
            {"pub-port",    required_argument, 0, 'p'},
            {"cycle",    required_argument, 0, 'c'},
            {"v",    no_argument, &verbose_flag, 'v'},
            {"log",    required_argument, 0, 'l'},
            {"size",    required_argument, 0, 's'},
            {0, 0, 0, 0}
          }; 

int parse(int argc, char **argv, t_setting *current_setting)
{
  int option_index = 0;
  int c;
  int cycle;
  int log;
  int goodArgument;
  //int allOptionMandatory;

  //allOptionMandatory = 0;
  /*if (argc >= 2)
  {*/
  cycle = -1;
  log = -1;
  goodArgument = 0;
    while ((c = getopt_long (argc, argv, "r:p:c:l:s:", long_options, &option_index)) != -1)
      {

          //c = getopt_long (argc, argv, "rp", long_options, &option_index);
          
        //if (c == -1)
          //break;
        switch (c)
          {
          case 0:
            if (long_options[option_index].flag != 0)
              break;
            printf ("option %s", long_options[option_index].name);
            if (optarg)
              printf (" with arg %s", optarg);
            printf ("\n");
            break;
          /*case 'v':
            puts ("option -v\n");
            break;*/
          case 'r':
            printf("Option -rep-port with value %s\n", optarg);
            current_setting->rep_port = optarg;
            puts ("option -rep-port\n");
            break;
          case 'p':
            printf("Option -pub-port with value %s\n", optarg);
            current_setting->pub_port = optarg;
            puts ("option -pub-port\n");
            break;
          case 'c':
          printf("Option -cycle with value %s\n", optarg);
          cycle = (int)atol(optarg);
            puts ("option -cycle\n");
          current_setting->cycle =  atoi(optarg);
            break;
          case 'l':
          printf("Option -log with value %s\n", optarg);
          log = (int)atol(optarg);
            puts ("option -log\n");
          current_setting->logfile = optarg;
            break;
          case 's':
          printf("Option -size with value %s\n", optarg);
          current_setting->gameInfo->map_size =  atoi(optarg);
            puts ("option -size\n");
             //allOptionMandatory++;
            break;
          case '?':
            printf("Invalid option\n");
            break;
           default:
            abort();
            //printf("Using : --rep-port [PORT] --pub-port [PORT] --cycle [INT] -v [VERBOSE] --log [FILE] --size [SIZE_MAP]\n");
          }
      }
      if (verbose_flag)
      {
        puts ("verbose flag is set");
        current_setting->verbose = 1;
      }

      /* Print any remaining command line arguments (not options). */
      if (optind < argc)
        {
          printf ("non-option ARGV-elements: ");
          while (optind < argc)
            printf ("%s ", argv[optind++]);
          putchar ('\n');
        }
        if (log == -1) {
          printf("--log is mandatory!\n");
          goodArgument++;
       }
       if (cycle == -1) {
          printf("--cycle is mandatory!\n");
          goodArgument++;
       }
      /*if (allOptionMandatory == 3)
      {
        printf("Les options obligatoires sont présentent 2\n");
        
        current_setting->rep_port = arg_rep_port;
        current_setting->pub_port = arg_pub_port;
        current_setting->verbose = 1;
        current_setting->cycle = arg_cycle;
        current_setting->logfile = arg_logfile;
        current_setting->size = arg_size;
        
        //Pour le test les données seront entrée en dure
        current_setting->cycle = 500;
        return (0);
      }
      else
      {
        printf("Using : --rep-port [PORT] --pub-port [PORT] --cycle [INT] -v [VERBOSE] --log [FILE] --size [SIZE_MAP]\n");
          return (1);
      }*/
    //}
    /*else
      printf("Using : --rep-port [PORT] --pub-port [PORT] --cycle [INT] -v [VERBOSE] --log [FILE] --size [SIZE_MAP]\n");*/

  if (goodArgument == 0)
    return (0);
  else
    return(1);
}

