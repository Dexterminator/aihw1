#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    // Read the board
    vector<string> board;
    int i = 0;
    for (string line; getline(cin, line);) {
        board.push_back(line);
        if (line.find("@") != string::npos)
        {
        	cout << "Found player at line: " << i << "\n";
        }
        i++;
    }

    // TODO: Find path to goal

    // Output answer
    // cout << "U R R U" << endl;
    return 0;
}
