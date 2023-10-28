#include <iostream>
#include <cstring>
using namespace std;
struct Person{
    char* name;
    double salary;
};

class SalaryManager{
    Person *person;
    int n;
    int max;

    public:
    SalaryManager(int num){
        max = num;
        person = new Person[num];
        n=0;
    }
    
    //找到指定名字的person，返回person的salary
    double &operator[](char* name){
        Person* p;
        for(p=person;p<person+n;p++){
            if(strcmp(p->name,name)==0)
                return p->salary;
        }
        p = person + n++;
        p->name = new char[strlen(name)+1];
        strcpy(p->name,name);
        p->salary = 0;
        return p->salary;
    }

    void showTotalSalary(){
        double total;
        for(Person* p = person;p<person+n;p++){
            total+=p->salary;
        }
        cout << "total salary: "<< total << endl;
    }

};

int main(){
    SalaryManager s(3);
    s["zhang"] = 50;
    s["wang"] = 40;
    s["li"] = 30;
    s.showTotalSalary();
    std::cout << "test!!!" <<std::endl;
    return 0;
}