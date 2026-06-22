// this question solve by DP tabulation bottum up aproach with these inside code of print LCS//
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> t(n+1,vector<int>(m+1));
        for(int row=0;row<n+1;row++){
            t[row][0]=0;
        }
        for(int col=0;col<m+1;col++){
            t[0][col]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        string lcs="";
        int i=0, j=0;
        while(i>=n && j>=m){
            if(s1[i-1] == s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i-1][j] >  t[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(begin(lcs),end(lcs));
        cout<<lcs<<endl;
        return t[n][m];
        
        
    }
};
// class Solution {
public:
int M,N;
int t[1001][1001];
int solve(int i,int j,string &S1,string &S2){
    if(i>=S1.length() || j>=S2.length()){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int take=0,not_take;
    if(S1[i] == S2[j]){
       take= 1+solve(i+1,j+1,S1,S2);
    }
    else{
        not_take=max(solve(i+1,j,S1,S2),solve(i,j+1,S1,S2));
    }
    return t[i][j]=max(take,not_take);
}
    int longestCommonSubsequence(string &S1, string &S2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,S1,S2);

        
    }
}; 
// following code of recursion + memoization//
class Solution {
public:
int M,N;
int t[1001][1001];
int solve(int i,int j,string &S1,string &S2){
    if(i>=S1.length() || j>=S2.length()){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int take=0,not_take;
    if(S1[i] == S2[j]){
       take= 1+solve(i+1,j+1,S1,S2);
    }
    else{
        not_take=max(solve(i+1,j,S1,S2),solve(i,j+1,S1,S2));
    }
    return t[i][j]=max(take,not_take);
}
    int longestCommonSubsequence(string &S1, string &S2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,S1,S2);

        
    }
};
