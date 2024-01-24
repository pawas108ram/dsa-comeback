#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct SegmentTreeNode {
    long long max;
    long long secondmax;
};

class SegmentTree {
    vector<SegmentTreeNode> sums;

public:
    SegmentTree(int n) {
        sums.resize(3*n);
    }
   SegmentTreeNode merge(SegmentTreeNode& a, SegmentTreeNode& b) {
    long long max_val = max(a.max, b.max);
    long long second_max = min(max(a.max, b.secondmax), max(a.secondmax, b.max));
    return {max_val, second_max};
}

    void build(vector<int>& a, int start, int end, int treeNode) {
    if (start == end) {
        sums[treeNode].max = a[start];
        sums[treeNode].secondmax = LLONG_MIN;
        return;
    }
    int mid = (start + end) / 2;
    build(a, start, mid, 2 * treeNode);
    build(a, mid + 1, end, 2 * treeNode + 1);
    sums[treeNode] = merge(sums[2 * treeNode], sums[2 * treeNode + 1]);
}


    void set(vector<int>& a, int start, int end, int treeNode, int value, int idx) {
        if (start == end) {
            a[idx] = value;
            sums[treeNode] = {value, LLONG_MIN};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            set(a, start, mid, 2 * treeNode, value, idx);
        } else {
            set(a, mid + 1, end, 2 * treeNode + 1, value, idx);
        }
        sums[treeNode] = merge(sums[2 * treeNode], sums[2 * treeNode + 1]);
        return;
    }

    void display(){
        for (int i = 0; i < sums.size();i++){
            cout << sums[i].max << " " << sums[i].secondmax << endl;
        }
    }

   

SegmentTreeNode query(int left, int right, int treeNode, int start, int end) {
    if (start > right || end < left) {
        return {LLONG_MIN,LLONG_MIN};
    }
    if (start >= left && end <= right) {
        return sums[treeNode];
    }
    int mid = (start + end) / 2;
    SegmentTreeNode s1 = query(left, right, 2 * treeNode, start, mid);
    SegmentTreeNode s2 = query(left, right, 2 * treeNode + 1, mid + 1, end);
    return merge(s1, s2);
}

};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SegmentTree st(n);
    st.build(arr, 0, n-1, 0);
    int m;
    cin >> m;
    st.display();
    // while (m--)
    // {
    //     char q;
    //     int x, y;
    //     cin >> q >> x >> y;
    //     if (q == 'Q')
    //     {
    //         SegmentTreeNode ele = st.query(x - 1, y - 1, 0, 0, n - 1);
    //         cout << ele.max + ele.secondmax << endl;
    //     }
    //     else
    //     {
    //         st.set(arr, 0, n - 1, 0, y, x - 1);
    //     }
    // }

    return 0;
}
