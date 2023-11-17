#include <iostream>
#include <vector>

using namespace std;

enum class AccountType
{
    SAVINGS = 1,
    CURRENT,
    FD
};

class Account
{
public:
    Account(const string &name,
            int accountNumber,
            AccountType accountType,
            int balance,
            int avgCashFlow) : m_accountNumber(accountNumber),
                               m_name(name),
                               m_accountType(accountType),
                               m_balance(balance),
                               m_avgCashFlow(avgCashFlow) {}

    string m_name;
    int m_accountNumber;
    AccountType m_accountType;
    int m_balance;
    int m_avgCashFlow;
};

// should not be added in below way, rather overload << operator

// enum CreditCardType
// {
//     SILVER = 1,
//     GOLD,
//     PLATINUM,
//     INVALID
// };

// string toString(CreditCardType ccType)
// {
//     switch (ccType)
//     {
//     case SILVER:
//         return "Silver";
//     case GOLD:
//         return "Gold";
//     case PLATINUM:
//         return "Platinum";
//     default:
//         return "Invalid";
//     }
// }

enum CCType
{
    SILVER = 1,
    GOLD,
    PLATINUM,
    INVALID
};

struct CreditCard
{

    CreditCard(CCType crediCardType) : m_crediCardType(crediCardType) {}

    friend ostream &operator<<(ostream &os, const CreditCard &ccObject)
    {
        switch (ccObject.m_crediCardType)
        {
        case CCType::SILVER:
            os << "Silver";
            return os;
        case CCType::GOLD:
            os << "Gold";
            return os;
        case CCType::PLATINUM:
            os << "Platinum";
            return os;
        }
        return os;
    }

    CCType m_crediCardType = CCType::INVALID;
};

class CreditCardEligibilityValidator
{
    // future requirements - active loan check, Investments check, Depository Participants
public:
    CreditCard checkForEligibleCreditCard(Account account)
    {
        if (AccountType::CURRENT == account.m_accountType)
        {
            if (account.m_balance >= 1000 || account.m_avgCashFlow >= 4000)
            {
                return CreditCard(CCType::PLATINUM);
            }
            else if (account.m_balance >= 500)
            {
                return CreditCard(CCType::SILVER);
            }
        }
        else if (AccountType::SAVINGS == account.m_accountType)
        {
            if (account.m_balance >= 100 || account.m_avgCashFlow >= 500)
            {
                return CreditCard(CCType::SILVER);
            }
        }
        else if (AccountType::FD == account.m_accountType)
        {
            if (account.m_avgCashFlow >= 5000)
            {
                return CreditCard(CCType::GOLD);
            }
        }
        return CreditCard(CCType::INVALID);
    }
};

int main()
{
    // creating accounts
    Account acc1("Kavin Textiles", 203412, AccountType::CURRENT, 2000, 1000);
    Account acc2("Kaavya Furnitures", 203413, AccountType::CURRENT, 500, 5000);
    Account acc3("Sam", 203456, AccountType::CURRENT, 600, 100);
    Account acc4("Parth", 206712, AccountType::SAVINGS, 10, 100);
    Account acc5("Abi", 211562, AccountType::FD, 60000, 7000);

    std::vector<Account *> accountsInBank{&acc1, &acc2, &acc3, &acc4, &acc5};

    // offer validator creation
    CreditCardEligibilityValidator ofv;

    // check for cc eligibility
    for (auto account : accountsInBank)
    {
        auto eligibleCreditCard = ofv.checkForEligibleCreditCard(*account);
        if (eligibleCreditCard.m_crediCardType != CCType::INVALID)
        {
            cout << "Account Name: " << account->m_name << " eligibile for " << eligibleCreditCard << endl;
        }
    }

    return 0;
}