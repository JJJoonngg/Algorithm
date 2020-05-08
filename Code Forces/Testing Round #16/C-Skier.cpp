//
// Created by 김종신 on 2020/05/07.
//
#include <iostream>
#include <map>

using namespace std;

class info {
private:
    int x;
    int y;
    int w;
    int z;
public:
    info(int _x, int _y, int _w, int _z) : x(_x), y(_y), w(_w), z(_z) {}

    bool operator<(const info &next) const {
        if (x != next.x) return x < next.x;
        else if (y != next.y) return y < next.y;
        else if (w != next.w) return w < next.w;
        else return z < next.z;
    }

};

struct xywz {
    int x, y, w, z;
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin >> input;
        int res = 0, idx = 0;
        map<info, int> m;
        pair<int, int> p1, p2;
        p1 = {0, 0};
        p2 = {0, 0};
        info a = {0, 0, 0, 0};
        info b = {0, 0, 0, 0};
        m.insert({a, idx++});
        for (auto cur : input) {
            if (cur == 'S') {
                p2.first--;
            } else if (cur == 'N') {
                p2.first++;
            } else if (cur == 'W') {
                p2.second--;
            } else if (cur == 'E') {
                p2.second++;
            }
            a = {p1.first, p1.second, p2.first, p2.second};
            b = {p2.first, p2.second, p1.first, p1.second};
            if (m.find(a) == m.end()) {
                m.insert({a, idx++});
                m.insert({b, idx++});
                res += 5;
            } else res++;
            p1 = p2;
        }
        cout << res << "\n";
    }
    return 0;
}