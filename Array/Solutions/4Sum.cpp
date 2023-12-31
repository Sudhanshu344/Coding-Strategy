class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3]) > target) break;
            if (((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1]) < target) continue;
            for (int j = i+1; j < n-2; j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if (((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1]) < target) continue;
                if (((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2]) > target) break;
                int left = j+1, right = n-1;
                while (left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) right--;
                    else if ( sum < target) left++;
                    else{
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        do{
                            left++;
                        }while(nums[left] == nums[left-1] && left < right);
                        
                        do{
                            right--;
                        }while(nums[right] == nums[right+1] && left < right);

                    }
                }
            }
        }
        return res;
    }
};