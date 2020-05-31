#include "Sniper.hpp"


void Sniper::activity(std::vector<std::vector<Soldier*>> &board, pair<int,int> location){
     pair<int,int> ToAttack;
    int Strongest =  std::numeric_limits<int>::infinity();
    for(int i = 0; i != board.size() ; i++){ // serch the nearest soldier to attack
        for (int j = 0 ; j < board[i].size() ; j++){
            if(board[i][j] != nullptr &&
                 board[i][j]->_player != board[location.first][location.second]->_player ){
                long CurrStrong = board[i][j]->_points;
                if (CurrStrong > Strongest) {
                    Strongest = CurrStrong;
                    ToAttack.first = i;
                    ToAttack.second = j;
                } 

            }
        }
    }//need if not have enemy soldier
    board[ToAttack.first][ToAttack.second]->_points -= board[location.first][location.second]->_ability;
    if (board[ToAttack.first][ToAttack.second]->_points <= 0){ //check if the soldier is dead
        delete(board[ToAttack.first][ToAttack.second]);
        board[ToAttack.first][ToAttack.second] = nullptr;
    }   

}