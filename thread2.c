/* All code provided is as is 
 * and not completely tested
 *
 * Author: Aadil Rizvi
 * Date: 22/1/2016
 *
 * Website: arembedded.com
*/

#include <thread2_inf.h>
#include <thread2.h>

struct mq_attr thread2_mq_attr;
mqd_t thread2_mq;

void thread2_init(void) {

    thread2_mq_attr.mq_maxmsg = 10;
    thread2_mq_attr.mq_msgsize = sizeof(thread2_mq_msg_t);

    thread2_mq = mq_open(THREAD2_MQ_NAME, \
                    O_CREAT | O_RDWR | O_NONBLOCK, \
                    0666, \
                    &thread2_mq_attr);

    ASSERT(thread2_mq != -1);
}

void thread2_main(void) {
    unsigned int exec_period_usecs;
    int status;
    thread2_mq_msg_t recv_msg;

    exec_period_usecs = 10000; /*in micro-seconds*/

    printf("Thread 2 started. Execution period = %d uSecs\n",\
                                           exec_period_usecs);

    while(1) {
        status = mq_receive(thread2_mq, (char*)&recv_msg, \
                            sizeof(recv_msg), NULL);

        if (status == sizeof(recv_msg)) {

            switch(recv_msg.type) {
                case DATA_TYPE_U32:
                    printf("Received data type:   U32,   value = %u\n",\
                            recv_msg.data.data_u32); 
                    break;         
                case DATA_TYPE_I32:
                    printf("Received data type:   I32,   value = %d\n",\
                            recv_msg.data.data_i32); 
                    break;         
                case DATA_TYPE_U16:
                    printf("Received data type:   U16,   value = %hu\n",\
                            recv_msg.data.data_u16); 
                    break;         
                case DATA_TYPE_I16:
                    printf("Received data type:   I16,   value = %hd\n",\
                            recv_msg.data.data_i16); 
                    break;         
                case DATA_TYPE_U8:
                    printf("Received data type:   U8,    value = %hhu\n",\
                            recv_msg.data.data_u8); 
                    break;         
                case DATA_TYPE_F32:
                    printf("Received data type:   F32,   value = %f\n",\
                            recv_msg.data.data_f32); 
                    break;         
                case DATA_TYPE_STR:
                    printf("Received data type:   STR,   value = %s\n",\
                            recv_msg.data.array); 
                    break;         
                default:
                    printf("Received invalid data type\n");
                    ASSERT(0);
                    break;         
            }
        }
 
        usleep(exec_period_usecs);
    }
}

