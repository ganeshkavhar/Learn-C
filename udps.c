#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 

int main() 
{    
    	char msgReceived[255]; 
	char msgforclient[255];
    	int UDPSocket, len; 
    	struct sockaddr_in server_Address, client_Address; 
    	bzero(&server_Address, sizeof(server_Address)); 
	printf("Waiting for the message from the client\n");
    	UDPSocket = socket(AF_INET, SOCK_DGRAM, 0);         
    	server_Address.sin_addr.s_addr = htonl(INADDR_ANY); 
    	server_Address.sin_port = htons(2000); 
    	server_Address.sin_family = AF_INET;  
    	bind(UDPSocket, (struct sockaddr*)&server_Address, sizeof(server_Address)); 
    	len = sizeof(client_Address); 
    	int n = recvfrom(UDPSocket, msgReceived, sizeof(msgReceived),  0, (struct sockaddr*)&client_Address,&len); 
    	msgReceived[n] = '\0'; 
	printf("Message received from the client: ");
    	puts(msgReceived); 
             	printf("Enter the reply to be sent to the client: ");
	gets(msgforclient);
    	sendto(UDPSocket, msgforclient, 255, 0, (struct sockaddr*)&client_Address, sizeof(client_Address)); 
	printf("Reply to the client sent \n");
} 