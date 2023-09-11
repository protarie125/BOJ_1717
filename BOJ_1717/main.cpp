#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;
vi root;

int par(int x) {
	if (root[x] == x) {
		return x;
	}

	return root[x] = par(root[x]);
}

void joint(int a, int b) {
	a = par(a);
	b = par(b);

	if (a < b) {
		root[a] = b;
	}
	else {
		root[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;
	root = vi(n + 1);
	for (auto i = 0; i <= n; ++i) {
		root[i] = i;
	}

	while (0 < (m--)) {
		int q, a, b;
		cin >> q >> a >> b;

		if (0 == q) {
			if (a == b) {
				continue;
			}

			if (b < a) {
				swap(a, b);
			}

			joint(a, b);
		}
		else {
			if (par(a) == par(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}