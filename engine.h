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
double dotProduct(int vectorComponent, struct matrix Matrix, struct vectors orthoVectors, int where);
struct vectors orthoVectors(int orthoVectorComponent, int DIM, int which);
double Gram_Schmidt(double dotProduct, int vectorComponent, int orthoVectorComponent);
int vectorComponent(struct vectors z, int which);