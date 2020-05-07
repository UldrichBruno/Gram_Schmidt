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
double Gram_Schmidt(struct vectors Vector, struct matrix Matrix, double dotProduct, int orthoVectorComponent, int DIM, int whichOneGet, double sum);
int vectorComponent(struct vectors z, int which);
