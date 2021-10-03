#ifndef MODULES_TASK_2_RATOV_S_HOARE_SORT_H_
#define MODULES_TASK_2_RATOV_S_HOARE_SORT_H_

#include <vector>

int partition(std::vector<int> *v, int low, int high);
void hoareSort(std::vector<int> *v, int low, int high);
void merge(std::vector<int> *v, int left, int mid, int right);

void runHoareSort(std::vector<int> *v);

std::vector<int> getRandomVector(int size, int type = 0);

#endif // MODULES_TASK_2_RATOV_S_HOARE_SORT_H_
