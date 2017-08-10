#include <iostream>
#include <stdlib.h>
#include <pthread.h>
using namespace std;
void *print_message_function( void *ptr )
{
char *message;
message = (char *) ptr;
cout << message << endl;
}
main()
{
pthread_t thread1, thread2;
char *message1 = "Thread 1";
char *message2 = "Thread 2";
int  iret1, iret2;
iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
pthread_join( thread1, NULL);
pthread_join( thread2, NULL); 
cout << "Thread 1 returns: " << iret1 << endl;
cout << "Thread 2 returns: " << iret2 << endl;
exit(0);
}

