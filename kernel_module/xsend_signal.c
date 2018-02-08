#include <stdlib.h>
#include <signal.h>
int main(int argc, char* argv)
{
	if(argc==1)
		return -1
	else
	{
		int pid=atoi(argv[1]);
		kill(pid,SIGALRM);
	}
	return 0;
}
