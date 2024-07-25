// Similar to word wrap
// Approach ->
//     Time complexity: O(n)
//     Space complexity: O(n⋅m) to store the answer and a line no auxiliary space

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // to store output
        vector<string> result;
        // get the size of arr
        int n = words.size();
        // pointer to traverse the arr
        int i = 0;
        // traverse the arr
        while (i < n) {
            // initialise the line length and start pointer
            int lineLength = 0;
            int start = i;

            // Determine how many words fit into the current line
            while (i < n && lineLength + words[i].length() + (i - start) <= maxWidth) {
                lineLength += words[i].length();
                i++;
            }

            // Number of spaces between words
            int spaceSlots = i - start - 1;
            // variable to store line
            stringstream line;

            // Handle the current line
            if (i == n || spaceSlots == 0) {
                // Last line or a line with a single word (left-justified)
                for (int j = start; j < i; j++) {
                    line << words[j];
                    if (j != i - 1) line << " ";
                }
                // Fill the remaining space with spaces
                while (line.str().length() < maxWidth) {
                    line << " ";
                }
            } else {
                // Fully justify the line
                int totalSpaces = maxWidth - lineLength;
                int spaceBetweenWords = totalSpaces / spaceSlots;
                int extraSpaces = totalSpaces % spaceSlots;

                for (int j = start; j < i; j++) {
                    line << words[j];
                    if (j != i - 1) {
                        // Distribute spaces evenly
                        int spacesToApply = spaceBetweenWords + (j - start < extraSpaces ? 1 : 0);
                        for (int s = 0; s < spacesToApply; s++) {
                            line << " ";
                        }
                    }
                }
            }

            result.push_back(line.str());
        }

        return result;
    }
};