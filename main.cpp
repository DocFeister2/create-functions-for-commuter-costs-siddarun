#include <iostream>
#include <cstdio>

using namespace std;

const double DOLLARS_PER_GALLON = 4.49;     // cost of gas per gallon
const double MILES_PER_COMMUTE = 20.5;    // miles in one round-trip commute
const double MILES_PER_GALLON = 36;       // car fuel efficiency

double myCommutes;
double myCost;

// Converts gas dollars into number of commutes
double toCommutes(double gasDollars) {
  double numCommutes;
  double gasGallons;
  double gasMiles;

  gasGallons = gasDollars / DOLLARS_PER_GALLON;
  gasMiles = gasGallons * MILES_PER_GALLON;

  numCommutes = (1/MILES_PER_COMMUTE)*gasMiles; // TODO: That math is not right! Something is missing here...

  return numCommutes;
}

/* Takes in number of commutes. Miles per commute is a constant, so total miles driven for the given commutes is first calculated. 
   Dividing this by the MILES_PER_GALLON constant, we get the total gallons spent for the commutes.
   Multiplying the gallons by DOLLARS_PER_GALLON constant gives the total cost of the commutes. */

// Converts number of commutes into gas cost
double toDollars(double commutes) {
  double totalCost;

  totalCost = (commutes * MILES_PER_COMMUTE)*(1/MILES_PER_GALLON)*(DOLLARS_PER_GALLON);
  
  return totalCost;
}

int main() {
  cout << "$20 will buy you: " << std::printf("%.1f",toCommutes(20)) << " commutes." << endl;
  cout << "$100.50 will buy you: " << std::printf("%.1f",toCommutes(100.50)) << " commutes." << endl;
  cout << "$500 will buy you: " << std::printf("%.1f",toCommutes(500)) << " commutes." << endl;
  cout << "$8000 will buy you: " << std::printf("%.1f",toCommutes(8000)) << " commutes." << endl;


  cout << "Enter the number of commutes you'd like to do: ";
  cin >> myCommutes;

  myCost = toDollars(myCommutes);

  cout << "Great idea! Let's drive! ";
  cout << myCommutes << " commutes will cost you $" << std::printf("%.1f", myCost) << endl;

  cout << "All done!" << endl;
}
