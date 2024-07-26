// it is a concept not a question
//     Time Complexity : O(m*n) if pattern appears in a text else O(n+m)
//     Auxiliary Space: O(1)

// The Bad Character Heuristic may take O(m*n) time in worst case. The worst case occurs when all characters of the text and pattern are same. For example, txt[] = “AAAAAAAAAAAAAAAAAA” and pat[] = “AAAAA”. The Bad Character Heuristic may take O(n/m) in the best case. The best case occurs when all the characters of the text and pattern are different. 

// we create a badmatchtable for the pattern by val = max(1, patternlen - indexofcurrWord - 1) (also include * entry for the charcters which is not present in a pattern)

// now traverse the text in pattern lenght window size 
// and compare the righmost element alwys 
//     if element is mismatched, then check on badmatchtabe and shift the pattern as per table's value
//     else compare from the righmost till start


/* C++ Program for Bad Character Heuristic of Boyer
Moore String Matching Algorithm */
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's
// bad character heuristic
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
	int i;

	// Initialize all occurrences as -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	// Fill the actual value of last occurrence
	// of a character
	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}

/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void search(string txt, string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];

	/* Fill the bad character array by calling
	the preprocessing function badCharHeuristic()
	for given pattern */
	badCharHeuristic(pat, m, badchar);

	int s = 0; // s is shift of the pattern with
			// respect to text
	while (s <= (n - m)) {
		int j = m - 1;

		/* Keep reducing index j of pattern while
		characters of pattern and text are
		matching at this shift s */
		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		/* If the pattern is present at current
		shift, then index j will become -1 after
		the above loop */
		if (j < 0) {
			cout << "pattern occurs at shift = " << s
				<< endl;

			/* Shift the pattern so that the next
			character in text aligns with the last
			occurrence of it in pattern.
			The condition s+m < n is necessary for
			the case when pattern occurs at the end
			of text */
			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		}

		else
			/* Shift the pattern so that the bad character
			in text aligns with the last occurrence of
			it in pattern. The max function is used to
			make sure that we get a positive shift.
			We may get a negative shift if the last
			occurrence of bad character in pattern
			is on the right side of the current
			character. */
			s += max(1, j - badchar[txt[s + j]]);
	}
}

/* Driver code */
int main()
{
	string txt = "ABAAABCD";
	string pat = "ABC";
	search(txt, pat);
	return 0;
}

// This code is contributed by rathbhupendra
