using namespace std;

#define MAX_SIZE_OF_MATRIX 50

struct vectors{
    double array[MAX_SIZE_OF_MATRIX];
    int size;
};

struct matrix{
    double array[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    int size;
};

struct matrix readMatrix(int inputDIM, string path);       // Load matrix from a file.
struct vectors readVector(int inputDIM, string path);       // Load vector from a file.
void printMatrix(struct matrix a);
void printVector(struct vectorss z);
double dotProduct(struct vectors Vector, struct matrix Matrix, int whichOneLeft, int whichOneRight);
void Gram_Schmidt(struct vectors Vector, struct matrix Matrix, int numOfVectors, int whichOneGet);
int vectorComponent(struct vectors z, int which);
double sum(struct vectors Vector, struct matrix Matrix, int whichOneGet, int numOfVectors);
