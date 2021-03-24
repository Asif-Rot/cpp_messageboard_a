#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace ariel {
    void resizerow(vector<vector<char>> board, unsigned int newsize, unsigned int size);
    void resizecol(vector<vector<char>> board, unsigned int col, unsigned int boardsize);

    Board::Board() {
        full = 0;
    }

    void Board::post(unsigned int row, unsigned int col, Direction d, string message) {
        unsigned int newsize = 0;
        unsigned int count = 0;

        if (full == 0) {
            full = 1;
            vector<char> tmp (col + message.length());
            fill(tmp.begin(), tmp.end(), '_');

            for (unsigned int i = 0 ; i < row + message.length() ; i++) {
                showboard.push_back(tmp);
            }
        }


        if (d == Direction::Horizontal) {
            if (row > showboard.size()) {
                newsize = row - showboard.size();
                resizerow(showboard, newsize, message.length());
            }
            
            if (col + message.length() > showboard[0].size()) {
                newsize = col + message.length();
                resizecol(showboard, newsize, showboard.size());   
            }
            count = 0;
            for (unsigned int i = col; i < col + message.length(); i++){
                showboard[row][i] = message.at(count);
                count++;
            }
        }
        else {
            if (row + message.length() > showboard.size()) {
                newsize = row + message.length() - showboard.size();
                resizerow(showboard, newsize, showboard[0].size());
            }

            if (col > showboard[0].size()) {
                resizecol(showboard, col, showboard.size());
            }

            count = 0;
            for (unsigned int i = row; i < row + message.size(); i++) {
                showboard[i][col] = message.at(count);
                count++;
	        }
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int length) {
        string printit;
        if (d == Direction::Horizontal) {
            for (unsigned int i = col; i < col + length; i++) {
                printit += showboard[row][i];
	        }

        }
        else {
            for (unsigned int i = row; i < row + length; i++) {
                printit += showboard[i][col];
	        }
	    }

        return printit;
    }

    void Board::show() {
        for (vector<char> &row: showboard) {
            for (char val: row) {
            	cout << val << " ";
            }
            cout << '\n';
	    }
    }

    void resizerow(vector<vector<char>> board, unsigned int newsize, unsigned int size) {
        vector<char> tmp (size);
        fill(tmp.begin(), tmp.end(), '_');

        for (unsigned int i = 0 ; i < newsize ; i++) {
            board.push_back(tmp);
        }
    }

    void resizecol(vector<vector<char>> board, unsigned int col, unsigned int boardsize) {
        unsigned int size = board[0].size();
        for (unsigned int  i = 0 ; i < boardsize ; i++) {
            board[i].resize(col);
            fill(board[i].begin()+size, board[i].end(), '_');
        }
    }
}
