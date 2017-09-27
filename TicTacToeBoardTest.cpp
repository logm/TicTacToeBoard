/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

///////ToggleTurn
TEST(TicTacToeBoardTest, toggleTurn) {
	TicTacToeBoard tic;
	ASSERT_TRUE(O == tic.toggleTurn());
	ASSERT_TRUE(X == tic.toggleTurn());
	ASSERT_TRUE(O == tic.toggleTurn());
	ASSERT_TRUE(X == tic.toggleTurn());
	ASSERT_TRUE(O == tic.toggleTurn());
	ASSERT_TRUE(X == tic.toggleTurn());
	ASSERT_TRUE(O == tic.toggleTurn());
	ASSERT_TRUE(X == tic.toggleTurn());
	ASSERT_TRUE(O == tic.toggleTurn());
}


///////PlacePiece 
TEST(TicTacToeBoardTest, OutBoundPlacementOver) {
	TicTacToeBoard tic;
	ASSERT_EQ(Invalid, tic.placePiece(5,2));
}

TEST(TicTacToeBoardTest, OutBoundPlacementUnder) {
	TicTacToeBoard tic;
	ASSERT_EQ(Invalid, tic.placePiece(2,-2));
}

TEST(TicTacToeBoardTest, CorrectBoardPlacement) {
	TicTacToeBoard tic;
	ASSERT_EQ(X, tic.placePiece(2,2));
}

///////GetPiece

TEST(TicTacToeBoardTest, CorrectBoardGet) {
	TicTacToeBoard tic;
	tic.placePiece(2,2);
	tic.placePiece(1,1);
	ASSERT_TRUE(X == tic.getPiece(2,2));
	ASSERT_TRUE(O == tic.getPiece(1,1));
}

TEST(TicTacToeBoardTest, OutBoundGet) {
	TicTacToeBoard tic;
	ASSERT_TRUE(Invalid == tic.getPiece(2,-2));
}

TEST(TicTacToeBoardTest, BlankBoardGet) {
	TicTacToeBoard tic;
	ASSERT_TRUE(Blank == tic.getPiece(2,2));
}

///////GetWinner

TEST(TicTacToeBoardTest, correctWinner) {
	TicTacToeBoard tic;
	tic.placePiece(0,0);//X
	tic.placePiece(1,1);//O
	tic.placePiece(0,1);//X
	tic.placePiece(2,1);//O
	tic.placePiece(0,2);//X
	ASSERT_TRUE(X == tic.getWinner()); //First row x winner
}

TEST(TicTacToeBoardTest, noWinner) {
	TicTacToeBoard tic;
	ASSERT_TRUE(Invalid == tic.getWinner());
}

TEST(TicTacToeBoardTest, DiagonalWinner) {
	TicTacToeBoard tic;
	tic.placePiece(0,0);//X
	tic.placePiece(1,2);//O
	tic.placePiece(1,1);//X
	tic.placePiece(2,1);//O
	tic.placePiece(2,2);//X
	ASSERT_TRUE(X == tic.getWinner()); //Diagonal winner
}
//This is my new Coverage Test
TEST(TicTacToeBoardTest, BlankWinner) {
	TicTacToeBoard tic;
	ASSERT_FALSE(Blank == tic.getWinner());
}