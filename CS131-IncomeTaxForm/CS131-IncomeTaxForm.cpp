#include <iostream>
#include <cmath>

using namespace std;

/*
Program Specifications Write a program to calculate U.S. income tax owed given wages, taxable interest, 
unemployment compensation, status (single or married) and taxes withheld. 

Taxpayers are only allowed to use this short form if adjusted gross income (AGI) is less than $120000. 

Dollar amounts are displayed as integers with no comma separators. For example, cout << "Deduction: $" << deduction

Note: this program is designed for incremental development. Complete each step and submit for grading 
before starting the next step. Only a portion of tests pass after each step but confirm progress.
*/

int main()
{
    /*
    Step 1 (2 pts). Input wages, taxable interest, unemployment compensation, status (1=single and 2=married) and taxes withheld as integers. 
    Calculate and output AGI (wages + interest + unemployment). 
    Output error message if AGI is above $120000 and the program stops with no additional output. Submit for grading to confirm two tests pass.
    */

    /*
    Step 2 (3 pts). Identify deduction amount based on status: (1) Single=$12000 or (2) Married=$24000. 
    Set status to 1 if not input as 1 or 2. Calculate taxable income (AGI - deduction). Set taxable income to zero if negative. 
    Output deduction and taxable income. Submit for grading to confirm five tests pass.
    */

    /*
    Step 3 (3 pts). Calculate tax amount based on exemption and taxable income (see tables below). 
    Tax amount should be stored as a double and rounded to the nearest whole number using round(). 
    Submit for grading to confirm eight tests pass.
    */

    /*
    Step 4 (2 pts). Calculate amount of tax due (tax - withheld). If the amount due is negative the tax payer receives a refund. 
    Output tax due or tax refund as positive values. Submit for grading to confirm all tests pass.
    */

    int wages;
    int taxableInterest;
    int unemploymentCompensation;
    int maritalStatus; // 1 = single and 2 = married
    int deduction = 12'000;
    int taxesWithheld;
    int AGI; // AGI = wages + interest + unemployment
    int taxableIncome;
    double federalTax = 0;
    int taxRefund;

    cin >> wages;
    cin >> taxableInterest;
    cin >> unemploymentCompensation;
    cin >> maritalStatus;
    cin >> taxesWithheld;
    
    AGI = wages + taxableInterest + unemploymentCompensation;
    if (maritalStatus == 1) // deduction for single
    {
        deduction = 12'000;
    }
    else if (maritalStatus == 2) // deduction for married
    {
        deduction = 24'000;
    }

    taxableIncome = AGI - deduction;
    if (taxableIncome < 0)
    {
        taxableIncome = 0;
    }
    // Federal tax brackets
    if ((maritalStatus == 1 && taxableIncome <= 10'000) || (maritalStatus == 2 && taxableIncome <= 20'000))
    {
        federalTax = taxableIncome * 0.10;
    }
    // Single filers
    else if (maritalStatus == 1 && taxableIncome > 10'000 && taxableIncome <= 40'000)
    {
        federalTax = 1000 + ((taxableIncome - 10'000) * 0.12);
    }
    else if (maritalStatus == 1 && taxableIncome > 40'000 && taxableIncome <= 85'000)
    {
        federalTax = 4600 + ((taxableIncome - 40'000) * 0.22);
    }
    else if (maritalStatus == 1 && taxableIncome < 85'000)
    {
        federalTax = 14500 + ((taxableIncome - 85'000) * 0.24);
    }
    // Married filers
    else if (maritalStatus == 2 && taxableIncome > 20'000 && taxableIncome <= 80'000)
    {
        federalTax = 2000 + ((taxableIncome - 20'000) * 0.12);
    }
    else if (maritalStatus == 2 && taxableIncome < 80'000)
    {
        federalTax = 9200 + ((taxableIncome - 80'000) * 0.22);
    }

    taxRefund = federalTax - taxesWithheld;
    
    // Output
    cout << "AGI: $" << AGI << endl;
    if (AGI > 120'000)
    {
        cout << "Error: Income too high to use this form\n";
    }
    else
    {
        cout << "Deduction: $" << deduction << endl;
        cout << "Taxable income: $" << taxableIncome << endl;
        cout << "Federal tax: $" << federalTax << endl;
        if (taxRefund < 0)
        {
            cout << "Tax refund: $" << fabs(taxRefund) << endl;
        }
        else
        {
            cout << "Taxes Owed: $" << fabs(taxRefund) << endl;
        }
    }

// End program sequence
    cout << endl << endl;
#ifdef _WIN32
    system("pause");
#else
    cout << "Press any key to continue . . . ";
    cin.get();
#endif
    return 0;
}
