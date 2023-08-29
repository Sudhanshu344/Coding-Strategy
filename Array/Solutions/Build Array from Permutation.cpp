#include<iostream>
#include<vector>
using namespace std;

void buildArray(vector<int>& nums){
    int length = nums.size();
    for(int i = 0; i < length; i++){
        int curr = nums[i];
        // Modulus is needed here because we are changing the value of nums during parsing, So that we can not use extra space.
        // Since we are multiplying the value with length (which is always greater then the array values). We can get the original value
        // even after it has been modified by doing modulus.
        int next = nums[nums[i]]%length;
        // We need to multiply length with next variable because to get next in above line, we can't use divide operation because,
        // if nums[nums[i]] hasn't been modified then the value "next" will get is 0, because initially everything is less then the length of array.
        // And at all places we need the unmodified array value for both current and next.
        nums[i] = next*length+curr; 
    }
    for(int i  = 0; i < length; i++){
        nums[i] = nums[i]/length;
    }
}

int main(){
    int n;
    vector<int> nums;
    cout<<"Enter number of inputs : ";
    cin>>n;
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
    buildArray(nums);
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<"\t";
    }
    return 0;
}