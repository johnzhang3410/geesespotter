#include "geesespotter_lib.h"
#include <iostream>

char * createBoard(std::size_t xdim, std::size_t ydim){
	char * board = new char[xdim*ydim];

	for (std::size_t k{0}; k < xdim*ydim; k++){
		board[k] = 0;
	}

	return board;
}

/*bool is_in_bound(std::size_t xloc, std::size_t yloc, std::size_t xdim, std::size_t ydim){
	if (xloc - 1 < 0 || xloc + 1 > xdim || yloc - 1 < 0 || yloc + 1 > ydim){
		return false;
	}
}*/

void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim){

	//bool is_in_bound{true};

	for (std::size_t k{0}; k < xdim*ydim; k++){

		//int counter = 0;
		//Gives the current location
		int xloc = k % xdim;
		int yloc = k / xdim;

		//Out of bound if the field is out of bound
		/*if (xloc < 0 || xloc > xdim || yloc < 0 || yloc > ydim){
			is_in_bound = false;
		}*/

		/*if (board[k] != 9){
			if (xloc < 0 || xloc > xdim || yloc < 0 || yloc > ydim){//Then it's on the side or corner
				is_in_bound = false;
			}
		}*/



		/*if (is_in_bound == true){
			board[]
		}*/

		//If the value in the field is bigger than '9' (Geese), set it to '9'
		/*0010 1011
		0000 1111
		0000 1011

		0010 1011
		0000 0010
		0010 1001*/
		/*if ((valueMask() & board[k]) == 10){
			board[k] ^= 0x03;
		}else if ((valueMask() & board[k]) == 11){
			board[k] ^= 0x02;
		}
		 */
		//If the value in the field is equal to '9' (Geese)
		if ((valueMask() & board[k]) == 9){
			//For all neighboring fields
			for (int i{-1}; i<2; i++){
				for(int j{-1}; j<2; j++){
					if ((xloc+j) < xdim && (xloc+j) >= 0 && (yloc+i) < ydim && (yloc+i) >= 0){
						int loc = (yloc+i)*xdim + xloc+j;
						if ((board[loc] & valueMask()) != 9){
							board[loc] += 1;
						}
					}
				}
			}

			//If index is at zero
			/*if (k == 0){
				if ((board[1] & valueMask()) != 9){
					board[1] += 1;
				}
				if ((board[xdim] & valueMask()) != 9){
					board[xdim] += 1;
				}
				if ((board[xdim+1] & valueMask()) != 9){
					board[xdim+1] += 1;
				}
				//If index is in the upper right corner
			}else if (k == xdim-1){
				if ((board[xdim-2] & valueMask()) != 9){
					board[xdim-2] += 1;
				}
				if ((board[2 * xdim-1] & valueMask()) != 9){
					board[2 * xdim-1] += 1;
				}
				if ((board[2 * xdim-2] & valueMask()) != 9){
					board[2 * xdim-2] += 1;
				}
				//If index is in the lower right corner
			}else if (k == xdim * ydim - 1){
				if ((board[xdim*ydim-2] & valueMask()) != 9){
					board[xdim * ydim-2] += 1;
				}
				if ((board[xdim*ydim-xdim-1] & valueMask()) != 9){
					board[xdim * ydim - xdim-1] += 1;
				}
				if ((board[xdim*ydim-xdim-2] & valueMask()) != 9){
					board[xdim * ydim - xdim-2] += 1;
				}
				//If the index is in the lower left corner
			}else if(k == xdim * ydim -xdim){
				if ((board[xdim*ydim-xdim+1] & valueMask()) != 9){
					board[xdim * ydim -xdim+1] += 1;
				}
				if ((board[xdim*ydim-2*xdim] & valueMask()) != 9){
					board[xdim * ydim - 2*xdim] += 1;
				}
				if ((board[xdim*ydim-2*xdim+1] & valueMask()) != 9){
					board[xdim * ydim - 2*xdim+1] += 1;
				}
				//If the index is in the first line middle
			}else if (k > 0 && k < xdim-1){
				if ((board[k-1] & valueMask()) != 9){
					board[k-1] += 1;
				}
				if ((board[k+1] & valueMask()) != 9){
					board[k+1] += 1;
				}
				if ((board[k+xdim-1] & valueMask()) != 9){
					board[k+xdim-1] += 1;
				}
				if ((board[k+xdim] & valueMask()) != 9){
					board[k+xdim] += 1;
				}
				if ((board[k+xdim+1] & valueMask()) != 9){
					board[k+xdim+1] += 1;
				}
				//For last line middle
			}else if (k > xdim*ydim - xdim && k < xdim*ydim-1){
				if ((board[k-1] & valueMask()) != 9){
					board[k-1] += 1;
				}
				if ((board[k+1] & valueMask()) != 9){
					board[k+1] += 1;
				}
				if ((board[k-xdim-1] & valueMask()) != 9){
					board[k-xdim-1] += 1;
				}
				if ((board[k-xdim] & valueMask()) != 9){
					board[k-xdim] += 1;
				}
				if ((board[k-xdim+1] & valueMask()) != 9){
					board[k-xdim+1] += 1;
				}
				//On the side from the left
			}else if (k % xdim == 0){
				if ((board[k-xdim] & valueMask()) != 9){
					board[k - xdim] += 1;
				}
				if ((board[k-xdim+1] & valueMask()) != 9){
					board[k-xdim + 1] += 1;
				}
				if ((board[k+1] & valueMask()) != 9){
					board[k+1] += 1;
				}
				if ((board[k+xdim] & valueMask()) != 9){
					board[k+xdim] += 1;
				}
				if ((board[k+xdim+1] & valueMask()) != 9){
					board[k+xdim + 1] += 1;
				}
				//On the side from the right
			}else if ((k-1) % xdim == 5){
				if ((board[k-xdim-1] & valueMask()) != 9){
					board[k-xdim-1] += 1;
				}
				if ((board[k-xdim] & valueMask()) != 9){
					board[k-xdim] += 1;
				}
				if ((board[k-1] & valueMask()) != 9){
					board[k-1] += 1;
				}
				if ((board[k+xdim-1] & valueMask()) != 9){
					board[k+xdim-1] += 1;
				}
				if ((board[k+xdim] & valueMask()) != 9){
					board[k+xdim] += 1;
				}
				//In the middle
			}else{
				if ((board[k-xdim-1] & valueMask()) != 9){
					board[k-xdim-1] += 1;
				}
				if ((board[k-xdim] & valueMask()) != 9){
					board[k-xdim] += 1;
				}
				if ((board[k-xdim+1] & valueMask()) != 9){
					board[k-xdim+1] += 1;
				}
				if ((board[k-1] & valueMask()) != 9){
					board[k-1] += 1;
				}
				if ((board[k+1] & valueMask()) != 9){
					board[k+1] += 1;
				}
				if ((board[k+xdim-1] & valueMask()) != 9){
					board[k+xdim-1] += 1;
				}
				if ((board[k+xdim] & valueMask()) != 9){
					board[k+xdim] += 1;
				}
				if ((board[k+xdim+1] & valueMask()) != 9){
					board[k+xdim+1] += 1;
				}
			}
		}*/
			/*if (board[k-xdim-1] > 9){
			board[k-xdim-1] = 9;
		}else if(board[k-xdim] > 9){
			board[k-xdim] = 9;
		}else if (board[k-xdim+1] > 9){
			board[k-xdim+1];
		}else if (board[k-1] > 9){
			board[k-1];
		}else if(board[k+1] > 9){
			board[k+1];
		}*/
		}
	}
}

