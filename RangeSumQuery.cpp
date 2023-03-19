class NumArray {
public:
    vector<int> seg;
    int n;
    void build(vector<int>& a, int idx, int low, int high){
        if(low == high){
            seg[idx] = a[low];
            return;
        }
        
        int mid = (low + high)/2;
        build(a, 2*idx+1, low, mid);
        build(a, 2*idx+2, mid+1, high);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    void updateUtil(int idx, int low, int high, int i, int val){
        if(low == high){
            seg[idx] = val;
            return;
        }
     
        int mid = (low + high)/2;
        if(i <= mid)
        updateUtil(2*idx+1, low, mid, i, val);
        else
        updateUtil(2*idx+2, mid+1, high, i, val);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    int rangeUtil(int idx, int low, int high, int l, int r){
        // l--r low--high or low--high l--r --> no overlap
        if(low > r || high < l)
            return 0;
        // l--- low -- high---r --> total overlap 
        if(l <= low && high <= r)
            return seg[idx];
        // partial overlap
        
        int mid  = (low + high)/2;
        
        int lsum = rangeUtil(2*idx+1, low, mid, l, r);
        int rsum = rangeUtil(2*idx+2, mid+1, high, l, r);
        
        return (lsum + rsum);
        
    }
    
    NumArray(vector<int>& nums) {
        if(nums.size() > 0)
        {
            n = nums.size();
            seg.resize(4*n);
            build(nums, 0, 0, n-1);
        }
    }
    
    void update(int index, int val) {
        if(n == 0)
            return;
        updateUtil(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        if(n == 0)
            return 0;
        return rangeUtil(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
