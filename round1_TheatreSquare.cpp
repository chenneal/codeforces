#include <iostream>

using namespace std;

typedef long long ll;
 
int main() {
    int m, n, a;
    int width, length;
    
    while (cin >> m >> n >> a) {
        width = (m%a == 0 ? m/a : m/a+1);
        length = (n%a == 0 ? n/a : n/a+1);
        cout << ll(width)*ll(length) << endl;
    }

    return 0;
}
