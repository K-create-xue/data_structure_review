
class UnionFindSet {
public:
    UnionFindSet(int n) {
        _ufs.resize(n, -1);
    }

    int findIndex(int x) {
        assert(x < _ufs.size());

        while (_ufs[x] >= 0)
            x = _ufs[x];
        return x;
    }
    //	//x1 和 x2 合并
    void unionNum(int x1, int x2) {
        assert(x1 < _ufs.size());
        assert(x2 < _ufs.size());
        int root1 = findIndex(x1);
        int root2 = findIndex(x2);
        if (root1 != root2) {
            _ufs[root1] += _ufs[root2];
            _ufs[root2] = root1;
        }
    }
    int setSize() {
        int size = 0;
        for (int i = 0; i < _ufs.size(); ++i) {
            if (_ufs[i] < 0)
                ++size;
        }
        return size;
    }
private:
    vector<int> _ufs;
};
