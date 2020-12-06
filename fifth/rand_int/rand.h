//
// Created by sergeyampo on 05.12.2020.
//

#ifndef OPENMPLABS_RAND_INT_RAND_H_
#define OPENMPLABS_RAND_INT_RAND_H_

#include <cstdint>
#include <execution>

template <typename T>
int64_t rand_int(const int64_t&, const int64_t&);

template <typename Cont>
Cont& fulfill_container_rand(Cont&, const int64_t&, const int64_t&);

#include "rand.cpp"

#endif //OPENMPLABS_RAND_INT_RAND_H_
