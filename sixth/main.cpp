//
// Created by sergeyampo on 21.12.2020.
//
#include "task.h"
#include <iostream>
#include "./rand_int/rand.h"
#include <omp.h>
#include "log_duration/profile.h"

using namespace std;

int main(){
  const int N = 10000;
  vector<int64_t> first(N, 0);
  vector<int64_t> second(first);

  fulfill_container_rand(first, -2, 2);
  fulfill_container_rand(second, -2, 2);

  cout << "Sequential:\n";
  {
	omp_set_dynamic(0);
	omp_set_num_threads(1);
	LOG_DURATION("Sequence time")
	omp_task_alt(first, second);
  }

  cout << "Locks:\n";
  {
	omp_set_dynamic(0);
	omp_set_num_threads(2);
    LOG_DURATION("2 threads")
	omp_task(first, second);
  }

  {
	omp_set_dynamic(0);
	omp_set_num_threads(4);
	LOG_DURATION("4 threads")
	omp_task(first, second);
  }

  {
	omp_set_dynamic(0);
	omp_set_num_threads(8);
	LOG_DURATION("8 threads")
	omp_task(first, second);
  }

  cout << "\nCritical:\n";

  {
	omp_set_dynamic(0);
	omp_set_num_threads(2);
	LOG_DURATION("2 threads")
	omp_task_critical(first, second);
  }

  {
	omp_set_dynamic(0);
	omp_set_num_threads(4);
	LOG_DURATION("4 threads")
	omp_task_critical(first, second);
  }

  {
	omp_set_dynamic(0);
	omp_set_num_threads(8);
	LOG_DURATION("8 threads")
	omp_task_critical(first, second);
  }

  cout << "\nReduction:\n";

  {
	omp_set_dynamic(0);
	omp_set_num_threads(2);
	LOG_DURATION("2 threads")
	omp_task_reduction(first, second);
  }

  {
	omp_set_dynamic(0);
	omp_set_num_threads(4);
	LOG_DURATION("4 threads")
	omp_task_reduction(first, second);
  }

  {
	omp_set_dynamic(0);
	omp_set_num_threads(8);
	LOG_DURATION("8 threads")
	omp_task_reduction(first, second);
  }

  cout << "\nBarrier:\n";

  {
	omp_set_dynamic(0);
	omp_set_num_threads(2);
	LOG_DURATION("2 threads")
	omp_task_barrier(first, second);
  }

  {
	omp_set_dynamic(0);
	omp_set_num_threads(4);
	LOG_DURATION("4 threads")
	omp_task_barrier(first, second);
  }

  {
	omp_set_dynamic(0);
	omp_set_num_threads(8);
	LOG_DURATION("8 threads")
	omp_task_barrier(first, second);
  }

  return 0;
}

