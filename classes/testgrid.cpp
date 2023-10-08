#include "grid.h"
#include <iostream>
#include <string>
#include <vector>


int main(){

    bool roundEnd= 0;

    grid poop(10,10);

     std::vector<std::vector<int>> playerTwo= poop.playerTwoGrid();

    for (int i=0;i< poop.get_length();i++){


        for (int j=0;j<poop.get_width();j++){

            std::cout<<playerTwo[i][j]<<" ";


        }

        std::cout<<std::endl;
    }
