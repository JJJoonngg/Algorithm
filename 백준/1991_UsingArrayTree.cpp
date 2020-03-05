#include <iostream>
using namespace std;

char arr[26][3];

void preorder(char ch) {
	if (ch == '.') return;
	else {
		cout << arr[ch - 'A'][0];
		preorder(arr[ch - 'A'][1]);
		preorder(arr[ch - 'A'][2]);
	}
}
void inorder(char ch) {
	if (ch == '.') return;
	else {
		inorder(arr[ch - 'A'][1]);
		cout << arr[ch - 'A'][0];
		inorder(arr[ch - 'A'][2]);
	}
}
void postorder(char ch) {
	if (ch == '.') return;
	else {
		postorder(arr[ch - 'A'][1]);
		postorder(arr[ch - 'A'][2]);
		cout << arr[ch - 'A'][0];

	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		arr[a - 'A'][0] = a;
		arr[a - 'A'][1] = b;
		arr[a - 'A'][2] = c;
	}
	
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;
}