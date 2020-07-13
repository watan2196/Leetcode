class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
     
        unordered_map<int,int>mp;
        
        for(int i:nums)
            mp[i]++;
        
        int ans=0;
        for(auto it:mp)
            ans+=it.second*(it.second-1)/2;
        
        return ans;
    }
};
