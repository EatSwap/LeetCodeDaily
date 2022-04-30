#include <vector>
#include <algorithm>

/**
 * 908. Smallest Range I
 * You are given an integer array nums and an integer k.
 * In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.
 * The score of nums is the difference between the maximum and minimum elements in nums.
 * Return the minimum score of nums after applying the mentioned operation at most once for each index in it.
 */

class Solution {
public:
	static int smallestRangeI(const std::vector<int>& nums, int k) {
		return std::max(0, *std::max_element(nums.begin(), nums.end()) - *std::min_element(nums.begin(), nums.end()) - (k << 1));
	}
};
