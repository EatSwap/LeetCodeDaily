#include <vector>

/**
 * 812. Largest Triangle Area
 * Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.
 */

class Solution {
public:
	static double largestTriangleArea(std::vector<std::vector<int>>& points) {
		const int n = points.size();
		double ret = 0.0;
		for (int i = 0; i < n; ++i) {
			for (int j = 1 + i; j < n; ++j) {
				for (int k = 1 + j; k < n; ++k) {
					ret = std::max(ret, 0.5 * abs(points[i][0] * points[j][1] + points[j][0] * points[k][1] + points[k][0] * points[i][1] - points[i][0] * points[k][1] - points[j][0] * points[i][1] - points[k][0] * points[j][1]));
				}
			}
		}
		return ret;
	}
};
