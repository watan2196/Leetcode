class Solution {
public:
    const int MOD=1e9+7;
    int numSub(string s) {
    
        long long int ans,cnt;
        ans=0;
        cnt=0;
        
        for(char c:s)
        {
            if(c == '1')
                cnt++;
            else
            {
                ans+=cnt*(cnt+1)/2;
                cnt=0;
            }
        }
        
        if(cnt)
            ans+=cnt*(cnt+1)/2;
        
        return ans%MOD;
        
        
    }
};
