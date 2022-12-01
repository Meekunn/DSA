/*
	Write a program that calculates the work done and power utilized by a person with mass, m after he/she moves through a distance, d. 
	This program must accept mass and distance from the user in order to compute the power and work done by the person. 
	Note: const 

	Force = mass * acceleration due gravity
	Work done = Force * distance
	Power Workdone or Energy / time
*/

#include <iostream>

int main() {

	float mass, distance, time, force, work, power;
	const float g = 9.8;

	std::cout << "Input the mass in kg: ";
	std::cin >> mass;
	std::cout << "Input the distance in meter: ";
	std::cin >> distance;
	std::cout << "Input the time in seconds: ";
	std::cin >> time;

	force = mass * g;
	work = force * distance;
	power = work / time;

	std::cout << "The calculated force is " << force << "Newton." << std::endl;
	std::cout << "The calculated work done by the mass " << mass << "kg is " << work << "Joules." << std::endl;
	std::cout << "The calculated power utilized by the mass " << mass << "kg in " << time << "seconds is " << power << "Watts." << std::endl;


	return 0;
}

