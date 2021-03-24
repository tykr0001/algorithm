#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int answer = 0;
        vector<int> prefix_sum(nums.size());
        prefix_sum[0] = nums[0];
        for (int i = 1; i < prefix_sum.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        
        // 2-pointer
        // [0 ... i] [i+1 ... j] [j+1 ... ]
        // beg : left most of right wall (minimum of j)
        // end : right most +1 of right wall (maximum of j+1)
        for (int i = 0, beg = 0, end = 0; i < prefix_sum.size(); i++) {
            beg = max(beg, i + 1);
            while (beg < prefix_sum.size() - 1 && prefix_sum[beg] - prefix_sum[i] < prefix_sum[i]) {
                beg++;
            }
            end = max(end, beg);
            while (end < prefix_sum.size() - 1 && prefix_sum[end] - prefix_sum[i] <= prefix_sum.back() - prefix_sum[end]) {
                end++;
            }
            answer += end - beg;
            answer %= MOD;
        }
        
        
        // // binary-search
        // // [0 ... i] [i+1 ... j] [j+1 ... ]
        // // beg : left most of right wall (minimum of j)
        // // end : right most +1 of right wall (maximum of j+1)
        // for (int i = 0; i < prefix_sum.size(); i++) {
        //     auto beg = lower_bound(prefix_sum.begin() + i + 1, prefix_sum.end(), 2 * prefix_sum[i]);
        //     auto end = upper_bound(prefix_sum.begin(), prefix_sum.end() - 1, prefix_sum[i] + (prefix_sum.back() - prefix_sum[i]) / 2);
        //     if (beg < end) {
        //         answer += end - beg;
        //         answer %= MOD;
        //     }
        // }
        
        return answer;
    }
};