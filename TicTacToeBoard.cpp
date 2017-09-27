#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  // if (getWinner() != Invalid) {
  //   return getWinner();
  // }
  if (turn == X) {
    turn = O;
    return turn;
  } else  if (turn == O) {
    turn = X;
    return turn;
  } else {
    return Invalid;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a 
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if (row > (BOARDSIZE - 1) || row < 0 || column > (BOARDSIZE - 1) || column < 0 ) { //out of bounds
    return Invalid;
  } else if(getPiece(row, column) != Blank)  { //Piece already there
    return Invalid;
  }
  board[row][column] = turn;
  //toggleTurn();
  return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row > 2 || row < 0 || column > 2 || column < 0 ) { //out of bounds
    return Invalid;
  } else if(getPiece(row, column) == Blank)  { //Piece already there
    return Blank;
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/

/**
 * BUG: Returns Blank winner if there are 3 blanks next to each other
**/

Piece TicTacToeBoard::getWinner()
{
    if (
    ((getPiece(0,0) == getPiece(1,0)) &&  (getPiece(1,0) == getPiece(2,0)) ) //first column winner
    ) { return getPiece(0,0); 
    } else if (
    ((getPiece(0,1) == getPiece(1,1)) &&  (getPiece(1,1) == getPiece(2,1))) //middle column winner
    ) { return getPiece(0,1); 
    } else if (
    ((getPiece(0,2) == getPiece(1,2)) &&  (getPiece(1,2) == getPiece(2,2)) ) //last column winner
    ) { return getPiece(0,2); 
    } else if (
    ((getPiece(0,0) == getPiece(0,1)) &&  (getPiece(0,1) == getPiece(0,2)) ) //first row winner
    ) { return getPiece(0,0); 
    } else if (
    ((getPiece(1,0) == getPiece(1,1)) &&  (getPiece(1,1) == getPiece(1,2))) //middle row winner
    ) { return getPiece(1,0); 
    } else if (
    ((getPiece(2,0) == getPiece(2,1)) &&  (getPiece(2,1) == getPiece(2,2)) ) //last row winner
    ) { return getPiece(2,0); 
    } else if (
    ((getPiece(0,0) == getPiece(1,1)) &&  (getPiece(1,1) == getPiece(2,2)) ) //decreasing diagonal winner
    ) { return getPiece(0,0); 
    } else if (
    ((getPiece(0,2) == getPiece(1,1)) &&  (getPiece(1,1) == getPiece(2,0)) ) //increasing diagonal winner
    ) { return getPiece(0,2); 
    } else {
      return Invalid;
    }
}

/* Correct get winner function
Piece TicTacToeBoard::getWinner()
{
    if (
    (getPiece(0,0) == getPiece(1,0)) &&  (getPiece(1,0) == getPiece(2,0)) && (getPiece(0,0) != Blank) //first column winner
    ) { return getPiece(0,0); 
    } else if (
    (getPiece(0,1) == getPiece(1,1)) &&  (getPiece(1,1) == getPiece(2,1)) && (getPiece(0,1) != Blank) //middle column winner
    ) { return getPiece(0,1); 
    } else if (
    (getPiece(0,2) == getPiece(1,2)) &&  (getPiece(1,2) == getPiece(2,2)) && (getPiece(0,2) != Blank) //last column winner
    ) { return getPiece(0,2); 
    } else if (
    (getPiece(0,0) == getPiece(0,1)) &&  (getPiece(0,1) == getPiece(0,2)) && (getPiece(0,1) != Blank) //first row winner
    ) { return getPiece(0,0); 
    } else if (
    (getPiece(1,0) == getPiece(1,1)) &&  (getPiece(1,1) == getPiece(1,2)) && (getPiece(1,1) != Blank) //middle row winner
    ) { return getPiece(1,0); 
    } else if (
    (getPiece(2,0) == getPiece(2,1)) &&  (getPiece(2,1) == getPiece(2,2)) && (getPiece(2,1) != Blank) //last row winner
    ) { return getPiece(2,0); 
    } else if (
    (getPiece(0,0) == getPiece(1,1)) &&  (getPiece(1,1) == getPiece(2,2)) && (getPiece(0,0) != Blank) //decreasing diagonal winner
    ) { return getPiece(0,0); 
    } else if (
    (getPiece(0,2) == getPiece(1,1)) &&  (getPiece(1,1) == getPiece(2,0)) && (getPiece(0,2) != Blank) //increasing diagonal winner
    ) { return getPiece(0,2); 
    } else {
      return Invalid;
    }
}
*/