//Top-Down
int solve(int ind, vector<int> &num, int k, vector<int> &dp){
    
    if(ind == num.size()){
        return 0;
    }
    int maxSum = 0, maxEle = num[ind];
    if(dp[ind] != -1){
        return dp[ind];
    }
    for(int i = ind; i <= min((int)num.size() - 1, ind + k - 1); i++){
        maxEle = max(maxEle, num[i]);
        maxSum = max(maxSum, solve(i + 1, num, k, dp) + maxEle*(i - ind + 1));
    }
    return dp[ind] = maxSum;
}
int maximumSubarray(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return solve(0, num, k, dp);
}

//Bottom-Up
int maximumSubarray(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n + 1,0);
    for(int ind = n - 1; ind >= 0; ind--){
        int maxSum = 0, maxEle = num[ind];
        for(int i = ind; i <= min((int)num.size() - 1, ind + k - 1); i++){
            maxEle = max(maxEle, num[i]);
            maxSum = max(maxSum,dp[i + 1] + maxEle*(i - ind + 1));
        }
        dp[ind] = maxSum;
    }
    return dp[0];
}
