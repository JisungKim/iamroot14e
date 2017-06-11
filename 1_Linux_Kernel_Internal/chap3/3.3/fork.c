/*
Jisung Kim	kimjs3115@gmail.com
*/
#include <unistd.h>
#include <sys/types.h>	// Jisung Kim : it is where pid_t, wait(), and etc are defined.
#include <stdio.h>
#include <stdlib.h>

int g = 2;

int main()
{
	pid_t pid;
	int l = 3;
	int status = 0;

	printf("PID(%d): Parent g=%d, l=%d \n", getpid(), g, l);

	if((pid=fork())<0) {
		perror("fork error!");
		exit(1);
	} else if (pid == 0) {
		g++;
		l++;
	} else {
		// Jisung Kim
		// Please refer to the man 2 wait.
		// OSX: the wait function needs additional parameter that is used to store the return status of the child process.
		wait(&status);
	}

	printf("PID(%d): g=%d, l=%d \n", getpid(), g, l);
	return 0;
}
