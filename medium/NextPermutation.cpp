class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      //  next_permutation(nums.begin(), nums.end());
        int n = nums.size();
        int i = n-1;
        
        while(i > 0 && nums[i] <= nums[i-1]) i--;
        
        if(i == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            
        int val = nums[i-1] + 1; //lower number + 1;

        sort(nums.begin() + i-1, nums.end());// sort to find lower_bound of val
        auto it = lower_bound(nums.begin() + i -1, nums.end(), val);//this will help us find the next number that is greater than the number we want to swap.
        
        int idx  = 0;
        if(it != nums.end()) idx = it - nums.begin();
        swap(nums[idx], nums[i-1]);
        sort(nums.begin() + i, nums.end());
     }
      
    
        
    }
};