#include <iostream>

/**
 * 762. Prime Number of Set Bits in Binary Representation
 * Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.
 * Recall that the number of set bits an integer has is the number of 1's present when written in binary.
 * For example, 21 written in binary is 10101, which has 3 set bits.
 */

class Solution {
private:
	static inline const int IS_PRIME[32] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
public:
	static int countPrimeSetBits(int left, int right) {
		int ret = 0;
		for (int i = left; i <= right; ++i) {
			int x = 0;
			for (int n = i; n; n >>= 1)
				x += n & 1;
			ret += IS_PRIME[x];
		}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::countPrimeSetBits(6, 10));
	return 0;
}
