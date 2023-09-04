#include<iostream>
#include<vector>
using namespace std;

vector<int> Shuffle(vector<int> nums, int n){
    int first = 0, second = n, max = 1001;
    for(int i =0; i < n*2; i++)
    {
        if(i % 2 == 0)
        {
            nums[i] = nums[i] + (nums[first++]%max)*max;
        }
        else{
            nums[i] = nums[i] + (nums[second++]%max)*max;
        }
    }
    for (int i = 0; i < n*2; i++){
        nums[i] /= max;
    }
    return nums;
}

int main(){
    int length;
    vector<int> nums;
    cout<<"Enter the size of the array : ";
    cin>>length;
    for (int i = 0; i < length; i++)
    {
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
    nums = Shuffle(nums, length/2);

    cout<<"\n";
    for (int i = 0; i < length; i++){
        cout<<nums[i]<<"\t";
    }
}