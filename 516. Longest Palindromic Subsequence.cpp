// this question solve by DP recursion + memoizaton  and this is queston is part of LCS=longest commen subsequence//
class Solution {
public:
int n;
int t[1001][1001];
int solve(int i,int j, string &s){
    n=s.length();
    if(i>j){
        return 0;
    }
    if(i==j){
        return 1;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int take=0,not_take=0;
    if(s[i] ==  s[j]){
        take=2+solve(i+1,j-1,s);
    }
    not_take=max(solve(i+1,j,s),solve(i,j-1,s));
    return t[i][j]=max(take,not_take);

}
    int longestPalindromeSubseq(string s) {
        n=s.length();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,s);
        
    }
};
