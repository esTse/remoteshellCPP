#include <unistd.h>
#include <arpa/inet.h>//Para internet
#include <iostream>
#include <string.h>//Para strings
#include <stdlib.h>
#include <cerrno>//Para los errores

using namespace std;

int open_socket();
void blind_to_port(int,int);

int main(){
	string comando;
	int bufsize;
	const int PORT = 6500;
	char buffer[2048];

	int listener = open_socket();
	blind_to_port(listener,PORT);
	if(listen (listener, 10) == -1){				
		cout << "No se pueden conectar mas clientes\n"<< strerror(errno);
		return 0;
	}

	cout << "Conexion establecida.\n";
    struct sockaddr_storage cliente; 	
	unsigned int addres_size = sizeof(cliente);
	int aceptar = accept(listener, (struct sockaddr*)&cliente, &addres_size);

	while(1){

  		cout << "\n > ";

			getline(cin,comando);
    		strcpy(buffer,comando.c_str());
			bufsize = strlen(buffer);
			send(aceptar, buffer, bufsize, 0);
			cout << buffer;
		   
	}
}

int open_socket(){
	int socket1 = socket(PF_INET, SOCK_STREAM,0);
	if(socket1 == -1){								
		cout << "Error al abrir el socket.\n" << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}
}

void blind_to_port(int socket, int port){
	struct sockaddr_in name;
		name.sin_family = PF_INET;
		name.sin_port = ((in_port_t)htons(port));
		name.sin_addr.s_addr = htonl(INADDR_ANY);

	int enlace = bind(socket, (struct sockaddr*)&name, sizeof(name));
	if(enlace == -1){
		cout << "No se puede enlazar al puerto, la direccion ya esta en uso.\n"<< strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}
}