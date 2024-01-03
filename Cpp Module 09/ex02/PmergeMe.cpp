#include "PmergeMe.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <sys/time.h>

void insertSort(std::vector<int>& data, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= left && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}

void merge(std::vector<int>& data, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (data[i] < data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = data[i++];
    }
    while (j <= right) {
        temp[k++] = data[j++];
    }

    for (i = left, k = 0; i <= right; ++i, ++k) {
        data[i] = temp[k];
    }
}

void mergeSort(std::vector<int>& data, int left, int right) {
    int dataSize = right - left + 1;
    int dynamicThreshold = std::max(10, static_cast<int>(std::log(dataSize) / std::log(2) * 2));

    if (dataSize <= dynamicThreshold) {
        insertSort(data, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}

std::string sortVector(int argc, char* argv[]) {
    clock_t start = clock();

    std::vector<int> dataVector;
    for (int i = 1; i < argc; ++i) {
        dataVector.push_back(std::atoi(argv[i]));
    }

    mergeSort(dataVector, 0, dataVector.size() - 1);
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    std::ostringstream oss;
    oss << "Time to process a range of " << dataVector.size() << " elements with std::vector: " << elapsed * 1000000 << " us";
    return oss.str();
}

std::string sortList(int argc, char* argv[]) {
    clock_t start = clock();

    std::list<int> dataList;
    for (int i = 1; i < argc; ++i) {
        dataList.push_back(std::atoi(argv[i]));
    }

    dataList.sort();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    std::ostringstream oss;
    oss << "Time to process a range of " << dataList.size() << " elements with std::list: " << elapsed * 1000000 << " us";
    return oss.str();
}