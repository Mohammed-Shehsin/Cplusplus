<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>

class Account {
protected:
    std::string accountNumber;
    double balance;

public:
    Account(const std::string& accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful. New balance: " << balance << std::endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds. Balance: " << balance << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    const std::string& getAccountNumber() const {
        return accountNumber;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string& accountNumber, double balance)
        : Account(accountNumber, balance) {}

    void withdraw(double amount) {
        // Charge a $1.50 transaction fee for each withdrawal
        double totalAmount = amount + 1.5;
        if (balance >= totalAmount) {
            balance -= totalAmount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds. Balance: " << balance << std::endl;
        }
    }
};

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(const std::string& accountNumber, double balance, double interestRate)
        : Account(accountNumber, balance), interestRate(interestRate) {}

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        std::cout << "Interest added. New balance: " << balance << std::endl;
    }

    double getInterestRate() const {
        return interestRate;
    }
};

class Client {
private:
    std::string name;
    std::vector<Account*> accounts;

public:
    Client(const std::string& name)
        : name(name) {}

    void addAccount(Account* account) {
        accounts.push_back(account);
    }

    void printAccounts() const {
        std::cout << "Accounts for " << name << ":\n";
        for (const auto& account : accounts) {
            std::cout << account->getAccountNumber() << " - $" << account->getBalance() << "\n";
        }
    }

    const std::string& getName() const {
        return name;
    }
};

class Bank {
private:
    std::vector<Client*> clients;

public:
    void addClient(Client* client) {
        clients.push_back(client);
    }

    void printClients() const {
        std::cout << "Clients:\n";
        for (const auto& client : clients) {
            std::cout << client->getName() << "\n";
            client->printAccounts();
            std::cout << "\n";
        }
    }
};



int main() {
    // Create accounts
    Account account1("A10001", 5000);
    SavingsAccount account2("S10001", 10000, 2.5);
    CheckingAccount account3("C10001", 2000);

    // Deposit and withdraw from accounts
    account1.deposit(1000);
    account1.withdraw(2000);
    account2.deposit(500);
    account2.addInterest();
    account3.withdraw(500);

    // Create clients and add accounts to them
    Client client1("John Doe");
    client1.addAccount(&account1);
    client1.addAccount(&account2);

    Client client2("Jane Smith");
    client2.addAccount(&account3);

    // Create bank and add clients to it
    Bank bank;
    bank.addClient(&client1);
    bank.addClient(&client2);

    // Print bank clients and their accounts
    bank.printClients();

    return 0;
}
=======
#include <iostream>
#include <string>
#include <vector>

class Account {
protected:
    std::string accountNumber;
    double balance;

public:
    Account(const std::string& accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful. New balance: " << balance << std::endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds. Balance: " << balance << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    const std::string& getAccountNumber() const {
        return accountNumber;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string& accountNumber, double balance)
        : Account(accountNumber, balance) {}

    void withdraw(double amount) {
        // Charge a $1.50 transaction fee for each withdrawal
        double totalAmount = amount + 1.5;
        if (balance >= totalAmount) {
            balance -= totalAmount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds. Balance: " << balance << std::endl;
        }
    }
};

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(const std::string& accountNumber, double balance, double interestRate)
        : Account(accountNumber, balance), interestRate(interestRate) {}

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        std::cout << "Interest added. New balance: " << balance << std::endl;
    }

    double getInterestRate() const {
        return interestRate;
    }
};

class Client {
private:
    std::string name;
    std::vector<Account*> accounts;

public:
    Client(const std::string& name)
        : name(name) {}

    void addAccount(Account* account) {
        accounts.push_back(account);
    }

    void printAccounts() const {
        std::cout << "Accounts for " << name << ":\n";
        for (const auto& account : accounts) {
            std::cout << account->getAccountNumber() << " - $" << account->getBalance() << "\n";
        }
    }

    const std::string& getName() const {
        return name;
    }
};

class Bank {
private:
    std::vector<Client*> clients;

public:
    void addClient(Client* client) {
        clients.push_back(client);
    }

    void printClients() const {
        std::cout << "Clients:\n";
        for (const auto& client : clients) {
            std::cout << client->getName() << "\n";
            client->printAccounts();
            std::cout << "\n";
        }
    }
};



int main() {
    // Create accounts
    Account account1("A10001", 5000);
    SavingsAccount account2("S10001", 10000, 2.5);
    CheckingAccount account3("C10001", 2000);

    // Deposit and withdraw from accounts
    account1.deposit(1000);
    account1.withdraw(2000);
    account2.deposit(500);
    account2.addInterest();
    account3.withdraw(500);

    // Create clients and add accounts to them
    Client client1("John Doe");
    client1.addAccount(&account1);
    client1.addAccount(&account2);

    Client client2("Jane Smith");
    client2.addAccount(&account3);

    // Create bank and add clients to it
    Bank bank;
    bank.addClient(&client1);
    bank.addClient(&client2);

    // Print bank clients and their accounts
    bank.printClients();

    return 0;
}
>>>>>>> 2c45aa1028e36147447036cfb72244e003978e98
