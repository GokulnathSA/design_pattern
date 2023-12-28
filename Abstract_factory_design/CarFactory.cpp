#include <iostream>
#include <memory>
#include "Car.cpp"
using namespace std;

class CarFactory
{
    private:
        unique_ptr<Car> car;
    protected:
        virtual unique_ptr<Tire> buildTire() = 0;
        virtual unique_ptr<Body> buildBody() = 0;
    public:
        virtual unique_ptr<Car> buildWholeCar() = 0;
};

class SimpleCarFactory : public CarFactory
{
    unique_ptr<Tire> buildTire()
    {
        return make_unique<SimpleTire>();
    }

    unique_ptr<Body> buildBody()
    {
        return make_unique<SimpleBody>();
    }

    unique_ptr<Car> buildWholeCar()
    {
        unique_ptr<Car> car = make_unique<Car>("Simple_car");
        car->setTire(buildTire());
        car->setBody(buildBody());
        return car;
    }
};

class LuxuryCarFactory : public CarFactory {
	unique_ptr<Tire> buildTire() 
    {
		return make_unique<LuxuryTire>();
	}
	unique_ptr<Body> buildBody() 
    {
		return make_unique<LuxuryBody>();
	}
	unique_ptr<Car> buildWholeCar() 
    {
		unique_ptr<Car> car = make_unique<Car>("LuxuryCar");
		car->setTire(buildTire());
		car->setBody(buildBody());
		return car;
	}
};
