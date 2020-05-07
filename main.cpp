#include <iostream>
#include "engine.h"

int main() {

    int inputDIM;
    int numOfVectors;
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
    cin >> numOfVectors;;

    cout << "Your vectors:" << endl;
    int counter = 0;
    for (int i = 0; i < inputDIM; i++) {
        cout << "Vector" << i + 1 << ": ";
        for (int j = counter; j < inputDIM + counter; j++) {
            cout << vectorComponent(readVector(inputDIM * numOfVectors, path2), j);
        }
        cout << endl;
        counter = counter + inputDIM;
    }
}
