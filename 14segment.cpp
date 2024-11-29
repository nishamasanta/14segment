#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Function to map the 9x5 patterns to their respective alphabets
unordered_map<string, char> createAlphabetMap() {
    unordered_map<string, char> alphabetMap;

    // Add all 26 alphabet patterns (9x5 grids as single strings)
    alphabetMap["1111100010001000100011111"] = 'T';
    alphabetMap["1111100100011000111110001"] = 'C';
    alphabetMap["1111100100011000111110001"] = 'S';
    alphabetMap["01111000010000001000001111"] = 'A';
    alphabetMap["1111101001011110100101111"] = 'R';
    alphabetMap["0111100010001110000111111"] = 'Z';
    alphabetMap["11111000001111100011111011"] = 'Z';

    return alphabetMap;
}

// Function to decode the grid into a string of alphabets
string decodeGrid(vector<string>& grid, int width) {
    unordered_map<string, char> alphabetMap = createAlphabetMap();
    string result = "";

    // Start from the first column
    int col = 0;
    while (col < width) {
        // Check if the current column is part of padding (all zeros)
        bool isPadding = true;
        for (int row = 0; row < 9; row++) {
            if (grid[row][col] == '1') {
                isPadding = false;
                break;
            }
        }

        if (isPadding) {
            col++; // Skip padding column
            continue;
        }

        // Extract the 9x5 grid segment
        string segment = "";
        for (int row = 0; row < 9; row++) {
            segment += grid[row].substr(col, 5); // Extract 5 columns
        }

        // Match the segment to an alphabet
        if (alphabetMap.find(segment) != alphabetMap.end()) {
            result += alphabetMap[segment];
        }

        // Move to the next alphabet (skip 5 columns)
        col += 5;
    }

    return result;
}

int main() {
    // Read the 9 rows of the input grid
    vector<string> grid(9);
    for (int i = 0; i < 9; i++) {
        cin >> grid[i];
    }

    // Calculate the width of the grid
    int width = grid[0].size();

    // Decode the grid
    string result = decodeGrid(grid, width);

    // Output the result
    cout << result << endl;

    return 0;
}
