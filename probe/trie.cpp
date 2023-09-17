// https://en.wikipedia.org/wiki/Trie
#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....

using namespace std;
// #define int long long
constexpr int MAX = 26;

struct Node {
    // string value;
    vector<Node*> children;
    bool isTerminal = false;

    Node() {
        children.assign(MAX, nullptr);
        isTerminal = false;
    }
};

struct Trie {
    Node *root = new Node();

    Trie() {}

    void insert(string key) {
        Node *crawl = root;
        for (int i = 0; i < key.length(); ++i) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) {
                crawl->children[index] = new Node();
            }
            crawl = crawl->children[index];
        }
        crawl->isTerminal = true;
    }

    bool contains(string key) {
        Node *crawl = root;
        for (int i = 0; i < key.length(); ++i) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) return false;
            crawl = crawl->children[index];
        }
        // return crawl->isTerminal;
        return true;
    }
};

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string keys[] = {
        "hello", "hello", "hellop",
        "cat", "car", "can",
        "update", "upgrade"
    };

    Trie t;
    for (const auto &s : keys) t.insert(s);
    cout << (t.contains("can") ? "yes" : "no") << endl;

    return 0;
}
