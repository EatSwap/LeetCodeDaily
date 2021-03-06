#include <vector>
#include <string>
#include <unordered_map>

/**
 * 599. Minimum Index Sum of Two Lists
 * Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.
 * You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.
 */

class Solution {
public:
	static std::vector<std::string> findRestaurant(const std::vector<std::string>& list1, const std::vector<std::string>& list2) {
		std::unordered_map<std::string, int> map;

		int m = list1.size(), n = list2.size();
		for (int i = 0; i < m; ++i) {
			map[list1[i]] = i;
		}

		int retMin = 0x7FFFFFFF;
		std::vector<std::string> ret;
		for (int i = 0; i < n; ++i) {
			if (map.count(list2[i])) {
				int x = i + map[list2[i]];
				if (x < retMin) {
					ret = {list2[i]};
					retMin = x;
				} else if (x == retMin) {
					ret.push_back(list2[i]);
				}
			}
		}

		return ret;
	}
};
