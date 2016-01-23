/* All code provided is as is
 * and not completely tested
 *
 * Author: Aadil Rizvi
 * Date: 22/1/2016
 *
 * Website: arembedded.com
*/         

#ifndef THREAD2_INF_H
#define THREAD2_INF_H

#include <pthread.h>
#include <util/util.h>
#include <mqueue.h>
#include <fcntl.h>

#define DATA_STR_LEN 30

typedef union my_data_s {
    unsigned int data_u32;
    int data_i32;
    unsigned short int data_u16;
    short int data_i16;
    unsigned char data_u8;
    float data_f32;
    unsigned char array[DATA_STR_LEN];
} thread2_data_t;

typedef struct my_mq_msg_s {
    int type;
    thread2_data_t data;
} thread2_mq_msg_t;

void thread2_send_data_u32(uint32_t data_u32);
void thread2_send_data_i32(int32_t data_i32);
void thread2_send_data_u16(uint16_t data_u16);
void thread2_send_data_i16(int16_t data_i16);
void thread2_send_data_u8(uint8_t data_u8);
void thread2_send_data_f32(float data_f32);
void thread2_send_data_str(char* data_str);

#endif