void hideBoard(char * board, std::size_t xdim, std::size_t ydim){
	/*0000 1001
	|0010 0000
	0010 1001*/
	for (std::size_t k{0}; k < xdim*ydim; k++){
		board[k] |= hiddenBit();
	}
}

void cleanBoard(char * board){
	delete []board;
	board = nullptr;
}

void printBoard(char * board, std::size_t xdim, std::size_t ydim){

	/*	int index = 0;
	for (int i{0}; i < xdim; i++){
		for (int j{0}; j < ydim; j++){
			if (board[(yloc+i)*xdim + xloc+j] )
		}
	}*/

	//int xloc = k % xdim;
	//int yloc = k/xdim;
	for (int i{0}; i<xdim*ydim; i++){

		if ((board[i] & markedBit()) == markedBit()){
			std::cout << 'M';
		}else if((board[i] & hiddenBit()) == hiddenBit()){
			std::cout << '*';
		}else{
			std::cout << (int)board[i];
		}

		if ((i+1) % xdim == 0){
			std::cout << std::endl;
		}
	}
}


int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	//Return 1 if the field is marked
	/*0011 0000
	0001 0000
	0001 0000*/

	if ((board[yloc*xdim + xloc] & markedBit()) == markedBit()){
		return 1;
		//Return 2 if field is already revealed. Outputs 1 if hidden, 0 if revealed
		/*	0000 0000
	0010 0000*/
	}

	if ((board[yloc*xdim + xloc] & hiddenBit()) == 0){
		return 2;
		//Return 9 if field contains a goose
		/*0010 1001
	0000 1111
	0000 1001 (Revealed, not marked and = 9)*/
	}

	if ((valueMask() & board[yloc*xdim + xloc]) == 9){
		board[yloc*xdim + xloc] &= valueMask();
		return 9;
	}

	if ((board[yloc*xdim + xloc] & valueMask()) == 0){
		for (int i{-1}; i<2; i++){
			for(int j{-1}; j<2; j++){
				if ((xloc+j) < xdim && (xloc+j) >= 0 && (yloc+i) < ydim && (yloc+i) >= 0){
					int loc = (yloc+i)*xdim + xloc+j;
					board[loc] ^= hiddenBit();
				}
			}
		}
	}else{
		board[yloc*xdim + xloc] ^= hiddenBit();
	}

	//If an empty field is revealed, also reveal the value of the neighbors that don't contain geese
	/*0010 0001 (Hidden and not marked with a value of 1)
	^0010 0000 (hiddenBit())
	0000 0001 (Revealed and not marked with a value of 1)*/
	/*if ((board[yloc*xdim + xloc] & valueMask()) == 0){
				//Reveal the field and later all fields surrounding it
				board[yloc*xdim + xloc] ^= hiddenBit();
				if (xloc - 1 >= 0 && xloc - 1 <= xdim){ //Checks if the field is out of bound in the x direction
					board[yloc*xdim + xloc-1] ^= hiddenBit(); //If not out of bound, reveal its value)(Left)
				}

				if (xloc + 1 >= 0 && xloc + 1 <= xdim){
					board[yloc*xdim + xloc+1] ^= hiddenBit(); //From the right
				}

				if (xloc - 1 >= 0 && yloc - 1 >= 0){ //Check if the upper left corner is in bound
					board[yloc*xdim + xloc -xdim - 1] ^= hiddenBit(); //If it is, flip the hiddenBit()
				}

				if (yloc - 1 >= 0){ //Checks the top
					board[yloc*xdim + xloc - xdim] ^= hiddenBit();
				}

				if (xloc + 1 < xdim && yloc - 1 >= 0){ //Checks the upper right corner
					board[yloc*xdim + xloc -xdim + 1] ^= hiddenBit();
				}

				if (xloc - 1 >= 0 && yloc + 1 < ydim){ //Checks bottom left corner
					board[yloc*xdim + xloc +xdim - 1] ^= hiddenBit();
				}

				if (yloc + 1 < ydim){ //Checks the bottom field
					board[yloc*xdim + xloc +xdim] ^= hiddenBit();
				}

				if (xloc + 1 < xdim && yloc + 1 < ydim){ //Checks lower right corner
					board[yloc*xdim + xloc + xdim +1] ^= hiddenBit();
				}
			}else{ //If the field is not empty (Have a value), just reveal the field itself
				board[yloc*xdim + xloc] ^= hiddenBit();
			}*/

	return 0;

}

