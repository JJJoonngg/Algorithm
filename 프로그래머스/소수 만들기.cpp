//
// Created by 김종신 on 2020/06/02.
//
#include <vector>

#define MAXI 3000
using namespace std;
bool arr[MAXI + 1];

int solution(vector<int> nums) {
    int answer = 0, siz = nums.size();
    arr[1] = true;
    for (int i = 2; i * i <= MAXI; i++)
        if (!arr[i]) { for (int j = i * i; j <= MAXI; j += i) arr[j] = true; }

    for (int i = 0; i < siz; i++)
        for (int j = i + 1; j < siz; j++)
            for (int k = j + 1; k < siz; k++)
                if (!arr[nums[i] + nums[j] + nums[k]])
                    answer++;

    return answer;
}