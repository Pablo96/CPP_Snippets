#include "Ej5_CustomClass.h"

void getVars(std::string &, float &, float &);
void printCustomClass(CustomClass &);

int main(int argc, char **args){
    using namespace std;
    string name;
    float height, weight;
    getVars(name, height, weight);

    // Default Constructor
    CustomClass classA;
    cout << "Printing class A:: " << endl;
    printCustomClass(classA);
    // Overload Constructor
    CustomClass classB(name, height, weight);
    cout << "Printing class B:: " << endl;
    printCustomClass(classB);
    // show the class A again
    cout << "Printing class A:: " << endl;
    printCustomClass(classA);
    return EXIT_SUCCESS;
}

void getVars(std::string &name, float &height, float &weight){
    using namespace std;

    cout << "Ingrese nombre: " << endl;
    cin >> name;
    cout << endl << "Altura: " << endl;
    cin >> height;
    cout << endl << "Peso: " << endl;
    cin >> weight;
    cout << endl;
}

void printCustomClass(CustomClass &c_class){
    using namespace std;

    cout << c_class.getName() << endl;
    cout << c_class.getHeight() << endl;
    cout << c_class.getWeight() << endl << endl;
}