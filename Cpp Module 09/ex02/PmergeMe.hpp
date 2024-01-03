#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>

std::string sortVector(int argc, char* argv[]);
std::string sortList(int argc, char* argv[]);
void mergeSort(std::vector<int>& data, int left, int right);
void merge(std::vector<int>& data, int left, int mid, int right);
void insertSort(std::vector<int>& data, int left, int right);

#endif
