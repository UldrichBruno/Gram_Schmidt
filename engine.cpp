#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "engine.h"
#include <cmath>

struct vectors readVector(int size, string path) {
    struct vectors v;
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

void printVector(struct vectors z) {
    for (int i = 0; i < z.size; i++) {
        cout << setw(7) << setprecision(3) << z.array[i]<< " ";
    }
    cout << endl;
    cout <<"--------------------------------------------------"<< endl;
}

struct matrix readMatrix(int size, string path1) {
    struct matrix a;
    a.size = size;
    int x;
    ifstream inFile;
    inFile.open(path1);
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

void printMatrix(struct matrix a) {
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            cout << setw(7) << setprecision(3) << a.array[i][j] << " ";
        }
        cout << endl;
    }
    cout <<"--------------------------------------------------"<< endl;
}

int vectorComponent(struct vectors z, int which) {
    int component = z.array[which];
    return component;
}

struct vectors orthoVectors(int orthoVectorComponent, int DIM, int which){
    struct vectors v;
    v.size = DIM;
    v.array[which] = orthoVectorComponent;

}

double dotProduct(int vectorComponent, struct matrix Matrix, struct vectors orthoVectors, int where){
    double product = 0;
    for (int i = 0; i < Matrix.size; i++){
        double b = 0;
        for (int j = 0; j < Matrix.size; j++) {
            double a = Matrix.array[i][j] * orthoVectors.array[where];
            where++;
            b = a + b;
        }
        double c = vectorComponent * b;
        product = product + c;
    }
    return product;
}

double Gram_schmidt(double dotProduct, int vectorComponent, struct vectors orthoVectors){

}
