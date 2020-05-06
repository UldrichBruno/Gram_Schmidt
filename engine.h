using namespace std;

#define MAX_SIZE_OF_MATRIX 50

struct vector{
    double array[MAX_SIZE_OF_MATRIX];
    int size;
};

void printMatrix(struct matrix a);
void printVector(struct vector z);
int separateVector(struct vector z, int start, int DIM);
struct matrix readMatrix(int inputDIM, string path);       // Load matrix from a file.
struct vector readVector(int inputDIM, string path);       // Load vector from a file.