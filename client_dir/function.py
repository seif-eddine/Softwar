#>>>>>>>>>>>>>>>>>>>>>>>>>>
#Include des fichier python
#>>>>>>>>>>>>>>>>>>>>>>>>>>

from client import robot

import time
import zmq

#>>>>>>>>>>>>>>>>
#Lancement du jeu
#>>>>>>>>>>>>>>>>

game = robot();

#>>>>>>>>>>>>>>>>>
#Lancement de l'IA
#>>>>>>>>>>>>>>>>>
port = game.init_client();
portSUB = game.init_client_publisher();

#id = game.zmq_init(port, game.identity);
game.worker.setsockopt(zmq.IDENTITY, game.identity)
game.worker.connect("tcp://localhost:" + port)
message = "";
game_start = "";
i = 0;
while message != "ok|null":
 print("Je rentre");
 game.worker.send(game.command[0] + "|" + game.identity);
 message = game.worker.recv();
 print("[" + game.identity + "] : ", message);
 print("tour : " + str(i))
 i = i + 1;

game.zmq_init_publisher(portSUB);

while True:
	game.worker.send(game.command[1] + "|null");
	message = game.worker.recv();
	print("Receiv = ", message)	
                #if (enemy en (1)
	#game.g_Command(game.command[12]);
        """game.g_Command(game.command[13], game.c13);
                #if enemy - d'energie
        game.g_Command(game.command[10], game.c10);
                #else enemy + d'energie
        game.g_Command(game.command[2], game.c2);
                #if (enemy en (2)
        game.g_Command(game.command[12], game.c12);
        game.g_Command(game.command[13], game.c13);
                #if enemy - d'energie
        game.g_Command(game.command[1], game.c1);
        game.g_Command(game.command[6], game.c6);
                #if enemy + d'energie
        game.g_Command(game.command[3], game.c3);
                #if (enemy en (3)
        game.g_Command(game.command[12], game.c12);
        game.g_Command(game.command[13], game.c13);
                #if enemy - d'energie
        game.g_Command(game.command[1], game.c1);
        game.g_Command(game.command[10], game.c10);
                #if enemy + d'energie
        game.g_Command(game.command[2], game.c2);
                #if (enemy en (4)
        game.g_Command(game.command[12], game.c12);
        game.g_Command(game.command[13], game.c13);
                #if - d'energie
        game.g_Command(game.command[1], game.c1);
        game.g_Command(game.command[4], game.c4);
                #if + d'energie
        game.g_Command(game.command[3], game.c3);
                #if (energy en 1 / 2 / 3 / 4
        game.g_Command(game.command[3], game.c12);
                #if max
        print("Energy to the maximum.")
                #if moin && (1)
        game.g_Command(game.command[8], game.c8);
                #if moin && (2)
        game.g_Command(game.command[1], game.c1);
        game.g_Command(game.command[6], game.c6);
                #if moin && (3)
        game.g_Command(game.command[1], game.c1);
        game.g_Command(game.command[8], game.c8);
                #if moin && (4)
        game.g_Command(game.command[1], game.c1);
        game.g_Command(game.command[5], game.c5);"""
