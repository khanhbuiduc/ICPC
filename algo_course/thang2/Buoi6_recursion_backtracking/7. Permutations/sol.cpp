vector <vector <int> > ans;
vector <bool> checkPosition;  
vector <int> accepted; 
int n; 
class Solution {
public:
    void backTrack(int position, const vector <int> &nums) {
        for (int i = 0; i < n; i++) {
            if (checkPosition[i] == false) {
                checkPosition[i] = true; 
                accepted[position] = nums[i];
                if (position == n - 1) {
                    ans.push_back(accepted); 
                }
                else {
                    backTrack(position + 1, nums); 
                }
                checkPosition[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        checkPosition.clear();
        accepted.clear(); 
        n = (int) nums.size();
        checkPosition.resize(n, false);
        accepted.resize(n, 0);
        backTrack(0, nums); 
        return ans; 
    }
};