/* Lab1
File: ledgeon.cpp
Date: 24 January 2023 
By:   Arnav A Bhalgat
A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES:
This program is a accounting calculator for a hosppital that can calculate the %increase/decrease in patients.
It can calculate the amount given to the charity.
*/
# include <iostream>
int main()
{   // Step1.
    // Taking the necessary inputs:

    float year1;
    std::cout<<"Enter the first year: ";
    std::cin>>year1;

    float patients_Y1;
    std::cout<<"Enter the number of patients we saw that year: ";
    std::cin>>patients_Y1;

    float year2;
    std::cout<<"Enter the second year: ";
    std::cin>>year2;

    float patients_Y2;
    std::cout<<"Enter the number of patients we saw that year: ";
    std::cin>>patients_Y2;

    //Do the calculations:
    
    double percent_inc;
    percent_inc=((patients_Y2-patients_Y1)/patients_Y1)*100;

    float charityY1, charityY2;
    const double avgCharityCost = 1008.97;

    charityY1 = avgCharityCost*patients_Y1;
    charityY2 = avgCharityCost*patients_Y2;

    // Printing the Outputs as asked.
    std::cout<<"In year "<< year1<<", our hospital issued "<<charityY1<<" dollars of charity charges.\n";
    std::cout<<"In year "<< year2<<", our hospital issued "<<charityY2<<" dollars of charity charges.\n";
    std::cout<<"Between "<< year1<<" and "<<year2<<", there was a "<<percent_inc<<"%"<< " increase in patients seen at our hospital.\n";

}