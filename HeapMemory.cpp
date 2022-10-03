// Memory Location in HEAP & STACK.
#include<iostream>
using namespace std;
int insert(int *x)
{
    for(int i=0; i<5; i++)
    {
        cout << "Enter value " << i << ":  ";
        cin >> x[i];
    }
    return *x;
}
void display(int *y)
{
    for(int i=0; i<5; i++)
    {
        cout << y[i] << "\t";
    }
}
int main()
{
    int a[5];                                               // array, value are store in STACK
    cout << "array \'a\' address: " << a << endl;
    cout << "array \'a\' address: " << &a[0] << endl;
    a[5] = insert(a);

    int *p;                                                 // pointer, value are store in HEAP
    p = new int[5];
    p[5] = insert(p);

    cout << "Stack value: \n";
    display(a);
    cout << "\n\nHeap value: \n";
    display(p);

return 0;
}
