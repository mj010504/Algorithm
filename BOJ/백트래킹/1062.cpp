#include <bits/stdc++.h>

using namespace std;

int checked;
int res = 0;
int n, k;
vector<int> word(50);

void dfs(int idx, int cnt) {
    if(cnt == k) {
        int temp = 0;
        for(int i = 0; i < n; i++) {
            if((word[i] & checked) == word[i]) temp++;
        }
        res = max(res, temp);
    }
    else {
        for(int i = idx; i < 26; i++) {
            if((checked & (1 << i)) == 0) {
                checked |= (1 << i);
                dfs(i + 1, cnt + 1);
                checked &= ~(1 << i);
            }
        }
    }
}

int main() {
    freopen("input.txt", "rt", stdin);  
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    if(k < 5) {
        cout << 0;
        exit(0);
    }

    if(k == 26) {
        cout << n;
        exit(0);
    }

    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;

        int num = 0;
        for(int j = 0; j < str.size(); j++) {
            num |= 1 << (str[j] - 'a');
        }
        word[i] = num;

    }


    dfs(0, 0);
    checked |= 1 << ('a' - 'a');
    checked |= 1 << ('n' - 'a');
    checked |= 1 << ('t' - 'a');
    checked |= 1 << ('i' - 'a');
    checked |= 1 << ('c' - 'a');

    cout << res;

    return 0;
}


/* 
    시간초과 때문에 힘들었던 문제, 단순한 백트래킹으로는 안풀리는 것 같다.
    알파벳은 비트마스킹을 통해 시간복잡도를 많이 줄일 수 있다는 것을 알았다.
*/
