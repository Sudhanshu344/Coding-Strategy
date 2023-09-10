#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDistinct(string s, string t){
    int m = s.size();
        int n = t.size();
        vector<vector<long long int>> dp(n+1, vector<long long int> (m+1, 0));
        for(int i = 0; i < m+1; i++) dp[0][i] = 1;

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                dp[i][j] = dp[i][j-1] + ((s[j-1] == t[i-1])? dp[i-1][j-1]: 0);
            }
        }

        return dp[n][m];
}


int main(){
    string s, t;
    cin>>s>>t;
    cout<<numDistinct(s, t);
    return 0;
}