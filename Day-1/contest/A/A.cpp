#include <bits/stdc++.h>
using namespace std;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r",  stdin);
    freopen(out_file.c_str(), "w",  stdout);
}

// int main() { // O(n^3)
//     if (getenv("LOCAL")) setIO();
//     double start = clock();
//     string s;
//     cin >> s;
//     int n = (int) s.size();
//     int answer = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i+1; j < n; j++) {
//             for (int k = j+1; k < n; k++) {
//                 if (s[i] == 'a' && s[j] == 'b' && s[k] == 'c') {
//                     ++answer;
//                 }
//             }   
//         }
//     }
//     cout << answer << endl;
//     cerr << ((double) clock() - start) / CLOCKS_PER_SEC << endl;
// }

// int main() { // O(n^2)
//     double start = clock();
//     string s; cin >> s;
//     int n = (int) s.size();
//     int answer = 0;
//     for (int j = 0; j < n; j++) {
//         if (s[j] != 'b') continue;
//         int countA = 0;
//         for (int i = 0; i < j; i++) {
//             if (s[i] == 'a') ++countA;
//         }
//         int countC = 0;
//         for (int i = j+1; i < n; i++) {
//             if (s[i] == 'c') ++countC;
//         }
//         answer += countA * countC;
//     }
//     cout << answer << endl;
//     cerr << ((double) clock() - start) / CLOCKS_PER_SEC << endl;
// }

int main() { // O(n)
    if (getenv("LOCAL")) setIO();
    double start = clock();
    string s; cin >> s;
    int n = (int) s.size();
    long long answer = 0;
    int countA = 0, countC = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'c') ++countC;
    }
    for (int j = 0; j < n; j++) {
        if (s[j] != 'b') {
            if (s[j] == 'a') ++countA;
            if (s[j] == 'c') --countC;
            continue;
        }
        answer += (long long) countA * countC;
    }
    cout << answer << endl;
    cerr << ((double) clock() - start) / CLOCKS_PER_SEC << endl;
}