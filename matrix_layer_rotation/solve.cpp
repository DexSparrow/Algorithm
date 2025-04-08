#include <bits/stdc++.h>

using namespace std;


void matrixRotation(vector<vector<int>> matrix, int rotate) {
    int width,height;
    // min of width and height will be even
    height = matrix.size();
    width = matrix[0].size();
    cout << height << " " << width;
    int minSide = min(height, width);
    int maxSide = height+width - minSide;
    int layer = minSide/2;
    for(int l =0; l < layer;l++){
        minSide -= 2*l;
        maxSide -= 2*l;
        int perimeter = (minSide + maxSide)*2 - 4;
        int order[2] = {width,height};
        int o = 0;
        int r = rotate%(perimeter);
        vector <int* > serialize;
        serialize.push_back(&matrix[1][0]);
        vector< vector<int>>::iterator matri = begin(matrix);
        cout <<"pointer = "<<matri[1][0]<<endl;
        cout << *(serialize[0]+1)<<endl;
        for(int index = 0; index < perimeter; index++){
            if(index && index%order[o]){
                o = (o==1?0:1);
            }
        }
        for(int side = 0; side < 4; side++){
            if(side%2){
                
            }
            else{

            }
        }
    }

}

/*
    1 2 3 4 5
    1 2 3 4 5

     2 3 4 5
     1 2 3 4
     1 2 3 4
     1 2 3 4
     1 2 3 4

*/


int main(){
    vector <vector <int>> V({
        {1,2,3},
        {4,5,6},
    });
    int rotate = 1;
    matrixRotation(V, rotate);

    return 0;
}



