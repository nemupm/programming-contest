class BIT
{
public:
    vector<int> bit;
    int M;

    BIT(int M):
        bit(vector<int>(M+1, 0)), M(M) {}

    int sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, int x) {
        assert(i>0);
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};
