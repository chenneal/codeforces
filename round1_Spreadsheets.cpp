#include <iostream>
#include <ctype.h>

using namespace std;

bool is_RC(string& s) {
    if(s[0] == 'R' && isdigit(s[1]))
    {
        for (int i = 2; i < s.size(); i++)
            if (s[i] == 'C')
                return true;
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        int line, column;
        bool C_appear;
        for (int i = 0; i < n; i++) {
            int line, column;
            C_appear = false;
            string s;
            cin >> s;
            if (is_RC(s)) {
                line = 0;
                column = 0;
                string result = "";
                for (char c : s) {
                    if (c == 'R')
                        continue;
                    if (c == 'C') {
                        C_appear = true;
                        continue;
                    }
                    if (!C_appear)
                        line = (c-'0') + line*10;
                    else 
                        column = (c-'0') + column*10;
                }
                while (column != 0) {
                    if (column % 26 == 0) {
                        result.insert(0, 1, 'Z');
                        column = column/26-1;

                    }
                    else {
                        result.insert(0, 1, char('A'+column%26-1));
                        column = column/26;
                    }
                }
                cout << result << line << endl;
            }
            else {
                line = 0;
                column = 0;
                int i = 0;
                while (isalpha(s[i])) {
                    column = s[i]-'A'+1 + column*26;
                    i++;
                }
                while (i < s.size()) {
                    line = s[i]-'0'+line*10;
                    i++;
                }
                cout << 'R' << line << 'C' << column << endl;
            }
        }
    }
    return 0;
}
