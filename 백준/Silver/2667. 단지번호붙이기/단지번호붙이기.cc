#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

int arr[25][25];
int n;

class Pair
{
public:
	int x, y;

	Pair(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

int BFS(Pair start) {
	queue<Pair*> q;
	q.push(&start);
	int count = 0;
	arr[start.x][start.y] = 0;
	while (q.size() > 0) {
		Pair current = *q.front();
		q.pop();
		count++;
		if (current.x > 0) {
			if (arr[current.x - 1][current.y] == 1) {
				arr[current.x - 1][current.y] = 0;
				q.push(new Pair(current.x - 1, current.y));
			}
		}
		if (current.y > 0) {
			if (arr[current.x][current.y - 1] == 1) {
				arr[current.x][current.y - 1] = 0;
				q.push(new Pair(current.x, current.y - 1));
			}
		}
		if (current.x < n - 1) {
			if (arr[current.x + 1][current.y] == 1) {
				arr[current.x + 1][current.y] = 0;
				q.push(new Pair(current.x + 1, current.y));
			}
		}
		if (current.y < n - 1) {
			if (arr[current.x][current.y + 1] == 1) {
				arr[current.x][current.y + 1] = 0;
				q.push(new Pair(current.x, current.y + 1));
			}
		}
	}
	return count;
}

int main() {
	cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < n; j++) {
			arr[j][i] = input[j] - 48;
		}
	}

	int count = 0;
	vector<int> amount;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == 1) {
				count++;
				amount.push_back(BFS(*new Pair(j, i)));
			}
		}
	}
	sort(amount.begin(), amount.end());

	cout << count << "\n";
	for (int i = 0; i < amount.size(); i++) {
		cout << amount[i] << "\n";
	}
	return 0;
}