#include <iostream>
#include <memory>
#include "CarFactory.cpp"

using namespace std;

int main()
{
    int type;
    cout<<"Enter type or 0 to exit"<<endl;
    cin>>type;
    unique_ptr<CarFactory> factory;
    if (type == 1)
    {
        factory = make_unique<SimpleCarFactory>();
    }
    else
    {
        factory = make_unique<LuxuryCarFactory>();
    }

    unique_ptr<Car> car = std::move(factory->buildWholeCar());
	car->printDetails();
    return 0;
}