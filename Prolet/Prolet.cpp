#include <iostream>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);

const int quarters_per_year = 4;
const int epoch_year = 1977;
const int quarters_since_year0 = 1977*4;
const int epoch_quarter = 1;

//This function will calculate the expected (working-age) per-capita GDP, for the user, in a given quarter of a given year.
//This function takes advantage of the given functions already defined.
int main() {
  std::cout << "Please enter the year for the calculation: ";
	int year = get_int();

	std::cout << "Please enter the quarter for the calculation: ";
	int quarterOfYear = get_int();

	// Calculate the number of quaters since Year 0.
	float calculatedQuarters;
	calculatedQuarters = (year*4) + (quarterOfYear-1);
	float finalQuarters;
	finalQuarters = calculatedQuarters - quarters_since_year0;

  // Calculate the GDP for the calcualted quartes
  double gdp = calculate_per_capita_gdp_estimate(finalQuarters);

  //Format the output for presentation
  std::string ordinal = quarter_to_ordinal(quarterOfYear);
	std::string GDP_formatted = format_money(gdp);

	// Returning Output
	std::cout << "In the " << ordinal << " quarter of " << year << ", the projected contribution to GDP per working-age person is $" << GDP_formatted << "." << std::endl;

	return 0;

}