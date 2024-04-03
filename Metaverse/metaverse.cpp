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
 * Input:
 * @param board The metaverse board represented as a 2D vector of integers.
 * @param row The row index of the cell for which neighbors need to be counted.
 * @param column The column index of the cell for which neighbors need to be counted.
 * 
 * Output:
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
 * Input:
 * @param currently_occupied The current state of the cell (occupied or unoccupied).
 * @param neighbor_count The number of occupied neighboring cells.
 * Output:
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


/**
 * Creates a new metaverse for a tick in future cosidering today's metaverse board.
 * 
 * Input:
 * @param board The current state of the metaverse board.
 * 
 * Output:
 * @return The new state of the metaverse board after the tick.
 * 
 * Process: Using Functions :--------------------------------------------------------
 *      1.  resize_metaverse (int rows, metaverse_t &board)
 *      2.  count_neighbors (const metaverse_t &board, int row, int column)
 *      3.  occupied_in_next_tick (bool currently_occupied, int neighbor_count)
 */
metaverse_t tick(const metaverse_t &board) {
  metaverse_t New_TickMeta;
  resize_metaverse(board.size(), New_TickMeta);

  for (int i = 0; i < New_TickMeta.size(); i++) {
    for (int j = 0; j < New_TickMeta[i].size(); j++) 
    {

      int neighborCounts = count_neighbors(board, i, j);
      New_TickMeta[i][j] = occupied_in_next_tick(board[i][j], neighborCounts);
    }
  }

  return New_TickMeta;
}


/** resize_metaverse()
 * This function will resize a Metaverse according to a given size.
 * 
 * Input: 
 * @param rows The number of rows to resize the metaverse board to.
 * @param board The metaverse board to be resized.
 * 
 * Output:
 * @return True if the metaverse board was successfully resized, false otherwise.
 * 
 * Process:The function will resize the given metaverse_t parameter according to the specified size. 
 *         The function always returns true.
 */
bool resize_metaverse(int rows, metaverse_t &board) {
    board.resize(rows);
    for (auto &column : board) {
        column.resize(rows);
    }
    return true;
}
  

/**
 * Converts a citizenship row to a metaverse row.
 * 
 * Input:
 * @param input_row The input string representing the citizenship row.
 * @param row The row index in the metaverse board.
 * @param board The metaverse board.
 * 
 * Output:
 * @return True if the conversion is successful, false otherwise.
 */
bool citizenship_row_to_metaverse_row(const std::string &input_row, int row,
                                      metaverse_t &board) {
  
  for (int strIndex = 0; strIndex < input_row.size(); strIndex++) {
    if (input_row[strIndex] == '1') {
      board[row][strIndex] = 1;
    } else if (input_row[strIndex] == '0') {
      board[row][strIndex] = 0;
    } else {
      return false;
    }
  }
return true;
}


/** read_metaverse_configuration_line_from_file()
 * Reads a line from the metaverse configuration file and extracts the size and generations values.
 * 
 * Input:
 * @param metaverse_file The input file stream to read from.
 * @param size [out] The variable to store the extracted size value.
 * @param generations [out] The variable to store the extracted generations value.
 * 
 * Output:
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


/**
 * @brief Initializes the metaverse from a file.
 * 
 * This function reads the metaverse configuration from the given file and initializes the metaverse and the number of generations.
 * 
 * Input:
 * @param metaverse_file The input file stream containing the metaverse configuration.
 * @param metaverse The metaverse to be initialized.
 * @param generations The number of generations to be initialized.
 * 
 * Output:
 * @return True if the metaverse is successfully initialized, false otherwise.
 */
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


/** model_metaverse()
 * @brief Model the metaverse for a given number of generations.
 * 
 * This function takes a starting metaverse and simulates its evolution for the specified number of generations.
 * Each generation is represented by a tick in the metaverse.
 * 
 * Input:
 * @param starting_metaverse The initial metaverse to start the simulation from.
 * @param generations The number of generations to simulate.
 * 
 * Output:
 * None. The function is initialized with the keyword void.
 * 
 * Process: Using Functions :--------------------------------------------------------
 *          1.  tick (const metaverse_t &board) 
 */
void model_metaverse(const metaverse_t &starting_metaverse, int generations) {
  metaverse_t current_metaverse = starting_metaverse;
  for (int i = 0; i < generations; i++) {
    display_metaverse(std::cout, current_metaverse);
    current_metaverse = tick(current_metaverse);
  
  }
}


