class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0) return -1;
        
        vector<int> amountDP(amount+1, INT_MAX);
        amountDP[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(int a : coins){
                if(a <= i && amountDP[i-a] != INT_MAX){
                    amountDP[i] = min(amountDP[i], amountDP[i-a]+1);
                }
            }
        }
        if(amountDP[amount] == INT_MAX){
            return -1;
        }else{
            return amountDP[amount];
        }
    }
};