#include <queue>
#include <vector>

/*
 * Definition for a Node.
 */
class Node {
public:
    int val;
    std::vector<Node*> children;

    explicit Node(int _val = 0, std::vector<Node*> _children = {}) : val(_val), children(std::move(_children)) {}
};

/**
 * 429. N-ary Tree Level Order Traversal
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
 */

class Solution {
public:
	static std::vector<std::vector<int>> levelOrder(const Node* root) {
		if (!root)
			return {};

		std::queue<std::pair<const Node*, int>> q;
		std::vector<std::vector<int>> ret = {{}};

		int currentDepth = 0;
		q.push({root, 0});
		while (!q.empty()) {
			auto n = q.front();
			q.pop();

			if (n.second > currentDepth)
				ret.emplace_back();
			currentDepth = n.second;

			ret.back().push_back(n.first->val);

			for (const auto* ch : n.first->children)
				q.push({ch, 1 + n.second});
		}

		return ret;
	}
};
