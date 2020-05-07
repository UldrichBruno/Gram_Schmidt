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

int vectorComponent(struct vectors Vector, int which) {
    int component = Vector.array[which];
    return component;
}


double dotProduct(struct vectors Vector, struct matrix Matrix, int whichOneLeft, int whichOneRight){
    double product = 0;
    for (int i = 0; i < Matrix.size; i++){
        double partialSum = 0;
        for (int j = 0; j < Matrix.size; j++) {
            double matrixPointVectorRight = Matrix.array[i][j] * Vector.array[whichOneRight * Matrix.size + j];
            partialSum = matrixPointVectorRight + partialSum;
        }
        double c = Vector.array[whichOneLeft * Matrix.size +i] * partialSum;
        product = product + c;
    }
    return product;
}

double sum(struct vectors Vector, struct matrix Matrix, int whichOneGet, int numOfVectors){
    double dotProd = 0;
    double norm = 0;
    double partial = 0;
    int n = 0;
    for (int i = 0; i < whichOneGet -1; i++){
        int c = Vector.array[whichOneGet * Vector.size - Vector.size + i];
        int d = Vector.array[Vector.size * numOfVectors + whichOneGet * Vector.size - Vector.size + i];
       struct vectors v =  Vector;
        struct matrix  m = Matrix  ;
       dotProd = dotProduct(Vector, Matrix, c, d);
       norm = dotProduct(Vector, Matrix, Vector.array[Vector.size * numOfVectors + whichOneGet * Vector.size - Vector.size + i], Vector.array[Vector.size * numOfVectors + whichOneGet * Vector.size - Vector.size + i]);
       double e = (dotProd * (Vector.array[Vector.size * numOfVectors + whichOneGet * Vector.size - Vector.size + i]))/(norm * norm);
       partial = partial + e;
    }
    return partial;
}

void Gram_Schmidt(struct vectors Vector, struct matrix Matrix, int numOfVectors, int whichOneGet){
    for (int j = 0; j < Vector.size; j++) {
        Vector.array[numOfVectors * Vector.size + (whichOneGet * Vector.size - Vector.size + j)] = Vector.array[whichOneGet * Vector.size - Vector.size + j] - sum(Vector, Matrix, whichOneGet, numOfVectors);
        cout << Vector.array[numOfVectors * Vector.size + (whichOneGet * Vector.size - Vector.size + j)];
    }
}


