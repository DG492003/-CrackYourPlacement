// Not a question, its a concept
// Time Complexity ->
//     The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
// Auxiliary Space: O(1)

// Step 1: Choose a suitable base and a modulus:
//     p(modulus) & b(base) both preferably a prime number
// Step 2: Initialize the hash value:
//     Set an initial hash value hash to 0.
// Step 3: Calculate the initial hash value for the pattern by iterating from left to right:
//     For each character, at position i, calculate its contribution to the hash value 
//     c*(b^(pattern_length-i-1)) % p and add it to hash.
// Step 4: Slide the pattern over the text
// Step 5: Update the hash value for each subsequent substring
//     hash = (hash - (text[i - pattern_length] * (b^(pattern_length - 1))) % p) * b + text[i]
// Step 6: Compare hash values


// Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
void search(char pat[], char txt[], int q){
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	// we use loop to compute above formula without overflow_error
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) {

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j]) {
					break;
				}
			}

			// if p == t and pat[0...M-1] = txt[i, i+1,
			// ...i+M-1]

			if (j == M)
				cout << "Pattern found at index " << i << endl;
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			// We might get negative value of t, converting
			// it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

/* Driver code */
int main()
{
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEK";

	// we mod to avoid overflowing of value but we should
	// take as big q as possible to avoid the collison
	int q = INT_MAX;

	// Function Call
	search(pat, txt, q);
	return 0;
}

// This is code is contributed by rathbhupendra
