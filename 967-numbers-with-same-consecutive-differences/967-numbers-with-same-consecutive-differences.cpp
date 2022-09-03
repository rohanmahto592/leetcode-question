class Solution {
public:
    void consecutive(vector<int>&ans,int n,int k,int t)
    {
        if(n==1)
        {
            ans.push_back(t);
            return;
        }
        int z=t%10;
        if(z>=k)
        {
            consecutive(ans,n-1,k,t*10+(z-k));
        }
        if((z+k)<=9 and k!=0)
        {
            consecutive(ans,n-1,k,t*10+(z+k));
        }
}
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
        consecutive(ans,n,k,i);
        }
        return ans;
    }
};