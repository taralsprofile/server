// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>

#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;


typedef  short int RET_COD;
#define SUCCESS	0
#define FAIULRE 1
#define PORT 5555


int ADD(int a, int b, int* c)
{
	*c = a + b;
	return a + b;
}




int main()
{
	

	RET_COD lnRetCode = SUCCESS;
	WSADATA wsadata;

	//removing some dummy chnages
	lnRetCode = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (0 != lnRetCode)
	{
		printf("WSAstartup failed");
	}

	SOCKET hServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == hServerSocket )
	{
		printf("socket Failed");
	}

	SOCKADDR_IN lstSockeAddr;
	lstSockeAddr.sin_addr.S_un.S_addr = inet_addr("192.168.0.107");
	lstSockeAddr.sin_family = AF_INET;
	lstSockeAddr.sin_port = htons(PORT);
	lnRetCode = bind(hServerSocket, (SOCKADDR*)&lstSockeAddr, sizeof(SOCKADDR));
	if (0 != lnRetCode)
	{
		printf("bind FAiled");
	}

	lnRetCode = listen(hServerSocket, SOMAXCONN);
	if (0 != lnRetCode)
	{
		printf("listen FAiled");
	}

	SOCKET hClientSocket = INVALID_SOCKET;
	int nAddrLengtht = sizeof(SOCKADDR);
	hClientSocket = accept(hServerSocket, (SOCKADDR*)& lstSockeAddr, &nAddrLengtht);
	if (INVALID_SOCKET == hClientSocket)
	{
		printf("Accept Failed");
	}

	printf("Client Connected IP: %s", inet_ntoa(lstSockeAddr.sin_addr));
	printf("PORT %d", ntohs(lstSockeAddr.sin_port));

		_getch();


	return 0;
}

