#include <iostream>
#include <vector>
using namespace std;

class QuickUnion{
    vector<int> id;
public:
    QuickUnion(int N){
        for (int i = 0; i < N; i++){
            id.push_back(i);
        }
    }
    int root(int q){
        while (id[q] != q){
            q = id[q];
        }
        return q;
    }
    bool connected(int p, int q){
        return root(p) == root(q);
    }
    void unions(int p, int q){
        int root_p = root(p);
        int root_q = root(q);
        if (root_q != root_p){
            id[root_p] = root_q;
        }
    }
};

int main(){
    QuickUnion uf(10);
    cout << uf.connected(5,6) << endl;
    cout << uf.connected(5,8) << endl;
    uf.unions(5,6);
    cout << uf.connected(5,6) << endl;
    uf.unions(5,8);
    cout << uf.connected(8,6) << endl;
    uf.unions(6,0);
    cout << uf.connected(5,0) << endl;
    cout << uf.connected(8,0) << endl;
    return 0;
}