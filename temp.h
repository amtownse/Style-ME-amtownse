//
// Created by Alexander Townsend on 2/4/21.
//

#ifndef STYLE_ME_TEMP_H
#define STYLE_ME_TEMP_H

class temp{
private:
    double fahrenheit;
public:
    /**constructor
     *
     */
    temp();

    /**A function to get the current temperature in degrees fahrenheit
    * @return temperature in degrees fahrenheit
    */
    double getFahrenheit();

    /**A function to set the temperature given a temperature in fahrenheit
    * @param f the temperature in degrees fahrenheit
    */
    void setFahrenheit(double fahrenheit);

    /**A function to get the current temperature in degrees celsius
     * @return temperature in degrees celsius
     */
    double getCelsius();

    /**A function to set the temperature given a temperature in celsius
     * @param celsius the temperature in degrees celsius
     */
    void setCelsius(double celsius);
};


#endif //STYLE_ME_TEMP_H
