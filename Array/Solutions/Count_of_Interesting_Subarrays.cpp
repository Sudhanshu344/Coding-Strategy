#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countInterestingSubarrays(vector<int>& nums, int modulo, int k){
    unordered_map<int, int> mp;
    int ans = 0, prefix = 0;
    mp[0]++;
    for(int i = 0; i < nums.size(); i++){
        if (nums[i]%modulo == k) prefix++;
        prefix %= modulo;
        if (mp.find((prefix - k + modulo)%modulo) != mp.end()){
            ans += mp[(prefix - k + modulo)%modulo];
        }
        mp[prefix]++;
    }
    return ans;
}

int main(){
    int n, modulo, k;
    vector<int> nums;
    cin>>n;
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
    cin>>modulo>>k;
    int sum = countInterestingSubarrays(nums, modulo, k);
    cout<<"answer is : "<<sum;
    return 0;
}