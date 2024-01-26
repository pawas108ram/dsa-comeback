#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long int

struct Node {
    ll sum;
    ll msum;
    ll ps;
    ll ss;

    

    Node(ll val) : sum(val), msum(max(0LL, val)), ps(max(0LL, val)), ss(max(0LL, val)) {}
    Node(ll sum,ll msum,ll ps,ll ss):sum(sum),msum(msum),ps(ps),ss(ss){}
    Node() : sum(0), msum(0), ps(0), ss(0) {}
};

class SegmentTree {
public:


    vector<Node> Nodes;

    SegmentTree(int n) {
        Nodes.resize(4 * n + 5);
    }

    Node merge(Node& a, Node& b) {
        ll msum = max({a.msum,b.msum,a.ss+b.ps});
        ll sum = a.sum + b.sum;
        ll ps = max(a.ps, a.sum + b.ps);
        ll ss = max(b.ss, b.sum + a.ss);
        return Node(sum, msum, ps, ss);
    }

    void build(vector<ll>& a, int start, int end, int treeNode) {
        if (start == end) {
            Nodes[treeNode] = Node(a[start]);
            return;
        }
        int mid = (start + end) >> 1;
        build(a, start, mid, 2 * treeNode + 1);
        build(a, mid + 1, end, 2 * treeNode + 2);
        Nodes[treeNode] = merge(Nodes[2 * treeNode + 1], Nodes[2 * treeNode + 2]);
        return;
    }

    void set(vector<ll>& a, int start, int end, int treeNode, int idx, ll value) {
        if (start == end) {
            Nodes[treeNode] = Node(value);
            a[idx] = value;
            return;
        }
        int mid = (start + end) >> 1;
        if (idx <= mid) {
            set(a, start, mid, 2 * treeNode + 1, idx, value);
        } else {
            set(a, mid + 1, end, 2 * treeNode + 2, idx, value);
        }
        Nodes[treeNode] = merge(Nodes[2 * treeNode + 1], Nodes[2 * treeNode + 2]);
    }

    Node query(int start, int end, int treeNode, int left, int right) {
        if (start > right || end < left) {
            return Node(LLONG_MIN);
        }
        if (start >= left && end <= right) {
            return Nodes[treeNode];
        }
        int mid = (start + end) >> 1;
        Node s1 = query(start, mid, 2 * treeNode + 1, left, right);
        Node s2 = query(mid + 1, end, 2 * treeNode + 2, left, right);
        return merge(s1, s2);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SegmentTree st(n);
    st.build(arr, 0, n - 1, 0);

    cout << st.query(0, n - 1, 0, 0, n - 1).msum << endl;

    while (m--) {
        ll x, y;
        cin >> x >> y;
        st.set(arr, 0, n - 1, 0, x,  y);
        cout << st.query(0, n - 1, 0, 0, n - 1).msum << endl;
    }

    return 0;
}
