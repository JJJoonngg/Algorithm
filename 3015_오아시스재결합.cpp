//
// Created by 김종신 on 18/10/2019.
//
#include <iostream>
#include <stack>
using namespace std;
long long n, ans = 0, cur, check;
stack<pair<int, int>> s;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> cur;
        check = 1;
        while(!s.empty() && s.top().first <= cur){
            ans += s.top().second;
            if(s.top().first == cur) check+= s.top().second;
            s.pop();
        }
        if(!s.empty()) ans++;
        s.push(make_pair(cur, check));
    }

    cout << ans << "\n";
    return 0;
}