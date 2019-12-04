//hw5_payroll
//Karma Gurung

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class PayRoll               // Each PayRoll object handles 1 employee
{
private:
	double hours;
	double payRate;

public:
	// Default constructor
	PayRoll() {
		hours = 0;
		payRate = 0;
	}

	// Mutators
	void  setHours(double h)
	{
		hours = h;
	}

	void setPayRate(double p)
	{
		payRate = p;
	}

	// Accessor
	double getGrossPay()
	{
		return (hours * payRate);
	}
};
const int NUM_EMPLOYEES = 7;

void displayAveMinMax(PayRoll Pay[7]) {
	double sum = 0.0;
	double min = Pay[0].getGrossPay(),
		max = Pay[0].getGrossPay();
	for (int empNum = 0; empNum < NUM_EMPLOYEES; empNum++) {
		sum += Pay[empNum].getGrossPay();
		if (Pay[empNum].getGrossPay() < min) {
			min = Pay[empNum].getGrossPay();
		}
		if (Pay[empNum].getGrossPay() > max) {
			max = Pay[empNum].getGrossPay();
		}
	}
	cout << "The average gross pay is: " << sum / NUM_EMPLOYEES << endl;
	cout << "The max is: " << max << endl;
	cout << "The min is: " << min << endl;

}

int main()
{
	//implement you code here // Create an array of PayRoll objects
	PayRoll PayAmount[7];

	double hrs,                      // Hours worked during 1 week pay period  
		rate;                     // Hourly pay rate
	int empNum;                      // Loop control variable and array index
	ifstream data;

	// Open data file
	data.open("payroll.dat");
	if (!data)
		cout << "Error opening data file\n";
	else
	{
		// Input and store work information for each employee
		for (empNum = 0; empNum < NUM_EMPLOYEES; empNum++)
		{
			data >> hrs >> rate;
			//implement you code here
			PayAmount[empNum].setHours(hrs);
			PayAmount[empNum].setPayRate(rate);

		}
		// Close the data file
		data.close();

		// Print out gross pay for each employee
		cout << "Employee  Gross pay\n";
		cout << "========  =========\n";
		cout << fixed << showpoint << setprecision(2);

		for (empNum = 0; empNum < NUM_EMPLOYEES; empNum++)
		{
			cout << "   " << (empNum + 1) << ":     $";
			cout << setw(7) << PayAmount[empNum].getGrossPay() << endl; 	//implement you code here to output

		}

	}
	displayAveMinMax(PayAmount);
//2nd commit
	return 0;
}

