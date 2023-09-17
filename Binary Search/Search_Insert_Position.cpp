#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector <int> nums, int target){
    int n = nums.size(), first = 0, last = n-1, mid = (first+last)/2;
    while (first <= last){
        if (nums[mid] > target) last = mid-1;
        else if (nums[mid] < target) first = mid+1;
        else return mid;
        mid = (first+last)/2;
    }
    if (nums[mid] > target) return mid;
    else return mid+1;
}

int main(){
    int n, target;
    cin>>n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin>>nums[i];
    }
    cin>>target;
    cout<<searchInsert(nums, target);
    return 0;
}