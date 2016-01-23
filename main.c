/* All code provided is as is 
 * and not completely tested
 *
 * Author: Aadil Rizvi
 * Date: 22/1/2016
 *
 * Website: arembedded.com
*/

#include <thread1.h>
#include <thread2.h>

pthread_t thread1;
pthread_t thread2;

void sig_handler(int signum) {
    if (signum != SIGINT) {
        printf("Received invalid signum = %d in sig_handler()\n", signum);
        ASSERT(signum == SIGINT);
    }

    printf("Received SIGINT. Exiting Application\n");

    pthread_cancel(thread1);
    pthread_cancel(thread2);

    mq_close(thread2_mq);
    mq_unlink(THREAD2_MQ_NAME);

    exit(0);
}

int main(void) {
    pthread_attr_t attr;
    int status; 

    signal(SIGINT, sig_handler);

    thread1_init();
    thread2_init();

    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, 1024*1024);
    
    printf("Creating thread1\n");
    status = pthread_create(&thread1, &attr, (void*)&thread1_main, NULL);
    if (status != 0) {
        printf("Failed to create thread1 with status = %d\n", status);
        ASSERT(status == 0);
    }    

    printf("Creating thread2\n");
    status = pthread_create(&thread2, &attr, (void*)&thread2_main, NULL);
    if (status != 0) {
        printf("Failed to create thread2 with status = %d\n", status);
        ASSERT(status == 0);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

