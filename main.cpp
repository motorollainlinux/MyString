#include <iostream>
#include <math.h>

using std::cout;
using std::cin;

void CalcCredit(int Summ, int Term, float prozent, bool Annuity) {
    if(Annuity) {
        double PaymentOnMounth, Overpayment, SummPayment;
        PaymentOnMounth = Summ*prozent/12*pow((1+prozent/12), Term)/(pow((1+prozent/12), Term)-1);
        Overpayment = PaymentOnMounth*Term-Summ;
        SummPayment = PaymentOnMounth*Term+Overpayment;
        cout << "Pay on mounth: " << PaymentOnMounth << " ₽\n";
        cout << "Overpayment: " << Overpayment << " ₽\n";
        cout << "Total payment: " << SummPayment << " ₽\n";
    } else {
        cout << "in worck...\n";
    }
}
void CalcContribution() {

}
/*int Summ, Term, float prozent, bool Anutent;*/
void UserEnter(int &Summ, int &Term, float &prozent, bool &Annuity) {
    bool IsCorretEnter;
    std::string Enter;
    do {
        cout << "Enter the loan amount: ";
        cin >> Enter;
        IsCorretEnter = true;
        for(int i = 0; i < Enter.size(); i++) {
            if(Enter[i] > '9' || Enter[i] < '0')
            IsCorretEnter = false;
        }
        if(IsCorretEnter) 
        Summ = std::stoi(Enter);
        else 
        cout << "Invalid enter!\n";
        cin.clear();
    }while(!IsCorretEnter);
    Enter = "";
    do {
        cout << "Enter the credit term: ";
        cin >> Enter;
        IsCorretEnter = true;
        for(int i = 0; i < Enter.size(); i++) {
            if(Enter[i] > '9' || Enter[i] < '0')
            IsCorretEnter = false;
        }
        if(IsCorretEnter) 
        Term = std::stoi(Enter);
        else 
        cout << "Invalid enter!\n";
        cin.clear();
    }while(!IsCorretEnter);
    Enter = "";
    do {
        int CountDots = 0;
        cout << "Enter the percent: ";
        cin >> Enter;
        IsCorretEnter = true;
        for(int i = 0; i < Enter.size(); i++) {
            if(Enter[i] == '.') {
                CountDots++;
                
            }
            if(Enter[i] > '9' && Enter[i] != '.' || Enter[i] < '0' && Enter[i] != '.' || CountDots > 1)
            IsCorretEnter = false;
        }
        if(Enter[0] == '.') {
            IsCorretEnter = false;
        }
        if(IsCorretEnter) 
        prozent = std::stof(Enter);
        else 
        cout << "Invalid enter!\n";
        cin.clear();
    }while(!IsCorretEnter);
    Enter = "";
    IsCorretEnter = false;
    do {
        cout << "Enter the credit type (0 - differentiated/1 - annuity): ";
        cin >> Enter;
        if(Enter == "0" || Enter == "differentiated") {
            Annuity = false;
            IsCorretEnter = true;
        } else if(Enter == "1" || Enter == "annuity") {
            Annuity = true;
            IsCorretEnter = true;
        } else
        cout << "Invalid enter!\n";
        cin.clear();
    }while(!IsCorretEnter);
}
int main() {
    int Summ, Term;
    float prozent;
    bool Annuity;
    UserEnter(Summ, Term, prozent, Annuity);
    CalcCredit(Summ, Term, prozent, Annuity);
    return 0;
}