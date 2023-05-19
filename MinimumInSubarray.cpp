/* 
You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are Q queries, and each query is defined in either of the following two ways:
Query on range:
You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). Note that in this query, i and j lies in the range: [1, N].
Update query:
You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
*/


#include<bits/stdc++.h>
#define M (beg+end)/2
using namespace std;

const int N = (int)(1e5+5);

int a[N];
int st[4*N];


void build(int beg, int end, int pos) {
	if(beg == end) {
		st[pos] = a[beg];
		return;
	}

	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	st[pos] = min(st[2*pos+1], st[2*pos+2]);
}

void update(int beg, int end, int idx, int val, int pos) {
	if(beg == end) {
		st[pos] = val;
		return;
	}

	if(idx <= M) {
		update(beg, M, idx, val, 2*pos+1);
	} else {
		update(M+1, end, idx, val, 2*pos+2);
	}

	st[pos] = min(st[2*pos+1], st[2*pos+2]);
}

int query(int beg, int end, int ql, int qr, int pos) {
	if(ql<=beg and qr>=end) {
		return st[pos];
	} else if(ql>end or qr<beg) {
		return INT_MAX;
	}

	return min(query(beg, M, ql, qr, 2*pos+1), query(M+1, end, ql, qr, 2*pos+2));
}


int main(){

    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    build(0,n-1,0);

    while(q--){
        char type;
        int a,b;
        cin >> type >> a >> b;
        if(type == 'q'){
            int res = query(0,n-1,a-1,b-1,0);
            cout << res << endl;
        } else {
            update(0,n-1,a-1,b,0);
        }
    }
    
    // write your code here
    return 0;
}
