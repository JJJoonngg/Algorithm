//
// Created by 김종신 on 2020/02/15.
//
#include <bits/stdc++.h>

#define MAXI 27
using namespace std;

int alphabet[MAXI];

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++)
            if (s[i] >= 'a' && s[i] <= 'z')
                alphabet[s[i] - 'a']++;
        s.clear();
    }
    int temp = -1;
    for (int i = 0; i < 26; i++)
        temp = max(alphabet[i], temp);
    for (int i = 0; i < 26; i++)
        if (alphabet[i] == temp)
            cout << (char) (i + 'a');
    cout << "\n";
    return 0;
}