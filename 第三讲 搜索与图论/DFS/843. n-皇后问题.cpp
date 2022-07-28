#include<iostream>
using namespace std;
#define MAX_N 10

int n;
int state[MAX_N];//state[x]=y表示第x行的皇后放在第y列

//检测(x,y)是否能放置皇后
bool IsAbleToPlace(int x, int y) {
	for (int i = 1; i < x; i++) {
		if (state[i] == y || abs(x - i) == abs(y - state[i])) {
			return false;
		}
	}
	return true;
}

void FormatPrintMap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (state[i] == j) {
				cout << 'Q';
			}
			else {
				cout << '.';
			}
		}
		cout << endl;
	}
	cout << endl;
}

//x表示下一个棋子放置的行
void PlaceQueen(int x) {
	for (int i = 1; i <= n; i++) {
		if (IsAbleToPlace(x, i)) {
			state[x] = i;
			if (x == n) {
				FormatPrintMap();
			}
			else {
				PlaceQueen(x + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	PlaceQueen(1);
	return 0;
}