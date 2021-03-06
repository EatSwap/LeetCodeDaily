#include <vector>
#include <unordered_map>
#include <iostream>

/**
 * 525. Contiguous Array
 * Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
 */

class Solution {
public:
	static int findMaxLength(const std::vector<int>& nums) {
		int sum = 0, n = nums.size(), ret = 0;
		std::unordered_map<int, int> m;
		m[0] = -1;
		for (int i = 0; i < n; ++i) {
			sum += 1 - (nums[i] << 1);
			if (m.count(sum))
				ret = ret < i - m[sum] ? i - m[sum] : ret;
			else
				m[sum] = i;
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::findMaxLength({0,1,0});
	return 0;
}
