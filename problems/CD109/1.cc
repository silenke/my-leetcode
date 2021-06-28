#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int last(int n, int m) {
        
        int k = 1;
        for (int i = 2; i <= n; i++) {
            k = (k + m - 1) % i + 1;
        }
        return k;
    }
};

int main() {
    
    int n, m;
    cin >> n >> m;
    
    cout << Solution().last(n, m);
    
    return 0;
}