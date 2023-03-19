class Solution {
public:
    
    vector<int> nsl(vector<int> nums,int n){
        vector<int> left(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty()) left[i] = -1;
            else{
                while(!s.empty() && nums[s.top()]>=nums[i]) s.pop();
                if(s.empty()) left[i] = -1;
                else{
                    left[i] = s.top();
                }
            }
            s.push(i);
        }
        return left;
    }
    
    vector<int> nsr(vector<int> nums,int n){
        vector<int> right(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()) right[i] = n;
            else{
                while(!s.empty() && nums[s.top()]>=nums[i]) s.pop();
                if(s.empty()) right[i] = n;
                else{
                    right[i] = s.top();
                }
            }
            s.push(i);
        }
        return right;
    }
    
    int mah(vector<int> nums,int n){
        int ans = 0;
        vector<int> left = nsl(nums,n),right = nsr(nums,n);
        // for(auto a:right) cout<<a<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            ans = max(ans,nums[i]*(right[i] - left[i] - 1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> nums(n,0);
        // for(int i=0;i<n;i++){
        //     if(matrix[0][i]=='1') nums[i]++;
        // }
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') nums[j]++;
                else nums[j] = 0;
            }
            
            ans = max(ans,mah(nums,n));
            // cout<<ans<<endl;
        }
        return ans;
    }
};
