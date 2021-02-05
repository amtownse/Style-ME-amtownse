//
// Created by Alexander Townsend on 2/4/21.
//

#include "temp.h"


temp::temp(){
    this->fahrenheit=32;
}


double temp::getFahrenheit() {
    return this->fahrenheit;
}


void temp::setFahrenheit(double fahrenheit){
    this->fahrenheit = fahrenheit;
}


double temp::getCelsius(){
    return (this->fahrenheit-32)*5/9;
}


void temp::setCelsius(double celsius) {
    this->fahrenheit=(celsius*9/5+32);
}

