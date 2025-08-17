using namespace std;
#include <vector>
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int startX = 0,startY = 0;//定义循环的圈的起点
        int loop = n / 2;
        int mid = n / 2;//记录中心点，如果是奇数，则中心点有值
        int count = 1;
        int offset = 1;//记录循环的边界
        int i,j;
        while (loop--){
            i = startX;
            j = startY;
            for (j = startY; j < n - offset; j++) {
                matrix[i][j] = count++;
            }
            for (i = startX; i < n - offset; i++) {
                matrix[i][j] = count++;
            }
            for (; j > startY; j--) {
                matrix[i][j] = count++;
            }
            for (; i > startX; i--) {
                matrix[i][j] = count++;
            }
            startX++;
            startY++;
            offset += 1;
            
        }
        if (n%2)
            {
                matrix[mid][mid] = count;
            }
            return matrix;
    }
};