#include <iostream>
#include <memory>
using namespace std;
#include "ToyFactory.cpp"

int main()
{
    int type;
    while(1)
    {
        cout<<"Enter type or 0 to exit"<<endl;
        cin>>type;
        if(!type)
        {
            break;
        }
        std::unique_ptr<Toy> v = std::move(ToyFactory::createToy(type));
        if(v)
        {
            v->showProduct();
        }
    }
    cout<<"Exit ..."<<endl;
    return 0;
}