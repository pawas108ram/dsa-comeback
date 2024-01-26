#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long int

struct node {
   ll maximum;
   ll secondMaximum;
    
  
};

class SegmentTree {
    
public:
    vector<node> nodes;
    SegmentTree(int n) {
        nodes.resize(4 * n + 5);
    }
    node merge(node &a, node &b) {
       ll maxele = max(a.maximum, b.maximum);
       ll secondmaxele = min(max(a.maximum, b.secondMaximum), max(a.secondMaximum, b.maximum));
        return { maxele, secondmaxele };
    }
    void build(vector<ll>& a,ll start,ll end,ll treeNode) {
        if (start == end) {
            nodes[treeNode] = { a[start],LLONG_MIN };
            return;
        }
       ll mid = (start + end) >> 1;
        build(a, start, mid, 2 * treeNode + 1);
        build(a, mid + 1, end, 2 * treeNode + 2);
        nodes[treeNode] = merge(nodes[2 * treeNode + 1], nodes[2 * treeNode + 2]);
        return;
    }

   void set(vector<ll>& a, ll start, ll end, ll treeNode, ll value, ll idx) {
    if (start == end) {
        a[idx] = value;
        nodes[treeNode] = { value, LLONG_MIN };
        return;
    }
    
        ll mid = (start + end) >> 1;
        if (idx <= mid) {
            set(a, start, mid, 2 * treeNode + 1, value, idx);
        }
        else {
            set(a, mid + 1, end, 2 * treeNode + 2, value, idx);
        }
        nodes[treeNode] = merge(nodes[2 * treeNode + 1], nodes[2 * treeNode + 2]);
        return;
    
}


    node query(int left,ll right,ll start,ll end,ll treeNode) {
        if (start > right || end < left) {
            return { LLONG_MIN,LLONG_MIN};
        }
        if (start >= left && end <= right) {
            return nodes[treeNode];
        }
       ll mid = (start + end) >> 1;
        node s1 = query(left, right, start, mid, 2 * treeNode + 1);
        node s2 = query(left, right, mid + 1, end, 2 * treeNode + 2);
        return merge(s1, s2);
    }
};
int main() {
   ll n;
    cin >> n;
    vector<long long int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree st(n);
    st.build(a, 0, n - 1, 0);
    

        ll m;
    cin >> m;
    while (m--) {
        char q;
       ll x, y;
        cin >> q >> x >> y;
        
        

        if (q == 'Q') {
            node ele = st.query(x-1, y-1, 0, n - 1, 0);
            cout << ele.maximum + ele.secondMaximum << endl;
        }
        else {
            st.set(a, 0, n - 1, 0, y, x-1);
        }
    }
    return 0;
}