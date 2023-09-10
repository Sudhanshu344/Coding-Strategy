#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maximum = 0;

void recursion(string text1, string text2, int i, int j, int curr_max){
    if (i >= text1.size() || j >= text2.size()){
        maximum = max(maximum, curr_max);
        return ;
    }
    if (text1[i] == text2[j]){
        recursion(text1, text2, i+1, j+1, curr_max+1);
    }
    recursion(text1, text2, i, j+1, curr_max);
    recursion(text1, text2, i+1, j, curr_max);
}

int longestCommonSubsequence(string text1, string text2){
    recursion(text1, text2, 0, 0, 0);
    return maximum;
}


int main(){
    string s, t;
    cin>>s>>t;
    longestCommonSubsequence(s, t);
    cout<<maximum;
    return 0;
}