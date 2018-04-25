import sys 
import random 
import zmq 
import time

class robot:
        command = [
                "identify", #0  -> NA
                "forward",  #1  -> 0,5
                "backward", #2  -> 1
                "leftfwd",  #3  -> 1
                "rightfwd", #4  -> 1
                "right",    #5  -> 0,5
                "left",     #6  -> 0,5
                "looking",  #7  -> 0
                "gather",   #8  -> 1
                "watch",    #9  -> 0
                "attack" ,  #10 -> 0,5
                "selfid",   #11 -> 0
                "selfstats",#12 -> 0
                "inspect",  #13 -> 0,5
                "next",     #14 -> 0
                "jump"]     #15 -> 0

        def __init__(self):
                self.nBr = random.randint(0, 9);
                self.clientN = str(self.nBr);
                self.NClientToSend = "#0x0" + self.clientN;
                self.identity = self.NClientToSend;
                self.energy = 50;
                self.energy_e = 45;
                self.actPoint = 1;
                self.port = 7000;
                self.portSUB = 6000;
                self.c0 = 0;
                self.c1 = 0.5;
                self.c2 = 1;
                self.c3 = 1;
                self.c4 = 1;
                self.c5 = 0.5;
                self.c6 = 0.5;
                self.c7 = 0;
                self.c8 = 1;
                self.c9 = 0;
                self.c10 = 0.5;
                self.c11 = 0;
                self.c12 = 0;
                self.c13 = 0.5;
                self.c14 = 0;
                self.c15 = 0;
                self.context = zmq.Context()
                self.worker = self.context.socket(zmq.DEALER)
                self.publisher = self.context.socket(zmq.SUB)

	def init_client(self):
                game = robot();
                if len(sys.argv) > 1:
                        game.port = sys.argv[1];
                print("Client en cour de connection sur le port " + str(game.port))
                print("Le client : " + game.identity + " souhaite ce connecter");
                return (game.port);

        def init_client_publisher(self):
                game = robot();
                if len(sys.argv) > 1:
                        game.portSUB = sys.argv[2];
                print("Client en cour de connection  en publication sur le port " + str(game.portSUB))
                print("Le client : " + game.identity + " souhaite ce connecter");
                return (game.portSUB);

        def g_identity(self, command, command_n):
                game = robot();
                game.worker.send(command + "|" + game.identity);
                message = game.worker.receiv();
                print("message = " + message);

        def g_Command(self, command, port):
                game = robot();
		time.sleep(5)
		print("send en cour ...");
                game.worker.setsockopt(zmq.IDENTITY, game.identity)
		game.worker.connect("tcp://localhost:" + port);
                print(command + "|null");
                game.worker.send(command + "|null");
		print("Send envoye");
                message = game.worker.recv();
                print("[" + game.identity + "] receiv : ", message);

        def zmq_init(self, port, id):
                game = robot();
                game.worker.setsockopt(zmq.IDENTITY, id)
                game.worker.connect("tcp://localhost:" + port)
                message = "";
                game_start = "";
                i = 0;
                while message != "ok|null":
                        print("Je rentre");
                        game.worker.send(game.command[0] + "|" + id);
                        message = game.worker.recv();
                        print("[" + id + "] : ", message);
                        print("tour : " + str(i))
                        i = i + 1;
		return id;

        def zmq_init_publisher(self, port):
                game = robot();
                game.publisher.connect("tcp://localhost:" + port)
                game.publisher.setsockopt(zmq.SUBSCRIBE, "")
                game_start = "";

                print("je vais rentre dans la boucle du publiser")
                while game_start != "GAME START":
                        game_start = game.publisher.recv();
                        print("Recev de game start :" + game_start);
                #time.sleep(1);s
