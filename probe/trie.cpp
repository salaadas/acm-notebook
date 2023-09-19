// https://en.wikipedia.org/wiki/Trie
// https://stackoverflow.com/a/32452073

// I could have omitted the `char c` in struct Node
// but I kept it there so that it is easier to understand

// In case of omitting it, we would use the index of each children
// as the values
#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....
#include <stack>

using namespace std;
// #define int long long
constexpr int MAX = 26;

struct Node {
    char c;
    vector<Node*> children;
    bool isTerminal = false;
    Node *parent;

    Node() {
        children.assign(MAX, nullptr);
        isTerminal = false;
    }

    Node(char _c) : c(_c) { Node(); }
};

struct Trie {
    Node *root = new Node();
    vector<string> words;
    Node *prefixRoot = new Node();
    string currentPrefixStr = "";

    Trie() {}

    void insert(string key) {
        Node *crawl = root;
        for (size_t i = 0; i < key.length(); ++i) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) {
                crawl->children[index] = new Node();
                crawl->children[index]->c = key[i];
                crawl->children[index]->parent = crawl;
            }
            crawl = crawl->children[index];
        }
        crawl->isTerminal = true;
    }

    Node *searchNode(string key) {
        Node *crawl = root;
        for (size_t i = 0; i < key.length(); ++i) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) return nullptr;
            crawl = crawl->children[index];
        }

        prefixRoot = crawl;
        currentPrefixStr = key;
        words.clear();
        return crawl;
    }

    bool startsWith(string key) {
        Node *t = searchNode(key);
        if (t != nullptr) return true;
        return false;
    }

    bool contains(string key) {
        Node *t = searchNode(key);
        if (t != nullptr && t->isTerminal) return true;
        return false;
    }

    void wordsFinder(Node *node) {
        if (node->isTerminal) {
            Node *tmp = node;
            stack<char> s;
            while (tmp != prefixRoot) {
                s.push(tmp->c);
                tmp = tmp->parent;
            }
            string word = currentPrefixStr;
            while (!s.empty()) {
                word.append(1, s.top()); // https://cplusplus.com/reference/string/string/append/
                s.pop();
            }
            words.push_back(word);
        }

        for_each(node->children.begin(), node->children.end(), [&](Node *n) {
            if (n) {
                wordsFinder(n);
            }
        });
    }

    void displayMatchingWords() {
        printf("--------------------\n");
        for_each(words.begin(), words.end(), [](const auto &s) { printf("%s\n", s.c_str()); });
        printf("--------------------\n");
    }

    void cleanup(Node *root) {
        if (root != nullptr) {
            for (size_t i = 0; i < root->children.size(); ++i) {
                cleanup(root->children[i]);
            }
            delete root;
        }
    }

    ~Trie() {
        cout << "cleanining up...." << endl;
        cleanup(root);
    }
};

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    vector<string> fruits = {
        "orange", "lemon", "kaffir ", "lime", "sweet ", "lime", "pomelo",
        "tangerine", "sudachi", "ugli ", "yuzu ", "tangelo", "kumquat",
        "mandarin ", "grapefruit", "banana", "apple", "grape", "jackfruit", "papaya"
    };

    Trie t;
    for (const auto &s : fruits) t.insert(s);
    cout << "What would you like to query (type only the first letters to see what happen\n> " << flush;
    string keyword; cin >> keyword;
    cout << "Here is what we found:" << endl;
    if (t.startsWith(keyword)) {
        Node *tmp = t.searchNode(keyword);
        t.wordsFinder(tmp);
        t.displayMatchingWords();
    }

    return 0;
}
