#include "Board.hpp"


namespace WarGame {

Soldier*& Board::operator[](std::pair<int,int> location){
    Soldier* s = this->board[location.first][location.second];
    if(location.first > board.size() || location.first < 0 || 
        location.second > board[location.first].size() || location.second < 0){
            throw runtime_error("outsid the board");
    }
    return s;
}

 Soldier* Board::operator[](std::pair<int,int> location) const{
    Soldier* s = this->board[location.first][location.second];
    if(location.first > board.size() || location.first < 0 || 
        location.second > board[location.first].size() || location.second < 0){
            throw runtime_error("outsid the board");
    }
    return s;
}
    
void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
    Soldier* s = this->board[source.first][source.second];
    if(s != nullptr && s->_player == player_number){
        std::pair<int,int> p = checkMove(source, direction);
        this->board[p.first][p.second] = s;
        this->board[source.first][source.second] = nullptr;
        s->activity(this->board, p);
    }
    else throw runtime_error("invalid move");
}

bool Board::has_soldiers(uint player_number) const{ // remember to change
    // std::vector<std::vector<Soldier*>>::iterator it;
    // std::vector<Soldier*>::iterator i;
    for(int i = 0; i < this->board.size() ; i++){
        for (int j = 0 ; j < this->board[i].size() ; j++){
            if(this->board[i][j] != nullptr && this->board[i][j]->_player == player_number){
                return true;
            }
        }
    }
    return false;
}


std::pair<int,int> Board::checkMove(std::pair<int,int> source, MoveDIR direction){
    if(direction == Up){
        if(source.first+1 <= this->board.size() && 
            this->board[source.first+1][source.second] == nullptr){
                return {source.first+1, source.second};
        }
        throw runtime_error("invalid move");
    }
    else if(direction == Down){
        if(source.first-1 >= 0 && 
            this->board[source.first-1][source.second] == nullptr){
                return {source.first-1, source.second};
        }
        throw runtime_error("invalid move");
    }

    else if(direction == Right){
        if(source.second+1 <= this->board[source.first].size() && 
            this->board[source.first][source.second+1] == nullptr){
                return {source.first, source.second+1};
        }
        throw runtime_error("invalid move");
    }

    else{
        if(source.second-1 >= 0 && 
            this->board[source.first][source.second-1] == nullptr){
                return {source.first, source.second-1};
        }
        throw runtime_error("invalid move");
    }
}

}