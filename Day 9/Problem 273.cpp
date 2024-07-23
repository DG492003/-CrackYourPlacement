// Approach -> TC - O(logn) SC - O(3);

// 1. Handling Zero:
//     -> Directly return "Zero" if the input number is zero.
// 2. Break the Number into Chunks:
//     -> The number is processed in chunks of three digits, from right to left. This is because each set of three digits can be easily converted into words and then scaled appropriately.
// 3. Helper Function:
//     -> This function takes a number less than 1000 and converts it into its word form.
//     -> Hundreds Place: 
//         1. If the number has hundreds, it adds the corresponding word (e.g., 300 -> "Three Hundred").
//     -> Tens and Units Place:
//         1. If the number is between 1 and 19, it directly adds the corresponding word from the units vector.
//         2. If the number is 20 or more, it splits into tens and units, adds the corresponding word from the tens vector, and if there's a units place, adds that too (e.g., 42 -> "Forty Two").
// 4. Main Function:
//     -> Iterates through the number in chunks of three digits.
//     -> For each chunk, uses the helper function to get the word representation.
//     -> If the chunk is not zero, adds the appropriate scale word ("Thousand", "Million", "Billion")     depending on its position. Concatenates the word representations of each chunk.
// 5. Building the Result:
//     Concatenates all the word chunks, ensuring correct spacing and order. Returns the final word rep.

class Solution {
private:
    // helper function to convert int to words
    string helper(int n) {
        // list of all ones
        vector<string> units = {"One",       "Two",      "Three",   "Four",
                                "Five",      "Six",      "Seven",   "Eight",
                                "Nine",      "Ten",      "Eleven",  "Twelve",
                                "Thirteen",  "Fourteen", "Fifteen", "Sixteen",
                                "Seventeen", "Eighteen", "Nineteen"};
        // list of all tens
        vector<string> tens = {"Twenty", "Thirty",  "Forty",  "Fifty",
                               "Sixty",  "Seventy", "Eighty", "Ninety"};

        // empty string to store ans
        string ans = "";

        // check for hundreds
        if (n / 100 > 0) {
            // get the no. of hundreds and update n
            ans += units[n / 100 - 1] + " Hundred";
            n %= 100;
            // if still n is greater than 0 add space for further words
            if (n > 0) {
                ans += " ";
            }
        }
        // now check if n lesser than 20
        // if its get the unit words
        if (n > 0 && n < 20)
            ans = ans + units[n - 1];

        // if its not get the tenth words
        else if (n >= 20) {
            ans = ans + tens[n / 10 - 2];
            // check the n in tenth if its still left get its words
            if (n % 10)
                ans += " " + units[n % 10 - 1];
        }
        // return the answer
        return ans;
    }

public:
    // main function
    string numberToWords(int num) {
        // handle 0 case
        if(num == 0)
            return "Zero";
        
        // list of all zeros after hundreds
        vector<string> hundreds = {"Thousand", "Million", "Billion"};
        // maintain count and answer variable
        int count = -1;
        string ans = "";

        // now check the number
        while(num > 0){
            string curr = helper(num%1000);

            if (!curr.empty()){
                if (!ans.empty()) {
                    ans = curr + " " + (count >= 0 ? hundreds[count] + " " : "") + ans;
            } 
                else {
                    ans = curr + (count >= 0 ? " " + hundreds[count] : "") + ans;
                }
            }  
            count++;
            num = num/1000;
        }
        return ans;
    }
};
