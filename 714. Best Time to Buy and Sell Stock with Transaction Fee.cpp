// this question solve by DP recursion +memoization and with space optimization is second solution following //
class Solution {
public:
 int t[50001][2];
 int FEE;
int solve(int day,vector<int>& prices,int n,bool buy){
    if(day>=n) return 0;
    int profit=0;
    if(t[day][buy]!=-1){
        return t[day][buy];
    }
    if(buy){
        int Take=solve(day+1,prices,n,false)-prices[day];
        int Not_Take=solve(day+1,prices,n,true);
         profit=max({profit,Take,Not_Take});
    }
    else{
        int Sell=solve(day+1,prices,n,true)+prices[day]-FEE;
        int Not_Sell=solve(day+1,prices,n,false);
        profit=max({profit,Sell,Not_Sell});
    }
    return t[day][buy]=profit;
}
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
         memset(t,-1,sizeof(t));
         bool buy=true;
        FEE=fee;  
       return  solve(0,prices,n,true);
        
    }
}; 
//this is  following question solve by DP  space optimitization //
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        int aheadBuy = 0;
        int aheadSell = 0;

        for(int day=n-1; day>=0; day--) {

            int currBuy =
                max(-prices[day]-fee + aheadSell,
                    aheadBuy);

            int currSell =
                max(prices[day] + aheadBuy,
                    aheadSell);

            aheadBuy = currBuy;
            aheadSell = currSell;
        }

        return aheadBuy;
    }
};
