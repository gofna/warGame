#include "SniperCommander.hpp"



std::pair<int,int> SniperCommander::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location){
    Sniper::activity(board, location);
      for(int i = 0; i < board.size() ; i++){
        for (int j = 0 ; j < board[i].size() ; j++){
            if(board[i][j] != nullptr && dynamic_cast<Sniper*>(board[i][j]) && board[i][j]->_player == this->_player) {
                 board[i][j]->activity(board, {i,j});
            }
        }
    }
}