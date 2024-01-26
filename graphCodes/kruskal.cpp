#include<bits/stdc++.h>
#include<vector>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        rank.assign(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionByRank(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[px] = py;
                rank[py]++;
            }
        }
    }
};

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;

    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({w, x, y});
    }

    sort(edges.begin(), edges.end());

    DSU ds(v);
    int cost = 0;
    vector<vector<int>> ans;

    for (auto edge : edges) {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        if (ds.find(x) != ds.find(y)) {
            cost += w;
            ds.unionByRank(x, y);
            ans.push_back({x, y, w});
        }
    }

    

    for (auto ele : ans) {
        cout << ele[0] << " " << ele[1] << " " << ele[2] << endl;
    }

    return 0;
}
