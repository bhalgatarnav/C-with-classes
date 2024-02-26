/* File: Prolet.cpp
# Date: 4 February 2024
# By:   Arnav A Bhalgat
# Lab 3 - Work Harder, Not Smarter
#
# ELECTRONIC SIGNATURE
# ARNAV A BHALGAT
#
# The electronic signature above indicates the script
# submitted for evaluation is my individual work, and I
# have a general understanding of all aspects of its
# development and execution.
#
# A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
# Estimating the contributions to GDP of a working individual.
*/
#include <iostream>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarterOfYear);
const int quarters_per_year = 4;
const int epoch_year = 1977;
const int quarters_since_year0 = 1977*4;
const int epoch_quarter = 1;

int main() {
	// Get the year for the calculation.
	std::cout << "Please enter the year for the calculation: ";
	int year = get_int();

	std::cout << "Please enter the Quarter of the year for the calculation: ";
	int quarterOfYear = get_int();

	// Calculate the number of quaters since Year 0.
	float calculatedQuarters;
	calculatedQuarters = (year*4) + (quarterOfYear-1);
	float finalQuarters;
	finalQuarters = calculatedQuarters - quarters_since_year0;
	
	

	// Calculate the per capita GDP estimate.
	double per_capita_gdp = calculate_per_capita_gdp_estimate();

	// Formatiing the Ouput
	std::string ordinal = quarter_to_ordinal(quarterOfYear);
	std::string GDP_formatted = format_money(per_capita_gdp);

	// Returning Output
	std::cout << "In the " << ordinal << " quarterOfYear of " << year << ", the projected contribution to GDP per working-age person is $" << GDP_formatted << "." << std::endl;

	return 0;
}