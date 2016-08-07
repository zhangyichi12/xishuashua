/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    var res = [];
    if(nums.length < 3) {
        return res;
    }

    nums = nums.sort((a, b) => {   
        return a - b;
    });
    console.log(nums);
    for(var i = 0; i <= nums.length - 3; i++) {
        if(i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        var start = i + 1;
        var end = nums.length - 1;
        while(start < end) {
            if(start > i + 1 && nums[start] === nums[start - 1]) {
                start++;
                continue;
            }
            var Sum = nums[i] + nums[start] + nums[end];
            if(Sum === 0) {
                res.push([nums[i], nums[start], nums[end]]);
                start++;
                end--;
            }
            else if(Sum < 0) {
                start++
            }
            else {
                end--;
            }
        }
    }

    return res;
};
