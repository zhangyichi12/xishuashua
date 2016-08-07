class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */

    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if(nums.empty() || nums.size() < 3) {
            return res;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i  -1]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r) {
                if(l > i + 1 && nums[l] == nums[l - 1]) {
                    l++;
                    continue;
                }

                int temp = nums[i] + nums[l] + nums[r];
                if(temp == 0) {
                    vector<int> path = { nums[i], nums[l], nums[r] };
                    res.push_back(path);
                    l++;
                    r--;
                }
                else if(temp < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return res;
    }
};
