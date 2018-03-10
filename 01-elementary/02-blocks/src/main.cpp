// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include <iostream>
#include <numeric>
#include <set>
#include <vector>

#include "blocks.h"

int main() {
  int blocks_count = 0;
  std::cin >> blocks_count;

  int blocks_density = 0;
  std::cin >> blocks_density;

  int width, height, depth = 0;
  std::vector<blocks::Block> input_blocks;
  for (int i = 0; i < blocks_count; i++) {
    std::cin >> width >> height >> depth;
    input_blocks.push_back(blocks::Block(width, height, depth, blocks_density));
  }

  std::cout << blocks::GetSumMassBlocks(input_blocks) << std::endl;
}
