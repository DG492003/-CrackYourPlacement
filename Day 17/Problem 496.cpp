// Approach ->
//      time complexity is O(n+m) space complexity is O(n)


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // stack to keep track of elements.
        stack<int> stack;
        // hash map to store the next greater element for each element in nums2.
        unordered_map<int, int> map;
        // Traverse nums2 from Right to Left:
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // For each element, pop elements from the stack until the top is
            // greater than the current element.
            while (!stack.empty() && stack.top() <= nums2[i]) {
                stack.pop();
            }
            // If the stack is empty, store -1 in the map for the current
            // element.
            if (stack.empty()) {
                map[nums2[i]] = -1;
            }
            // else store the top of the stack as the next greater element.
            else {
                map[nums2[i]] = stack.top();
            }
            // Push the current element onto the stack
            stack.push(nums2[i]);
        }
        // Replace each element in nums1 with its next greater element from the
        // map.
        for (int i = 0; i < nums1.size(); ++i) {
            nums1[i] = map[nums1[i]];
        }
        // Return the modified nums1 array.
        return nums1;
    }
};