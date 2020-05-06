#include <iostream>
#include "engine.h"

int main() {
    struct matrix origin;

    int inputDIM;
    int numOfVectors;
    string path1;        // Example: C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
    string path2;        // Example: C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt

    cout << "Welcome to program which find an Orthogonal base of given vectors from C^n." << endl;
    cout << "Please, enter your vectors with n složky (max n samples). Otherwise this program will work badly." << endl;
    cout << "Input dimension of space:" << endl;
    cin >> inputDIM;
//    cout << "Input the matrix of your dot product:" << endl;
    //   cin >> path1;
    cout << "Input path to read vectors." << endl;
    cin >> path2;
    cout << "Input number of your vectors vectors." << endl;
    cin >> numOfVectors;
    cout << "Your vectors:" << endl;
/*
    // test

    struct vector test = readVector(inputDIM * numOfVectors, path2);
    for (int i = 0; i <= inputDIM * numOfVectors; i++) {
        cout << test.array[i] << endl;
    }
}*/
    /*  int start = 0;
      int end = inputDIM;

      for (int i = 0; i <= inputDIM - 1; i++){
         struct vector oneVector = separateVector(readVector(inputDIM * numOfVectors, path2), start, end);
         start = start + inputDIM;
         end = end + inputDIM;
         cout << "Vector" << i + 1 << ": ";
              for (int z = 0; z < inputDIM; z++)
                 cout << oneVector.array[z];
         cout << endl;
          }
      }*/
    int oneVector = separateVector(readVector(inputDIM * numOfVectors, path2), 3, 6);
    for (int i = 0; i <= inputDIM - 1; i++)
        cout << oneVector.array[i];
}