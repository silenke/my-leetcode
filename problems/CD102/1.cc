#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int couples(int n) {
        
        if (n == 1) return 0;
        return n * 2 - 3;
    }
};

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        
        int n, p, m;
        cin >> n >> p >> m;
        cout << Solution().couples(n) << endl;
    }
    
    return 0;
}