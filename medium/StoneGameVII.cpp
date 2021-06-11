class Solution {
public:
    int ans = 0;
    int mem[1004][1004];
    int recurse( int i , int j, vector<int>& stones, int sum) {
        int n = stones.size();
        if(i >= j || sum <=0) {
            return 0;
        }
    
       
        if(mem[i][j] != -1) {
            return mem[i][j];
        }
      
         int chooseleft = sum - stones[i] -   recurse(i+1, j, stones, sum - stones[i]);
         int chooseright = sum - stones[j] -  recurse(i, j-1, stones, sum -stones[j]);
        mem[i][j] =  max(chooseleft, chooseright);
         return mem[i][j];
    }
    int stoneGameVII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        memset(mem, -1, sizeof(mem));
        return recurse(0, stones.size()-1, stones, sum);
      
        
    }
};