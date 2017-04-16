#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#define TAM 1024
#define FILENAME "received.csv"

int main( int argc, char *argv[] ) {
	int sockfd, puerto, n, tamano_direccion;
	struct sockaddr_in dest_addr;
	struct hostent *server;
	char buffer[TAM];
	char buffer_send[TAM];
	FILE* f_received;

	f_received=fopen(FILENAME, "w");
	if(f_received==NULL)
	{
		printf("ERROR AL ABRIR EL ARCHIVO.");
		exit(0);
	}

	if (argc < 3) {
		fprintf( stderr, "Uso %s host puerto\n", argv[0] );
		exit(0);
	}

	server = gethostbyname( argv[1] );
	if ( server == NULL ) {
		fprintf( stderr, "ERROR, no existe el host\n");
		exit(0);
	}

	puerto = atoi( argv[2] );
	sockfd = socket( AF_INET, SOCK_DGRAM, 0 );
	if (sockfd < 0) {
		perror( "apertura de socket" );
		exit( 1 );
	}

	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons( atoi( argv[2] ) );
	dest_addr.sin_addr = *( (struct in_addr *)server->h_addr );
	memset( &(dest_addr.sin_zero), '\0', 8 );

	printf( "Ingrese el mensaje a transmitir: " );
	memset( buffer, 0, TAM );
	fgets( buffer, TAM, stdin );

	tamano_direccion = sizeof( dest_addr );
	n = sendto( sockfd, (void *)buffer, TAM, 0, (struct sockaddr *)&dest_addr, tamano_direccion );
	if ( n < 0 ) {
		perror( "Escritura en socket" );
		exit( 1 );
	}
	while(1)
	{
		memset( buffer, 0, sizeof( buffer ) );
		n = recvfrom( sockfd, (void *)buffer, TAM, 0, (struct sockaddr *)&dest_addr, &tamano_direccion );
		if ( n < 0 ) {
			perror( "Lectura de socket" );
			exit( 1 );
		}
		//printf("%s\n", buffer);
		
		if(!strcmp(buffer, "END_CODE"))
			break;
			
		//fprintf(f_received, "%s", buffer);
		fwrite(buffer , 1 , TAM , f_received );
		memset( buffer_send, 0, sizeof( buffer ) );
		strcpy(buffer_send, "Send more please");
		n = sendto( sockfd, (void *)buffer_send, TAM, 0, (struct sockaddr *)&dest_addr, tamano_direccion );
		if ( n < 0 ) {
			perror( "Escritura en socket" );
			exit( 1 );
		}
	}
	fclose(f_received);
	close(sockfd);
	return 0;
} 
