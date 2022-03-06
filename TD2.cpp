#include <iostream>

using namespace std;

//class declaration
class vector {
private:
    float *elements;
    int dim;

public:

    vector()  {
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

    const float &get(int i) const {
        return elements[i];
    }

    void set(int i, const float &j) {
        elements[i] = j;
    }

    int size() const {
        return dim;
    }

    float &operator[](int i) {
        return elements[i];
    }

    const float &operator[](int i) const {
        return elements[i];
    }

    void operator=(const vector &vect) {//tiet kiem bo nho khi dung reference,nhanh hon
        delete[] elements;//chi delete dc pointer vi new tra ve pointer
        dim = vect.dim;
        elements = new float[dim];
        for (int i = 0; i < dim; i++) {
            elements[i] = vect.elements[i];
        }
    }

    void operator+=(const vector& vect2) {
        if (dim != vect2.dim) {
            cout << "sai dim roi dit con me may" << endl;
        } else {
            for (int i = 0; i < dim; i++) {
                elements[i] += vect2.elements[i];
            }
        }
    }

//    vector operator+(const vector& v2) const{
//        vector v3(*this);//pointer chi vao instant nay
//        v3.operator+=(v2);
//        return v3;
//    }

    ~vector() {
//        cout << elements << endl;
//        cout << "dit com me may" << endl;
        delete[] elements;

    }
};
    vector operator+(const vector& v1, const vector& v2){
        vector v3(v1);
        v3.operator+=(v2);
        return v3;
    }
int main() {
    vector v3(10, 1.2);
    const vector v4(v3);
    v3.set(4, 3.5);
//    v3.get(9) = 18;
//    for (int i = 0; i < v3.size(); i++) {
//        cout << v3.get(i) << endl;
//    }
//    cout << "iu nghia" << endl;
//    for (int i = 0; i < v4.size(); i++) {
//        cout << v4.get(i) << endl;
//    }

//    TD2
//operator[]
//    cout<<v3[5]<<endl;
//    v3[5] = 4;
//    cout << v4[8]<<endl;
//    cout<<v3.operator[](7)<<endl;
//
//operator=
//    v3 = v4;
//    for (int j = 0; j < v3.size(); j++) {
//        cout << v3[j] << endl;
//    }
//    return 0;

//operator+=
    vector v5(10,1.6);
    v3+=v5;
    for (int j = 0; j < v3.size(); j++) {
        cout << v3[j] << endl;
    }
cout<<"cach dong"<<endl;

//operator+
    v3 = v4 + v5;
    for (int j = 0; j < v3.size(); j++) {
        cout << v3[j] << endl;
    }

    return 0;
}
