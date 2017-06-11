/*
Jisung Kim	kimjs3115@gmail.com
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>	// Jisung Kim : that is where the clone() is defined.

int g=2;

int sub_func(void *arg)
{
	g++;
	printf("PID(%d) : Child g=%d \n", getpid(), g);
	sleep(2);
	return 0;
}

// Jisung Kim
// Why some people use the function prototype as int main(void) not int main() or void main()?
int main(void)
{
	int pid;
	int child_stack[4096];
	int l = 3;
	printf("PID(%d) : Parent g=%d, l=%d \n", getpid(), g, l);
/*
int clone(int (*fn)(void *), void *child_stack,
                 int flags, void *arg, ... );
I don't understand the purpose of existance of void *child_stack.
why the example arranged additional +4005 for the starting point?
and why the starting point starts from the end of the array but not from the start of the array?
*/
	clone(sub_func, (void *)(child_stack+4095), CLONE_VM | CLONE_THREAD | CLONE_SIGHAND, NULL);
	sleep(1);
	printf("PID(%d) : Parent g=%d, l=%d", getpid(), g, l);
	return 0;
}
