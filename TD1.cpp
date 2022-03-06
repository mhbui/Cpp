#include <iostream>

using namespace std;

//class declaration
class vector {
private:
    float *elements;
    int dim;

public:

    vector() {
        elements = nullptr;
        dim = 0;
    }

    vector(int dim) {
        this->dim = dim;
        elements = new float[dim];
    }

    vector(int dim, float a) {
        this->dim = dim;
        elements = new float[dim];
        for (int i = 0; i < dim; i++) {
            elements[i] = a;
        }
    }

    vector(const vector &vect) {
        dim = vect.dim;
        elements = new float[dim];
        for (int i = 0; i < dim; i++) {
            elements[i] = vect.elements[i];
        }
    }

    const float& get(int i) const {
        return elements[i];
    }

    void set(int i, const float &j) {
        elements[i] = j;
    }

    int size() const{
        return dim;
    }

    ~vector() {
        cout << elements << endl;
        cout << "dit com me may" << endl;
        delete[] elements;

    }
};

int main() {
    vector v3(10, 1.2);
    const vector v4(v3);
    v3.set(4, 3.5);
//    v3.get(9) = 18;
    for (int i = 0; i < v3.size(); i++) {
        cout << v3.get(i) << endl;
    }
    cout << "iu nghia" << endl;
    for (int i = 0; i < v4.size(); i++) {
        cout << v4.get(i) << endl;
    }
    return 0;
}
