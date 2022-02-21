#include <string>
#include <cassert>
#include <iostream>

/**
 * 389. Find the Difference
 * You are given two strings s and t.
 * String t is generated by random shuffling string s and then add one more letter at a random position.
 * Return the letter that was added to t.
 */

class Solution {
public:
	static char findTheDifference(const std::string& s, const std::string& t) {
		int c[26]{};
		for (char ch : s) {
			++c[ch - 'a'];
		}
		for (char ch : t) {
			if (--c[ch - 'a'] < 0)
				return ch;
		}
		assert(false);
		return 0;
	}
};

int main() {
	std::cout << Solution::findTheDifference("abcd", "abcde");
	return 0;
}