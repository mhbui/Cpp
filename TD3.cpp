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

    vector(const vector& vect) {//copy vector nay vao vector khac qua reference -> dung & de tiet kiem bo nho, khong muon co copy xay ra; ko co & thi dung copy trc khi co copy xay ra
        dim = vect.dim;
        elements = new float[dim];
        for (int i = 0; i < dim; i++) {
            elements[i] = vect.elements[i];
        }
    }

    const float &get(int i) const {// dung & tranh 1 lan copy return
        return elements[i];
    }

    void set(int i, const float& j) { //chon dung & vi tranh 1 lan copy
        elements[i] = j;
    }

    int size() const {
        return dim;
    }

    float& operator[](int i) { // co the doi cai gia tri cua elements[i], neu dung float operator[] thi chi doi gia tri cua ban copy => khong doi duoc vi khong dung o ben trai cua dau bang.
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

    void operator+=(const vector& vect2) { // khong co &
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

class vector_intel : public vector{
private:

public:
    vector_intel() : vector(){}
    vector_intel(int dim) : vector(dim){}
    vector_intel(int dim, float a) : vector(dim,a){}
    vector_intel(const vector_intel& vect) : vector(vect){}

    vector_intel& operator+=(const vector_intel& vect2){
        if (size()<vect2.size()){
            vector_intel vect3(vect2);
            for(int i=0;i<size();i++){
                cout <<"this: "<< (*this)[i] <<endl;
                vect3[i]+=(*this)[i];
            }
            (*this)=vect3;
        }
        else{
            vector_intel vect4(*this);
            for (int j=0;j<vect2.size();j++){
                vect4[j]+=vect2[j];
            }
            (*this) = vect4;
        }
        return (*this);
}

};
int main() {
    //TD3
    vector_intel vect1(12,1.2);
    vector_intel vect2(10,2.4);
    vect1+=vect2;
    for(int i=0; i<vect1.size();i++){
        cout << vect1[i]<<endl;
    }

    cout<<"iu thu"<<endl;


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

