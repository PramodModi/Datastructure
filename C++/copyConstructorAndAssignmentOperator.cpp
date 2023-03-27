# include<iostream>
#include<string>
using namespace std;

class MyClass{
    private:
        char* str;
    public:
        MyClass(){}
        MyClass(char* myString){
            int size = strlen(myString)+1;
            str = new char[size];
            for(int i =0; i< size; i++)
                str[i] = myString[i];
        }
        MyClass(const MyClass & obj){
            cout<<"Copy Constructor\n";
            int size = strlen(obj.str)+1;
            str = new char[size];
            for(int i =0; i< size; i++)
                str[i] = obj.str[i];

        }
        MyClass& operator =(const MyClass & obj){
            cout<<"Assignment Operator\n";
            if (this != &obj){
                delete [] str;
                str = new char[strlen(obj.str) + 1];
                for(int i =0; i< strlen(obj.str)+1; i++)
                    str[i] = obj.str[i];
                cout<<"Assined \n";
            }

            return *this;
        }

        ~MyClass(){
            cout<<"destructor\n";
            delete [] str;
        } 
        void print(){
            cout<<str<<"\n";
        }
};

int main(){
    /* Below is with pointer
    //char* myString = "First Class";
    MyClass *obj = new MyClass("First Class");
    obj->print();
    MyClass *obj1 = new MyClass(*obj); // Copy Constructor
    obj1->print();
    MyClass *obj2 = new MyClass("Second class");
    obj2->print();
    *obj2 = *obj; //Assignment Operator
    obj2->print();
    delete obj;
    obj2->print();
    delete obj1;
    delete obj2*/
    MyClass obj("First Class");
    obj.print();
    MyClass obj1 = obj; //Copy COnstructor
    obj1.print();
    MyClass obj2 ("Second Class");
    obj2.print();
    obj2 = obj1; //Assignment Operator
    obj2.print();
    
}