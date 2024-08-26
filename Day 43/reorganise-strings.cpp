class Solution {
public:
    string reorganizeString(string s) {
        // Step 1: Create a frequency map to count occurrences of each character
        unordered_map<char, int> freq_map;
        for (char c : s) {
            freq_map[c]++;
        }

        // Step 2: Use a max-heap to store characters by their frequency
        priority_queue<pair<int, char>> max_heap;
        for (auto& [ch, freq] : freq_map) {
            max_heap.push({freq, ch});
        }

        // Step 3: Reorganize the string using the characters from the heap
        string res;
        while (max_heap.size() >= 2) {
            // Get the two most frequent characters
            auto [freq1, char1] = max_heap.top();
            max_heap.pop();
            auto [freq2, char2] = max_heap.top();
            max_heap.pop();

            // Append these characters to the result
            res += char1;
            res += char2;

            // Decrease their frequency and push them back into the heap if
            // still needed
            if (--freq1 > 0)
                max_heap.push({freq1, char1});
            if (--freq2 > 0)
                max_heap.push({freq2, char2});
        }

        // Step 4: Handle the case where only one character is left
        if (!max_heap.empty()) {
            auto [freq, ch] = max_heap.top();
            if (freq > 1)
                return ""; // If frequency > 1, it's impossible to reorganize
            res += ch;     // Append the last remaining character
        }

        return res;
    }
};
