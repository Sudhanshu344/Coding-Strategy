#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool checkStrings(string s1, string s2)
{
    vector<int> odd(26, 0), even(26, 0);
    for (int i = 0; i < s1.size(); i++)
    {
        if ( i % 2 )
        {
            odd[s1[i] - 'a']++;
            odd[s2[i] - 'a']--;
        }
        else
        {
            even[s1[i] - 'a']++;
            even[s2[i] - 'a']--;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if ( odd[i] || even[i]) return false;
    }

    return true;
}

int main()
{
    string str1, str2;
    cout<<"Enter the first string - ";
    cin>>str1;
    cout<<"Enter the second string - ";
    cin>>str2;
    bool res = checkStrings(str1, str2);
    if (res)
        cout<<"true";
    else
        cout<<"false";
    return 0;

}