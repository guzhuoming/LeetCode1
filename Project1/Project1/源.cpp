#include<iostream>
#include<vector>
using namespace std;
// 长按键入 20201021
bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0;
    bool ans = true;
    // i: index for name
    // j: index for typed
    while (i < name.length() && j < typed.length()) {
        if (name[i] == typed[j]) {
            // i, j not arrived at the end of name or typed
            if (i + 1 < name.length() && j + 1 < typed.length()) {
                if (name[i + 1] == name[i] && typed[j] == typed[j + 1]) {
                    i++;
                    j++;
                }
                else if (name[i + 1] != name[i] && typed[j] == typed[j + 1]) {
                    j++;
                }
                else if (name[i + 1] != name[i] && typed[j] != typed[j + 1]) {
                    i++;
                    j++;
                }
                else {
                    return false;
                }
            }
            // i or j arrived at the end of name or typed
            else {
                if (i == name.length() - 1 && j != typed.length() - 1) {
                    j++;
                    continue;
                }
                if (i != name.length() - 1 && j == typed.length() - 1) {
                    i++;
                    continue;
                }
                if (i == name.length() - 1 && j == typed.length() - 1) {
                    return true;
                }
            }
        }
        else {
            ans = false;
            break;
        }
    }
    return ans;
}
// 划分字母空间 20201022
vector<int> partitionLabels(string S) {
    vector<int> ans;
    int* last_index = new int[26];
    for (int i = 0; i < S.length(); i++) {
        last_index[S[i] - 'a'] = i;
    }
    int start = 0, end = 0;
    for (int i = 0; i < S.length(); i++) {
        end = max(last_index[S[i] - 'a'], end);
        if (i == end) {
            ans.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return ans;
}
int main() {
    // 长按键入 20201021
    //string a = "alex";
    //string b = "aaleex";
    //cout << isLongPressedName(a, b) << endl;
    //return 0;

    // 划分字母 20201022
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = partitionLabels(s);
}