#include <iostream>
#include <string>
using namespace std;

class Grocery {
protected:
    string name;
    double price;
    int quantity;

public:
    // Default Constructor
    Grocery() {
        name = "";
        price = 0;
        quantity = 0;
        cout << "GROCERY Constructor was called." << endl;
    }

    // Parameterized Constructor
    Grocery(string n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
        cout << "GROCERY Constructor was called." << endl;
    }

    // Copy Constructor
    Grocery(const Grocery& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Grocery& operator=(const Grocery& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    virtual double calculateSum() const {
        return price * quantity;
    }

    virtual void display() const = 0;

    virtual ~Grocery() {
        cout << "GROCERY Destructor was called." << endl;
    }
};

class Fruit : public Grocery {
public:
    Fruit(string n, double p, int q)
        : Grocery(n, p, q) {
        cout << "FRUIT Constructor was called." << endl;
    }

    Fruit(const Fruit& other)
        : Grocery(other) {}

    Fruit& operator=(const Fruit& other) {
        Grocery::operator=(other);
        return *this;
    }

    void display() const override {
        cout << "Fruit: " << name << endl;
        cout << "Price: PHP " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Subtotal: PHP " << calculateSum() << endl << endl;
    }

    ~Fruit() {
        cout << "FRUIT Destructor was called." << endl;
    }
};

class Vegetable : public Grocery {
public:
    Vegetable(string n, double p, int q)
        : Grocery(n, p, q) {
        cout << "VEG Constructor was called." << endl;
    }

    Vegetable(const Vegetable& other)
        : Grocery(other) {}

    Vegetable& operator=(const Vegetable& other) {
        Grocery::operator=(other);
        return *this;
    }

    void display() const override {
        cout << "Vegetable: " << name << endl;
        cout << "Price: PHP " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Subtotal: PHP " << calculateSum() << endl << endl;
    }

    ~Vegetable() {
        cout << "VEG Destructor was called." << endl;
    }
};

double TotalSum(Grocery* list[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        if (list[i] != nullptr)
            total += list[i]->calculateSum();
    }

    return total;
}

int main() {

    Grocery* GroceryList[4];

    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    cout << "\nJenna's Grocery List \n\n";

    for (int i = 0; i < 4; i++)
        GroceryList[i]->display();

    cout << "TOTAL = PHP " << TotalSum(GroceryList, 4) << endl;

    cout << "\nDeleting Lettuce..." << endl;

    delete GroceryList[3];
    GroceryList[3] = nullptr;

    cout << "\n Updated Grocery List (checking) \n\n";

    for (int i = 0; i < 4; i++) {
        if (GroceryList[i] != nullptr)
            GroceryList[i]->display();
    }

    cout << "New TOTAL = PHP " << TotalSum(GroceryList, 4) << endl;

    //
    for (int i = 0; i < 3; i++) {
        delete GroceryList[i];
        GroceryList[i] = nullptr;
    }

    return 0;
}
