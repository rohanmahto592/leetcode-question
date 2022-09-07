class Solution {
public:
    #define mod 1000000007
    long long int calculate(int num,long long int signal)
    {
        if(signal==0)
        {
            return 1;
        }
        long long int power=calculate(num,signal/2);
        power*=power;
        power%=mod;
        if((signal%2)==1)
        {
            power*=num;
            power%=mod;
        }
        return power%mod;
    }
    int countGoodNumbers(long long n) {
       
        long long int odd=n/2;
         long long int even=n-odd;
        int x=(calculate(5,even)*calculate(4,odd))%mod;
        return x%mod;
    }
};