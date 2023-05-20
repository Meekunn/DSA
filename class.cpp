#include <iostream>
#include <vector>
#include <iomanip>

/*
maker: a string representing the maker of the vehicle
model: a string representing the model of the vehicle
year: an integer representing the year the vehicle was made
price: a double representing the price of the vehicle
getDescription(): a virtual function that returns a string describing the vehicle
*/
class Vehicle {
	public: 
		Vehicle() {

		}
		Vehicle(std::string maker, std::string model, int year, double price){
			this->maker = maker;
			this->model = model;
			this->year = year;
			this->price = price;
		}
		~Vehicle() {

		}
		virtual std::string getDescription() {
			return std::to_string(this->year ) + " " + this->maker + " " + this->model + " " + (std::to_string(this->price));
		}
		virtual double getPrice() {
			return this->price;
		}

	protected:
		std::string maker;
		std::string model;
		int year;
		double price;
};

/*
Create a subclass named Car that inherits from Vehicle with the following additional attributes and methods:
-numDoors: an integer representing the number of doors on the car
-isElectric: a boolean representing whether the car is electric or not
-getDescription(): an overridden function that returns a string describing the car, including its make, model, year, number of doors, and whether it is electric
*/

class Car: public Vehicle {
	public:
		Car() {

		}
		Car(std::string maker, std::string model, int year, double price, int numDoors, bool isElectric):Vehicle(maker, model, year, price) {
			this->numDoors = numDoors;
			this->isElectric = isElectric;
		}
		~Car() {

		}
		std::string getDescription() {
			return std::to_string(this->year) + " " + this->maker + " " + this->model + " - " + (std::to_string(this->numDoors)) + " doors, " + (this->isElectric ? "electric" : "not electric");
		}
		double getPrice() {
			return this->price;
		}

	private:
		int numDoors;
		bool isElectric;
};

/*
Create a subclass named Truck that inherits from Vehicle with the following additional attributes and methods:
numWheels: an integer representing the number of wheels on the truck
payloadCapacity: a double representing the maximum payload capacity of the truck
getDescription(): an overridden function that returns a string describing the truck, including its make, model, year, number of wheels, and maximum payload capacity
*/

class Truck: public Vehicle {
	public:
		Truck() {

		}
		Truck(std::string maker, std::string model, int year, double price, int numWheels, double payloadCapacity):Vehicle(maker, model, year, price) {
			this->numWheels = numWheels;
			this->payloadCapacity = payloadCapacity;
		}
		~Truck() {

		}
		std::string getDescription() {
			return std::string(this->maker) + " " + std::string(this->model) + " - " + (std::to_string(this->numWheels)) + " wheels, " + (std::to_string(this->payloadCapacity)) + " 1b payload capacity";
		}
		double getPrice() {
			return this->price;
		}

	private:
		int numWheels;
		double payloadCapacity;
};

/*
Create a class named VehicleInventory with the following attributes and methods:
inventory: a vector of pointers to Vehicle objects 
std::vector<Vehicle *>
addVehicle: a function that takes a pointer to a Vehicle object and adds it to the inventory
getInventoryValue: a function that returns the total value of all the vehicles in the inventory
printInventory(): a function that prints a description of each vehicle in the inventory, using the getDescription() function
*/

class VehicleInventory {
	public:
		VehicleInventory() {

		}
		~VehicleInventory() {

		}
		void addVehicle(Vehicle *obj) {
			pointers.push_back(obj);
		}
		int getInventoryVehicles() {
			return pointers.size();
		}
		double getInventoryCost () {
			double total = 0;
			for (int i = 0; i < pointers.size(); i++) {
				total += this->pointers[i]->getPrice();
			}
			return total;
		}
		void printInventory() {
			for (int i = 0; i < pointers.size(); i++) {
				std::cout << "Vehicle " << (i+1) << ": " << this->pointers[i]->getDescription() << std::endl;
			}
		}

	private:
		std::vector<Vehicle *> pointers;
};

int main() {

		Vehicle *vehicle1 = new Car("Toyota", "Camry", 2010, 20000.00, 2, false);
		Vehicle *vehicle2 = new Truck("Ford", "F-150", 2020, 35000.00, 4, 2000.00);
		Vehicle *vehicle3 = new Car("Tesla", "Model S", 2010, 20000.00, 4, true);

		VehicleInventory inventory;
		inventory.addVehicle(vehicle1);
		inventory.addVehicle(vehicle2);
		inventory.addVehicle(vehicle3);

		std::cout << "Total Vehicles In Inventory is " << inventory.getInventoryVehicles() << std::endl;
		std::cout << "Total Inventory Value is $" << std::fixed << std::setprecision(2) << inventory.getInventoryCost() << std::endl;
		inventory.printInventory();

		delete vehicle1;
		delete vehicle2;
		delete vehicle3;

		return 0;
}