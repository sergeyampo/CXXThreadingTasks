//
// Created by sergeyampo on 21.12.2020.
//
#include "task.h"


long double omp_task(const std::vector<int64_t>& first_vec, const std::vector<int64_t>& second_vec){
  omp_lock_t multiply_lock;
  omp_init_lock(&multiply_lock);
  long double answer = 1.0;
#pragma omp parallel for shared(answer)
	for (int i = 0; i < first_vec.size(); ++i) {
	  for (int j = 0; j < second_vec.size(); ++j) {
		auto sum = first_vec[i] + second_vec[j];
		if (sum != 0) {
		  omp_set_lock(&multiply_lock);
		  answer *= sum;
		  omp_unset_lock(&multiply_lock);
		}
	  }
	}
	omp_destroy_lock(&multiply_lock);

	return answer;
  }

long double omp_task_alt(const std::vector<int64_t>& first_vec, const std::vector<int64_t>& second_vec){
  long double answer = 1.0;
#pragma omp parallel for shared(answer)
  for (int i = 0; i < first_vec.size(); ++i) {
	for (int j = 0; j < second_vec.size(); ++j) {
	  auto sum = first_vec[i] + second_vec[j];
	  if (sum != 0) {
		answer *= sum;
	  }
	}
  }

  return answer;
}

long double omp_task_critical(const std::vector<int64_t>& first_vec, const std::vector<int64_t>& second_vec){
  long double answer = 1.0;
#pragma omp parallel for shared(answer)
  for (int i = 0; i < first_vec.size(); ++i) {
	for (int j = 0; j < second_vec.size(); ++j) {
	  auto sum = first_vec[i] + second_vec[j];
	  if (sum != 0) {
#pragma omp critical
		{
		  answer *= sum;
		}
	  }
	}
  }

  return answer;
}

long double omp_task_reduction(const std::vector<int64_t>& first_vec, const std::vector<int64_t>& second_vec){
  long double answer = 1.0;
#pragma omp parallel for reduction(*:answer)
  for (int i = 0; i < first_vec.size(); ++i) {
	for (int j = 0; j < second_vec.size(); ++j) {
	  auto sum = first_vec[i] + second_vec[j];
	  if (sum != 0) {
		  answer *= sum;
	  }
	}
  }

  return answer;
}

long double omp_task_barrier(const std::vector<int64_t>& first_vec, const std::vector<int64_t>& second_vec) {
  long double answer = 1.0;
  long double result = 1.0;
#pragma omp parallel shared(answer, result)
  {
#pragma omp for
  for (int i = 0; i < first_vec.size(); ++i) {
	for (int j = 0; j < second_vec.size(); ++j) {
	  auto sum = first_vec[i] + second_vec[j];
	  if (sum != 0) {
		answer *= sum;
	  }
	}
  }
#pragma omp barrier
#pragma omp critical
  result *= answer;
}
  return result;
}