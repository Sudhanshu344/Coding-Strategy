#include <iostream>
#include <vector>
using namespace std;

int totalSteps(vector<int>& nums){
    int n =nums.size(), res = 0;
    vector<int> stack, dp(n, 0);
    for(int i = n-1; i >= 0; --i){
        while(!stack.empty() && nums[i]>nums[stack.back()]){
            dp[i] = max(++dp[i], dp[stack.back()]);
            stack.pop_back();
            res = max(res, dp[i]);
        }
        stack.push_back(i);
    }
    return res;
}

int main(){
    vector<int> nums;
    int n, result;
    cout<<"Total number of elements in the array : ";
    cin>>n;
    cout<<"Enter elements :\n";
    for (int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
    result = totalSteps(nums);
    cout<<"Result = "<<result;
    return 0;
}