class UnionFind {
public:
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void union(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            if (size[root_x] < size[root_y]) {
                parent[root_x] = root_y;
                size[root_y] += size[root_x];
            } else {
                parent[root_y] = root_x;
                size[root_x] += size[root_y];
            }
        }
    }

    bool equal(int x, int y) {
        return find(x) == find(y);
    }

    int count(int x) {
        int root = find(x);
        return size[root];
    }
};
