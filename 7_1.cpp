#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int prime = 101; 
const int base = 256;
vector<int> rabinKarp(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = 0;
    int textHash = 0;    
    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * base) % prime;
    vector<int> occurrences;
    for (int i = 0; i < m; i++) {
        patternHash = (base * patternHash + pattern[i]) % prime;
        textHash = (base * textHash + text[i]) % prime;
    }
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                occurrences.push_back(i);
        }
        if (i < n - m) {
            textHash = (base * (textHash - text[i] * h) + text[i + m]) % prime;
            if (textHash < 0)
                textHash += prime;
        }
    }
    return occurrences;
}
int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    vector<int> occurrences = rabinKarp(text, pattern);
    if (occurrences.empty()) {
        cout << "-1" << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int i = 0; i < occurrences.size(); i++) {
            cout << occurrences[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
