#include <vector>
#include <map>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::map<int, int> cookies;

        for (int cookieSize : s) {
            cookies[cookieSize]++;
        }

        int contentChildren = 0;

        for (int greedFactor : g) {
            auto it = cookies.lower_bound(greedFactor);

            if (it != cookies.end()) {
                contentChildren++;
                if (--(it->second) == 0) {
                    cookies.erase(it);
                }
            }
        }

        return contentChildren;
    }
};

/*
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;

        if (g.size() == 0 || s.size() == 0)
            return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0;
        int si = 0;
        for (auto child : g) {
            while (s[si] < child) {
                si++;
                // all cookies are content
                if (si >= s.size())
                    return ans;
            }
            si++;
            ans++;

            // all cookies are content
            if (si >= s.size())
                return ans;
        }

        return ans;
    }
};
*/