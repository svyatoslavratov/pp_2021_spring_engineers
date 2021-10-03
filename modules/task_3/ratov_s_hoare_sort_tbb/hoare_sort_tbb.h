#ifndef MODULES_TASK_3_RATOV_S_HOARE_SORT_H_
#define MODULES_TASK_3_RATOV_S_HOARE_SORT_H_

#include <vector>

int partition(std::vector<int> *v, int low, int high);
void hoareSort(std::vector<int> *v, int low, int high);
std::vector<int> merge(const std::vector<int> &v1,
                       const std::vector<int> &v2);

void runHoareSort(std::vector<int> *v, int numThreads = 4);

std::vector<int> getRandomVector(int size, int type = 0);

#endif // MODULES_TASK_3_RATOV_S_HOARE_SORT_H_
