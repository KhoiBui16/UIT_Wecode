/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
merge
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
//###INSERT CODE HERE -
	for (auto x : A)
		Hash[x]++;
	vector<int> res(K);
	int i = 0;
	for (map<int, int>::iterator it = Hash.begin(); it != Hash.end(); it++) {
		if (i >= k)
			break;
		res[i++] = it->first;
		it->second -= 1;
	}
	map<int, int>::iterator it = Hash.begin();
	while (i < k) {
		while (it->second == 0)
			it++;
		res[i++] = it->first;
		it->second -= 1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> k;

	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> ans = get_ans(a,k);

	for (const int& x: ans) cout << x << ' ';
	return 0;
}
