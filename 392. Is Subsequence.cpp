// this question solve by DP bottum up //
class Solution {
public:
int n,m;
    bool isSubsequence(string s, string t) {
    n=s.length();
    m=t.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1));
    for(int row=0;row<n+1;row++){
        dp[row][0]=0;
    }

    for(int col=0;col<m+1;col++){
        dp[0][col]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j =1;j<m+1;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    string temp="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            temp.push_back(s[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1] ){
                i--;
            }
            else{
                j--;
            }
        }
        }
       
        reverse(begin(temp),end(temp));
        if(temp ==  s){
            return true;

        }
        return false;  

        
    }
};
