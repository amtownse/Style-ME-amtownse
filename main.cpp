#include <iostream>
using namespace std;

class temp {
    double f;
public:
    temp() : f(32) {}
    double getf() {return f;}
    void setf(double p)
    { f = p;}
    double getc() const {
        return (f-32)*(5/9);        // NEED TO FIX
    }
    void setc(int c) { f=(c*(9/5)+32);} //BUGGY
};

int main() {
    int choice = 0;
    while (!(cin >> choice))
    {
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    int t = 0;
    while (!(cin >> t)) {
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    temp mytemp;
    (choice == 1) ? mytemp.setf(t) : mytemp.setc(t);
//    if (choice == 1)
//        mytemp.setf(t);
//    else
//        mytemp.setc(t);
    string a;
    if (mytemp.getc() < 0)
        a="cold";
    else if (mytemp.getc() > 30)
        a="hot";
    else
        a="beautiful";
    cout << "Hello, " << a << " World!" << endl;
    return 0;
}