#include <iostream>
#include <string>
#include "LinkedList.cpp"
#include "Employee.cpp"

using namespace std;

template <typename C>
void print(LinkedList<C> &l)
{
    for (typename LinkedList<C>::iterator itr = l.begin(); itr!= l.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

int main()
{
    // Part 1: Integers
    LinkedList<int> intList;
    int x = 0;
    cout << "Create a list of integers: ";
    while (cin >> x && x!= 0)
    {
        intList.push_front(x);
    }
    
    cout << "The size of linked list is: " << intList.get_size() << endl;
    cout << "The linked list is: ";
    print(intList);
    int key;
    cout << "Enter the key: ";
    cin >> key;
    if (intList.find(key))
        cout << "Is the key in the list? 1" << endl;
    else
        cout << "Is the key in the list? 0" << endl;
    int k;
    cout << "How many values you want to remove? ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        intList.pop_front();
    }
    
    cout << "The list is: ";
    print(intList);

    // Part 2: Strings
    LinkedList<string> stringList;
    string str;
    cout << "Create a list of strings: ";
    while (cin >> str && str!= "exit")
    {
        stringList.push_front(str);
    }
    
    cout << "The size of linked list is: " << stringList.get_size() << endl;
    cout << "The linked list is: ";
    print(stringList);
    cout << "How many values you want to remove? ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        stringList.pop_front();
    }
    
    cout << "The linked list is: ";
    print(stringList);

    // Part 3: Employees
    LinkedList<Employee> employeeList;
    Employee emp;
    cout << "Create a list of employees: " << endl;
    while (cin >> emp && emp.get_id()!= 0)
    {
        employeeList.push_front(emp);
    }
    
    cout << "The size of linked list is: " << employeeList.get_size() << endl;
    cout << "The linked list is: ";
    print(employeeList);
    cout << "How many values you want to remove? ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        employeeList.pop_front();
    }
    
    cout << "The linked list is: ";
    print(employeeList);

    return 0;
}