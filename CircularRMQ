/* https://codeforces.com/problemset/problem/52/C */
#include<bits/stdc++.h>
#define int long long
#define M (beg+end)/2
using namespace std;

const int N = (int)(2e5+5);

const int MAX = (int)(1e13+1);
int a[N];
int st[4*N];
int lazy[4*N];


void pushdown(int pos, int beg, int end) {
	if(lazy[pos] != 0) {
		st[pos] += lazy[pos];
		if(beg != end) {
			lazy[2*pos+1] += lazy[pos];
			lazy[2*pos+2] += lazy[pos];
		}
		lazy[pos] = 0;
	}
}

void build(int beg, int end, int pos) {
	if(beg == end) {
		st[pos] = a[beg];
		return;
	}

	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	st[pos] = min(st[2*pos+1], st[2*pos+2]);
}

void update(int beg, int end, int l, int r, int v, int pos) {
	pushdown(pos, beg, end);
	if(l <= beg and r >= end) {
		lazy[pos] += v;
		pushdown(pos, beg, end);
		return;
	} else if(l>end or r<beg) {
		return;
	}
	update(beg, M, l, r, v, 2*pos+1);
	update(M+1, end, l, r, v, 2*pos+2);
	st[pos] = min(st[2*pos+1], st[2*pos+2]);
}

int query(int beg, int end, int l, int r, int pos) {
	pushdown(pos, beg, end);
	if(l <= beg and r>= end) {
		return st[pos];
	} else if(l>end or r<beg) {
		return MAX;
	}
	return min(query(beg, M, l, r, 2*pos+1), query(M+1, end, l, r, 2*pos+2));
}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	build(0, n-1, 0);
	int q;
	cin>>q;
	while(q--) {
		int l, r, v;
		char ch;
		cin>>l>>r;
		ch = cin.get();
		if(ch == ' ') {
			cin>>v;
			if(l <= r) {
				update(0, n-1, l, r, v, 0);
			} else {
				update(0, n-1, l, n-1, v, 0);
				update(0, n-1, 0, r, v, 0);
			}
		} else {
			if(l <= r) {
				cout<<query(0, n-1, l, r, 0) <<"\n";
			} else {
				cout<< min(query(0, n-1, l, n-1, 0), query(0, n-1, 0, r, 0)) <<"\n";
			}
		}
	}
	return 0;
}
