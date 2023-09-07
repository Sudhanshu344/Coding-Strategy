#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestArithSeqLength(vector<int>& nums){
    int ans = 0;
    unordered_map<int, vector<int>> mp;
    for(int right = 1; right < nums.size(); right++){
        for (int left = 0; left < right; left++){
            int diff = nums[right] - nums[left];
            if (mp.find(diff) == mp.end())
                mp[diff] = vector<int> (501, 1);
            mp[diff][right] = max(mp[diff][right], mp[diff][left]+1);
            ans = max(mp[diff][right], ans);
        }
    }
    return ans;
}

int main(){
    int n;
    vector <int> nums;
    cout<<"Number of elements - ";
    cin>>n;
    cout<<"Enter all elements - ";
    for (int i  = 0; i < n ; i++){
        int num;
        cin>>num;
        nums.push_back(num); 
    }
    int ans = longestArithSeqLength(nums);
    cout<<"Answer is : "<<ans;
    return 0;
}