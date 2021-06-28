#include "..\..\leetcode.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        parents.clear();
        for (int i = 0; i < equations.size(); i++) {
            const auto& a = equations[i][0];
            const auto& b = equations[i][1];
            const double v = values[i];
            if (!parents.count(a) && !parents.count(b)) {
                parents[a] = {b, v};
                parents[b] = {b, 1.0};
            } else if (!parents.count(a)) {
                parents[a] = {b, v};
            } else if (!parents.count(b)) {
                parents[b] = {a, 1.0 / v};
            } else {
                const auto& ra = find(a);
                const auto& rb = find(b);
                parents[ra.first] = {rb.first, v / ra.second * rb.second};
            }
        }

        vector<double> res;
        for (const auto& p : queries) {
            const string& a = p[0];
            const string& b = p[1];
            if (!parents.count(a) || !parents.count(b)) {
                res.push_back(-1.0);
                continue;
            }
            const auto& ra = find(a);
            const auto& rb = find(b);
            if (ra.first != rb.first) {
                res.push_back(-1.0);
            } else {
                res.push_back(ra.second / rb.second);
            }
        }
        return res;
    }

private:
    unordered_map<string, pair<string, double>> parents;

    const pair<string, double>& find(const string& a) {
        if (a != parents[a].first) {
            const auto& pa = find(parents[a].first);
            parents[a] = {pa.first, parents[a].second * pa.second};
        }
        return parents[a];
    };
};