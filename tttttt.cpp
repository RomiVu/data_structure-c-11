#include <iostream>
#include <cstdio>
#include <ctime> // for time ()
#include <random> // for mersenne twister
#include <vector>
#include <set>
#include <string>


using namespace std;
 
void CloseWindow()
{
    cout << "Tap twice 'Enter' to exit the window..." << endl;
    cin.clear();
    cin.ignore(32767, '\n');
    cin.get();
}


 /*
class Person{
private:
    string m_name;
    int m_age;
 protected:
    int m_sex; // can be accessed by Person members, friends, and derived classes
public:
    Person(const string& name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
        m_sex = 1;
    }
 
    const string& getName() const { return m_name; }
    int getAge() const { return m_age; }
 
};
// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person {
private:
    double m_battingAverage;
    int m_homeRuns;
 
public:
    BaseballPlayer(const string& name = "", int age = 0,
        double battingAverage = 0.0, int homeRuns = 0)
        : Person{ name, age }, // call Person(const string&, int) to initialize these fields
            m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
         m_sex = 2;
    }
 
    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};

 
int main(int argc, char const *argv[])
{   
    BaseballPlayer pedro{ 0.342, 42 };
 
    cout << pedro.getName() << '\n';
    cout << pedro.getAge() << '\n';
    cout << pedro.getHomeRuns() << '\n';
    cout << pedro.m_sex << '\n';
    CloseWindow();
    return 0;
}
*/
class Base
{
protected:
    int m_value;

private:
    void print() { cout << "base print  \n"; }
 
public:
    Base(int value)
        : m_value(value)
    {
    }
 
    void identify() { std::cout << "I am a Base\n"; }
};
 
class Derived: public Base
{
// private:
//     void print() { cout << "[private] Derived print  \n"; }

public:
    Derived(int value)
        : Base(value)
    {
    }
    void identify() { std::cout << "I am a Derived\n"; }

    void print() { cout << "public Derived print  \n"; }
};
int main()
{
    Base base(5);
    base.identify();
 
    Derived derived(7);
    derived.identify();
    
    CloseWindow();
    return 0;
}