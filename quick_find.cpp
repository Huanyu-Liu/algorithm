#include <iostream>
#include <vector>
using namespace std;

class QuickFindUF{
    vector<int> id;
public:
    QuickFindUF(int N){
        
        for (int i = 0; i < N; i++){
            id.push_back(i);
        }
    }
    bool connected(int p, int q){
        return id[p] == id[q];
    }
    void unions(int p, int q){
        int pid = id[p];
        int qid = id[q];
        if (pid != qid){
            for (auto i = id.begin(); i != id.end(); i++){
                if (*i == pid){
                    *i = qid;
                }
            }
        }
    }
};

int main(){
    QuickFindUF uf(10);
    cout << uf.connected(5,6) << endl;
    cout << uf.connected(8,0) << endl;
    uf.unions(5,6);
    cout << uf.connected(5,6) << endl;
    uf.unions(5,8);
    cout << uf.connected(8,6) << endl;
    uf.unions(6,0);
    cout << uf.connected(8,0) << endl;
    return 0;
}