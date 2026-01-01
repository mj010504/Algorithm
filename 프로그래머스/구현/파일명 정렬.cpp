#include<bits/stdc++.h>

using namespace std;

struct file {
    string head;
    int number, n;

    bool operator<(const file &b) const {
        if (head != b.head) {
            return head < b.head;
        }

        if (number != b.number) {
            return number < b.number;
        }

        return n < b.n;
    }
};

bool isDigit(char c) {
    if(c >= '0' && c <= '9') return true;
    return false;
}

vector<string> solution(vector<string> fv) {
    vector<string> res;
    vector<file> files;

    for(int j = 0; j < fv.size(); j++) {
        auto f = fv[j];
        string head = "", number = "", tail = "";
        int i = 0;

        // Head 뽑기
        for(i = 0; i < f.size(); i++) {
            if(isDigit(f[i])) {
                break;
            }
            else {
                head += f[i];
            }
        }

        // Number 뽑기
        for(; i < f.size(); i++) {
            if(!isDigit(f[i])) {
                break;
            }
            else {
                number += f[i];
            }
        }

        for(int k = 0; k < head.size(); k++) {
            head[k] = tolower(head[k]);
        }

        files.push_back({head, stoi(number), j});
    }

    sort(files.begin(), files.end());
    for(auto f : files) {
        res.push_back(fv[f.n]);
    }

    return res;
}

int main() {

  
    return 0;
}
