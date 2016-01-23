/* All code provided is as is 
 * and not completely tested
 *
 * Author: Aadil Rizvi
 * Date: 22/1/2016
 *
 * Website: arembedded.com
*/

#include <thread1.h>
#include <thread2_inf.h>

void thread1_init(void) {

    //Nothing right now    

}

void thread1_main(void) {
    unsigned int exec_period_usecs;
    int cnt=0;

    exec_period_usecs = 1000000; /*in micro-seconds*/

    printf("Thread 1 started. Execution period = %d uSecs\n",\
                                           exec_period_usecs);
    while(1) {
        switch (cnt) {

            case 0:
                /* Send a U32 type value on the MQ */
                thread2_send_data_u32(99999999);
                break;
            case 1:
                /* Send an I32 type value on the MQ */
                thread2_send_data_i32(-1324287);
                break;
            case 2:
                /* Send a U16 type value on the MQ */
                thread2_send_data_u16(100);
                break;
            case 3:
                /* Send a I16 type value on the MQ */
                thread2_send_data_i16(-45);
                break;
            case 4:
                /* Send a U8 type value on the MQ */
                thread2_send_data_u8(5);
                break;
            case 5:
                /* Send a F32 type value on the MQ */
                thread2_send_data_f32(3.1415);
                break;
            case 6:
                /* Send a STR type value on the MQ */
                thread2_send_data_str("This is a test str\n");
                break;
            default:
                printf("Invalid counter value in sending thread\n");
                break;
        }

        cnt += 1;

        if (cnt > 6) {
           cnt = 0;
        }
        usleep(exec_period_usecs);
    }
}

