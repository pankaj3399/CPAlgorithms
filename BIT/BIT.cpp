#include<bits/stdc++.h>

using namespace std;

const int N = (int)(1e5+5);

int bit[N];

// Sum of [0, r]
int query(int r, int n) {
	int res = 0;
	for(int i=r+1; i>0; i -= (i & -i)) {
		res += bit[i];
	}

	return res;
}

void update(int k, int delta, int n) {
	k += 1;
	for(; k<=n; k += (k & -k)) {
		bit[k] += delta;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];

	for(int i=0; i<n; i++) update(i, arr[i], n);

	int q;
	cin>>q;
	while(q--) {
		int type;
		cin>>type;

		if(type == 0) {
			int idx, val;
			cin>>idx>>val;
			int delta = val - arr[idx];
			arr[idx] = val;
			update(idx, delta, n);
		} else {
			int l, r;
			cin>>l>>r;

			int ans = query(r, n);
			if(l > 0) ans -= query(l-1, n);
			cout<<ans<<"\n";

		}
	}
	return 0;
}

/*
	2 1 3 2 3

    2 3 3 2 3  -> 8

	2 3 0 2 3  -> 2    	
*/
