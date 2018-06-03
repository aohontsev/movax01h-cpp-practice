// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "blocks.h"

#include <numeric>

namespace blocks {

// Max can be not more then 10^14
int64_t Block::GetMass() {
  return 1ull * density_ * depth_ * height_ * width_;
}

// Max can be not more then 10^19
uint64_t GetSumMassBlocks(const std::vector<Block>& blocks) {
  return std::accumulate(blocks.begin(), blocks.end(), 0ull,
                         [](uint64_t current_sum, blocks::Block block) {
                           return current_sum + block.GetMass();
                         });
}

} // namespace blocks
