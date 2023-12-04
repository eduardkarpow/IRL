#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_SENDER_THREADS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int message_count = 0;
struct message {
        int id;
        char text[100];
};
struct message message_queue[10];

//Отправкка сообщений
void* message_sender(void* arg) {
   while (1) {
      pthread_mutex_lock(&mutex);
      int rc = pthread_cond_wait(&cond, &mutex);
      if (rc == 0) {
          while(message_count!=0){
               struct message msg = message_queue[message_count - 1];
               printf("Message Sent: ID %d, Message: %s\n", msg.id, msg.text);
               message_count--;
           }
      }

                pthread_mutex_unlock(&mutex);
    }
}

//Генерация сообщений
void* message_generator(void* arg) {
        srand(time(NULL));
        int id = *(int*)arg;
        int counter = 0;
        while (1) {
                pthread_mutex_lock(&mutex);

                struct message new_msg;
                new_msg.id = id;
                sprintf(new_msg.text, "Hello message %d", counter++);

                message_queue[message_count] = new_msg;
                message_count++;

                pthread_cond_signal(&cond);
                pthread_mutex_unlock(&mutex);
                sleep(rand()%5);
        }
}
int main() {
        pthread_t sender_thread;
        pthread_t sender_threads[NUM_SENDER_THREADS];
        pthread_create(&sender_thread, NULL, message_sender, NULL); // Поток отправки сообщений
        int i;
        int thread_ids[NUM_SENDER_THREADS];
        for (i = 0; i < NUM_SENDER_THREADS; ++i) {
                thread_ids[i] = i + 1;
                pthread_create(&sender_threads[i], NULL, message_generator, &thread_ids[i]);
        }
        for (i = 0; i < NUM_SENDER_THREADS; ++i) {
                pthread_join(sender_threads[i], NULL);
        }
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
        return 0;
}

