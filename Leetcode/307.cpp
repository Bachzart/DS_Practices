/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
/* method 1: process by block */
class NumArray {
public:
    vector<int> &nums;
    vector<int> sum;
    int size;
    NumArray(vector<int>& nums): nums(nums) {
        int n = nums.size();
        size = sqrt(n);
        sum.resize((n + size - 1) / size);
        for(int i = 0; i < n; i++) {
            sum[i / size] += nums[i];
        }
    }
    
    void update(int index, int val) {
        sum[index / size] += val - nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int b1 = left / size, i1 = left % size, b2 = right / size, i2 = right % size;
        if(b1 == b2) return accumulate(nums.begin() + b1 * size + i1, nums.begin() + b2 * size + i2 + 1, 0);
        int sum1 = accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + size, 0);
        int sum2 = accumulate(nums.begin() + b2 * size, nums.begin() + b2 * size + i2 + 1, 0);
        int sum3 = accumulate(sum.begin() + b1 + 1, sum.begin() + b2, 0);
        return sum1 + sum2 + sum3;
    }
};

/* method 2: segment tree */
class NumArray {
private:
    vector<int> segtree;
    int n;
    void build(int node, int s, int e, vector<int>& nums) {
        if(s == e) {
            segtree[node] = nums[s];
            return;
        }
        int m = s + (e - s) / 2;
        build(node * 2 + 1, s, m, nums);
        build(node * 2 + 2, m + 1, e, nums);
        segtree[node] = segtree[node * 2 + 1] + segtree[node * 2 + 2];
    }
    void change(int index, int val, int node, int s, int e) {
        if(s == e) {
            segtree[node] = val;
            return;
        }
        int m = s + (e - s) / 2;
        if(index <= m) change(index, val, node * 2 + 1, s, m); 
        else change(index, val, node * 2 + 2, m + 1, e);
        segtree[node] = segtree[node * 2 + 1] + segtree[node * 2 + 2];
    }
    int range(int left, int right, int node, int s, int e) {
        if(left == s && right == e) return segtree[node];
        int m = s + (e - s) / 2;
        if(right <= m) return range(left, right, node * 2 + 1, s, m);
        else if(left > m) return range(left, right, node * 2 + 2, m + 1, e);
        else return range(left, m, node * 2 + 1, s, m) + range(m + 1, right, node * 2 + 2, m + 1, e);
    }
public:
    NumArray(vector<int>& nums): n(nums.size()), segtree(nums.size() * 4) {
        build(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        change(index, val, 0, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return range(left, right, 0, 0, n - 1);
    }
};