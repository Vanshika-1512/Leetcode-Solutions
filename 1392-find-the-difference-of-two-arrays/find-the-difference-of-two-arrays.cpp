class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> v;
        vector <int> a;
        vector<int> b;
        for(int i=0; i<nums1.size(); i++){
            int found = 0;
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    found = 1;
                }
            }
            if(found == 0 && find(a.begin(), a.end(), nums1[i]) == a.end()){
                a.push_back(nums1[i]);
            }
        }
        for(int i=0; i<nums2.size(); i++){
            int found = 0;
            for(int j=0; j<nums1.size(); j++){
                if(nums2[i] == nums1[j]){
                    found = 1;
                }
            }
            if(found == 0 && find(b.begin(), b.end(), nums2[i]) == b.end()){
                b.push_back(nums2[i]);
            }
        }
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};