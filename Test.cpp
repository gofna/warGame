#include "doctest.h"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Board.hpp"
#include <cassert>
#include "Soldier.hpp"
using namespace WarGame;

// TEST_CASE("build legal game") {
// 	Board board (8,1);

//     CHECK(!board.has_soldiers(1));
//     board[{0,0}] = new FootSoldier(1);
// 	CHECK_THROWS(board[{0,0}] = new FootSoldier(1));
//     CHECK(board.has_soldiers(1));
//     CHECK(!board.has_soldiers(1));
//     board[{7,0}] = new FootSoldier(2);
//     CHECK(board.has_soldiers(2));

// }

TEST_CASE("Foot soldiers semple full game") {
    WarGame::Board board(8,1);

    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7,0}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0,0}, WarGame::Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, WarGame::Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, WarGame::Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, WarGame::Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, WarGame::Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, WarGame::Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, WarGame::Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, WarGame::Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    board.move(1, {0,0}, WarGame::Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
    board.move(1, {1,0}, WarGame::Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
    CHECK(!board.has_soldiers(2));
}

// TEST_CASE("test FootSoldiers+FootCommander activity") {
//     		Board b(8, 8);
// 			// Add soldiers for player 1:
//             CHECK(b.has_soldiers(1) == false);
// 			b[{0,1}] = new FootSoldier(1);
// 			b[{0,3}] = new FootCommander(1);
// 			b[{0,5}] = new FootSoldier(1);
// 			CHECK(b.has_soldiers(1) == true);

// 			// Add soldiers for player 2:
//             CHECK(b.has_soldiers(2) == false);
// 			b[{7,1}] = new FootSoldier(2);
// 			b[{7,3}] = new FootCommander(2);
// 			b[{7,5}] = new FootSoldier(2);
// 			CHECK(b.has_soldiers(2) == true);

//             CHECK(b.has_soldiers(1) == true);
//             CHECK(b.has_soldiers(2) == true);

//             CHECK_NOTHROW(b.move(1, {0,1}, Board::MoveDIR::Up));      // FootSoldier of player 1 moves forward and attacks.
//             CHECK(b[{7,1}]->_points == 90);
// 			CHECK(b[{7,3}]->_points == 150);
// 			CHECK(b[{7,5}]->_points == 100);
// 			CHECK(b[{0,1}] == nullptr);
// 			CHECK(b[{1,1}] != nullptr);
// 			CHECK(b[{1,1}]->_points == 100);
// 			CHECK(b[{0,3}]->_points == 150);
// 			CHECK(b[{0,5}]->_points == 100);

// 			CHECK_NOTHROW(b.move(2, {7,1}, Board::MoveDIR::Down));
// 			CHECK(b[{1,1}]->_points == 90);
// 			CHECK(b[{0,3}]->_points == 150);
// 			CHECK(b[{0,5}]->_points == 100);
// 			CHECK(b[{7,1}] == nullptr);
// 			CHECK(b[{6,1}] != nullptr);
// 			CHECK(b[{6,1}]->_points == 90);
// 			CHECK(b[{7,3}]->_points == 150);
// 			CHECK(b[{7,5}]->_points == 100);

// 			CHECK_NOTHROW(b.move(1, {0,3}, Board::MoveDIR::Up));
// 			CHECK((b[{7,3}]->_points == 130 || b[{6,1}]->_points == 70 || b[{6,1}]->_points == 60));
// 			CHECK(b[{7,5}]->_points == 140);
// 			CHECK(b[{0,5}]->_points == 100);
// 			CHECK(b[{0,3}] == nullptr);
// 			CHECK(b[{1,3}] != nullptr);
// 			CHECK(b[{1,3}]->_points == 150);
// 			CHECK(b[{1,1}]->_points == 90);

// 			CHECK_NOTHROW(b.move(1, {1,1}, Board::MoveDIR::Left));
// 			CHECK(b[{6,1}]->_points == 80);
// 			CHECK((b[{7,3}]->_points == 130 || b[{7,3}]->_points == 150));
// 			CHECK(b[{7,5}]->_points == 140);
// 			CHECK_THROWS(b.move(1, {1,2}, Board::MoveDIR::Left)); // the commander is there

// }

// TEST_CASE("test all types") {
//     		Board b(10, 10);
// 			// Add soldiers for player 1:
//             CHECK(b.has_soldiers(1) == false);
// 			b[{0,6}] = new Paramedic(1);
// 			b[{0,7}] = new ParamedicCommander(1);
// 			b[{1,0}] = new FootSoldier(1);
// 			b[{1,3}] = new Sniper(1);
// 			b[{1,4}] = new SniperCommander(1);
// 			b[{1,9}] = new Sniper(1);
// 			b[{2,1}] = new FootCommander(1);
// 			b[{2,5}] = new FootCommander(1);
// 			b[{3,0}] = new FootSoldier(1);
// 			b[{3,8}] = new FootSoldier(1);
// 			CHECK(b.has_soldiers(1) == true);

// 			// Add soldiers for player 2:
//             CHECK(b.has_soldiers(2) == false);
// 			b[{8,1}] = new FootCommander(2);
// 			b[{8,3}] = new SniperCommander(2);
// 			b[{8,5}] = new ParamedicCommander(2);
// 			b[{8,7}] = new FootCommander(2);
// 			b[{8,9}] = new SniperCommander(2);
// 			b[{9,0}] = new FootSoldier(2);
// 			b[{9,2}] = new Sniper(2);
// 			b[{9,4}] = new Paramedic(2);
// 			b[{9,6}] = new FootSoldier(2);
// 			b[{9,8}] = new Sniper(2);
// 			CHECK(b.has_soldiers(2) == true);

// 			CHECK_NOTHROW(b.move(1, {3,0}, Board::MoveDIR::Up)); // moved FootSoldier
// 			CHECK(b[{8,1}]->_points == 110);
// 			CHECK(b[{3,0}] == nullptr);
// 			CHECK(b[{4,0}] != nullptr);

// 			CHECK_NOTHROW(b.move(2, {8,9}, Board::MoveDIR::Down)); // moved SniperCommander
// 			CHECK(b[{8,9}] == nullptr);
// 			CHECK(b[{7,9}] != nullptr);
// 			CHECK(b[{0,7}]->_points == 100);
// 			CHECK(b[{2,5}]->_points == 100);
// 			CHECK(b[{2,1}]->_points == 100);

// 			CHECK_NOTHROW(b.move(1, {2,1}, Board::MoveDIR::Up)); // moved FootCommander
// 			CHECK(b[{2,1}] == nullptr);
// 			CHECK(b[{3,1}] != nullptr);
// 			CHECK(b[{8,1}]->_points == 100);
// 			CHECK(b[{7,9}]->_points == 110);

// 			CHECK_NOTHROW(b.move(2, {7,9}, Board::MoveDIR::Left));// moved SniperCommander
// 			CHECK(b[{7,9}] == nullptr);
// 			CHECK(b[{7,8}] != nullptr);
			
// 			CHECK_NOTHROW(b.move(1, {3,1}, Board::MoveDIR::Up)); 
// 			CHECK_NOTHROW(b.move(1, {4,1}, Board::MoveDIR::Up)); 
// 			CHECK_NOTHROW(b.move(1, {5,1}, Board::MoveDIR::Up)); 
// 			CHECK(b[{8,1}] == nullptr);
// 			CHECK(b[{9,0}]->_points == 90);

// 			CHECK_NOTHROW(b.move(1, {0,6}, Board::MoveDIR::Up));
// 			CHECK(b[{0,6}] == nullptr);
// 			CHECK(b[{1,6}] != nullptr);
// 			CHECK(b[{2,5}]->_points == 150);
// 			CHECK(b[{0,7}]->_points == 150);

// 			CHECK_THROWS(b.move(1, {1,4}, Board::MoveDIR::Left)); 
// 			CHECK_THROWS(b.move(1, {4,9}, Board::MoveDIR::Left)); // there is no Soldier here to move
// }

// TEST_CASE("test FootSoldiers+FootCommander activity") {
//     		Board b(8, 8);
// 			// Add soldiers for player 1:
//             CHECK(b.has_soldiers(1) == false);
// 			b[{0,1}] = new FootSoldier(1);
// 			b[{0,3}] = new FootCommander(1);
// 			b[{0,5}] = new FootSoldier(1);
// 			CHECK(b.has_soldiers(1) == true);

// 			// Add soldiers for player 2:
//             CHECK(b.has_soldiers(2) == false);
// 			b[{7,1}] = new FootSoldier(2);
// 			b[{7,3}] = new FootCommander(2);
// 			b[{7,5}] = new FootSoldier(2);
// 			CHECK(b.has_soldiers(2) == true);

//             CHECK(b.has_soldiers(1) == true);
//             CHECK(b.has_soldiers(2) == true);

//             CHECK_NOTHROW(b.move(1, {0,1}, Board::MoveDIR::Up));      // FootSoldier of player 1 moves forward and attacks.
//             CHECK(b[{7,1}]->_points == 90);
// 			CHECK(b[{7,3}]->_points == 150);
// 			CHECK(b[{7,5}]->_points == 100);
// 			CHECK(b[{0,1}] == nullptr);
// 			CHECK(b[{1,1}] != nullptr);
// 			CHECK(b[{1,1}]->_points == 100);
// 			CHECK(b[{0,3}]->_points == 150);
// 			CHECK(b[{0,5}]->_points == 100);

// 			CHECK_NOTHROW(b.move(2, {7,1}, Board::MoveDIR::Down));
// 			CHECK(b[{1,1}]->_points == 90);
// 			CHECK(b[{0,3}]->_points == 150);
// 			CHECK(b[{0,5}]->_points == 100);
// 			CHECK(b[{7,1}] == nullptr);
// 			CHECK(b[{6,1}] != nullptr);
// 			CHECK(b[{6,1}]->_points == 90);
// 			CHECK(b[{7,3}]->_points == 150);
// 			CHECK(b[{7,5}]->_points == 100);

// 			CHECK_NOTHROW(b.move(1, {0,3}, Board::MoveDIR::Up));
// 			CHECK((b[{7,3}]->_points == 130 || b[{6,1}]->_points == 70 || b[{6,1}]->_points == 60));
// 			CHECK(b[{7,5}]->_points == 140);
// 			CHECK(b[{0,5}]->_points == 100);
// 			CHECK(b[{0,3}] == nullptr);
// 			CHECK(b[{1,3}] != nullptr);
// 			CHECK(b[{1,3}]->_points == 150);
// 			CHECK(b[{1,1}]->_points == 90);

// 			CHECK_NOTHROW(b.move(1, {1,1}, Board::MoveDIR::Left));
// 			CHECK(b[{6,1}]->_points == 80);
// 			CHECK((b[{7,3}]->_points == 130 || b[{7,3}]->_points == 150));
// 			CHECK(b[{7,5}]->_points == 140);
// 			CHECK_THROWS(b.move(1, {1,2}, Board::MoveDIR::Left)); // the commander is there

// }




