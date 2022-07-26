#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<cstring>
using namespace std;

int main(int argc, char* argv[]){
	//while(1){
	int status;
    	char* argument_list[argc]; 
    	pid_t pid;
    	int j=0;
    	cout<<"No. of arguments: "<<argc<<"\n";
  
    	
	//copy argv into argument_list such that argument_list[0]=argv[1] because argv[0] on cmd line has ./filename.out as the zeroth 		argument which we dont want to pass to execvp()
	
	
	for(int i=1;i<argc;++i){
		// just for test purpose; print argv[]
		cout<<argv[i]<<"\n";
		// now copy
		argument_list[j]=argv[i];
		++j;
	}
	argument_list[j]=0;
	
	
	// just for test purpose; print argument_list[]
	for(int i=0;i<argc-1;++i){
		//cout<<argv[i]<<"\n";
		cout<<argument_list[i]<<"\n";
		
	}
	
	//store the command separately
	
	const char* command = argument_list[0];
	
	
	pid = fork();
	
	if (pid < 0) {     // fork a child
          cout<<"*** ERROR: forking child process failed"<<"\n";
          exit(1);
     	}
	else if (pid==0){
		//just for test purpose cout in child
		cout<<"In Child"<<"\n";
		if (strcmp(argument_list[0], "exit") == 0)  
               	exit(0);
               	//just for test purpose this line should not print exited if exit 0
               	cout<<"exited"<<"\n";	
		if(execvp(command,argument_list)==-1)
			{perror("Child process end because execvp() failed");}
			exit(0);
	}
	else{
		while (wait(&status) != pid){
			cout<<"Waiting for child"<<"\n";
		
		}
	
	}
	
 //} 	
}
