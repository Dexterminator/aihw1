#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Square
{
	int line;
	int pos;
	char type;
	string path;

	Square (int line, int pos, char type, string path) {
		this->line = line;
		this->pos = pos;
		this->type = type;
		this->path = path;
	}
};

int main(int argc, char **argv)
{
    // Read the board
    vector<string> board;
    int i = 0;
    size_t found;
    bool found_player = false;
    Square player_square = Square(0, 0, ' ', "");
    for (string line; getline(cin, line);) {
        board.push_back(line);
        found = line.find("@");
        if (found != string::npos)
        {
			    player_square = Square(i, found, '@', "");
			    found_player = true;
        }
        i++;
    }
    if (!found_player) {
    	cout << endl;
    	return 0;
    }

    queue<Square> q;
    q.push(player_square);
    board[player_square.line][player_square.pos] = 'v';
    while (!q.empty()) {
    	Square square = q.front();
    	q.pop();

    	if (square.type == '.') {
    		cout << square.path << endl;
    		return 0;
    	}

    	if (square.type == ' ' || square.type == '@') {
    		int line_up = square.line - 1;
	    	char up = board[line_up][square.pos];
	    	q.push(Square(line_up, square.pos, up, square.path + "U"));
	    	board[line_up][square.pos] = 'v';

	    	int line_down = square.line + 1;
	    	char down = board[line_down][square.pos];
	    	q.push(Square(line_down, square.pos, down, square.path + "D"));
	    	board[line_down][square.pos] = 'v';

	    	int pos_right = square.pos + 1;
	    	char right = board[square.line][pos_right];
	    	q.push(Square(square.line, pos_right, right, square.path + "R"));
	    	board[square.line][pos_right] = 'v';

	    	int pos_left = square.pos - 1;
	    	char left = board[square.line][pos_left];
	    	q.push(Square(square.line, pos_left, left, square.path + "L"));
	    	board[square.line][pos_left] = 'v';
    	}
    }
    cout << "no path" << endl;
    return 0;
}
