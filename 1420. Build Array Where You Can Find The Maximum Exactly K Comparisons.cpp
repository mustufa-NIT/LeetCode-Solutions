//this code solve by DP recursion + memoization//
class Solution {
public:
int N,M,K;
int MOD=1e9+7;
int t[51][51][101];
int solve(int i,int search_cost,int maxSoFar){
    if(i>=N){
        if(search_cost == K){
            return 1;
        }
        
            return 0;
    
    }
    if(t[i][search_cost][maxSoFar]!=-1) return t[i][search_cost][maxSoFar];
    int result=0;
    for(int num=1;num<=M;num++){
        if(num > maxSoFar){
        result=(result+solve(i+1,search_cost+1,num))%MOD;
        }
        else{
            result=(result+solve(i+1,search_cost,maxSoFar))%MOD;
        }
    }
   return t[i][search_cost][maxSoFar]=result % MOD;

}
    int numOfArrays(int n, int m, int k) {
         N=n;
         M=m;
         K=k;
         memset(t,-1,sizeof(t));
        return solve(0,0,0);
        
    }
};
