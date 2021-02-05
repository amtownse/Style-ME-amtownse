#include <iostream>
using namespace std;

class temp {
private:
    double fahrenheit;
public:
    /**constructor
     *
     */
    temp(){
        this->fahrenheit=32;
    }

    /**A function to get the current temperature in degrees fahrenheit
    * @return temperature in degrees fahrenheit
    */
    double getf() {
        return this->fahrenheit;
    }

    /**A function to set the temperature given a temperature in fahrenheit
    * @param f the temperature in degrees fahrenheit
    */
    void setf(double fahrenheit){
        this->fahrenheit = fahrenheit;
    }

    /**A function to get the current temperature in degrees celsius
     * @return temperature in degrees celsius
     */
    double getc(){
        return (this->fahrenheit-32)*5/9;
    }

    /**A function to set the temperature given a temperature in celsius
     * @param celsius the temperature in degrees celsius
     */
    void setc(double celsius) {
        this->fahrenheit=(celsius*9/5+32);
    }
};

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
    (choice == 1) ? mytemp.setf(tempInput) : mytemp.setc(tempInput);

    //determine what the weather is like
    string weather = (mytemp.getc() < 0) ? "cold" : (mytemp.getc() > 30) ? "hot" : "beautiful";

    //print out the results
    cout << "Hello, " << weather << " World!" << endl;
    return 0;
}