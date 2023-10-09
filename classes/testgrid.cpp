#include "grid.h"

int main() {
  bool roundEnd = 0;
int anum = 97;

  grid poop(10, 10);

  std::vector<std::vector<int>> playerTwo = poop.playerTwoGrid();

  std::cout << " 1 2 3 4 5 6 7 8 9 10" << std::endl;

  for (int i = 0; i < poop.get_length(); i++) {
    
    char letter = static_cast<char>(anum);
    std::cout << letter << " ";

    anum = anum + 1;

    for (int j = 0; j < poop.get_width(); j++) {
      std::cout << playerTwo[i][j] << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}
