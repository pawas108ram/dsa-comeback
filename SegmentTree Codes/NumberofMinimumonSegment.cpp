#include <bits/stdc++.h>
using namespace std;

struct minonsegmentitem {
    int m, c;

    bool operator<(const minonsegmentitem& other) const {
        return m < other.m;
    }

    bool operator==(const minonsegmentitem& other) const {
        return m == other.m;
    }
};

struct SegmentTree {
    int size;
    vector<minonsegmentitem> values;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        values.resize(2 * size);
    }

    minonsegmentitem merge(minonsegmentitem a, minonsegmentitem b) {
        if (a < b) {
            return a;
        } else if (b < a) {
            return b;
        } else {
            return {a.m, a.c + b.c};
        }
    }

    void build(vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                values[x] = {a[lx], 1};
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int node, int value, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = {value, 1};
            return;
        }
        int mid = (lx + rx) / 2;
        if (node < mid) {
            set(node, value, 2 * x + 1, lx, mid);
        } else {
            set(node, value, 2 * x + 2, mid, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int node, int value) {
        set(node, value, 0, 0, size);
    }

    minonsegmentitem minvalue(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return {INT_MAX, 1};
        }
        if (lx >= l && rx <= r) {
            return values[x];
        }
        int mid = (lx + rx) / 2;
        minonsegmentitem s1 = minvalue(l, r, 2 * x + 1, lx, mid);
        minonsegmentitem s2 = minvalue(l, r, 2 * x + 2, mid, rx);
        return merge(s1, s2);
    }

    minonsegmentitem minvalue(int l, int r) {
        return minvalue(l, r , 0, 0, size);
    }

    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    SegmentTree st;
    st.init(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    st.build(a);

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            st.set(x, y);
        } else if (op == 2) {
            minonsegmentitem ele = st.minvalue(x, y );
            cout << ele.m << " " << ele.c << endl;
        }
    }

    return 0;
}
