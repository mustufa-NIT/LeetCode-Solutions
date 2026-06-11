//this question solve by DP recursion +  memoization//
class Solution {
public:
int t[5001][2];
int solve(int day,vector<int>& prices,int n,bool buy){
    n=prices.size();
    int profit=0;
    if(day>=n) return 0;
    if(t[day][buy]!=-1) return t[day][buy];
    if(buy){
        int Take=solve(day+1,prices,n,false)-prices[day];
        int Not_Take=solve(day+1,prices,n,true);
        profit=max(Take,Not_Take);
    }
    else{
        int Sell=prices[day]+solve(day+2,prices,n,true);
        int Not_Sell=solve(day+1,prices,n,false);
        profit=max({profit,Sell,Not_Sell});
    }

    return t[day][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        int n=prices.size();
       bool buy=true;
        return solve(0,prices,n,true);
         
        
    }
};
