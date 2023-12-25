#include <iostream>
using namespace std;
#include "Objects.cpp"

class ToyFactory
{
    public:
        static std::unique_ptr<Toy> createToy(int type)
        {
            std::unique_ptr<Toy> toy;
            switch(type)
            {
                case 1:
                {
                    toy = std::make_unique<Car>();
                    break;
                }
                case 2:
                {
                    toy = std::make_unique<Bike>();
                    break;
                }
                case 3:
                {
                    toy = std::make_unique<Plane>();
                    break;
                }
                default:
                {
                    cout << "invalid toy type please re-enter type" << endl;
			        return NULL;
                }
            }
            toy->prepareParts();
	        toy->combineParts();
	        toy->assembleParts();
	        toy->applyLabel();
	
	        return toy;
        }

};