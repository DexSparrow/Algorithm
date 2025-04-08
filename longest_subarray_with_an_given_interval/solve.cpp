#include <bits/stdc++.h>

using namespace std;


int pickingNumbers(vector <int> V){
    sort(begin(V), end(V));
    int mx = 0;
    for(int i = 0;i < V.size();i++){
        int l = i+1;
        int c =0;
        while(l<V.size()){
            if(V[i]==V[l])c++;
            l++;
            if(abs(V[i]-V[l])>1)break;
        }
        for(int x = i;x<l;x++)cout << V[x]<<" ";
        cout <<c<<endl;
        mx = max(mx,l-i);
        i += c;
    }
    return mx;

}

int main(){
    vector <int> V({4, 6, 5, 3, 3,2,2, 1});
    int res = pickingNumbers(V);
    cout<<"res = "<<res<<endl;
    return 0;
}


