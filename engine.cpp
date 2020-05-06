#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "engine.h"
#include <cmath>

void printMatrix(struct matrix a) {
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            cout << setw(7) << setprecision(3) << a.array[i][j] << " ";
        }
        cout << endl;
    }
    cout <<"--------------------------------------------------"<< endl;
}

struct matrix readMatrix(int size, string path) {
    struct matrix a;
    a.size = size;
    int x;
    ifstream inFile;
    inFile.open(path);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >> x) {
        for (int i = 0; i < a.size; i++) {
            for (int j = 0; j < a.size; j++) {
                a.array[i][j] = x;
                inFile >> x;
            }
        }
    }
    inFile.close();
    return a;
}

void printVector(struct vector z) {
    for (int i = 0; i < z.size; i++) {
        cout << setw(7) << setprecision(3) << z.array[i]<< " ";
    }
    cout << endl;
    cout <<"--------------------------------------------------"<< endl;
}

struct vector readVector(int size, string path) {
    struct vector v;
    v.size = size;
    int x;
    ifstream inFile;
    inFile.open(path);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >> x) {
        for (int i = 0; i < v.size; i++) {
            v.array[i] = x;
            inFile >> x;
        }
    }
    inFile.close();
    return v;
}

int separateVector(struct vector z, int start, int end){
    int oneVector [start - end];
    for (int i = start; i < end; i++){
        oneVector[i] = z.array[i];
    }
    return oneVector;
}

int *getArray() {
    int b[] = {
            4, 1, 2, 3
    };
    return b;
}