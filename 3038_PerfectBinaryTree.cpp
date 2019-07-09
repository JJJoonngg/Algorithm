/*
문제
완전 이진 트리의 각 노드는 계측적인 구조로 이루어져 있다. 루트 노드의 레벨은 0이며,
레벨 1의 두 자식 노드를 가지고 있다. 또, 레벨 1의 자식 노드의 레벨은 2이다.
보통 레벨이 N인 완전 이진 트리는 2N-1개의 노드를 가지고 있다. 레벨이 N-1이 아닌 모든 노드는 자식 노드를 두 개씩 가지고 있다.
1부터 2N-1까지 숫자를 레벨이 N인 완전 이진 트리의 각 노드에 적을 수 있다.
이때, 레벨이 D인 각각의 노드에 대해서 왼쪽 서브트리에 쓰여 있는 숫자의 합과 오른쪽 서브트리에 쓰여 있는 숫자의 합의 차이는 2D라는 조건을 만족해야 한다.
예를 들어, 루트의 왼쪽 서브 트리의 합과 오른쪽 서브 트리의 합의 차이는 1이어야 하며, 레벨이 1인 경우에는 2이어야 한다. 또, 모든 숫자는 한 번씩 사용해야 한다.
N이 주어졌을 때, 문제의 조건에 맞게 완전 이진 트리의 각 노드에 숫자를 정하는 프로그램을 작성하시오.
입력
첫째 줄에 트리의 레벨인 N이 주어진다. (1 ≤ N ≤ 15)
3
출력
첫째 줄에 문제의 조건에 맞게 숫자를 채운 완전 이진 트리를 프리오더로 순회한 결과를 출력한다.
3 1 7 5 6 2 4
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[16];
int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;



	return 0;
}
