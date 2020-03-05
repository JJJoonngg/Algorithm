//
// Created by 김종신 on 24/10/2019.
//
#include <bits/stdc++.h>

#define MAXI 21
using namespace std;
int arr[MAXI];
bool check[MAXI];
int answer = 0, siz;

void dfs(int depth, int sum, int res) {
    if (depth >= siz){
        if (sum == res)
            answer++;
        return;
    }
    dfs(depth + 1 , sum+arr[depth], res);
    dfs(depth + 1 , sum-arr[depth], res);
}

int solution(vector<int> numbers, int target) {
    siz = numbers.size();
    for (int i = 0; i < siz; i++)
        arr[i] = numbers[i];

    dfs(1, arr[0], target);
    dfs(1, arr[0] * -1, target);

    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    cout << solution(v, 3) << "\n";
    return 0;
}