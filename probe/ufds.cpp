#include <iostream>
#include <vector>
#include <set>

// UFDS good for:
// checking if 2 items is in the same set
// unit 2 disjoint sets into one larger one

// these operations are not efficient with STL sets
// having a vector of sets and looping through them
// is expensive

// set_union (in algorithm) will not be efficient enough

// using namespace std;

typedef std::vector<int> vi;

int N = 8; // number of initial sets
vi p(N); // parents; initially, p[i] = i
vi rank(N); // initially 0

// union by rank:
// meaning that union the set with lower rank to the set with
// a higher ranking

int findSet(int i)
{
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}

bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
 {
    if (!isSameSet(i, j)) {
        int pi = findSet(i), pj = findSet(j);
        if (rank[pi] > rank[pj]) {
            p[pj] = pi;
        } else {
            p[pi] = pj;
            if (rank[pi] == rank[pj]) {
                ++rank[pj];
            }
        }
    }
}

typedef std::set<int> si;

int numDisjointSets()
{
    si marked;
    for (size_t i = 0; i < p.size(); ++i) {
        marked.insert(findSet(i));
    }
    return marked.size();
}

int sizeOfSets(int i)
{
    numDisjointSets(); // this call is to make the whole thing compressed
    int x = findSet(i);
    int cnt = 0;
    for (const auto &i : p) {
        if (i == x) ++cnt;
    }
    return cnt;
}

int main()
{
    for (int i = 0; i < N; ++i) {
        p[i] = i;
    }

    // p.shrink_to_fit();
    // rank.shrink_to_fit();

    for (int i : p) {
        printf("%d ", i);
    }
    printf("\n");


    unionSet(0, 1);
    unionSet(2, 3);
    unionSet(4, 5);
    unionSet(6, 7);

    unionSet(0, 2);
    unionSet(4, 6);
    unionSet(0, 4);

    for (int i : rank) {
        printf("%d ", i);
    }
    printf("\n");

    printf("%d\n", numDisjointSets());

    return(0);
}
