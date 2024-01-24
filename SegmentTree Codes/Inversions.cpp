#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<long long> sums;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        sums.assign(2 * size, 0);
    }

   void build(vector<int>& a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        if (lx < a.size()) {
            sums[x] = 0;
        } else {
            sums[x] = 0;
        }
        return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid, rx);
    sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
}


    void set(int node, int value, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = value;
            return;
        }
        int mid = (lx + rx) / 2;
        if (node < mid) {
            set(node, value, 2 * x + 1, lx, mid);
        } else {
            set(node, value, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int node, int value) {
        set(node, value, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return sums[x];
        }
        int mid = (lx + rx) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lx, mid);
        long long s2 = sum(l, r, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }
};

int main() {
    int n, m;
    cin >> n;
    SegmentTree st;
    st.init(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    st.build(a);

    for (int i = 0; i < n;i++){
        int num = a[i];
        cout << st.sum(num-1, n) << " ";
        st.set(num-1  , 1);
    }
    cout << endl;

    return 0;
}
