#include "metaverse.h"
#include <iostream>
#include <fstream>

void unit_test_read_metaverse_configuration_line_from_file() {
 std::ifstream metaverse_file{"universe.meta"};
 bool success_or_failure{false};
 int generations{0};
 int size{0};
 success_or_failure = read_metaverse_configuration_line_from_file(metaverse_file, size, generations);
 std::cout << "read_metaverse_configuration_line_from_file result : " << success_or_failure << "\n";
 std::cout << "read_metaverse_configuration_line_from_file size : " << size << "\n";
 std::cout << "read_metaverse_configuration_line_from_file generations: " << generations << "\n";
}

void unit_test_count_neighbors(){}

int main() {

  //unit_test_read_metaverse_configuration_line_from_file();

  metaverse_t metaverse{};
  int generations{};

  std::string metaverse_filename{"universe.meta"};

  std::ifstream metaverse_file{metaverse_filename};

  if (!initialize_metaverse_from_file(metaverse_file, metaverse, generations)) {
    std::cout << "Could not initialize the metaverse!\n";
    return 1;
  }

  model_metaverse(metaverse, generations);

  return 0;
}

