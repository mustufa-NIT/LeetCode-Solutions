class Solution {
public:
int n;
int t[1002][1002];
//this question solve by DP recursion + memoization // 
int solve(int i,vector<vector<int>>& pairs,int p){
    n=pairs.size();
    if(i>=n){
        return 0;
    }
    int take=0;
    int not_take=0;
    if(p!=-1 && t[i][p+1]!=-1){
        return t[i][p+1];
    }
    if(p==-1 || pairs[p][1]<pairs[i][0]){
        take=1+solve(i+1,pairs,i);
    }
    not_take=solve(i+1,pairs,p);
    if(p!=-1){
        return t[i][p+1]=max(take,not_take);
    }
   return max(take,not_take);

}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(t,-1,sizeof(t));
       return  solve(0,pairs,-1);

        
    }
};
