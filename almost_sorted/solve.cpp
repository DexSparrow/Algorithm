#include <bits/stdc++.h>

using namespace std;

int isVectEqual(vector <int> & a, vector <int> &b){
    for(int i = 0; i < a.size(); i++){
        if(a[i]-b[i])return 0;
    }
    return 1;
}


void almostSorted(vector<int> arr) {
    vector <int> temp(arr);
    sort(begin(temp), end(temp));
    int test = isVectEqual(arr, temp);
    if(test){
        cout<<"yes";
    }
    else{
        int diff = 0;
        vector <int> check;
        int i;
        for(i =0;i < arr.size();i++){
            if(arr[i]-temp[i]){
                diff++;
                if(!check.size()){
                    check.push_back(i);                    
                }
                else if(check.size()==1){
                    check.push_back(i);
                }
                else if(check.size()==2){
                    check[1] = i;
                }
            }
        }
        if(check.size()==1)check.push_back(i-1);
        int swappable,reversible;
        swappable = (diff==2);
        vector <int> A,B;
        A = vector <int>(begin(arr)+check[0],begin(arr)+check[1]+1);
        B = vector <int>(begin(temp)+check[0],begin(temp)+check[1]+1);
        reverse(begin(A), end(A));
        reversible = isVectEqual(A, B);
        if(swappable){
            cout << "yes"<<endl<<"swap "<<check[0]+1<<" "<<check[1]+1;
            cout << "yes"<<endl<<"swap "<<check[0]+1<<" "<<check[1]+1;
        }
        else if (reversible){
            cout << "yes"<<endl<<"reverse "<<check[0]+1<<" "<<check[1]+1;
        }
        else{
            cout << "no";
        }
        
    }
    
}

int main(){
    vector <int> A({4104, 8529, 49984, 54956, 63034, 82534, 84473, 86411, 92941, 95929, 108831, 894947, 125082, 137123, 137276, 142534, 149840, 154703, 174744, 180537, 207563, 221088, 223069, 231982, 249517, 252211, 255192, 260283, 261543, 262406, 270616, 274600, 274709, 283838, 289532, 295589, 310856, 314991, 322201, 339198, 343271, 383392, 385869, 389367, 403468, 441925, 444543, 454300, 455366, 469896, 478627, 479055, 484516, 499114, 512738, 543943, 552836, 560153, 578730, 579688, 591631, 594436, 606033, 613146, 621500, 627475, 631582, 643754, 658309, 666435, 667186, 671190, 674741, 685292, 702340, 705383, 722375, 722776, 726812, 748441, 790023, 795574, 797416, 813164, 813248, 827778, 839998, 843708, 851728, 857147, 860454, 861956, 864994, 868755, 116375, 911042, 912634, 914500, 920825, 979477});
    almostSorted(A);

}


