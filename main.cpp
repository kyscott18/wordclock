#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void shift(vector<vector<bool> > &mat) {
    for (int i = 0; i < 10; ++i) {
        mat[i] = mat[i+1];
    }
}

void print(const vector<vector<bool> > mat) {
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            cout << mat.at(j).at(i) << " ";
        }
        cout << endl;
    }
}

int main(int argc, char * argv[]) {
    int hz = 5;
    char word[] = "ff ff";
    
    unordered_map<char, vector<vector<bool> > > l;
    l.reserve(26);
    l['F'] = {{1,1,1,1,1}, {1,0,1,0,0}, {1,0,1,0,0}};
    l[' '] = {{0,0,0,0,0}};
    
    
    vector<vector<bool> > mat;
    mat.resize(11);
    for (int i = 0; i < 11; ++i) {
        mat.at(i).resize(11);
    }
    
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] > 90) word[i] -= 32;
    }
    
    //loop section
    for (int i = 0; word[i] != '\0'; ++i) {
        vector<vector<bool> > spot = l.at(word[i]);
        for (int j = 0; j <= spot.size(); ++j) {
            shift(mat);
            if (j != spot.size()) {
                for (int k = 0; k < 5; ++k) {
                    mat[10][k+3] = spot[j][k];
                }
            } else {
                for (int k = 0; k < 5; ++k) {
                    mat[10][k+3] = 0;
                }
            }
            print(mat);
            cout << endl << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(1000*(1/hz)));
    }
}
