//////////////////////////////////////
//Author: Randall Woodruff
//Title: Red queens
//summary: the purpose of this program is to demonstrate a recusive backtracking solution to the "red queens problem
//In brief, the goal is to fit as many queens on a standard chess board without any of the queens attaking one another. 
//solution:  this project will be facilated by the implimation of a board class which will provide the ability to iterate over avalibe legal moves and maange the current board state and print it to the screen.  

# include "board.h"
# include <iostream>
#include <assert.h> 

void placeMove(board &b, int r, int c);
void boardClassTester();

bool fillQueens(int nQs, board &b);

int main(){
	boardClassTester();
	board bob;

	bob.print();
	/*std::cout<<std::endl;
	

	placeMove(bob,0,0);
	placeMove(bob,1,7);
	
	placeMove(bob,4,4);
	bob.removeMove(1,7);
	bob.print();
	placeMove(bob,4,4);
	
	bob.removeMove(0,0);
	placeMove(bob,4,4);
	placeMove(bob,1,7);
	*/

	if(fillQueens(8,bob)){
		std::cout<<"YAY!!!";
	}
		std::cout<<"awwww...";
}


void placeMove(board &b, int r, int c){
	if ( !b.setMove (r,c) ){
		std::cout<<"cannot make move at location "<<r<<", "<<c <<std::endl;
	}
	b.print();
	std::cout<<std::endl;
}

void boardClassTester(){
	board bob;

	assert(bob.setMove(-1,0)==false);// bouds check
	assert(bob.setMove( 0,-1)==false);// bouds check
	assert(bob.setMove( 0,0)==true);
	assert(bob.setMove( 1,0)==false);//not safe move check, row
	assert(bob.setMove( 2,1)==true);
	assert(bob.setMove( 2,5)==false);//not safe move check, collum
	assert(bob.setMove( 7,7)==false);//not safe move check, diagonal
	assert(bob.setMove( 7,8)==false);// bouds check
	assert(bob.setMove( 8,7)==false);// bouds check
	//testing removes function
	bob.removeMove(2,1);
	assert(bob.setMove( 2,5)==true);//should now work
	assert(bob.setMove( 0,1)==false);//should not have allowed move here now
}


bool fillQueens(int nQs, board &b){
	if ( nQs == 0 ) {
		b.print();	
		return true;
	}

	for( int i = 0 ; i< b.size()*b.size() ; i++){//itterate over board moves
		if ( b.setMove( i/b.size(), i%b.size() ) ){//attempting to set move
			if ( fillQueens(nQs-1, b)) return true; //once it finds a legal move, recurses
			b.removeMove( i/b.size(), i%b.size()  );// fall through case where problem could not be solves with current index, need to undo move
		}


	}
	return false;

}