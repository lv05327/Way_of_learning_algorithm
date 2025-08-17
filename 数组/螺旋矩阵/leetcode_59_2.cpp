#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir = 0, curr = 0, x = 0, y = 0, nx = 0, ny = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};//定义两个方向上的方向数组
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        while (curr < n * n) {
            curr++;
            matrix[x][y] = curr;
            visited[x][y] = true;
            
            nx = x + dx[dir];
            ny = y + dy[dir];
            
            if (nx >= n || ny >= n || nx < 0 || ny < 0 || visited[nx][ny]) {
                dir = (dir + 1) % 4;//判断是否要转向
                x = x + dx[dir];
                y = y + dy[dir];
            } else {
                x = nx;
                y = ny;
            }
        }
        return matrix;
    }
};
