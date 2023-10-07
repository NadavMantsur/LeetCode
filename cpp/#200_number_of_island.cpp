// DFS stands for Depth-First Search, and it is a fundamental algorithm used in 
// computer science and graph theory for traversing or searching through tree or 
// graph data structures. The primary idea behind DFS is to explore as far as 
// possible along a branch before backtracking.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int numOfRows = grid.size();
        int numOfCols = grid[0].size();

        for (int i = 0; i < numOfRows; ++i) {
            for (int j = 0; j < numOfCols; ++j) {
                if (grid[i][j] == '1') { // Found land
                    ++cnt;
                    dfs(grid, i, j);
                }
            }
        }

        return cnt;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int numOfRows = grid.size();
        int numOfCols = grid[0].size();

        if (i < 0 || j < 0 || i >= numOfRows || j >= numOfCols || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0'; // Mark cell as visited

        // Explore adjacent cells
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
        };

    cout << sol.numIslands(grid) <<endl; //by reference to prevent copy

    return 0;
}