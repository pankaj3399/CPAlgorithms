/* https://www.spoj.com/problems/KQUERYO/ */
#include<bits/stdc++.h>
#define M (beg + end)/2
using namespace std;

const int N = (int)(3e5+5);

vector<int> st[4*N];
int arr[N];

void build(int beg, int end, int pos) {
	if(beg == end) {
		st[pos].push_back(arr[beg]);
		return;
	}

	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);

	merge(st[2*pos+1].begin(), st[2*pos+1].end(), st[2*pos+2].begin(), st[2*pos+2].end(), back_inserter(st[pos]));
}

int query(int beg, int end, int ql, int qr, int k, int pos) {
	if(ql <= beg && qr >= end) {
		// Completely inside
		auto it = upper_bound(st[pos].begin(), st[pos].end(), k);
		int numLesser = it - st[pos].begin();
		return (end - beg + 1 - numLesser);
	} else if(ql > end or qr < beg) {
		return 0;
	}

	return query(beg, M, ql, qr, k, 2*pos+1) + query(M+1, end, ql, qr, k, 2*pos+2);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	cin>>n;

	for(int i=0; i<n; i++) cin>>arr[i];

	build(0, n-1, 0);

	int q;
	int ans = 0;

	cin>>q;

	while(q--) {
		int a, b, c;
		cin>>a>>b>>c;
		a ^= ans;
		b ^= ans;
		c ^= ans;
		if(a < 1) a=1;
		if(b > n) b=n;
		if(a > b) {
			ans = 0;
			cout<<ans<<"\n";
			continue;
		}
		a--;
		b--;

		ans = query(0, n-1, a, b, c, 0);
		cout<<ans<<"\n";
	}

	return 0;
}


