#include <iostream>
#include "engine.h"

int main() {
    int numOfVectors;
    int inputDIM;
    string path1 = "C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt";        // Example: C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
    string path2 = "C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt";        // Example: C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt

    cout << "Welcome to program which find an Orthogonal base of given vectors from C^n." << endl;
    cout << "Please, enter your vectors with n složky (max n samples). Otherwise this program will work badly." << endl;
    cout << "Input dimension of space:" << endl;
    cin >> inputDIM;
//    cout << "Input the matrix of your dot product:" << endl;
    //   cin >> path1;
    //  cout << "Input path to read vectors." << endl;
    //  cin >> path2;
    cout << "Input number of your vectors vectors." << endl;
    cin >> numOfVectors;

    struct vectors givenVectors = readVector(inputDIM * numOfVectors,path2);

    cout << "Your vectors:" << endl;
    int counter = 0;
    for (int i = 0; i < inputDIM; i++) {
        cout << "Vector" << i + 1 << ": ";
        for (int j = counter; j < inputDIM + counter; j++) {
            cout << vectorComponent(givenVectors, j);
        }
        cout << endl;
        counter = counter + inputDIM;
    }
    cout << "" << endl;
    cout << "Your matrix: " << endl;

    struct matrix givenMatrix = readMatrix(inputDIM, path1);
    printMatrix(givenMatrix);

    for (int i = 2; i < inputDIM * numOfVectors; i++) {
        struct vectors Final = Gram_Schmidt(initializeOrthoVector(givenVectors, numOfVectors), givenMatrix, numOfVectors, i);
    }
    for (int i = 0; i < numOfVectors * inputDIM; i++){
        printVector(Final.array[i]);
    }
   /* cout << "All vectors:";
    int counter2 = 0;
    for (int i = 0; i < inputDIM * numOfVectors * 2; i++) {
        cout << "Vector" << i + 1 << ": ";
        for (int j = counter2; j < inputDIM + counter2; j++) {
            cout << vectorComponent(readVector(inputDIM * numOfVectors * 2, path2), j);
        }
        cout << endl;
        counter2 = counter2 + inputDIM;
    }
    cout << "" << endl;*/
}