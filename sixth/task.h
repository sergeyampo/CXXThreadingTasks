//
// Created by sergeyampo on 21.12.2020.
//

#ifndef OPENMPLABS_SIXTH_TASK_H_
#define OPENMPLABS_SIXTH_TASK_H_

#include <vector>
#include <stdint.h>
#include <omp.h>

long double omp_task(const std::vector<int64_t>&, const std::vector<int64_t>&);
long double omp_task_alt(const std::vector<int64_t>&, const std::vector<int64_t>&);
long double omp_task_critical(const std::vector<int64_t>&, const std::vector<int64_t>&);
long double omp_task_barrier(const std::vector<int64_t>&, const std::vector<int64_t>&);
long double omp_task_reduction(const std::vector<int64_t>&, const std::vector<int64_t>&);

#endif //OPENMPLABS_SIXTH_TASK_H_
