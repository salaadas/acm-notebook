// TODO: not done yet, too compilicated for today

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

const int N = (1 << 10) * 100;

typedef vector<char> vc;

class SegmentTree {
    private:
    vc A, st;
    int n;
    inline
    int left(int p) { return p << 1; }
    inline
    int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) {
        if (L == R) st[p] = A[L] - '0';
        else {
            int mid = (L+R)/2;
            // cout << "p: " << p << endl;
            // cout << "left: " << left(p) << endl;
            // cout << "right: " << right(p) << endl;
            build(left(p), L, mid);
            build(right(p), mid+1, R);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    int showRange(int p, int L, int R, int tL, int tR) {
        if (R < tL || L > tR) return 0;
        if (tL <= L && R <= tR) return st[p];
        int mid = (L+R)/2;
        int b1 = showRange(left(p), L, mid, tL, tR);
        int b2 = showRange(right(p), mid+1, R, tL, tR);
        return b1 + b2;
    }
    void inverse(int p, int L, int R, int tL, int tR) {
        if (L > R) {
            return;
        }
        if (L == R) {
            st[p] = st[p] == 0 ? 1 : 0;
        } else if (tL <= L && R <= tR) {
            int mid = (L+R)/2;
            inverse(left(p), L, mid, tL, tR);
            inverse(right(p), mid + 1, R, tL, tR);
            // st[p] = (st[p] + 1) % 2;
        }
    }

    public:
    SegmentTree(vc _A) : A(_A) {
        n = (int)A.size();
        st.assign(4*n, 0);
        build(1, 0, n - 1);
    }

    int showRange(int tL, int tR) {
        return showRange(1, 0, n - 1, tL, tR);
    }

    void inverse(int L, int R) {
        inverse(1, 0, n - 1, L, R);
    }
};

int main()
{
    int t; cin >> t;
    while (t--) {
        int pairs; cin >> pairs;
        std::string line;
        int times;
        vector<char> masters;
        masters.clear();
        while (pairs--) {
            cin >> times;
            getline(cin >> ws, line);
            for (int i = 0; i < times * line.size(); ++i) {
                masters.push_back(line[i % line.size()]);
            }
        }

        for (const auto &c : masters) {
            cout << c;
        }
        cout << endl;

        // build tree
        SegmentTree st(masters);

        int queries; cin >> queries;
        char cmd;
        int start, end;
        int q = 1;
        while (queries--) {
            cin >> ws; // strips whitespace
            scanf("%c%d%d", &cmd, &start, &end);
            printf("start: %d end: %d\n", start, end);
            switch (tolower(cmd)) {
                case 's': {
                    printf("Q%d: %d\n", q++, st.showRange(0, masters.size() - 1));
                } break;
                case  'f': {
                    // mutate pirates to bucc
                } break;
                case 'e': {
                    // mutate to barbary
                } break;
                case 'i': {
                    // inverse
                } break;
            }
        }
        printf("num of bucc b4 inverse: %d\n", st.showRange(0, masters.size() - 1));
        st.inverse(0, masters.size() - 1);
        printf("num of bucc after inverse: %d\n", st.showRange(0, masters.size() - 1));
    }
    return(0);
}
