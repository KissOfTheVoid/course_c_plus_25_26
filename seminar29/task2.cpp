#include<vector>
using namespace std;

class Solution {
public:
    long long trap(vector<int>& height) {
        int n = (int)height.size();
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        long long ans = 0;

        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if (leftMax <= rightMax) {
                // правая стенка точно >= leftMax, значит вода на l определяется leftMax
                ans += (long long)(leftMax - height[l]);
                ++l;
            } else {
                // левая стенка точно >= rightMax, значит вода на r определяется rightMax
                ans += (long long)(rightMax - height[r]);
                --r;
            }
        }
        return ans;
    }
};
