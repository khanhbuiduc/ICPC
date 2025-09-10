class Solution {
public:
    void backTracking(int pos, vector <int> &listNumbers, vector <vector <int> > &ans, const vector <int> &nums) {
        for (int choice = 0; choice <= 1; choice++) {
            if (choice == 1) {
                listNumbers.push_back(nums[i]); 
            }
            if (pos < (int) nums.size() - 1) {
                backTracking(pos + 1, listNumbers, ans, nums); 
            }
            else {
                ans.push_back(listNumbers); 
            }
            if (choice == 1) {
                listNumbers.pop_back(); 
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int> > ans;
        vector <int> listNumbers; 
        backTracking(0, listNumbers, ans, nums);  
        return ans; 
    }
};