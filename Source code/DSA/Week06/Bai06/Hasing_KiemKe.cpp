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

// #include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int N;

int count_distinct(const vector<string>& ids){

	map<string,int> Hash;

//###INSERT CODE HERE -
    for (string x : ids)
        Hash[x]++;
    int cnt = 0;
    return Hash.size();
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	vector<string> ids(N);

	for (int i = 0; i < N; i++) cin >> ids[i];

	cout << count_distinct(ids);

	return 0;
}
