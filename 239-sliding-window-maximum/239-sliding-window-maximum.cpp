class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        deque<int>q;
        int n=nums.size();
        vector<int>vc;
        while(j<n){
            while(!q.empty() and q.back()<nums[j])
                {
                    q.pop_back();
                }
            q.push_back(nums[j]);
            if((j-i+1)<k)
            {  
                j++;
            }
           
            else if((j-i+1)==k){
               vc.push_back(q.front());
                
               if(q.front()==nums[i]){
                   q.pop_front();
               }
                
                i++;
                j++;
            }
        }
       
        return vc;
    }
};