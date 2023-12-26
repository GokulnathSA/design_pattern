#include <iostream>
#include "CarFactory.cpp"

using namespace std;

int main()
{
    int type;
    cout<<"Enter type or 0 to exit"<<endl;
    cin>>type;
    CarFactory* factory = NULL;
    if (type == 1)
    {
        factory = new SimpleCarFactory;
    }
    else
    {
        factory = new LuxuryCarFactory;
    }

    Car *car = factory->buildWholeCar();
	car->printDetails();
    return 0;
}