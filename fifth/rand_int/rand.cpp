//
// Created by sergeyampo on 05.12.2020.
//
#include <random>
#include <iterator>
#include <cstdint>
#include <algorithm>
#include <execution>


using namespace std;

template <typename T>
T rand_int(const T& from, const T& to) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<T> dis(from, to);

  return dis(gen);
}

template <typename Cont>
Cont& fulfill_container_rand(Cont& cont, const int64_t& beg, const int64_t& end){
  generate(execution::par_unseq, std::begin(cont), std::end(cont), [&]() -> int64_t { return rand_int(beg, end); });

  return cont;
}