/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

/* just for reference */
class BookMyShow {
    int n, m;
    vector<int> min;
    vector<long> sum;

    // 将 idx 上的元素值增加 val
    void add(int o, int l, int r, int idx, int val) {
        if (l == r) {
            min[o] += val;
            sum[o] += val;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m) add(o * 2, l, m, idx, val);
        else add(o * 2 + 1, m + 1, r, idx, val);
        min[o] = std::min(min[o * 2], min[o * 2 + 1]);
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
    }

    // 返回区间 [L,R] 内的元素和
    long query_sum(int o, int l, int r, int L, int R) { // L 和 R 在整个递归过程中均不变，将其大写，视作常量
        if (L <= l && r <= R) return sum[o];
        long sum = 0L;
        int m = (l + r) / 2;
        if (L <= m) sum += query_sum(o * 2, l, m, L, R);
        if (R > m) sum += query_sum(o * 2 + 1, m + 1, r, L, R);
        return sum;
    }

    // 返回区间 [1,R] 中 <= val 的最靠左的位置，不存在时返回 0
    int index(int o, int l, int r, int R, int val) { // R 在整个递归过程中均不变，将其大写，视作常量
        if (min[o] > val) return 0; // 说明整个区间的元素值都大于 val
        if (l == r) return l;
        int m = (l + r) / 2;
        if (min[o * 2] <= val) return index(o * 2, l, m, R, val); // 看看左半部分
        if (m < R) return index(o * 2 + 1, m + 1, r, R, val); // 看看右半部分
        return 0;
    }

public:
    BookMyShow(int n, int m) : n(n), m(m), min(n * 4), sum(n * 4) {}

    vector<int> gather(int k, int maxRow) {
        int i = index(1, 1, n, maxRow + 1, m - k);
        if (i == 0) return {}; // 不存在
        int seats = query_sum(1, 1, n, i, i);
        add(1, 1, n, i, k); // 占据 k 个座位
        return {i - 1, seats};
    }

    bool scatter(int k, int maxRow) {
        if ((long) (maxRow + 1) * m - query_sum(1, 1, n, 1, maxRow + 1) < k) return false; // 剩余座位不足 k 个
        // 从第一个没有坐满的排开始占座
        for (int i = index(1, 1, n, maxRow + 1, m - 1);; ++i) {
            int left_seats = m - query_sum(1, 1, n, i, i);
            if (k <= left_seats) { // 剩余人数不够坐后面的排
                add(1, 1, n, i, k);
                return true;
            }
            k -= left_seats;
            add(1, 1, n, i, left_seats);
        }
    }
};
