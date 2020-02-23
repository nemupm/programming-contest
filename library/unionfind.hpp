class UnionFind {
    vector<int> _nodes;

public:
    UnionFind(int size) : _nodes(vector<int>(size+1, -1)) {}

    int findRoot(int a) {
        if (_nodes[a] == -1) return a;
        const int root = findRoot(_nodes[a]);
        _nodes[a] = root;
        return root;
    }
    void unite(int a, int b) {
        const int rootA = findRoot(a);
        const int rootB = findRoot(b);
        if (rootA == rootB) return;

        _nodes[rootB] = rootA;
    }
};
