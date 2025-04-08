#include <bits/stdc++.h>
using namespace std;

void shift(vector <int> & v,int s,int dir = 1){
    int len = v.size();
    s = s%len;
    int sens = (s>int(len/2)? -1 : 1); // invert or not
    if(sens<0){
        s = len-1-s;
    }
    dir *= sens;
    vector <int> brouillon(s);
    if(dir<0){
        for(int i = 0;i < s;i++){
            brouillon[i]=v[i];
        }
        for(int i = 0; i < len-s;i++){
            v[i] = v[s+i];
        }
        for(int i = 0;i < s;i++){
            v[len-s+i]=brouillon[i];
        }
    }
    else{
        for(int i = 0;i < s;i++){
            brouillon[i]=v[(len-s)+i];
        }
        for(int i = 0;i < len-s;i++){
            v[len-1-i]=v[len-1-s-i];
        }
        for(int i = 0; i < s;i++){
            v[i] = brouillon[i];
        }
    }
//    cout << dir << " : ";
}


int main(){
    vector <int> v = {1,2,3,4,5,6,7,8,9};
    for(int i = 0;i < 1000;i++)v.push_back(i+10);
    vector <int> save(v);
    vector <int> n = {8,9,1,2,3,4,5,6,7};
//  for(auto&x:v)cout<<x <<" ";cout<<endl;
    for(int s = 0; s < v.size();s++){
        shift(v, s);
        for(auto&x:v)cout<<x <<" ";cout<<endl;
        v = save;
    }
    //int s = 6;
    

    return 0;
}



