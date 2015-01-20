class UnionFindSet {
private:
    int *id;
    int *sz; //代表集合大小，用于启发式合并
    int *mc; //集合的最大元素
public:
    UnionFindSet(int n) {
        id = new int[n];
        sz = new int[n];
        mc = new int[n];
        for (int i = 0; i < n; i++) {
            id[i] = mc[i] = i;
            sz[i] = 1;
        }
    }
    ~UnionFindSet() {
        delete []id;
        delete []sz;
        delete []mc;
    }
    int find(int p) {
        if (id[p] == p) return p;
        return id[p] = find(id[p]);
    }
    // 将p和q合并
    void unionComp(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
            mc[j] = max(mc[i], mc[j]);
        } else {
            id[j] = i;
            sz[i] += sz[j];
            mc[i] = max(mc[i], mc[j]);
        }
    }
    // 返回p所属集合里面的最大元素
    int getMaxInComp(int p) {
        return mc[find(p)];
    }
};
class Successor {
private:
    bool *deleted;
    int n;
    UnionFindSet uf;
public:
    Successor(int n) : uf(n) {
        deleted = new bool[n];
        this->n = n;
        memset(deleted, false, sizeof(bool) * n);
    }
    ~Successor() {
        delete []deleted;
    }
    void remove(int id) {
        deleted[id] = true;
        if (id - 1 >= 0 && deleted[id - 1]) uf.unionComp(id - 1, id);
        if (id + 1 < n && deleted[id + 1]) uf.unionComp(id + 1, id);
    }
    int query(int id) {
        if (!deleted[id]) return id;
        int mc = uf.getMaxInComp(id) + 1;
        return mc < n ? mc : -1;
    }
};

Successor *algo;
void init(int N) {algo=new Successor(N);}
void removeNum(int num) {algo->remove(num);}
int query(int x) {return algo->query(x);}
