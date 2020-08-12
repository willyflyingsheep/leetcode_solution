class Solution {
private:
    const int INF = 1e8 + 1;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // step1: build graph
        vector<vector<int>> paths(n, vector<int>(n, INF));
        for (auto & edge : edges) {
            paths[edge[0]][edge[1]] = edge[2];
            paths[edge[1]][edge[0]] = edge[2];
        }
        
        // step2: Floyd-Warshall's Algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (paths[i][j] > paths[i][k] + paths[k][j]) {
                        paths[i][j] = paths[i][k] + paths[k][j];
                    }
                }
            }
        }
        
        // step3: get the answer
        int min_neighbors = n;
        int res = -1;
        for (int i = 0; i < n; ++i) {
            int neighbors = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && paths[i][j] <= distanceThreshold) {
                    neighbors++;
                }
            }
            if (neighbors <= min_neighbors) {
                min_neighbors = neighbors;
                res = i;
            }
        }
        return res;
        
    }
};