//
// Created by 김종신 on 2019/11/28.
//
#include <bits/stdc++.h>
using namespace std;

int n;
struct info {int num, value;};
deque<info> deq;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++){
        int tmp; cin>> tmp;
        deq.push_back({i,tmp});
    }
    while(!deq.empty()){
        if(deq.size() == 1){
            cout << deq.front().num <<" ";
            break;
        }
        int val = deq.front().value;
        cout << deq.front().num <<" ";
        deq.pop_front();
        if(val < 0){
            val *= -1;
            for(int i = 0;i< val ; i++){
                info cur = deq.back();
                deq.pop_back();
                deq.push_front({cur});
            }
        }else {
            for(int i = 0;i< val-1 ; i++){
                info cur = deq.front();
                deq.pop_front();
                deq.push_back({cur});
            }
        }
    }
    cout << "\n";

    return 0;
}
