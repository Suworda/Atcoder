//gpt 진짜 이만큼 발전했나요?

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
 successor DSU:
 find(x) = 아직 사용하지 않은 x 이상 최소 위치
*/
struct DSUNext {
    vector<int> p;

    DSUNext(int n = 0) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        int r = x;
        while (p[r] != r) r = p[r];

        while (p[x] != x) {
            int nx = p[x];
            p[x] = r;
            x = nx;
        }
        return r;
    }

    int take_next(int l) {
        int x = find(l);
        p[x] = find(x + 1);
        return x;
    }
};

/*
 predecessor DSU:
 day d를 index d+1로 관리한다.
 find(r) = 아직 사용하지 않은 r 이하 최대 index
 take_prev_lt(R) = day < R 중 최대 day
*/
struct DSUPrev {
    vector<int> p;

    DSUPrev(int n = 0) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        int r = x;
        while (p[r] != r) r = p[r];

        while (p[x] != x) {
            int nx = p[x];
            p[x] = r;
            x = nx;
        }
        return r;
    }

    int take_prev_lt(int r) {
        int idx = find(r);     // idx는 day idx-1에 대응
        int day = idx - 1;
        p[idx] = find(idx - 1);
        return day;
    }
};

struct SegTree {
    int n, size;
    vector<int> mn, mx, lazy;

    SegTree(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        size = 1;
        while (size < max(1, n)) size <<= 1;

        const int INF = 1e9;

        mn.assign(2 * size, INF);
        mx.assign(2 * size, -INF);
        lazy.assign(2 * size, 0);

        for (int i = 0; i < n; i++) {
            mn[size + i] = mx[size + i] = 0;
        }

        for (int i = size - 1; i >= 1; i--) {
            pull(i);
        }
    }

    void pull(int k) {
        mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
        mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
    }

    void apply(int k, int v) {
        mn[k] += v;
        mx[k] += v;
        lazy[k] += v;
    }

    void push(int k) {
        if (lazy[k] == 0) return;

        apply(k << 1, lazy[k]);
        apply(k << 1 | 1, lazy[k]);
        lazy[k] = 0;
    }

    void range_add(int l, int r, int v) {
        range_add(1, 0, size, l, r, v);
    }

    void range_add(int k, int nl, int nr, int ql, int qr, int v) {
        if (qr <= nl || nr <= ql || n <= nl) return;

        if (ql <= nl && nr <= qr && nr <= n) {
            apply(k, v);
            return;
        }

        push(k);

        int mid = (nl + nr) >> 1;
        range_add(k << 1, nl, mid, ql, qr, v);
        range_add(k << 1 | 1, mid, nr, ql, qr, v);

        pull(k);
    }

    bool ok_min(int k, int th) const {
        return mn[k] >= th;
    }

    bool ok_max(int k, int th) const {
        return mx[k] <= th;
    }

    /*
      first_bad_min(l, th):
      l 이상에서 처음으로 value < th 인 위치.
      없으면 n.
    */
    int first_bad_min(int l, int th) {
        int res = first_bad(1, 0, size, l, 0, th);
        return res == -1 ? n : res;
    }

    /*
      first_bad_max(l, th):
      l 이상에서 처음으로 value > th 인 위치.
      없으면 n.
    */
    int first_bad_max(int l, int th) {
        int res = first_bad(1, 0, size, l, 1, th);
        return res == -1 ? n : res;
    }

    /*
      type = 0: value < th 인 첫 위치 찾기
      type = 1: value > th 인 첫 위치 찾기
    */
    int first_bad(int k, int nl, int nr, int l, int type, int th) {
        if (nr <= l || n <= nl) return -1;

        if (l <= nl && nr <= n) {
            bool ok;
            if (type == 0) ok = ok_min(k, th);
            else ok = ok_max(k, th);

            if (ok) return -1;
        }

        if (nr - nl == 1) {
            return nl;
        }

        push(k);

        int mid = (nl + nr) >> 1;

        int left = first_bad(k << 1, nl, mid, l, type, th);
        if (left != -1) return left;

        return first_bad(k << 1 | 1, mid, nr, l, type, th);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> L(N), R(N);

    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        --L[i];              // L은 0-index
        // R은 exclusive upper bound처럼 사용한다.
        // 원래 day <= R_i 이므로 0-index day < R_i.
    }

    vector<int> P(N);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        --P[i];
    }

    vector<int> x(N), y(N);

    /*
      x[q]:
      P[q]가 L로 바뀔 때,
      L 작업들을 최대한 빨리 배치하는 관점에서 새로 추가되는 날.
    */
    {
        DSUNext ds(N);

        for (int q = 0; q < N; q++) {
            int job = P[q];
            x[q] = ds.take_next(L[job]);
        }
    }

    /*
      y[q]:
      P[q]가 R에서 빠질 때,
      R 작업들을 최대한 늦게 배치하는 관점에서 새로 비게 되는 날.
    */
    {
        DSUPrev ds(N);

        for (int q = N - 1; q >= 0; q--) {
            int job = P[q];
            y[q] = ds.take_prev_lt(R[job]);
        }
    }

    /*
      off:
      타입별 상수항 + 모든 day가 R이라고 볼 때의 -day 항.
      초기 all R에서는 작업 i를 day i에 하면 된다.
    */
    ll off = 0;

    for (int i = 0; i < N; i++) {
        off += (ll)(R[i] - 1) - i;
    }

    /*
      e_i는 i = 0 ... N-2까지만 보면 된다.
      마지막 prefix에서는 #X == #Y라서 항상 0.
    */
    SegTree seg(max(0, N - 1));

    ll xySum = 0;   // Σ(x + y)
    ll absSum = 0;  // Σ|e_i|

    vector<ll> ans;
    ans.reserve(N + 1);

    ans.push_back(off + xySum + absSum);

    for (int q = 0; q < N; q++) {
        int job = P[q];

        /*
          job이 R에서 L로 변한다.
          zero-index L 기준:
          R 상수: R_i - 1
          L 상수: -L_i
          변화량: -L_i - (R_i - 1)
                 = -(L_i + R_i - 1)
        */
        off -= (ll)L[job] + R[job] - 1;

        int l = x[q];
        int r = y[q];
        int v = 1;

        if (l > r) {
            swap(l, r);
            v = -1;
        }

        xySum += (ll)l + r;

        /*
          x 추가와 y 추가의 net effect:
          e[l ... r-1] += v
        */
        int cur = l;

        while (cur < r) {
            /*
              v = +1:
                e >= 0  구간은 |e|가 +1
                e <= -1 구간은 |e|가 -1

              v = -1:
                e >= 1  구간은 |e|가 -1
                e <= 0  구간은 |e|가 +1
            */

            int thMin = max(0, -v);
            int nx = seg.first_bad_min(cur, thMin);
            if (nx > r) nx = r;

            absSum += (ll)(nx - cur) * v;
            cur = nx;

            if (cur >= r) break;

            int thMax = min(0, -v);
            nx = seg.first_bad_max(cur, thMax);
            if (nx > r) nx = r;

            absSum += (ll)(nx - cur) * (-v);
            cur = nx;
        }

        if (l < r) {
            seg.range_add(l, r, v);
        }

        ans.push_back(off + xySum + absSum);
    }

    for (int i = 0; i <= N; i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }

    cout << '\n';

    return 0;
}