int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	/*0010 0101 (0x25)
	&0000 1111 (0x0F)
	0000 0101 (0x05)

	0010 0101 (0x25)
	&1111 0000 (0xF0)
	0010 0000 (0x20)

	//True for second
	0011 0101 (0x30) (hidden and marked)
	&0011 0000 (0x30)
	0011 0000 (0x30) (hidden and marked)

	0011 0101 (hidden and marked)
	^0001 0000 (0x10)
	0010 0101 (hidden and not marked)

	//True condition for third
	0010 (Hidden and not marked)
	0011 (hidden and marked)
	0010 (hidden and not marked)
//0011 0000 (0x30)
	0011 0101 (Hidden and marked)
	&0011 0000 (0x30)
	0011 0000 (0x30) (Hidden and not marked)*/

	if ((board[xdim*yloc + xloc] & 0xF0) == 0x00) {
		return 2;
	}else if((board[xdim*yloc + xloc] & 0x30) == 0x30){
		board[xdim*yloc + xloc] ^= markedBit();
		return 0;
	}else if ((board[xdim*yloc + xloc] & 0x30) == hiddenBit()){
		board[xdim*yloc + xloc] |= 0x30;
		return 0;
	}

	// check if marked, then unmark
	// check if hidden, then mark it
	return 0;
}

bool isGameWon(char * board, std::size_t xdim, std::size_t ydim){
	//Game is won when there are only geeses left (value 9) and all other fields have been revealed
	/*0010 1001
	0011 0000
	0010 0000*/
	for (std::size_t k{0}; k < xdim*ydim; k++){
		//If geese has been revealed then game is not won
		if ((board[k] & 0x30) == hiddenBit() && (board[k] & valueMask()) != 9){
			return false;
		}
	}
	return true;
}

//1. If it has a hidden bit and it does not equal to 9, then return false
//2. else return true


