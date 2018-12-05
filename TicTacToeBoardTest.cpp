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
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurnX)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.toggleTurn();
	ASSERT_EQ(testPiece, O);
}

TEST(TicTacToeBoardTest, toggleTurnO)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.toggleTurn();
	testPiece = testBoard.toggleTurn();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoardTest, placeFirstPiece)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,0);
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoardTest, placeOccupiedPiece)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,0);
	testPiece = testBoard.placePiece(0,0);
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoardTest, placeRowAboveBounds)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(3,0);
	ASSERT_EQ(testPiece, Invalid);
}

TEST(TicTacToeBoardTest, placeRowBelowBounds)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(-1,0);
	ASSERT_EQ(testPiece, Invalid);
}

TEST(TicTacToeBoardTest, placeColAboveBounds)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,3);
	ASSERT_EQ(testPiece, Invalid);
}

TEST(TicTacToeBoardTest, placeColBelowBounds)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,-1);
	ASSERT_EQ(testPiece, Invalid);
}

TEST(TicTacToeBoardTest, placeGameOver)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	for ( int i = 0; i < 2; i++ )
	{
		for ( int j = 0; j < 2; j++ )
		{
			testPiece = testBoard.placePiece(i,j);
		}
	}
	testPiece = testBoard.placePiece(2,1);
	testPiece = testBoard.placePiece(2,0);
	testPiece = testBoard.placePiece(2,2);
	testPiece = testBoard.placePiece(1,2);
	testPiece = testBoard.placePiece(0,2);
	testPiece = testBoard.placePiece(0,2);
	ASSERT_EQ(testPiece, Blank);
}


TEST(TicTacToeBoardTest, getPlacedPiece)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,0);
	testPiece = testBoard.getPiece(0,0);
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoardTest, getBlankPiece)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,0);
	testPiece = testBoard.getPiece(1,0);
	ASSERT_EQ(testPiece, Blank);
}

TEST(TicTacToeBoardTest, getInvalidPiece)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,0);
	testPiece = testBoard.getPiece(3,3);
	ASSERT_EQ(testPiece, Invalid);
}

TEST(TicTacToeBoard, getWinnerXRow0)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,0);
	testPiece = testBoard.placePiece(0,1);
	testPiece = testBoard.placePiece(1,0);
	testPiece = testBoard.placePiece(1,1);
	testPiece = testBoard.placePiece(2,0);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoard, getWinnerXRow1)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,1);
	testPiece = testBoard.placePiece(0,0);
	testPiece = testBoard.placePiece(1,1);
	testPiece = testBoard.placePiece(1,0);
	testPiece = testBoard.placePiece(2,1);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoard, getWinnerXRow2)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,2);
	testPiece = testBoard.placePiece(0,1);
	testPiece = testBoard.placePiece(1,2);
	testPiece = testBoard.placePiece(1,1);
	testPiece = testBoard.placePiece(2,2);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoard, getWinnerXDia0)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,0);
	testPiece = testBoard.placePiece(0,1);
	testPiece = testBoard.placePiece(1,1);
	testPiece = testBoard.placePiece(1,2);
	testPiece = testBoard.placePiece(2,2);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoard, getWinnerXDia2)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(2,0);
	testPiece = testBoard.placePiece(0,1);
	testPiece = testBoard.placePiece(1,1);
	testPiece = testBoard.placePiece(1,2);
	testPiece = testBoard.placePiece(0,2);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoard, getWinnerXCol0)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(0,0);
	testPiece = testBoard.placePiece(1,1);
	testPiece = testBoard.placePiece(0,1);
	testPiece = testBoard.placePiece(1,2);
	testPiece = testBoard.placePiece(0,2);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoard, getWinnerXCol1)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(1,0);
	testPiece = testBoard.placePiece(0,1);
	testPiece = testBoard.placePiece(1,1);
	testPiece = testBoard.placePiece(0,2);
	testPiece = testBoard.placePiece(1,2);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoard, getWinnerXCol2)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.placePiece(2,0);
	testPiece = testBoard.placePiece(1,1);
	testPiece = testBoard.placePiece(2,1);
	testPiece = testBoard.placePiece(1,2);
	testPiece = testBoard.placePiece(2,2);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, X);
}

TEST(TicTacToeBoard, getInvalidWinner)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, Invalid);
}

TEST(TicTacToeBoard, getBlankWinner)
{
	TicTacToeBoard testBoard;
	Piece testPiece;
	for ( int i = 0; i < 2; i++ )
	{
		for ( int j = 0; j < 2; j++ )
		{
			testPiece = testBoard.placePiece(i,j);
		}
	}
	testPiece = testBoard.placePiece(2,1);
	testPiece = testBoard.placePiece(2,0);
	testPiece = testBoard.placePiece(2,2);
	testPiece = testBoard.placePiece(1,2);
	testPiece = testBoard.placePiece(0,2);
	testPiece = testBoard.getWinner();
	ASSERT_EQ(testPiece, Blank);
}