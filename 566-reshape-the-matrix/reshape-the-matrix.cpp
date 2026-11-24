class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(n*m != r*c){
            return mat;
        }
        vector<vector<int>> v;
        int x = 0, y = 0;
        for(int i=0; i<r; i++){
            vector<int> a;
            for(int j=0; j<c; j++){
                if(y < m){
                    a.push_back(mat[x][y]);
                    y++;
                }
                else{
                    if(x != n-1){
                        x++;
                        y = 0;
                        a.push_back(mat[x][y]);
                        y++;
                    }
                }
            }
            v.push_back(a);
        }
        return v;
    }
};