#include <iostream>
#include <omp.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include "./rand_int/rand.h"
#include "log_duration/profile.h"
#include "task.h"

using namespace std;

int main() {
  const int N = 5000000;
  vector<int64_t> first(N, 0);
  vector<int64_t> second(first);

  fulfill_container_rand(first, -1, 1);
  fulfill_container_rand(second, -1, 1);

  int64_t answer = 0;
  {
    LOG_DURATION("Sequence");
	answer = task(begin(first), end(first), begin(second), end(second));
	cout << answer << "\n";
  }

  answer = 1;
  int64_t answer_sec = 1;
  {
	LOG_DURATION("Parallel");
	//The task is not created for the omp section
#pragma omp parallel
	{

#pragma omp sections
	  {
#pragma omp section
		{
		  answer *= task(begin(first), begin(first) + (N / 2), begin(second), begin(second) + (N / 2));
		}
#pragma omp section
		{
		  answer_sec *= task(begin(first) + (N / 2), end(first), begin(second) + (N / 2), end(second));
		}
	  }
	}
  }
  cout << answer*answer_sec << "\n";

  return 0;
}
