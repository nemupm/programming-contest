// RMQ (Range Minimum Query)
class SegmentTree {
    vector<int> nodes_;
    int size_;

    int query (const int left, const int right, const int index, const int l, const int r) const {
        if (r <= left || right <= l) return INT_MAX;
        if (left <= l && r <= right) return nodes_[index];

        return min (
                query(left, right, 2 * index + 1, l, (l + r) / 2),
                query(left, right, 2 * index + 2, (l + r) / 2, r)
        );
    }

public:
    SegmentTree(const int maxSize) {
        size_ = 1;
        while (size_ < maxSize) size_ *= 2;
        nodes_ = vector<int> (2 * size_, INT_MAX);
    };

    void update (int index, const int value) {
        index += size_ - 1;
        nodes_[index] = value;
        while (index > 0) {
            index = (index - 1) / 2;
            nodes_[index] = min(nodes_[2 * index + 1], nodes_[2 * index + 2]);
        }
    }

    // get value in [left, right)
    int get (const int left, const int right) const {
        return query(left, right, 0, 0, size_);
    }
};
