#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int solution(vector<int> av, vector<int> bv) {
    int res = 0;
    int gcdA, gcdB;
    int n = av.size();
    gcdA = av[0];
    gcdB = bv[0];

    for(int i = 1; i < n; i++) {
        gcdA = gcd(gcdA, av[i]);
    }

    for(int i = 1; i < n; i++) {
        gcdB = gcd(gcdB, bv[i]);
    }

    bool temp = true;
    for(int i = 0; i < n; i++) {
        if(bv[i] % gcdA == 0) {
            temp = false;
            break;
        }
    }
    if(temp) res = max(res, gcdA);
    
    if(gcdB > gcdA) {
        temp = true;
        for(int i = 0; i < n; i++) {
            if(av[i] % gcdB == 0) {
                temp = false;
                break;
            }
        }
       
        if(temp) res = max(res, gcdB);
    }
 
  
    return res;
}   

int main() {
    vector<int> av = {10, 20};
    vector<int> bv = {5, 17};
    solution(av, bv);
  
    return 0;
}
