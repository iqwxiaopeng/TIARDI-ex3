#pragma once
#include "SynchronousEventDemultiplexerInterface.h"
#include "EventHandlerInterface.h"
#include <list>
#include "SOCK_Stream.h"
#include "SOCK_Acceptor.h"
#include "INET_Addr.h"

using namespace std;

class SynchronousEventDemultiplexerSock : public SynchronousEventDemultiplexerInterface, public EventHandlerInterface  {
private:
	list<SOCK_Stream*> socketList; 
	SOCK_Acceptor* acceptorPtr;

	fd_set readfds;
	fd_set writefds;
	fd_set Errorfds;

	void prepFdsSet(); 

public:
	SynchronousEventDemultiplexerSock(INET_Addr addr); 
	~SynchronousEventDemultiplexerSock();
	NetworkEvent getNetworkEvent();
	void handleEvent(Handle* handle);

	
};