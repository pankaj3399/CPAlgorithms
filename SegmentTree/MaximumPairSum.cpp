/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input of a 'U' followed by space and then two integers i and x.
U i x
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input of a 'Q' followed by a single space and then two integers x and y.
Q x y
You must find two integers i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
 */

#include<bits/stdc++.h>
using namespace std;
#define M (begin+end)/2
const int N = 1e5;

int a[N];
vector<pair<int,int>>st(4*N);


void build(int begin, int end, int pos) {
    if(begin == end){
        // leafs
        st[pos] = {a[begin], -1};
        return;
    }
    build(begin, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	// calculate st[pos] from st[2pos +1] st[2pos+2]
    pair<int,int> p1 = st[2*pos + 1];
    pair<int,int> p2 = st[2*pos +2];
    pair<int,int>p3;
    if(p1.first > p2.first) {
        p3.first = p1.first;
        p3.second = max(p1.second, p2.first);
    } else {
         p3.first = p2.first;
         p3.second = max(p2.second, p1.first);       
    }
    st[pos] = p3;
}


pair<int,int> query(int begin, int end, int ql, int qr, int pos) {
	if(ql<=begin and qr>=end) {
		return st[pos];
	} else if(ql>end or qr<begin) {
          return {-1, -1};
        }
    pair<int,int> p1 = query(begin, M, ql, qr, 2*pos+1);
    pair<int,int> p2 =  query(M+1, end, ql, qr, 2*pos+2);

    pair<int,int>p3;
     if(p1.first > p2.first) {
        p3.first = p1.first;
        p3.second = max(p1.second, p2.first);
    } else {
         p3.first = p2.first;
         p3.second = max(p2.second, p1.first);       
    }

	return p3;
}


void update(int begin, int end, int idx, int val, int pos) {
	if(begin == end) {
          st[pos] = {val, -1};
          return;
	}

	if(idx <= M) {
		update(begin, M, idx, val, 2*pos+1);
	} else {
		update(M+1, end, idx, val, 2*pos+2);
	}

    // calculate st[pos] from st[2pos +1] st[2pos+2]
    pair<int,int> p1 = st[2*pos + 1];
    pair<int,int> p2 = st[2*pos +2];
    pair<int,int>p3;
    if(p1.first > p2.first) {
        p3.first = p1.first;
        p3.second = max(p1.second, p2.first);
    } else {
         p3.first = p2.first;
         p3.second = max(p2.second, p1.first);       
    }
    st[pos] = p3;

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
        char type;
        int a,b;
        cin >> type >> a >> b;
        if(type == 'Q'){
            pair<int,int> res = query(0,n-1,a-1,b-1,0);
            cout << res.first + res.second << endl;
        } else {
            update(0,n-1,a-1,b,0);
        }
    }
    
    // write your code here
    return 0;
}
