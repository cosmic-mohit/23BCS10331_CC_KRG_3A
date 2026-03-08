#include <iostream>
#include <vector>
using namespace std;

// Function to build LPS array
void buildLPS(string &patt, vector<int> &lps) {
    int m = patt.size();
    int len = 0;   
    int i = 1;

    while (i < m) {
        if (patt[i] == patt[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(string &text, string &patt) {
    int n = text.size();
    int m = patt.size();

    vector<int> lps(m, 0);
    buildLPS(patt, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == patt[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j;   // pattern found
        }
        else if (i < n && text[i] != patt[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1;  // not found
}

int main() {
    string text = "aaaaaab";
    string patt = "aaab";

    int index = KMP(text, patt);

    if (index != -1)
        cout << "Pattern found at index: " << index << endl;
    else
        cout << "Pattern not found!" << endl;

    return 0;
}