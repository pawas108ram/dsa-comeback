#include <bits/stdc++.h>
#include <vector>
#define ll long long int
using namespace std;

struct sumproperties{
    ll squaresum;
    ll sum;
}

struct lazyproperties{
    ll value;
    ll type;

}
class SegmentTree {
public:
    vector<sumproperties> sums;
    vector<lazyproperties> lazy;
    SegmentTree(int n) {
        sums.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
    }

    sumproperties merge(sumproperties &a,sumproperties &b){
        ll squaresum = a.squaresum + b.squaresum;
        ll sum = a.sum + b.sum;
        return {squaresum, sum};
    }

    void build(int start, int end, vector<ll>& a, int treeNode) {
        if (start == end) {
            sums[treeNode] = {a[start]*a[start],a[start]} ;
            return;
        }
        int mid = (start + end) >> 1;
        build(start, mid, a, 2 * treeNode + 1);
        build(mid + 1, end, a, 2 * treeNode + 2);
        sums[treeNode] = merge(sums[2 * treeNode + 1], sums[2 * treeNode + 2]);
        return;
    }

    long long getsum(int start, int end, int treeNode, int left, int right) {
        if (start > end) {
            return 0;
        }
        if (start > right || end < left) {
            return 0;
        }
        if (start >= left && end <= right) {
            return sums[treeNode].squaresum;
        }
        int mid = (start + end) >> 1;
        long long s1 = getsum(start, mid, 2 * treeNode + 1, left, right);
        long long s2 = getsum(mid + 1, end, 2 * treeNode + 2, left, right);
        return s1 + s2;
    }

  void addx(int start, int end, int treeNode, int left, int right, int value) {
    if (start > end) {
        return;
    }
    if (lazy[treeNode].type==1 &&  lazy[treeNode] != 0) {
        sums[treeNode].squaresum+=(end-start+1)*
        if (start != end) {
            lazy[2 * treeNode + 1] += lazy[treeNode];
            lazy[2 * treeNode + 2] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    if (start > right || end < left) {
        return;
    }
    if (start >= left && end <= right) {
        sums[treeNode] +=  value * value;
        if (start != end) {
            lazy[2 * treeNode + 1] += value;
            lazy[2 * treeNode + 2] += value;
        }
        return;
    }
    int mid = (start + end) >> 1;
    addx(start, mid, 2 * treeNode + 1, left, right, value);
    addx(mid + 1, end, 2 * treeNode + 2, left, right, value);
    sums[treeNode] = sums[2 * treeNode + 1] + sums[2 * treeNode + 2];
}

void setx(int start, int end, int treeNode, int left, int right, int value) {
    if (start > end) {
        return;
    }
    if (lazy[treeNode] != 0) {
        sums[treeNode] =  lazy[treeNode] * lazy[treeNode];
        if (start != end) {
            lazy[2 * treeNode + 1] = lazy[treeNode];
            lazy[2 * treeNode + 2] = lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    if (start > right || end < left) {
        return;
    }
    if (start >= left && end <= right) {
        sums[treeNode] =  value * value;
        if (start != end) {
            lazy[2 * treeNode + 1] = value;
            lazy[2 * treeNode + 2] = value;
        }
        return;
    }
    int mid = (start + end) >> 1;
    setx(start, mid, 2 * treeNode + 1, left, right, value);
    setx(mid + 1, end, 2 * treeNode + 2, left, right, value);
    sums[treeNode] = sums[2 * treeNode + 1] + sums[2 * treeNode + 2];
}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        SegmentTree tree(n);
        tree.build(0, n - 1, arr, 0);
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int st, nd, x;
                cin >> st >> nd >> x;

                tree.addx(0, n - 1, 0, st, nd, x);
            } else if (op == 2) {
                int st, nd;
                cin >> st >> nd;

                cout << tree.getsum(0, n - 1, 0, st, nd) << endl;
            } else {
                int st, nd, x;
                cin >> st >> nd >> x;

                tree.setx(0, n - 1, 0, st, nd, x);
            }
        }
    }
    return 0;
}
