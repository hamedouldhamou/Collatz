#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{

int n;
pid_t pid, pid1;

	if (argc == 1) {
		fprintf(stderr,"Usage: ./hw1 <starting value>\n");
		
		return -1;
	}

	n = atoi(argv[1]); //  n is the input starting value
		
	if (n < 0)/* Making sure we do not enter a negative value*/
	{
	fprintf(stderr,"Negative numbers are not accepted\n");
	return -1;
	}
	else/*if n is not negative*/
	{
	pid = fork(); //fork a child process
	if (pid < 0){ /*error occured */
	fprintf(stderr,"Fork Failed\n");
	return 0;
	}	
	else if (pid == 0)/*child process*/
	{
		

		
			
		while (n !=1){ /*Main loop for collatz conjecture*/
		printf("%d,",n); //Print n
		if(n%2 ==0){ // if n is even

			n = n/2;
		}
		else 		// if n is odd
		{
			n=3*n+1;		
		}
		}
		printf("1\n");// after the loop end we print out 1
		pid1 = getpid();
		printf("child: pid = %d\n",pid);
		printf("child: pid1= %d\n",pid1);
		

	}
	else {/* parent process*/
	pid1 = getpid();
	wait(NULL);
	printf("parent :pid= %d\n",pid);
	printf("parent :pid1= %d\n",pid1);
	}

	}
	return 0;
}
