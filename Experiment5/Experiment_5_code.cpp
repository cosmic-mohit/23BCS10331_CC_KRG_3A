#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    unordered_set<string> st;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }

    while(m--) {
        string s;
        cin >> s;

        bool found = false;

        for(int i = 0; i < s.length() && !found; i++) {
            char original = s[i];

            for(char ch = 'a'; ch <= 'c'; ch++) {
                if(ch == original) continue;

                s[i] = ch;

                if(st.count(s)) {
                    found = true;
                    break;
                }
            }

            s[i] = original; 
        }

        if(found) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}