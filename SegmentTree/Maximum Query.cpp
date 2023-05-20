// You are given an array of integet of size N and Q queries in form of (l, r). 
// You are supposed to find the maximum value of array between index l and r (both inclusive)
#include<bits/stdc++.h>
#define M (beg+end)/2
using namespace std;

const int N = (int)(1e4+5);

int a[N];
int st[4*N];


void build(int beg, int end, int pos) {
	if(beg == end) {
		st[pos] = a[beg];
		return;
	}

	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	st[pos] = max(st[2*pos+1], st[2*pos+2]);
}


int query(int beg, int end, int ql, int qr, int pos) {
	if(ql<=beg and qr>=end) {
		return st[pos];
	} else if(ql>end or qr<beg) {
		return INT_MIN;
	}

	return max(query(beg, M, ql, qr, 2*pos+1), query(M+1, end, ql, qr, 2*pos+2));
}



int main(){
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    build(0,n-1,0);
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        int res = query(0,n-1,a,b,0);
        cout << res << endl;  
    }
    
    // write your code here
    return 0;
}
