#include <iostream>
#include <string>
using namespace std;

int lo = 0, maxLen = 0;

void checkPalindrome(string s, int left, int right){
    while (left >= 0 && right < s.size() && s[left] == s[right]){
        --left;
        ++right;
    }

    if (maxLen < right - left -1){
        maxLen = right -left - 1;
        lo = left+1;
    }
}

string longestPalindrome(string s){
    if (s.size() < 2){
        return s;
    }


    for (int i = 0; i < s.size(); i++){
        checkPalindrome(s, i, i);
        checkPalindrome(s, i, i+1);
    }

    return s.substr(lo, maxLen);
    
}

int main(){
    string s;
    cin>>s;
    s = longestPalindrome(s);
    cout<<s;
}