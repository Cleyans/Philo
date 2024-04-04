#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/time.h>

// flag -pthread needed

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return (0);
}

// PTHREAD CREATE //
/* ptread_t use to store the thread
&p1 The pointer of the thread that you target
Null second argument = Customization of what you want the thread to do
&routine this is the fonction that you want to use in your thread
Null 4 argument = The argument of the routine
*/

// PTHREAD JOIN (WAITING THE END OF THE THREAD)//
/*
&p1 is thread that you want to wait
the second argument is the return of thread that you can storage
*/

int main(int ac, char *av[])
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    printf("Seconds : %ld\nMicro-seconds : %ld\n", current_time.tv_sec, current_time.tv_usec);

    // pthread_t p1, p2;
    // pthread_mutex_init(&mutex, NULL);
    // pthread_create(&p1, NULL, &routine, NULL);
    // pthread_create(&p2, NULL, &routine, NULL);
    // pthread_join(p1, NULL);
    // pthread_join(p2, NULL);
    // pthread_mutex_destroy(&mutex);
    // printf("%d\n", mails);

}
