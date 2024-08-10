/*
Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree.
    -> The calculation of leftHeight and rightHeight takes O(log N) time.
    -> In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree).
    -> Therefore, the total time complexity is O(log N * log N).

Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree.
    -> The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the binary tree.
    -> Since the given tree is a complete binary tree, the height will always be log N.
    -> Therefore, the space complexity is O(log N).

Approach ->
Maximum Number of Nodes: 2^h-1
To check if the last level of the Binary Tree is filled or not we can compare the left and right heights of the tree.
    If the left height equals right height, it indicates that the last level is completely filled.
    If the left height does not equal right height, the last level is not completely filled.
*/