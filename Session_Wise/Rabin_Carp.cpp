#include <iostream>
using namespace std;

int base=10;

int hashFunc(string &s){
    int result=0;
    for(int i=0;i<s.length();i++){
        result =result*base + (s[i]-'a'+1);
    }
    return result;
}

int rabinKarp(string &text, string &patt){
    int n=text.size();
    int m=patt.size();
    int pattHash=hashFunc(patt);
    
    for(int i=0;i<n;i++){
        string temp=text.substr(i,m);
        int textHash=hashFunc(temp);
        if(pattHash == textHash){
            return i;
        }
    }
    return -1;
}

int main()
{
    string text="abcbaccacb";
    string patt="acb";
    
    int index=rabinKarp(text,patt);
    if(index != -1){
      cout << "Patten found at index: " << index << endl;
    }
    else {
        cout << "Pattern not found!" << endl;
    }
}