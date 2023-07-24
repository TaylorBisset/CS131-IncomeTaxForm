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

    int wages;
    int taxableInterest;
    int unemploymentCompensation;
    int maritalStatus; // 1 = single and 2 = married
    int taxesWithheld;
    int AGI; // AGI = wages + interest + unemployment

    cin >> wages;
    cin >> taxableInterest;
    cin >> unemploymentCompensation;
    cin >> maritalStatus;
    cin >> taxesWithheld;
    
    AGI = wages + taxableInterest + unemploymentCompensation;

    cout << "AGI: $" << AGI << endl;
    if (AGI > 120'000)
    {
        cout << "Error: Income too high to use this form\n";
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
