#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int get_next(int ptr, vector<int>& nums) {
        int N = nums.size();
        return ((ptr + nums[ptr]) % N + N) % N;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] % N == 0)
                continue;
            int slow = i, fast = i;

            while (nums[slow] * nums[get_next(fast, nums)] > 0 
                && nums[slow] * nums[get_next(get_next(fast, nums), nums)] > 0) {

                slow = get_next(slow, nums);
                fast = get_next(get_next(fast, nums), nums);

                if (fast == slow) {
                    if (slow == get_next(slow, nums)) return false;
                    else return true;
                }
            }
            int j = i, val = nums[i];
            while (nums[j] * val > 0) {
                int next = get_next(j, nums);
                nums[j] = 0;
                j = next;
            }
        }
        return false;
    }
};
int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];
    Solution obj;
    cout << obj.circularArrayLoop(nums);
}