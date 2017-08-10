#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
 
using namespace std;
int global=2;
pid_t process_ID = 0;
main(){
    string process_type;
    int iStack=50;
    pid_t pID = fork();
    if (pID==0) {
   	 process_type = "Child Process: ";
   	 global++;
   	 iStack++;
   	 process_ID = (int) getpid();
   	 execlp("ls", "ls", "-l", "/", NULL);
   	 cout<<"Main program is over"<<endl;
    }
else if (pID > 0) {
	 process_type = "Parent Process: ";
   	 process_ID = (int) getppid();
}
    cout<<process_type;
    cout<<" Global variable: "<<global;
    cout<<" Stack Variable: "<<iStack<<endl;
    cout<<" Process ID is "<<process_ID<<endl;

} 


