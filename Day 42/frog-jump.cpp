class Solution {
public:
    // Memoization map: maps (current stone, last jump) to whether the stone can be reached
    map<pair<int, int>, bool> memo;

    // Set to store positions of stones for quick lookup
    unordered_set<int> stone_positions;

    bool canCross(vector<int>& stones) {
        // Initial check: the first two stones must have a distance of 1
        if (stones[1] - stones[0] != 1)
            return false;

        // The last stone position
        int last_stone = stones.back();

        // Fill the set with positions of stones
        for (int stone : stones) {
            stone_positions.insert(stone);
        }

        // Start the recursive function with the first stone and an initial jump length of 1
        return canCrossHelper(last_stone, stones[1], 1);
    }

private:
    bool canCrossHelper(int last_stone, int current_stone, int jump_length) {
        // If we have reached the last stone, return true
        if (current_stone == last_stone) {
            return true;
        }

        // Check if this state has been computed before
        if (memo.find(make_pair(current_stone, jump_length)) != memo.end()) {
            return memo[make_pair(current_stone, jump_length)];
        }

        bool result = false;

        // Try jumps of length (jump_length - 1), jump_length, and (jump_length + 1)
        if (jump_length - 1 > 0 && stone_positions.find(current_stone + jump_length - 1) != stone_positions.end()) {
            result = result || canCrossHelper(last_stone, current_stone + jump_length - 1, jump_length - 1);
        }
        if (stone_positions.find(current_stone + jump_length) != stone_positions.end()) {
            result = result || canCrossHelper(last_stone, current_stone + jump_length, jump_length);
        }
        if (stone_positions.find(current_stone + jump_length + 1) != stone_positions.end()) {
            result = result || canCrossHelper(last_stone, current_stone + jump_length + 1, jump_length + 1);
        }

        // Memoize the result before returning
        memo[make_pair(current_stone, jump_length)] = result;
        return result;
    }
};
