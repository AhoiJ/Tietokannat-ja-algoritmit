#include "Runway.h"
#include "Runway_takeoff.h"
#include "Utility.h"
#include "RANDOM.h"
#include "Extended_queue.h"
#include "Queue.h"
#include <iostream>

using namespace std;

void initialize(int &end_time, int &queue_limit,
	double &arrival_rate, double &departure_rate);
void run_idle(int time);
void run_idle_landing(int time);
void run_idle_takeoff(int time);
void main_1();
void main_2();
void main_3();
void main_4();

int main() {
	int loops = 0;
	while (loops == 0) {
		int choise;
		cout << " This program has multiple versions." << endl
			<< "Choose 1 if you wish to use the default version." << endl
			<< "Choose 2 if you wish to use the 2 runway version." << endl
			<< "Choose 3 if you wish to use the 2 runway with extra usefullness." << endl
			<< "Choose 4 if you wish to use the 3 runway version." << endl;
		cin >> choise;
		if (choise == 1)
		{
			cout << "This program simulates an airport with only one runway." << endl
				<< "One plane can land or depart in each unit of time." << endl;
			main_1();
			loops = 1;

		}
		else if (choise == 2) {
			cout << "This program simulates an airport with two runways." << endl
				<< "One plane can land or depart in each unit of time to different runways." << endl;
			main_2();
			loops = 1;
		}
		else if (choise == 3) {
			cout << endl << "This program simulates an airport with two runways." << endl
				<< "One plane can land or depart in each unit of time to different runways." << endl
				<< "or if runways are free, they can reroute to eachoter" << endl;
			main_3();
			loops = 1;
		}
		else if (choise == 4) {
			cout << endl << "This program simulates an airport with three runways." << endl
				<< "One of the runways is preserved for landings, one for takeoffs " << endl
				<< "and the third one is primarily for landings but can be used for takeoffs." << endl;
			main_4();
			loops = 1;
		}
		else if (choise != 1 || choise != 2 || choise == 3 || choise == 4) {
			cout << "Enter valid choise." << endl;
			loops = 0;
		}
	}
	system("pause");
	return 0;
}

void main_1()     //  Airport simulation program
			   /*
			   Pre:  The user must supply the number of time intervals the simulation is to
			   run, the expected number of planes arriving, the expected number
			   of planes departing per time interval, and the
			   maximum allowed size for runway queues.
			   Post: The program performs a random simulation of the airport, showing
			   the status of the runway at each time interval, and prints out a
			   summary of airport operation at the conclusion.
			   Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
			   */

{
	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;
	Runway small_airport(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (small_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (small_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane moving_plane;
		switch (small_airport.activity(current_time, moving_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			moving_plane.land(current_time);
			break;
		case takingoff:
			moving_plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
		}
	}
	small_airport.shut_down(end_time);
}

void initialize(int &end_time, int &queue_limit,
	double &arrival_rate, double &departure_rate)
	/*
	Pre:  The user specifies the number of time units in the simulation,
	the maximal queue sizes permitted,
	and the expected arrival and departure rates for the airport.
	Post: The program prints instructions and initializes the parameters
	end_time, queue_limit, arrival_rate, and departure_rate to
	the specified values.
	Uses: utility function user_says_yes
	*/

{

	cout << "Up to what number of planes can be waiting to land "
		<< "or take off at any time? " << flush;
	cin >> queue_limit;

	cout << "How many units of time will the simulation run?" << flush;
	cin >> end_time;

	bool acceptable;
	do {
		cout << "Expected number of arrivals per unit time?" << flush;
		cin >> arrival_rate;
		cout << "Expected number of departures per unit time?" << flush;
		cin >> departure_rate;
		if (arrival_rate < 0.0 || departure_rate < 0.0)
			cerr << "These rates must be nonnegative." << endl;
		else
			acceptable = true;

		if (acceptable && arrival_rate + departure_rate > 1.0)
			cerr << "Safety Warning: This airport will become saturated. " << endl;

	} while (!acceptable);
}

void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
	cout << time << ": Runway is idle." << endl;
}

void run_idle_takeoff(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
	cout << time << ": Takeoff runway is idle." << endl;
}

void run_idle_landing(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
	cout << time << ": Landing runway is idle." << endl;
}

void main_2() {

	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;
	Runway takeoff_airport(queue_limit);
	Runway landing_airport(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (landing_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (takeoff_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane landing_plane;
		Plane takeoff_plane;
		switch (landing_airport.activity(current_time, landing_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			landing_plane.land(current_time);
			break;
			// poistettu taking off case.
		case idle:
			run_idle_landing(current_time);
		}

		switch (takeoff_airport.activity(current_time, takeoff_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case takingoff:
			takeoff_plane.fly(current_time);
			break;
			// poistettu landing case.
		case idle:
			run_idle_takeoff(current_time);
		}

	}
	landing_airport.shut_down(end_time);
	takeoff_airport.shut_down(end_time);
}

void main_3() {

	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;
	Runway_takeoff takeoff_airport(queue_limit);
	Runway landing_airport(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (landing_airport.landingQueueFull() == success) {
				takeoff_airport.can_land(current_plane);
				landing_airport.addToSwitchCount();
			}
			else if (landing_airport.landingQueueStatus() == fail && takeoff_airport.takeoffQueueStatus() == success) {
				takeoff_airport.can_land(current_plane);
				landing_airport.addToSwitchCount();
			}
			else if (landing_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (takeoff_airport.takeoffQueueStatus() == fail && landing_airport.landingQueueStatus() == success) {
				landing_airport.can_depart(current_plane);
				takeoff_airport.addToSwitchCount();
			}
			else if (takeoff_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane landing_plane;
		Plane takeoff_plane;
		switch (landing_airport.activity(current_time, landing_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			landing_plane.land(current_time);
			break;
		case takingoff:
			landing_plane.fly(current_time);
			break;
		case idle:
			run_idle_landing(current_time);
		}

		switch (takeoff_airport.activity(current_time, takeoff_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			takeoff_plane.land(current_time);
			break;
		case takingoff:
			takeoff_plane.fly(current_time);
			break;
		case idle:
			run_idle_takeoff(current_time);
		}

	}
	landing_airport.shut_down(end_time);
	takeoff_airport.shut_down(end_time);
}

void main_4() {

	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;
	Runway_takeoff takeoff_airport(queue_limit);
	Runway landing_airport(queue_limit);
	Runway third_airport(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (landing_airport.landingQueueStatus() == fail) {
				third_airport.can_land(current_plane);
				landing_airport.addToSwitchCount();
			}
			else if (landing_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (takeoff_airport.takeoffQueueStatus() == fail && third_airport.landingQueueStatus() == success) {
				third_airport.can_depart(current_plane);
				takeoff_airport.addToSwitchCount();
			}
			else if (takeoff_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane landing_plane;
		Plane takeoff_plane;
		Plane third_plane;
		switch (landing_airport.activity(current_time, landing_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			landing_plane.land(current_time);
			break;
		case takingoff:
			landing_plane.fly(current_time);
			break;
		case idle:
			run_idle_landing(current_time);
		}

		switch (takeoff_airport.activity(current_time, takeoff_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			takeoff_plane.land(current_time);
			break;
		case takingoff:
			takeoff_plane.fly(current_time);
			break;
		case idle:
			run_idle_takeoff(current_time);
		}

		switch (third_airport.activity(current_time, third_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			third_plane.land(current_time);
			break;
		case takingoff:
			third_plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
		}

	}
	landing_airport.shut_down(end_time);
	takeoff_airport.shut_down(end_time);
	third_airport.shut_down(end_time);
}