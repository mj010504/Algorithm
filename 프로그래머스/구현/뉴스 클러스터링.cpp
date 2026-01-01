#include<bits/stdc++.h>

using namespace std;

bool isSpecial(char c) {
    if(c >= 'a' && c <= 'z') return false;
    if(c >= 'A' && c <= 'Z') return false;
    return true;
}

int solution(string str1, string str2) {
    int res = 0;
    map<string, int> a, b;
    for(int i = 0; i < str1.size() - 1; i++) {
        string temp = "";
        temp += tolower(str1[i]); temp += tolower(str1[i + 1]);
        if(!isSpecial(temp[0]) && !isSpecial(temp[1])) {
            a[temp] += 1;
        }
    }

    for(int i = 0; i < str2.size() - 1; i++) {
        string temp = "";
        temp += tolower(str2[i]); temp += tolower(str2[i + 1]);
        if(!isSpecial(temp[0]) && !isSpecial(temp[1])) {
            b[temp] += 1;
        }
    }   

    if(a.size() == 0 && b.size() == 0) return 65536;

    // 교집합, 합집합
    int g = 0, h = 0;
    for(auto aa : a) {
        int temp = min(aa.second, b[aa.first]);
        g += temp;
    }

    // 합집합 사용된 원소 구분
    map<string, int> m;
    for(auto aa : a) {
        m[aa.first] = 1;
        int temp = max(aa.second, b[aa.first]);
        h += temp;
    }

    for(auto bb : b) {
        if(m[bb.first] != 1) {
            h += bb.second;
        }
    }

    double temp = (double)g / (double)h;
    res = temp * 65536;

    return res;
}
