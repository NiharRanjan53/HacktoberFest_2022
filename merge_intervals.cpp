 class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>>ans;
        ans.push_back(in[0]);
        
        for(auto i:in)
        {
            if(ans.back()[1]<i[0])
            {
                ans.push_back(i);
            }
            else
            {
                ans.back()[1]=max(ans.back()[1],i[1]);
            }
        }
        return ans;
    }
};
