#include<iostream>
using namespace std;
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
int main() {
    string a = "alex";
    string b = "aaleex";
    cout << isLongPressedName(a, b) << endl;
    return 0;
}