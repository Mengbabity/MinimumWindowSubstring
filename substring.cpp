#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> tmp(128, 0);
		for (auto c : t)
			tmp[c]++;
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end<s.size()) {
			if (tmp[s[end++]]-->0)
				counter--;
			while (counter == 0) {
				if (end - begin<d)
				{
					head = begin;
					d = end - head;
				}
				if (tmp[s[begin++]]++ == 0)
					counter++;
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};
void main()
{
	Solution s;
	s.minWindow("ADOBECODEBANC", "ABC");

}
