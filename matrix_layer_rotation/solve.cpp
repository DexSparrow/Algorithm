#include <bits/stdc++.h>

using namespace std;



// we have two options for serializing
/*
    Option 1:
    We will use pointer and for each layer we build one vector that group the concerned element (rectangular)
    Option 2:
    We use vector traveling like ({0,0}, {0,1} , {0,9}) => (a, b, c)
    the a is starting point and c is the destination , to readch c we will increment a with b (I think it's about translating as I remember from the lesson in the high school xD)
*/


void shift(vector <int*> & v,int s,int dir = 1){ // I used this function that I take from the shiftVector.cpp I coded xD. By the way I coded the shift first because I thiought about serizlizing that is my main approach
    int len = v.size();
    s = s%len;
    int sens = (s>int(len/2)? -1 : 1); // invert the direction or not
    if(sens<0){
        s = len-s;
    }
    dir *= sens;
    vector <int> brouillon(s); // for storing variable that will be used for allocating and so we can move with iteration
    if(dir<0){
        for(int i = 0;i < s;i++){
            brouillon[i]=*(v[i]);
        }
        for(int i = 0; i < len-s;i++){
            *(v[i]) = *(v[s+i]);
        }
        for(int i = 0;i < s;i++){
            *(v[len-s+i])=brouillon[i];
        }
    }
    else{
        for(int i = 0;i < s;i++){
            brouillon[i]=*(v[(len-s)+i]);
        }
        for(int i = 0;i < len-s;i++){
            *(v[len-1-i])=*(v[len-1-s-i]);
        }
        for(int i = 0; i < s;i++){
            *(v[i]) = brouillon[i];
        }
    }

}


void matrixRotation(vector<vector<int>>& matrix, int rotate) {
    int width,height;
    // {Subject}: min of width and height will be even
    height = matrix.size();
    width = matrix[0].size();
    int ww = width;// save for width
    int hh = height;// save for height
    int minSide = min(height, width);
    int maxSide = height+width - minSide;
    int layer = minSide/2;
    for(int l =0; l < layer;l++){ // layer traversal
        vector <int*> serialize;
        minSide -= 2*l;
        maxSide -= 2*l;
        int perimeter = (minSide + maxSide)*2 - 4;
        int order[2] = {width,height};
        int o = 0;
        int r = rotate%(perimeter);
        for(int x = 0; x < width-1 ; x++){
            serialize.push_back(&(matrix[l][x+l]));
        }
        for(int y = 0; y < height-1 ; y++){
            serialize.push_back(&(matrix[l+y][ww-1-l]));
        }
        for(int x = 0; x < width-1 ; x++){
            serialize.push_back(&(matrix[hh-1-l][ww-1-l-x]));
        }
        for(int y = 0; y < height-1 ; y++){
            serialize.push_back(&(matrix[hh-1-l-y][l]));
        }
        width -= 2;
        height -= 2;
        shift(serialize, rotate, -1);
    }

}


// Just a brouillon to visualize the problem since I code in nano and not using GUI desktop environnement :)
// CLI >> all (but not for web tho)
/*
    1 2 3 4 5
    1 2 3 4 5

     2 3 4 5
     1 2 3 4
     1 2 3 4
     1 2 3 4
     1 2 3 4

*/


void desc(vector <vector <int>> & V){ // displaying the matrix i used alphabetical translation for displaying cause number with more than 1 digit will make the visualizing dirty :(
    for(auto&x: V){
        for(auto&i: x)cout << char(i+97-1) << " ";
        cout<<endl;
    }
}

int main(){
    vector <vector <int>> V({
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20}
/*
    {9718805, 60013003, 5103628, 85388216, 21884498, 38021292, 73470430, 31785927},
{69999937, 71783860, 10329789, 96382322, 71055337, 30247265, 96087879, 93754371},
{79943507, 75398396, 38446081, 34699742, 1408833, 51189, 17741775, 53195748},
{79354991, 26629304, 86523163, 67042516, 54688734, 54630910, 6967117, 90198864},
{84146680, 27762534, 6331115, 5932542, 29446517, 15654690, 92837327, 91644840},
{58623600, 69622764, 2218936, 58592832, 49558405, 17112485, 38615864, 32720798},
{49469904, 5270000, 32589026, 56425665, 23544383, 90502426, 63729346, 35319547},
{20888810, 97945481, 85669747, 88915819, 96642353, 42430633, 47265349, 89653362},
{55349226, 10844931, 25289229, 90786953, 22590518, 54702481, 71197978, 50410021},
{9392211, 31297360, 27353496, 56239301, 7071172, 61983443, 86544343, 43779176},
*/
    });
    int rotate = 3;//40
    desc(V);cout<<"----X----"<<endl;
    matrixRotation(V, rotate);
    desc(V);cout<<"----X----"<<endl;
    return 0;
}



