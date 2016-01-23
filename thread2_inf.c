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

void thread2_send_data_u32(uint32_t data_u32) {
    int status;
    thread2_mq_msg_t send_msg;

    send_msg.type = DATA_TYPE_U32;
    send_msg.data.data_u32 = data_u32;

    status = mq_send(thread2_mq, (const char*)&send_msg, sizeof(send_msg), 1);
    ASSERT(status != -1);
}

void thread2_send_data_i32(int32_t data_i32) {
    int status;
    thread2_mq_msg_t send_msg;

    send_msg.type = DATA_TYPE_I32;
    send_msg.data.data_i32 = data_i32;

    status = mq_send(thread2_mq, (const char*)&send_msg, sizeof(send_msg), 1);
    ASSERT(status != -1);
}

void thread2_send_data_u16(uint16_t data_u16) {
    int status;
    thread2_mq_msg_t send_msg;

    send_msg.type = DATA_TYPE_U16;
    send_msg.data.data_u16 = data_u16;

    status = mq_send(thread2_mq, (const char*)&send_msg, sizeof(send_msg), 1);
    ASSERT(status != -1);
}

void thread2_send_data_i16(int16_t data_i16) {
    int status;
    thread2_mq_msg_t send_msg;

    send_msg.type = DATA_TYPE_I16;
    send_msg.data.data_i16 = data_i16;

    status = mq_send(thread2_mq, (const char*)&send_msg, sizeof(send_msg), 1);
    ASSERT(status != -1);
}

void thread2_send_data_u8(uint8_t data_u8) {
    int status;
    thread2_mq_msg_t send_msg;

    send_msg.type = DATA_TYPE_U8;
    send_msg.data.data_u8 = data_u8;

    status = mq_send(thread2_mq, (const char*)&send_msg, sizeof(send_msg), 1);
    ASSERT(status != -1);
}

void thread2_send_data_f32(float data_f32) {
    int status;
    thread2_mq_msg_t send_msg;

    send_msg.type = DATA_TYPE_F32;
    send_msg.data.data_f32 = data_f32;

    status = mq_send(thread2_mq, (const char*)&send_msg, sizeof(send_msg), 1);
    ASSERT(status != -1);
}

void thread2_send_data_str(char* data_str) {
    int status;
    thread2_mq_msg_t send_msg;

    ASSERT(data_str != NULL);

    send_msg.type = DATA_TYPE_STR;
    snprintf(send_msg.data.array, DATA_STR_LEN, "%s", data_str);

    status = mq_send(thread2_mq, (const char*)&send_msg, sizeof(send_msg), 1);
    ASSERT(status != -1);
}




