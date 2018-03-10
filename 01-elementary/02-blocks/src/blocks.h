// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#ifndef BLOCKS_HANDLER_H_
#define BLOCKS_HANDLER_H_

#include <vector>

namespace blocks {

class Block {
public:
  Block() {}
  Block(int w, int h, int dep, int den)
      : width_(w), height_(h), depth_(dep), density_(den) {}
  int64_t GetMass();

private:
  int density_ = 0; // in g/cm^3
  int depth_ = 0;   // in cm
  int height_ = 0;  // in cm
  int width_ = 0;   // in cm
};

uint64_t GetSumMassBlocks(const std::vector<Block> &blocks);

} // namespace blocks

#endif // BLOCKS_HANDLER_H_
