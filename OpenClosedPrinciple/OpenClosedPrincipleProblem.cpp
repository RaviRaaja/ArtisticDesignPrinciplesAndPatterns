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

enum CreditCardType
{
    SILVER = 1,
    GOLD,
    PLATINUM,
    INVALID
};

string toString(CreditCardType ccType)
{
    switch (ccType)
    {
    case SILVER:
        return "Silver";
    case GOLD:
        return "Gold";
    case PLATINUM:
        return "Platinum";
    default:
        return "Invalid";
    }
}

class CreditCardEligibilityValidator
{
    // future requirements - active loan check, Investments check, Depository Participants
public:
    CreditCardType checkForEligibleCreditCard(Account account)
    {
        if (AccountType::CURRENT == account.m_accountType)
        {
            if (account.m_balance >= 1000 || account.m_avgCashFlow >= 4000)
            {
                return CreditCardType::PLATINUM;
            }
            else if (account.m_balance >= 500)
            {
                return CreditCardType::SILVER;
            }
        }
        else if (AccountType::SAVINGS == account.m_accountType)
        {
            if (account.m_balance >= 100 || account.m_avgCashFlow >= 500)
            {
                return CreditCardType::SILVER;
            }
        }
        else if (AccountType::FD == account.m_accountType)
        {
            if (account.m_avgCashFlow >= 5000)
            {
                return CreditCardType::GOLD;
            }
        }
        return CreditCardType::INVALID;
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
        if (eligibleCreditCard != CreditCardType::INVALID) {
            cout << "Account Name: " << account->m_name << " eligibile for " << toString(eligibleCreditCard) << endl;
        }
    }

    return 0;
}