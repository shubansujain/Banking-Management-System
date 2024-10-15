// Project: Banking Management System
#include <iostream>
using namespace std;
class Bank {
private:
    int total;
    string id;
    struct person {
        string name, ID, address, contact;
        double cash;
    } person[100];

public:
    Bank() { total = 0; }
    void choice();
    void person_Data();
    void show();
    void update();
    void search();
    void transaction();
    void del();
};
int main() {
    Bank b;
    b.choice();

    return 0;
}
void Bank::choice() {
    char ch;
    while (1) {
        cout << "\n\nPress..!!" << endl;
        cout << "1. Create a New Account" << endl;
        cout << "2. View Customers List" << endl;
        cout << "3. Update Information of an Existing Account" << endl;
        cout << "4. Check the details of an Existing Account" << endl;
        cout << "5. For Transactions" << endl;
        cout << "6. Remove an Existing Account" << endl;
        cout << "7. Exit" << endl;
        cin >> ch;
        switch (ch) {
        case '1':
            Bank::person_Data();
            break;
        case '2':
            Bank::show();
            break;

        case '3':
            Bank::update();
            break;
        case '4':
            Bank::search();
            break;
        case '5':
            Bank::transaction();
            break;
        case '6':
            Bank::del();
            break;
        case '7':
            exit(0);
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}
void Bank::person_Data() {
    cout << "Enter the data of person " << total + 1 << endl;

    cin.ignore(); // Clears any leftover newline characters

    cout << "Enter name: ";
    getline(cin, person[total].name); // Using getline for name

    cout << "ID: ";
    getline(cin, person[total].ID); // Using getline for ID

    cout << "Address: ";
    getline(cin, person[total].address); // Using getline for address

    cout << "Contact: ";
    getline(cin, person[total].contact); // Using getline for contact

    cout << "Total Cash: ";
    cin >> person[total].cash; // Use cin for numeric input (cash)

    cin.ignore(); // Clears the buffer after using cin

    total++;
}

void Bank::show() {
    for (int i = 0; i < total; i++) {
        cout << "Data of Person" << i + 1 << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "ID: " << person[i].ID << endl;
        cout << "Address: " << person[i].address << endl;
        cout << "Contact: " << person[i].contact << endl;
        cout << "Cash: " << person[i].cash << endl;
    }
}
void Bank::update() {
    cout << "Enter ID of the person whose data you want to update: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            found = true;
            cout << "Previous data of person " << i + 1 << ":\n";
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;

            cout << "\nEnter new data" << endl;
            cin.ignore(); // Clears the buffer

            cout << "Enter name: ";
            getline(cin, person[i].name);

            cout << "ID: ";
            getline(cin, person[i].ID);

            cout << "Address: ";
            getline(cin, person[i].address);

            cout << "Contact: ";
            getline(cin, person[i].contact);

            cout << "Total Cash: ";
            cin >> person[i].cash;

            break;
        }
    }
    if (!found) {
        cout << "No such record found with ID: " << id << endl;
    }
}

void Bank::search() {
    cout << "Enter Id of person whose data you want to search " << endl;
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;
            break;
        }
        if (i == total - 1) {
            cout << "No such record found" << endl;
        }
    }
}
void Bank::transaction() {
    int cash;
    char ch;
    cout << "Enter id of person whose data you want to do transactions" << endl;
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "\nExisting  Cash: " << person[i].cash << endl;
            cout << "Press 1 to deposit" << endl;
            cout << "Press 2 to withdraw" << endl;
            cin >> ch;
            switch (ch) {
            case '1':
                cout << "How much cash you want to deposit" << endl;
                cin >> cash;
                person[i].cash += cash;
                cout << "Your new cash is" << person[i].cash << endl;
                break;
            case '2':
            back:
                cout << "How much cash you want to withdraw" << endl;
                cin >> cash;
                if (cash > person[i].cash) {
                    cout << "Your existing cash is just" << person[i].cash
                         << endl;
                    goto back;
                }
                person[i].cash -= cash;
                cout << "Your new cash is " << person[i].cash << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
            }
            break;
        }
        if (i == total - 1) {
            cout << "No such record found" << endl;
        }
    }
}
void Bank::del() {
    char ch;
    cout << "Press 1 to remove specific record" << endl;
    cout << "Press 2 to remove full record" << endl;
    cin >> ch;
    switch (ch) {
    case '1':
        cout << "Enter id of person whose data you want to delete" << endl;
        cin >> id;
        for (int i = 0; i < total; i++) {
            if (id == person[i].ID) {
                for (int j = i; j < total; j++) {
                    person[j].name = person[j + 1].name;
                    person[j].ID = person[j + 1].ID;
                    person[j].address = person[j + 1].address;
                    person[j].contact = person[j + 1].contact;
                    person[j].cash = person[j + 1].cash;
                    total--;
                    break;
                }
            }
            if (i == total - 1) {
                cout << "No such record found" << endl;
            }
        }
        break;
    case '2':
        total = 0;
        cout << "All records are deleted" << endl;
        break;
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}