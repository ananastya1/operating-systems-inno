#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int is_prime(int n)
{
  if (n <= 1)
    return 0;
  for (int d = 2; d * d <= n; d++)
    if (n % d == 0)
      return 0;
  return 1;
}

int primes_count_in_interval(int start, int finish)
{
  int ret = 0;
  for (int i = start; i < finish; i++)
    if (is_prime(i) != 0)
      ret++;
  return ret;
}

// The structure that will be passed to the threads, corresponding to an interval to count the number of primes in.
typedef struct prime_counter_request
{
  int start, finish;
} prime_counter_request;

void *prime_counter(void *arg)
{
    prime_counter_request *my_data = (prime_counter_request *)arg;
    int left = my_data->start;
    int right = my_data->finish;
    //printf("%d %d\n", left, right);
    int * p = malloc(sizeof(int));
    *p = primes_count_in_interval(left, right);
    //printf("%d\n", res);
   // printf("%li %s\n", my_data->thread_id, my_data->message);
    //pthread_exit(0);

    //void * pp = (void *) p;
    return p;
  /*
    TODO
    Complete this function. It takes a primes_counter_request as a parameter and returns the number of primes in the specified interval.

    Be careful how you return the return value.
  */
}

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]), n_threads = atoi(argv[2]);
  int segment_size = n / n_threads;

  pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

  prime_counter_request *requests = malloc(n_threads * sizeof(prime_counter_request));

  void **results = malloc(n_threads * sizeof(void *));
  int l = 0;
  int r = segment_size;
  int amount;

  for (int i = 0; i < n_threads; i++)
  {
    l  += segment_size * ((i==0) ? 0 : 1);
    r += segment_size * ((i==0) ? 0 : 1);
    //printf("%d %d\n", l, r);
    prime_counter_request temp = {l, r};
    requests[i] = temp;
    pthread_create(&threads[i], NULL, prime_counter, (void *)(requests + i));
    /*
      TODO
      Complete this loop. You shall spawn <n_threads> threads, each of which computes the number of primes in a segment of length <segment_size>. The union of those intervals shall correspond to the interval [0, n).

      First, initialize the value of requests[i] with a simple mathematical computation. Be careful not to overrun the last interval.

      Second, spawn a thread that takes requests[i] as an argument. Be careful how you pass the arguments.
    */
  }

  int * res;

  for (int i = 0; i < n_threads; i++)
  {
    pthread_join(threads[i], (void **) &res);
    //printf("%d\n", *res);
    results[i] = res;
    /*
      TODO
      Join the results of threads into the results array.
    */
  }

  int total_result = 0;
  for (int i = 0; i < n_threads; i++) {
        total_result += *(int *)results[i];
  }


    free(results);
    free(threads);
  
  /*
    TODO
    Free the allocated memory.
  */

  printf("%d\n", total_result);

  exit(EXIT_SUCCESS);
}