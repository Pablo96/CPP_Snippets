#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;

namespace Prototyping{
    /** Record is the base Prototype */
    class Record
    {
    public:
        virtual ~Record() {}
        virtual void print() = 0;
        virtual Record* clone() = 0;
    };

    /** CarRecord is a Concrete Prototype */
    class CarRecord : public Record
    {
        string m_carName;
        int m_ID;

    public:
        CarRecord(string carName, int ID)
        : m_carName(carName), m_ID(ID)
        {}

        void print() override
        {
            cout << "Car Record" << endl
                << "Name  : "   << m_carName << endl
                << "Number: "   << m_ID << endl << endl;
        }

        Record* clone() override
        {
            return new CarRecord(*this);
        }
    };

    /** PersonRecord is the Concrete Prototype */
    class PersonRecord : public Record
    {
    private:
        string m_personName;
        int m_age;

    public:
        PersonRecord(string personName, int age)
        : m_personName(personName), m_age(age)
        {}

        void print() override
        {
            cout << "Person Record" << endl
                << "Name : " << m_personName << endl
                << "Age  : " << m_age << endl << endl;
        }

        Record* clone() override
        {
            return new PersonRecord(*this);
        }
    };

    /** Opaque record type, avoids exposing concrete implementations */
    enum RecordType
    {
        CAR,
        PERSON
    };

    /** RecordFactory is the client */
    class RecordFactory
    {
    private:
        unordered_map<RecordType, Record*, hash<int> > m_records;

    public:
        RecordFactory()
        {
            m_records[CAR]    =  new CarRecord("Ferrari", 5050);
            m_records[PERSON] = new PersonRecord("Tom", 25);
        }

        Record* createRecord(RecordType recordType)
        {
            return m_records[recordType]->clone();
        }
    };

    // used when 
    void main()
    {
        RecordFactory recordFactory;

        auto record = recordFactory.createRecord(CAR);
        record->print();

        record = recordFactory.createRecord(PERSON);
        record->print();
    }
}// Fin Prototyping

namespace Singleton 
{
    class StringSingleton
    {
    public:
        static StringSingleton* getInstance()
        {
            static StringSingleton instance;
            return &instance;
        }
    protected: 
        // Default constructor available only to members or friends of this class
        StringSingleton(){}
    
        // This functions arnt given body so if we accidentally callthem will have compile errors
    private:    
        //disallow assignment operator
        const StringSingleton &operator=(const StringSingleton &old); 
        // disallow copy constructor
        StringSingleton(const StringSingleton &old); 


        // Note that although this should be allowed, 
        // some compilers may not implement private destructors
        // This prevents others from deleting our one single instance,
        // which was otherwise created on the heap
        // In any especial case we want to delete a singleton
        // i think is better to give it a shutdown method or similar
        ~StringSingleton(){}
    };
 
    void main()
    {
        StringSingleton* obj1 = StringSingleton::getInstance();
        StringSingleton* obj2 = StringSingleton::getInstance();

        printf("obj1 %ld  obj2 %ld", (long) obj1, (long) obj2);
    }
}// Fin Singleton

namespace Decorators
{
    //Our Car base virtual class
    class Car {
    protected:
        string _str;
    public:
        Car()
        {
            _str = "Unknown Car";
        }

        virtual string getDescription()
        {       
            return _str;
        }

        virtual double getCost() = 0;

        virtual ~Car()
        {
            cout << "~Car()\n";
        }
    };

    //Decorator Base class: This will allow cars subsistems be treated as cars
    class OptionsDecorator : public Car
    {
    public:
        virtual string getDescription() = 0;
        virtual ~OptionsDecorator()
        {
            cout<<"~OptionsDecorator()\n";
        }
    };
    
    // First Concrete Car
    class CarModel1 : public Car
    {       
    public:
        CarModel1()
        {
            _str = "CarModel1";
        }
        virtual double getCost()
        {
            return 31000;
        }

        ~CarModel1()
        {
            cout<<"~CarModel1()\n";
        }
    };

    // Create some decorators
    class PremiumSoundSystem: public OptionsDecorator
    {
        Car *_b;
    public:
        PremiumSoundSystem(Car *b)
        {
            _b = b;
        }
        string getDescription()
        {
            return _b->getDescription() + ", PremiumSoundSystem";
        }

        double getCost()
        {
            return 300 + _b->getCost();
        }
        ~PremiumSoundSystem()
        {
            cout << "~PremiumSoundSystem()\n";
            delete _b;
        }
    };
 
    class ManualTransmission: public OptionsDecorator
    {
        Car *_b;
    public:
        ManualTransmission(Car *b)
        {
            _b = b;
        }
        string getDescription()
        {
            return _b->getDescription()+ ", ManualTransmission";
        }

        double getCost()
        {
            return 800 + _b->getCost();
        }
        ~ManualTransmission()
        {
            cout << "~ManualTransmission()\n";
            delete _b;
        }
    };

    void main()
    {
        // Create our first base car
        Car* car = new CarModel1();
        cout << car->getDescription() << "\costs: $" << car->getCost() << endl;

        // Now the interesting part:
        // Since Decorations have car as it base class we can do this
        car = new PremiumSoundSystem(car);
        cout << car->getDescription() << "\tcosts: $" << car->getCost() << endl;
        
        car = new ManualTransmission(car);
        cout << car->getDescription() << "\tcosts: $" << car->getCost() << endl;
    }
}// Fin Decorators

int main()
{
    //Prototyping::main();
    //Singleton::main();
    Decorators::main();
    // Another pattern Called Mixin will be in its own file
    return 0;
}