class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
        
        int V = accumulate(nums.begin(), nums.end(), 0);
        if(V % 2 == 1) return false;
        V /= 2;
        
        vector<bool> DP(V+1, false);
        DP[0] = true;
        for(int num : nums){
            for(int i = V; i >= num; --i){
                // DP[i] = DP[i]        not selecte num    i >= num
                // DP[i] = DP[i - num]  selecte num        i >= num
                // DP[i] = DP[i]                           i < num               
                DP[i] = DP[i] || DP[i - num];
            }
        }
        return DP[V];
    }


    int partitionSubsetSum(const vector<int>& nums, int target){
        vector<int> DP(target+1, 0);
        DP[0] = 1;
        for(int num : nums){
            for(int i = target; i >= num; --i){
                // f(n,t) = f(n-1,t) + f(n-1,t-num)  t >= num
                // f(n,t) = f(n-1,t)                 t < num    
                DP[i] = DP[i] + DP[i-num];  
            }
        }
        return DP[target];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        // sum(P) - sum(N) = S
        // sum(P) + sum(N) + sum(P) - sum(N) = S + sum(P) + sum(N)
        // 2 * sum(P) = S + sum(nums)
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < abs(S) || (sum + S) % 2 != 0){
            return 0;
        }
        
        int P =(sum + S) / 2;        
        return partitionSubsetSum(nums, P);
    }
};

