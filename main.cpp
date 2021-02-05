#include <iostream>
#include <cmath>
#include "temp.h"
using namespace std;

double MPH_KPH_CONVERSION = 1.609344;

/**A function to calculate wind chill with parts from code written in cs021
 *
 * @param choice whether it is celsius or fahrenheit
 * @param temperature in fahrenheit
 */
void FindWindChill(double choice, double temperature);

int main() {
    double choice = 0;

    //prompt the user for a number 1 or 2
    cout << "Would you like to enter a temperature in fahrenheit(1) or celsius(2):" << endl;

    //define the variable to hold the garbage from invalid lines
    string junk;

    //get a valid response from the user, valid response being either 1 or 2
    while (!(cin >> choice) || (choice!=1 && choice!=2))
    {
        cout << "Please enter either '1' or '2'" << endl;
        cin.clear();
        getline(cin, junk);
    }

    //clear the input line
    getline(cin, junk);

    //prompt the user for a temperature
    cout << ((choice==1) ? "Enter the temperature in degrees fahrenheit" : "Enter the temperature in degrees celsius") << endl;

    //get a valid temperature from the user
    double tempInput = 0;
    while (!(cin >> tempInput)) {
        cin.clear();
        getline(cin, junk);
    }

    //create the temp object and put in the temperature, taking into account the choice the user made earlier
    temp mytemp;
    (choice == 1) ? mytemp.setFahrenheit(tempInput) : mytemp.setCelsius(tempInput);

    //determine what the weather is like
    string weather = (mytemp.getCelsius() < 0) ? "cold" : (mytemp.getCelsius() > 30) ? "hot" : "beautiful";

    //print out the results
    cout << "Hello, " << weather << " World!" << mytemp.getFahrenheit() << endl;

    //call windchill
    FindWindChill(choice, mytemp.getFahrenheit());

    return 0;
}


void FindWindChill(double choice, double temperature){
    cout << "Would you like to calculate the windchill? (y/n)" << endl;

    string windResult;
    cin >> windResult;
    if (windResult == "y" || windResult == "Y") {

        double windChoice = 0;

        //prompt the user for a number 1 or 2
        cout << "Would you like to enter a windspeed in mph(1) or kph(2):" << endl;

        //define the variable to hold the garbage from invalid lines
        string junk;

        //get a valid response from the user, valid response being either 1 or 2
        while (!(cin >> windChoice) || (windChoice != 1 && windChoice != 2)) {
            cout << "Please enter either '1' or '2'" << endl;
            cin.clear();
            getline(cin, junk);
        }

        //clear the input line
        getline(cin, junk);

        //prompt the user for a temperature
        cout << ((windChoice == 1) ? "Enter the windspeed in mph" : "Enter the windspeed in kph") << endl;

        //get a valid temperature from the user
        double windInput = 0;
        while (!(cin >> windInput)) {
            cin.clear();
            getline(cin, junk);
        }

        double windSpeed = (windChoice == 1) ? windInput : windInput/MPH_KPH_CONVERSION;

        double windChill=35.74+0.6215 * temperature-35.75*pow(windSpeed,0.16)+0.4275 * temperature*pow(windSpeed,0.16);
        cout << "The windchill is ";
        if(choice == 1) {
            cout << windChill << " degrees fahrenheit" << endl;
        }else{
            cout << (windChill-32)*5/9 << " degrees celsius" << endl;
        }
    }

}