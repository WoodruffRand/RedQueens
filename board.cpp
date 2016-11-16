#include "board.h"
#include <iostream>

board::board(void){
	initBoard();
	initMoves();
}


board::~board(void){
}


//public functions 

void board::print(){
	for(int i = 0 ; i < BOARD_SIZE;i++){
		std::cout<<'|';
		for(int j = 0 ; j < BOARD_SIZE;j++){
			std::cout<<cBoard[i][j];
		}
		std::cout<<'|'<<std::endl;
	}
}

int board::size(){

	return BOARD_SIZE;
}

bool board::setMove(int r, int c){
	if( moveLegal(r,c) ){
		cBoard[r][c]= 'Q';  //set queen in board 
		updateLegalMoves (r,c);//update legal movese
		return true;
	}

	return false;
}

void board::removeMove(int r, int c){
	if( cBoard[r][c] == 'Q' ){//avoids work if no piece is present
		cBoard[r][c]= ' ';  //remove queen in board 
		redoLegalMoves ();//update legal movese
	}

}

void board::redoLegalMoves(){
	initMoves(); //WHOA! carefull!
	
	for(int i = 0 ; i < BOARD_SIZE;i++){
		for(int j = 0 ; j < BOARD_SIZE;j++){
			if (cBoard[i][j] == 'Q'){
				updateLegalMoves(i,j);
			}
		}
	}

}


void board::updateLegalMoves (int r,int c){
	setRowBlocked(r);
	setCollumnBlocked(c);
	setDiagonalsBlocked(r,c);
}

void board::setRowBlocked(int r){
	for (int i = 0; i < BOARD_SIZE; i++){
		mBoard [r][i]=false;
	}
}

void board::setCollumnBlocked(int c){
	for (int i = 0; i < BOARD_SIZE; i++){
		mBoard [i][c]=false;
	}
}

void board::setDiagonalsBlocked(int r,int c){
	
	//neg slop diag
	int rowInd = r;
	int colInd = c; 
	
	while ( indexLegal(--rowInd) & indexLegal(--colInd) ){
		mBoard [rowInd][colInd]=false;
	}

	rowInd = r;
	colInd = c; 
	
	while ( indexLegal(++rowInd) & indexLegal(++colInd) ){
		mBoard [rowInd][colInd]=false;
	}
	//pos slope diag

	rowInd = r;
	colInd = c; 
	
	while ( indexLegal(--rowInd) & indexLegal(++colInd) ){
		mBoard [rowInd][colInd]=false;
	}

	rowInd = r;
	colInd = c; 
	
	while ( indexLegal(++rowInd) & indexLegal(--colInd) ){
		mBoard [rowInd][colInd]=false;
	}

}







///private helper functions
void board::initBoard(){
	for(int i = 0 ; i < BOARD_SIZE;i++){
		for(int j = 0 ; j < BOARD_SIZE;j++){
			cBoard[i][j]=' ';
		}
	}

}


void board::initMoves(){
	for(int i = 0 ; i < BOARD_SIZE;i++){
		for(int j = 0 ; j < BOARD_SIZE;j++){
			mBoard[i][j]=true;
		}
	}

}



bool board::moveLegal(int r,int c){
	if( !indexLegal(r) ) return false;
	if( !indexLegal(c) ) return false;
	return mBoard[r][c]   ;

}

bool board::indexLegal(int x){
	if( x<0 ) return false;
	if (BOARD_SIZE-1<x ) return false; 

	return true;
}