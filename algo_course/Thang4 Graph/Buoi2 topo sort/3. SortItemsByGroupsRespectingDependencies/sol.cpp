class Solution {
public:
    bool haveCycle(int u, vector <int> &state, const vector <vector <int>> &adj) {
        state[u] = 1; 
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            if (state[v] == 1) {
                return true; 
            }
            else if (state[v] == 0) {
                if (haveCycle(v, state, adj) == true) {
                    return true; 
                }
            }
        }
        state[u] = 2;
        return false; 
    }
    void dfs(int u, stack <int> &store, vector <bool> &visited, const vector <vector <int>> &adj) {
        visited[u] = true;
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            if (visited[v] == false) {
                dfs(v, store, visited, adj); 
            }
        }
        store.push(u); 
    }
    vector <int> process(const vector <vector <int>> &adj) {
        vector <int> ret; 
        vector <int> state;
        int k = (int) adj.size(); 
        state.resize(k, 0); 
        for (int u = 0; u < k; u++) {
            if (state[u] == 0) {
                if (haveCycle(u, state, adj) == true) {
                    return ret; 
                }
            }
        }
        stack <int> store; 
        vector <bool> visited; 
        visited.resize(k, false);
        for (int u = 0; u < k; u++) {
            if (visited[u] == false) {
                dfs(u, store, visited, adj); 
            }
        } 
        while (store.empty() == false) {
            int u = store.top();
            store.pop();
            ret.push_back(u); 
        }
        return ret; 
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < (int) group.size(); i++) {
            if (group[i] == -1) {
                group[i] = m;
                m++; 
            }
        }
        vector <vector <int> > adj;
        adj.resize(n);
        vector <vector <int> > adj_group; 
        adj_group.resize(m); 
        for (int u = 0; u < n; u++) {
            vector <int> &listElement = beforeItems[u];
            for (int j = 0; j < (int) listElement.size(); j++) {
                int v = listElement[j];
                adj[v].push_back(u);
                if (group[v] != group[u]) {
                    adj_group[group[v]].push_back(group[u]);
                } 
            }
        }
        vector <int> ans; 
        vector <int> topo = process(adj);
        if (topo.empty() == true) {
            return ans; 
        }
        vector <int> topoGroup = process(adj_group);
        if (topoGroup.empty() == true) {
            return ans; 
        }
        vector <vector <int>> group_order;
        group_order.resize(m); 
        for (int i = 0; i < (int) topo.size(); i++) {
            int u = topo[i];
            group_order[group[u]].push_back(u);
        }
        for (int i = 0; i < (int) topoGroup.size(); i++) {
            int g = topoGroup[i]; 
            for (int j = 0; j < (int) group_order[g].size(); j++) {
                int u = group_order[g][j]; 
                ans.push_back(u); 
            }
        }
        return ans;
    }
};