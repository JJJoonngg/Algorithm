//
// Created by 김종신 on 2019/11/25.
//
#include <bits/stdc++.h>

using namespace std;

struct info {int weight,height,grade;};
info arr[51];
int n;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i].weight >> arr[i].height;
        arr[i].grade = 1;
    }
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            if(arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)
                arr[i].grade++;
        }
    }

    for(int i=0;i<n;i++) cout << arr[i].grade <<" ";
    cout <<endl;

    return 0;
}
