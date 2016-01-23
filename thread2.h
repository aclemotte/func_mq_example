/* All code provided is as is 
 * and not completely tested
 *
 * Author: Aadil Rizvi
 * Date: 22/1/2016
 *
 * Website: arembedded.com
*/

#ifndef THREAD2_H
#define THREAD2_H

#include <pthread.h>
#include <util/util.h>
#include <mqueue.h>
#include <fcntl.h>

#define THREAD2_MQ_NAME "/thread2_mq"

extern struct mq_attr thread2_mq_attr;
extern mqd_t thread2_mq;

void thread2_main(void);

#endif
