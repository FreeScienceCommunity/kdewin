
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

int verbose = 0;

int main(int c, char **argv)
{
    struct timeval  tv, tt;
    long long int t1, t2;
/* misissue for setenv() test
    char szBuf[30];
    char *lpBuf;

    setenv("test", "1", 0);
    GetEnvironmentVariableA("test", szBuf, 20);
    lpBuf = getenv("test");
*/
    gettimeofday(&tv, NULL);
    t1 = ((long long int)tv.tv_sec) * 1000000LL + tv.tv_usec;
		if (verbose) {
			printf("1 sec:  %d\n",tv.tv_sec); 
			printf("1 usec: %d\n",tv.tv_usec); 
			printf("1 sec+usec:  %ld\n",t1); 
		}
		sleep(1);
    gettimeofday(&tt, NULL);
    t2 = ((long long int)tt.tv_sec) * 1000000LL + tt.tv_usec;
		if (verbose) {
			printf("2 sec:  %d\n",tt.tv_sec); 
			printf("2 usec: %d\n",tt.tv_usec); 
			printf("2 usec:  %ld\n",t2); 
			printf("diff usec:  %ld\n",t2-t1); 
		}
		if (t2-t1 != 1000000LL)
			printf("time difference not a second\n");
}
