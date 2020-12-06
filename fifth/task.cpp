///*
// Created by sergeyampo on 05.12.2020.
#include <cstdint>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int64_t task(vector<int64_t>::iterator lhs_beg, vector<int64_t>::iterator lhs_end, vector<int64_t>::iterator rhs_beg, vector<int64_t>::iterator rhs_end){
  int64_t multiplier = 1;
  for(;lhs_beg < lhs_end; ++lhs_beg){
    for(;rhs_beg < rhs_end; ++rhs_beg){
      auto sum = *lhs_beg + *rhs_beg;
      if(sum != 0){
        multiplier *= sum;
      }
    }
  }

  return multiplier;
}
//

