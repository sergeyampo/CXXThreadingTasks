#include <iostream>
#include <omp.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include "./rand_int/rand.h"
#include "log_duration/profile.h"
#include "task.h"
#include "libs/CppConsoleTable.hpp"

using namespace std;

int main() {
  const int N = 5000000;
  vector<int64_t> first(N, 0);
  vector<int64_t> second(first);

  fulfill_container_rand(first, -1, 1);
  fulfill_container_rand(second, -1, 1);

  int64_t answer = 0;
 /* {
    LOG_DURATION("Sequence");
	answer = task(begin(first), end(first), begin(second), end(second));
	cout << answer << "\n";
  }*/

  answer = 1;
  {
	LOG_DURATION("Parallel 2");
#pragma omp parallel
	{

#pragma omp sections reduction(*:answer) firstprivate(first, second)
	  {
#pragma omp section
		{
		  answer *= task(begin(first), begin(first) + (N / 2), begin(second), begin(second) + (N / 2));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (N / 2), end(first), begin(second) + (N / 2), end(second));
		}
	  }
	}
  }
  answer = 1;
  {
	LOG_DURATION("Parallel 4");
#pragma omp parallel
	{

#pragma omp sections reduction(*:answer) firstprivate(first, second)
	  {
#pragma omp section
		{
		  answer *= task(begin(first), begin(first) + (N / 4), begin(second), begin(second) + (N / 4));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (N / 4), begin(first) + (N / 2), begin(second) + (N / 4), begin(second) + (N / 2));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (N / 2), begin(first) + (3*N / 4), begin(second) + (N / 2), begin(second) + (3*N / 4));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (3*N / 4), end(first), begin(second) + (3*N / 4), end(second));
		}		
	  }
	}
  }
  answer = 1;
  {
	LOG_DURATION("Parallel 8");
#pragma omp parallel
	{

#pragma omp sections reduction(*:answer) firstprivate(first, second)
	  {
#pragma omp section
		{
		  answer *= task(begin(first), begin(first) + (N / 8), begin(second), begin(second) + (N / 8));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (N / 8), begin(first) + (N / 4), begin(second) + (N / 8), begin(second) + (N / 4));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (N / 4), begin(first) + (3*N / 8), begin(second) + (N / 4), begin(second) + (3*N / 8));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (3*N / 8), begin(first) + (N / 2), begin(second) + (3*N / 8), begin(second) + (N / 2));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (N / 2), begin(first) + (5*N / 8), begin(second) + (N / 2), begin(second) + (5*N / 8));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (5*N / 8), begin(first) + (6*N / 8), begin(second) + (5*N / 8), begin(second) + (6*N / 8));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (6*N / 8), begin(first) + (7*N / 8), begin(second) + (6*N / 8), begin(second) + (7*N / 8));
		}
#pragma omp section
		{
		  answer *= task(begin(first) + (7*N / 8), end(first), begin(second) + (7*N / 8), end(second));
		}
	  }
	}
  }

  cout << answer << "\n";

  return 0;
}
