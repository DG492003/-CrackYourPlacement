// Approach -> O(1)

// // Define all possible cases and perform divisions to access the indexes

class Solution {
public:
    string intToRoman(int num) {
        // define all the possible cases by a list/arr
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[] = {"","M","MM","MMM"};
        
        // getting the results in 1000s, 100s, 10s and 1s
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};