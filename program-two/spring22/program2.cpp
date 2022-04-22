//Date:     4/21/2022
//Author:   Will Arthur
//Tools:    Mackbook Pro, G++, Pico
//Purpose:  Get loan data from user, make calculation and output data.  

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    char loanType;
    float loanAmount,rate;
    int numPayments, years;
       
    cout << "What loan type? (H/h for Mortgage or A/a for Auto Loan)\n";
    cin >> loanType;
    cout << "How much do you want to borrow?\n";
    cin >> loanAmount;
    
    if(loanType == 'A' || loanType == 'a')
    {
        cout << "How many payments? (36, 48, or 60)\n";
        cin >> numPayments;
    }
    else if(loanType == 'H' || loanType == 'h')
    {
        cout << "How many years? (15, 20, or 30)\n";
        cin >> years;
        numPayments = years * 12;
    }
    
    switch(numPayments)
    {
        case 36:
            rate = .0299;
            break;
        case 48:
            rate = .0302;
            break;
        case 60:
            rate = .0389;
            break;
        case 180:
            rate = .0312;
            break;
        case 240:
            rate = .03625;
            break;
        case 360:
            rate = .0387;
            break;
    }
    
    if(loanAmount >= 200000) rate += .015;
    
    float monthlyPayment = ((rate * pow(1 + rate, numPayments)) / (pow(1 + rate, numPayments) - 1)) * loanAmount;
    float ratePercent = rate * 100;
    float totalPayment = (1 + rate) * loanAmount;
    float interestPaid = loanAmount * rate;
    
    ofstream file;
    file.open("report.txt");
    
    cout << setw(75); cout << "Loan Type:" << right << ((loanType == 'a' || loanType == 'A') ? "Auto" : "Mortgage");
    
}

