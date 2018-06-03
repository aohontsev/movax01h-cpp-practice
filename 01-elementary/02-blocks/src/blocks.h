// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#ifndef MOVAX01H_CPP_PRACTICE_ELEMENTARY_BLOCKS_BLOCKS_H_
#define MOVAX01H_CPP_PRACTICE_ELEMENTARY_BLOCKS_BLOCKS_H_

#include <stdint.h>
#include <vector>

namespace blocks {

class Block {
 public:
  Block() = default;
  Block(int w, int h, int dep, int den)
      : width_(w), height_(h), depth_(dep), density_(den) {}
  int64_t GetMass();

 private:
  int density_ = 0;  // in g/cm^3
  int depth_   = 0;  // in cm
  int height_  = 0;  // in cm
  int width_   = 0;  // in cm
};

uint64_t GetSumMassBlocks(const std::vector<Block>& blocks);

} // namespace blocks

#endif // MOVAX01H_CPP_PRACTICE_ELEMENTARY_BLOCKS_BLOCKS_H_
