#include <bits/stdc++.h>

using namespace std;


int dfs(vector <int> * p,int a,int score){
    if(a>=p->size()){
        return score;

    }
    int b = a+1;
    int mx = score;
    for(b ;b < p->size();b++){
        if(abs((*p)[b] - (*p)[a])<2){
            mx = max(mx,dfs(p,b,score+1));
        }
    }
    return mx;
}

int solve(vector <int> V){
    int mix = 0;
    for(int i = 0;i < V.size();i++){
        mix = max(mix,dfs(&V,i,0));
        //cout<<mix<<endl;
    }
    return mix+1;

    return 0;
}


int main(){
    vector <int> A({1,2,3,99,99,99,99,99,0,0,0,10,0,0,0});
    //vector <int> A({4, 2, 3, 4, 4, 9, 98, 98, 3, 3, 3, 4, 2, 98, 1, 98, 98, 1, 1, 4, 98, 2, 98, 3, 9, 9, 3, 1, 4, 1, 98, 9, 9, 2, 9, 4, 2, 2, 9, 98, 4, 98, 1, 3, 4, 9, 1, 98, 98, 4, 2, 3, 98, 98, 1, 99, 9, 98, 98, 3, 98, 98, 4, 98, 2, 98, 4, 2, 1, 1, 9, 2, 4});
    //vector <int> A({7, 12, 13, 19, 17, 7, 3, 18, 9, 18, 13, 12, 3, 13, 7, 9, 18, 9, 18, 9, 13, 18, 13, 13, 18, 18, 17, 17, 13, 3, 12, 13, 19, 17, 19, 12, 18, 13, 7, 3, 3, 12, 7, 13, 7, 3, 17, 9, 13, 13, 13, 12, 18, 18, 9, 7, 19, 17, 13, 18, 19, 9, 18, 18, 18, 19, 17, 7, 12, 3, 13, 19, 12, 3, 9, 17, 13, 19, 12, 18, 13, 18, 18, 18, 17, 13, 3, 18, 19, 7, 12, 9, 18, 3, 13, 13, 9, 7});
    int res= 0;
    res = solve(A);
    cout <<endl;
    cout << res <<endl;

    return 0;
}




