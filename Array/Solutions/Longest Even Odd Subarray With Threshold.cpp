#include <iostream>
#include <vector>
using namespace std;

int longestAlternatingSubarray(vector<int>& nums, int threshold){
    int ans = 0, i = 0, last = INT_MAX;
    while(i < nums.size()){
        if ((nums[i] > threshold) || (i > 0 && (nums[i]%2) == (nums[i-1]%2))){
            ans = (ans>(i-last))?ans:(i-last);
            last = INT_MAX;
        }
        if ((last==INT_MAX) && nums[i] <= threshold && !(nums[i]%2)){
            last = i;
        }
        i++;
    }

    ans = (ans>(i-last))?ans:(i-last);
    return ans;
}

int main(){
    vector<int> arr;
    int n, threshold, result;
    cout<<"Total number of elements in the array : ";
    cin>>n;
    cout<<"Enter elements :\n";
    for (int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Threshold value : ";
    cin>>threshold;
    result = longestAlternatingSubarray(arr, threshold);
    cout<<"Result = "<<result;
    return 0;
}