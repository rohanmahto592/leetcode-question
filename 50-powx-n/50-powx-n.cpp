class Solution {
public:
    
    double myPow(double x, int n) {
        bool flag=0;
        long nn=n;
        if(n<0)
        {
            nn=(-1)*nn;
            flag=1;
            
        }
        double ans=1.0;
        while(nn>0)
        {
            if(nn%2==0)
            {
                x=x*x;
                nn=nn/2;
            }
            else
            {
                ans=ans*x;
                nn=nn-1;
            }

        }
        if(flag==1)
        {
            return 1.0/ans;
        }
        else
        {
            return ans;
        }
    }
};