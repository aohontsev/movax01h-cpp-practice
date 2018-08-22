// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "string"

#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

typedef std::string Date;

enum class MainFuncExitCodes {
  SUCCESS = 0,
  INPUT_STREAM_IS_EMPTY = 1,
  INPUT_STREAM_IS_NOT_SORTED = 2,
  BOUNDARY_VALUE_NOT_FOUND = 3
};

MainFuncExitCodes main_func(std::istringstream *str) {
  // Fill vector from stream.
  std::vector<Date> dates;
  std::copy(std::istream_iterator<Date>(*str), std::istream_iterator<Date>(),
            std::back_inserter(dates));
  if (dates.empty()) {
    std::cout << "Error. Input stream is empty.\n";
    return MainFuncExitCodes::INPUT_STREAM_IS_EMPTY;
  }

  // Find first and last element.
  std::vector<Date>::iterator first =
      std::find(dates.begin(), dates.end(), "01/01/18");
  std::vector<Date>::iterator last =
      std::find(dates.begin(), dates.end(), "31/12/18");
  if (first == dates.end() || last == dates.end()) {
    std::cout << "Error. Cannot find first or last value.\n";
    return MainFuncExitCodes::BOUNDARY_VALUE_NOT_FOUND;
  } else if (last < first) {
    std::cout << "Error. Input stream order is reversed or mixed.\n";
    return MainFuncExitCodes::INPUT_STREAM_IS_NOT_SORTED;
  }

    // Print into console elements between firsl and lst element.
  std::copy(first, last, std::ostream_iterator<Date>(std::cout, "\n"));
  std::cout << "\n";

  // Insert new element.
  dates.insert(dates.end() - 1, "30/12/18");

  // Find first and last element.
  first = std::find(dates.begin(), dates.end(), "01/01/18");
  last = std::find(dates.begin(), dates.end(), "31/12/18");
  if (first == dates.end() || last == dates.end()) {
    std::cout << "Error. Cannot find first or last value.\n";
    return MainFuncExitCodes::BOUNDARY_VALUE_NOT_FOUND;
  } else if (last < first) {
    std::cout << "Error. Input stream order is reversed or mixed.\n";
    return MainFuncExitCodes::INPUT_STREAM_IS_NOT_SORTED;
  }

  // Print into console elements between firsl and lst element.
  std::copy(first, last, std::ostream_iterator<Date>(std::cout, "\n"));
  return MainFuncExitCodes::SUCCESS;
};
