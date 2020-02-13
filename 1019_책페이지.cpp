//풀이 참조
//https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019?qid=9aa7818e-779e-499a-9c13-d2a5ac2ef8af&v=&b=&from_search=1 
#include <bits/stdc++.h>
constexpr auto MAXI = 10;
using namespace std;
long long arr[MAXI], S = 1, E, cur = 1;
//앞 자릿수들 갯수 count
void func(int x) {
	while (x > 0) {
		arr[x % 10] += cur;
		x /= 10;
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> E;
	while (S <= E) {
		//끝자리 0
		while (S <= E && S % 10 != 0) {
			func(S);
			S++;
		}
		if (E < S) break;
		//끝자리 9
		while (S <= E && E % 10 != 9) {
			func(E);
			E--;
		}
		//다음 자릿수
		S /= 10, E /= 10;

		//현재 자릿수 계산
		for (int i = 0; i < MAXI; i++)
			arr[i] += (E - S + 1) * cur;
		cur *= 10;
	}

	for (int i = 0; i < MAXI; i++) cout << arr[i] << " ";
	cout << "\n";
	return 0;
}