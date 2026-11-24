class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int st = 0, end = n*m-1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            int x = matrix[mid/m][mid%m];
            if(x == target){
                return true;
            }
            else if(x < target){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return false;
    }
};