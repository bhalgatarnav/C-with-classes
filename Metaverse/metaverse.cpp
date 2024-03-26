#include "metaverse.h"
#include "display.h"
#include <cctype>
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <unistd.h>
#include <vector>

int count_neighbors(const metaverse_t &board, int row, int column) {
  return 0;
}

bool occupied_in_next_tick(bool currently_occupied, int neighbor_count) {
  return false;
}

metaverse_t tick(const metaverse_t &board) {
  return metaverse_t{};
}

bool resize_metaverse(int rows, metaverse_t &board) {
  return false;
}

bool citizenship_row_to_metaverse_row(const std::string &input_row, int row,
                                      metaverse_t &board) {
  return false;
}

bool read_metaverse_configuration_line_from_file(std::ifstream &metaverse_file,
                                                 int &size, int &generations) {
  return false;
}
bool initialize_metaverse_from_file(std::ifstream &metaverse_file,
                                    metaverse_t &metaverse,
                                    int &generations) {
  int size{};
  int actual_row{};

  generations = 0;

  if (!read_metaverse_configuration_line_from_file(metaverse_file, size,
                                                   generations)) {
    return false;
  }

  if (!resize_metaverse(size, metaverse)) {
    return false;
  }

  metaverse_file >> std::ws;
  while (!metaverse_file.eof()) {
    std::string line{};
    if (!std::getline(metaverse_file, line)) {
      return false;
    }
    if (!citizenship_row_to_metaverse_row(line, actual_row, metaverse)) {
      return false;
    }
    actual_row++;
    metaverse_file >> std::ws;
  }
  return actual_row == size;
}

void model_metaverse(const metaverse_t &starting_metaverse, int generations) {
}
