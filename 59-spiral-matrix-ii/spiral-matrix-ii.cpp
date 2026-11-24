class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        int x = 1;
        int top=0, bottom=n-1;
        int left=0, right=n-1;
        while(top <= bottom && left <= right){
            for(int j=left; j<=right; j++){
                v[top][j] = x;
                x++;
            }
            top++;
            for(int i=top; i<=bottom; i++){
                v[i][right] = x;
                x++;
            }
            right--;
            if(top <= bottom){
                for(int j=right; j>=left; j--){
                    v[bottom][j] = x;
                    x++;
                }
                bottom--;
            }
            if(left <= right){
                for(int i=bottom; i>=top; i--){
                    v[i][left] = x;
                    x++;
                }
                left++;
            }
        }
        return v;
    }
};