#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

class base36{
    private: vector<int> _rep;
    public:
    base36(){}
    base36(ull n){
        while(n>35){
            _rep.push_back(n%36);
            n/=36;
        }
        _rep.push_back(n%36);
    }

    base36(vector <int> & s){
        for(auto&x:s){
            _rep.push_back(x);
        }
    }
    void desc(){
        string res;
        const int S =_rep.size();
        for(int i = 0;i < S;i++){
            res= char((_rep[i]<=9?'0':('A'-10))+_rep[i])+ res;
        }
        cout << res <<endl;
    }
    void desc_(){
        string res;
        for(auto&x:_rep)res=to_string(x)+res;
        cout << res<<endl;
    }
    
    base36 operator +(base36 s){
        vector <int> * a, *b;
        a = &(_rep);
        b = &(s._rep);
        if(_rep.size() < s._rep.size()){
            a = &(s._rep);
            b = &(_rep);
        }
        vector <int> res;
        int r = 0;
        int calc;
        int Asize,Bsize;
        Asize = a->size();
        Bsize = b->size();
        for(int i = 0; i < Asize; i++){
            calc = (*a)[i]+r;
            if(i<Bsize)calc+=(*b)[i];
            r = calc/36;
            res.push_back(calc-36*r);
        }
        if(r){
            while(r>35){
                res.push_back(r%36);
                r/=36;
            }
            res.push_back(r);
        }
        return base36(res);
    }
    
};

int L;
base36 TAB[1000000];

void initTab(){
    TAB[0]=base36(0);
    TAB[1]=base36(1);
    L = 2;
}

base36 fibo(int x){
    if(x<L)return TAB[x];
    base36 c = fibo(x-1)+fibo(x-2);
    TAB[L++]=c;
    return c;
}


int main(){
    initTab();
    /*
    base36 A(150);
    base36 B(13);
    base36 C = A+B;
    C.desc();
    return 1;
    */
    int N = 6;
    int n = pow(N,N);
    //7**7 823543;
    //10**10 100000;
    cout << n <<endl;
    //for(int i =0;i < n;i++){
        //cout << fibo(i) << " ";
    //    fibo(i).desc();
    //}
    fibo(n).desc();
    return 1;
}
