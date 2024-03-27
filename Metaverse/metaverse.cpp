#include "metaverse.h"
#include "display.h"
#include <cctype>
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <unistd.h>
#include <vector>


/** count_neighbors()
 * Counts the number of neighboring cells that contain the value 1 in a given metaverse board.
 * 
 * @param board The metaverse board represented as a 2D vector of integers.
 * @param row The row index of the cell for which neighbors need to be counted.
 * @param column The column index of the cell for which neighbors need to be counted.
 * @return The count of neighboring cells that contain the value 1.
 * 
 * Process: Create a verctor that will have the changes in rows and columns
 *          Check if the resulting row or column is a valid row or column
 *          If it is valid, check if the location is occupied
 *          If it is occupied, increment the count
 */
int count_neighbors(const metaverse_t &board, int row, int column) {


  std::vector<std::vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  int count = 0;

    for (const auto& direction : directions) 
    {
        int newRow = row + direction[0];
        int newCol = column + direction[1];
        
        if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size()) {
            if(board[newRow][newCol]==1){
              count++;
            };
        }
    }
  return count;
}
 


/** occupied_in_next_tick()
 * Determines if a cell will be occupied in the next tick based on its current state and neighbor count.
 * @param currently_occupied The current state of the cell (occupied or unoccupied).
 * @param neighbor_count The number of occupied neighboring cells.
 * @return True if the cell will be occupied in the next tick, false otherwise.
 * 
 * Process: Check if cell is currently occupied
 *          Check the neighbor count for the cell
 * Logic:   •	If the location is occupied and it has either two or three occupied neighbors, the location will continue to be occupied during the next generation.
            •	If the location is not occupied and it has exactly three occupied neighbors, the location will become occupied during the next generation. change the unoccupied location to occupied.
            •	Otherwise, the location is not occupied during the next generation.

 */
bool occupied_in_next_tick(bool currently_occupied, int neighbor_count) {
  if (currently_occupied == 1 && (neighbor_count == 2 || neighbor_count == 3)) {
    return true;
  }
  else if (currently_occupied == 0 && neighbor_count == 3) {
    return true;
  }
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

/** read_metaverse_configuration_line_from_file()
 * Reads a line from the metaverse configuration file and extracts the size and generations values.
 * 
 * @param metaverse_file The input file stream to read from.
 * @param size [out] The variable to store the extracted size value.
 * @param generations [out] The variable to store the extracted generations value.
 * @return True if the line was successfully read and values were extracted, false otherwise.
 */
bool read_metaverse_configuration_line_from_file(std::ifstream &metaverse_file,
                                                 int &size, int &generations) {
  char comma;
  if ((metaverse_file >> size) && (metaverse_file >> comma) && (metaverse_file >> generations)){
    return true;
  }
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
