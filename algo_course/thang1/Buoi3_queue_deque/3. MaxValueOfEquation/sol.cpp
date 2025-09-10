class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = (int) points.size();
        vector <int> x(n), y(n); 
        for (int i = 0; i < n; i++) {
            x[i] = points[i][0];
            y[i] = points[i][1]; 
        } 
        deque <int> mydeque; 
        int ans = -1000000007; 
        for (int i = 0; i < n; i++) {
            while (mydeque.empty() == false && x[i] - x[mydeque.front()] > k) {
                mydeque.pop_front(); 
            }    
            if (mydeque.empty() == false) {
                ans = max(ans, x[i] + y[i] + y[mydeque.front()] - x[mydeque.front()]);
            }
            while (mydeque.empty() == false && y[i] - x[i] >= y[mydeque.back()] - x[mydeque.back()]) {
                mydeque.pop_back(); 
            }
            mydeque.push_back(i); 
        }
        return ans; 
    }
};