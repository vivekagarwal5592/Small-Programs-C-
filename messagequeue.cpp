#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
using namespace std;
struct msgbuffer{
	public:
   long mtype;
   char messageContent[1024];
};



void *msg_rcv(void*){
	
	for(;;){
	
key_t key = 111;
int msg_flag = 0666;
		msgbuffer rbuf;
int message_id = msgget(key,msg_flag);
msgrcv(message_id , &rbuf, 1024, 1, 0);
	cout << "friend:" << rbuf.messageContent << endl;
}

}

 void msgsend(){
			size_t bufflen;
	key_t key = 222;
	int msg_flag = IPC_CREAT | 0666;
			int msg_id;
	msgbuffer buffer;
			msg_id = msgget(key,msg_flag);	
		buffer.mtype = 1;
	char message[1000];
			string msg;
	cin.ignore(); 
			 getline(cin, msg); 
			strcpy(message, msg.c_str());
	strcpy (buffer.messageContent,message);
   			 bufflen = sizeof(buffer.messageContent);
	msgsnd(msg_id,&buffer,bufflen,IPC_NOWAIT);
}

int main(){
  
   int rc;
 			pthread_t t;
 rc = pthread_create(&t, NULL, 
                          msg_rcv, NULL);
  for(;;){
  				msgsend();	
  }	
			return 0;
}

 

