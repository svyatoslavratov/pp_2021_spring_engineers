#include <random>
#include <limits>
#include <functional>
#include <algorithm>
#include <stdexcept>

#include "../../../modules/task_1/ratov_s_hoare_sort/hoare_sort.h"

int partition(std::vector<int> *v, int low, int high)
{
    int pivot = v->at(high);
    int smallerElementIndex = low - 1;

    for (int i = low; i < high; ++i)
    {
        if (v->at(i) < pivot)
        {
            std::swap(v->at(++smallerElementIndex), v->at(i));
        }
    }

    std::swap(v->at(smallerElementIndex + 1), v->at(high));

    return smallerElementIndex + 1;
}

void hoareSort(std::vector<int> *v, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(v, low, high);
        hoareSort(v, low, partitionIndex - 1);
        hoareSort(v, partitionIndex + 1, high);
    }
}

void merge(std::vector<int> *v, int left, int mid, int right)
{
    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = left;
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    while (leftIndex < sizeLeft && rightIndex < sizeRight)
    {
        if (v->at(left + leftIndex) <= v->at(mid + 1 + rightIndex))
        {
            v->at(mergedIndex) = v->at(left + leftIndex);
            leftIndex++;
        }
        else
        {
            v->at(mergedIndex) = v->at(mid + 1 + rightIndex);
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < sizeLeft)
    {
        v->at(mergedIndex) = v->at(left + leftIndex);
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < sizeRight)
    {
        v->at(mergedIndex) = v->at(mid + 1 + rightIndex);
        rightIndex++;
        mergedIndex++;
    }
}

void runHoareSort(std::vector<int> *v)
{
    int numSegments = 4;
    int elementsPerSegment = v->size() / numSegments + ((v->size() % numSegments == 0) ? 0 : 1);

    for (int i = 0; i < numSegments; ++i)
    {
        hoareSort(v,
                  i * elementsPerSegment,
                  std::min((i + 1) * elementsPerSegment - 1, static_cast<int>(v->size() - 1)));
    }

    for (int i = 0; i < numSegments - 1; ++i)
    {
        merge(v,
              0,
              (i + 1) * elementsPerSegment - 1,
              std::min((i + 2) * elementsPerSegment - 1, static_cast<int>(v->size() - 1)));
    }
}

std::vector<int> getRandomVector(int size, int type)
{
    std::vector<int> newVec(size);
    std::random_device dev;
    std::mt19937 randomGenerator(dev());

    if (type == 1)
    {
        std::uniform_int_distribution<int> randomValue(1, std::numeric_limits<int>::max());

        for (int &item : newVec)
        {
            item = randomValue(randomGenerator);
        }
    }
    else if (type >= 0 && type <= 3)
    {
        std::uniform_int_distribution<int> randomValue(std::numeric_limits<int>::min(),
                                                       std::numeric_limits<int>::max());

        for (int &item : newVec)
        {
            item = randomValue(randomGenerator);
        }

        if (type == 2)
        {
            sort(newVec.begin(), newVec.end());
        }
        else if (type == 3)
        {
            sort(newVec.begin(), newVec.end(), std::greater<int>());
        }
    }
    else
    {
        throw std::invalid_argument("Invalid type of vector");
    }

    return newVec;
}
