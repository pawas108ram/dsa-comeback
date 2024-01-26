#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;

class SegmentTree{
    public:
    vector<ll> sums;
    vector<ll> lazy;
    SegmentTree(int n){
        sums.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
    }
    void build(vector<ll>&a,int start,int end,int treeNode){
        if(start==end){
            sums[treeNode] = a[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(a, start, mid, 2 * treeNode + 1);
        build(a, mid + 1, end, 2 * treeNode + 2);
        sums[treeNode] = sums[2 * treeNode + 1] + sums[2 * treeNode + 2];
        return;
    }

  void updateLazy(int start, int end, int left, int right, int treeNode, int inc) {
    if (end < start || start > right || end < left) {
        return;
    }
    if (lazy[treeNode] != 0) {
        sums[treeNode] += lazy[treeNode];
        if (start != end) {
            lazy[2 * treeNode + 1] += lazy[treeNode];
            lazy[2 * treeNode + 2] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    if (start >= left && end <= right) {
        sums[treeNode] += inc;
        if (start != end) {
            lazy[2 * treeNode + 1] += inc;
            lazy[2 * treeNode + 2] += inc;
        }
        return;
    }
    int mid = (start + end) >> 1;
    updateLazy(start, mid, left, right, 2 * treeNode + 1, inc);
    updateLazy(mid + 1, end, left, right, 2 * treeNode + 2, inc);
    sums[treeNode] = sums[2 * treeNode + 1] + sums[2 * treeNode + 2];
    return;
}




    long long query(int start,int end,int left,int right,int treeNode){
        if(start>right || end<left){
            return 0;}
        if(start>=left && end<=right){
            return sums[treeNode];
        }
        int mid = (start + end) >> 1;
        long long s1 = query(start, mid, left, right, 2 * treeNode + 1);
        long long s2 = query(mid + 1, end, left, right, 2 * treeNode + 2);
        return s1 + s2;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    SegmentTree st(n);
    st.build(arr, 0, n - 1, 0);
    while(m--){
        int q;
        cin >> q;
        if(q==1){
            int l, r, v;
            cin >> l >> r >> v;
            st.updateLazy(0, n - 1, l, r-1 , 0, v);
        }
        else if(q==2){
            int i;
            cin >> i;
            cout << st.query(0,n-1,0,i,0) << endl;
        }
    }
}