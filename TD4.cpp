#include <iostream>
#include <utility>

using namespace std;

//class declaration
template <typename T>
class vector {
private:
    T *elements;
    int dim;

public:

    vector()  {
        elements = nullptr;
        dim = 0;
    }

    vector(int dim) {
        this->dim = dim;
        elements = new T[dim];
    }

    vector(int dim, T a) {
        this->dim = dim;
        elements = new T[dim];
        for (int i = 0; i < dim; i++) {
            elements[i] = a;
        }
    }

    vector(const vector &vect) {
        dim = vect.dim;
        elements = new T[dim];
        for (int i = 0; i < dim; i++) {
            elements[i] = vect.elements[i];
        }
    }

    const T &get(int i) const {
        return elements[i];
    }

    void set(int i, const T &j) {
        elements[i] = j;
    }

    int size() const {
        return dim;
    }

    T &operator[](int i) {
        if (i<0 or (i>=size())){
            throw(i);
        }
        return elements[i];
    }

    const T &operator[](int i) const {
        return elements[i];
    }

    void operator=(const vector &vect) {//tiet kiem bo nho khi dung reference,nhanh hon
        delete[] elements;//chi delete dc pointer vi new tra ve pointer
        dim = vect.dim;
        elements = new T[dim];
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

    vector<T> friend operator*(const vector<T>& v1, float i);
};
template <typename T>
vector<decltype(std::declval<T>() * std::declval<float>())> operator*(const vector<T>& v1, float i){
    vector<decltype(std::declval<T>() * std::declval<float>())> v3(v1);
    for (int j = 0;j<v1.size();j++){
        v3.elements[j] *= i;
    }
    return v3;
}

template <typename T>
vector<T> operator+(const vector<T>& v1, const vector<T>& v2){
    vector<T> v3(v1);
    v3.operator+=(v2);
    return v3;
}

template <typename Y>
ostream& operator<<(ostream& os, const vector<Y>& obj){
    for (int j = 0; j < obj.size(); j++) {
        os << obj[j] << endl;
    }
    return os;
}

template <typename Y>
istream& operator >>(istream& is, vector<Y>& obj){
    for (int j = 0; j < obj.size(); j++) {
        is >> obj[j];
    }
    return is;
}

int main() {
    vector<char> v3(10, 'p');
    const vector<char> v4(v3);
    v3.set(4, 'l');
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
    vector<char> v5(10,'m');
    v3+=v5;
    cout<<v3;
    cout<<"cach dong"<<endl;
//    cin >> v3;
//    cout << v3;
//operator+

try {
    v3[30];
}

catch(int i){
    cout<<i<<endl;
}
    return 0;
}
