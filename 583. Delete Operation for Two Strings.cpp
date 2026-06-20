// this question solve by DP recursion + memoization //
class Solution {
public:
 int t[501][501];
int solve(int i,int j,string &word1,string &word2){
       int n=word1.size();
        int m=word2.size();

    if(i>=n || j>=m){
        return 0;
    }
    if(t[i][j]!=-1) return t[i][j];
    int take=0, not_take=0;
    if(word1[i] == word2[j]){
        take=1+solve(i+1,j+1,word1,word2);
    }
    not_take=max(solve(i+1,j,word1,word2),solve(i,j+1,word1,word2));
    return t[i][j]=max(take,not_take);
}
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        int LCS=solve(0,0,word1,word2);
        return (word1.length()-LCS + word2.length()-LCS);
        
    }
};
