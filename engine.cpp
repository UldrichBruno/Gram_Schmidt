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


double dotProduct(struct vectors Vector, struct matrix Matrix, double whichOneLeft, double whichOneRight){
    double product = 0;
    for (int i = 0; i < Matrix.size; i++){
        double partialSum = 0;
        for (int j = 0; j < Matrix.size; j++) {
            double matrixPointVectorRight = Matrix.array[i][j] * (whichOneRight + j);
            partialSum = matrixPointVectorRight + partialSum;
        }
        double c = (whichOneLeft + i) * partialSum;
        product = product + c;
    }
    return product;
}

double sum(struct vectors Vector, struct matrix Matrix, int whichOneGet, int numOfVectors){
    double dotProd = 0;
    double norm = 0;
    double partial = 0;
    for (int i = 0; i < whichOneGet -1; i++){
        double left = Vector.array[whichOneGet - Vector.size + i];
        double right = Vector.array[whichOneGet - Vector.size / numOfVectors + i];
       dotProd = dotProduct(Vector, Matrix, left, right);
       norm = dotProduct(Vector, Matrix, right, right);
       double e = (dotProd * right)/(norm * norm);
       partial = partial + e;
    }
    return partial;
}

struct vectors Gram_Schmidt(struct vectors Vector, struct matrix Matrix, int numOfVectors, int whichOneGet){
    for (int i = 0; i < Vector.size; i++) {
        Vector.array[Vector.size + (whichOneGet * Vector.size / numOfVectors - Vector.size / numOfVectors + i)] = Vector.array[whichOneGet * Vector.size / numOfVectors - Vector.size + i] - sum(Vector, Matrix, Vector.size + (whichOneGet * Vector.size / numOfVectors - Vector.size / numOfVectors + i), numOfVectors);
        //cout << Vector.array[Vector.size + (whichOneGet * Vector.size / numOfVectors- Vector.size / numOfVectors + i)];
    }
    return Vector;
}

struct vectors initializeOrthoVector(struct vectors Vectors, int numOfVectors){
    for (int i = 0; i < Vectors.size / numOfVectors; i++) {
        Vectors.array[Vectors.size + i] = Vectors.array[i];
    }
    return Vectors;
}

struct vectors Result (struct vectors Vectors, struct matrix Matrix, int numOfVectors, int DIM){
    for (int i = 2; i < DIM * numOfVectors; i++) {
        Gram_Schmidt(initializeOrthoVector(Vectors, numOfVectors), Matrix, numOfVectors, i);
    }
    return Vectors;
}