#pragma once
class board
{
public:
	board(void);
	~board(void);
	
	void print();
	bool setMove(int c, int r);
	void removeMove(int c, int r);
	int size();

private: //helper methods
	void initBoard();
	void initMoves();

	bool moveLegal(int r,int c);
	bool indexLegal(int x);

	void updateLegalMoves (int r,int c);
	void redoLegalMoves();

	void setRowBlocked(int r);
	void setCollumnBlocked(int c);
	void setDiagonalsBlocked(int r,int c);

private: //iVars
	static const int BOARD_SIZE = 8;
	char cBoard[BOARD_SIZE][BOARD_SIZE];// stores location of pieces on board
	bool mBoard[BOARD_SIZE][BOARD_SIZE];//stores valid spcaces left on board 
};

