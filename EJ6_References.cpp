#include <iostream>
#include <stdexcept> //this import exceptions!!

class Test{
public:
    Test(){
        x = 0;
        y = 0;
        z = 0;
    }
    Test(int i, int j, int k): x(i), y(j), z(k){}
    ~Test(){}
    int x;
    int y;
    int z;

    Test& operator=(Test other){
        if(this != &other){
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
    int& operator[](int index){
        switch(index){
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: throw std::out_of_range("Index out of range.");
        }
    }
private:
};

std::ostream& operator<<(std::ostream& os, const Test& obj)
{
    os << "(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
    return os;
}

class TestMat{
public:
    TestMat(){
        up = Test();
        forward = Test();
        right = Test();
    }
    TestMat(Test& new_up, Test& new_forward, Test& new_right){
        up = new_up;
        forward = new_forward;
        right = new_right;
    }
    ~TestMat(){}
    Test up;
    Test forward;
    Test right;
    
    Test getColX() const{
        return Test(right.x, forward.x, up.x);
    }
    Test getColY() const{
        return Test(right.y, forward.y, up.y);
    }
    Test getColZ() const{
        return Test(right.z, forward.z, up.z);
    }

    Test& operator[](int index){
        switch(index){
            case 0: return right;
            case 1: return forward;
            case 2: return up;
            default: throw std::out_of_range("Index out of range.");
        }
    }

private:
};

std::ostream& operator<<(std::ostream& os, const TestMat& mat)
{
    os << "|" << mat.right << "| " << std::endl << "|" << mat.forward << "| " << std::endl << "|" << mat.up << "| " << std::endl;
    return os;
}

 static const Test up = Test(0,0,1);

int main(int argc, char** args){
    using namespace std;

    Test upObj = Test(5,2,1);
    Test forObj = Test(1,2,3);
    Test rigObj = Test(9,6,4);
    
    TestMat mat = TestMat(upObj, forObj, rigObj);
    //mat.up = upObj;

    cout << "Mat" << endl;
    cout << mat << endl << endl;
    cout << "Mat Col X" << endl;
    cout << mat.getColX() << endl << endl;

    mat.up = forObj;
    
    cout << "After up vec change." << endl;
    cout << "Mat" << endl;
    cout << mat << endl << endl;
    cout << "Mat Col X" << endl;
    cout << mat.getColX() << endl << endl;

    cout << "Mat Vec Member by []" << endl;
    cout << mat.up[2] << endl << endl;
    cout << "Mat Vec Member by [][]" << endl;
    cout << mat[2][2] << endl << endl;
    cout << "Static Vec UP" << endl;
    cout << up << endl << endl;

    return 0;
}

/*
int main(int argc, char** args){
    using namespace std;

    int num1, num2, num3;
    num1 = 8;
    num2 = 10;
    num3 = -5;

    Test obj = Test();
    Test obj2 = Test(&num1, &num2, &num3);
    Test &obj3 = Test(obj2.y, obj2.z, obj2.x);
    
    cout << "obj" << endl;
    cout << obj << endl;
    cout << "nums" << endl;
    cout << num1 << ", " << num2 << ", " << num3 << endl;
    cout << "obj2" << endl;
    cout << obj2 << endl;
    cout << "obj3" << endl;
    cout << obj3 << endl << endl;

    obj2.x = 5;
    cout << "nums after obj2 mod" << endl;
    cout << num1 << ", " << num2 << ", " << num3 << endl;
    cout << "obj2 after mod" << endl;
    cout << obj2 << endl << endl;
    
    num1 = 1; num2 = -8; num3 = 6;
    cout << "nums after mod" << endl;
    cout << num1 << ", " << num2 << ", " << num3 << endl;
    cout << "obj3 after nums mod" << endl;
    cout << obj3 << endl << endl;
    return 0;
}*/