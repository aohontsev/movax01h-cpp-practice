// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include <iostream>
#include <numeric>
#include <set>
#include <vector>

#include "temperature.h"

int main() {
  int days_count = 0;
  std::cin >> days_count;

  int input_value = 0;
  std::vector<int> days_temp;
  for (int i = 0; i < days_count; i++) {
    std::cin >> input_value;
    days_temp.push_back(std::move(input_value));
  }

  std::vector<int> above_average =
      temperature::GetIndexesAboveAverage(days_temp);

  std::cout << above_average.size() << std::endl;
  for (const int& item : above_average)
    std::cout << item << " ";
  std::cout << std::endl;
}
