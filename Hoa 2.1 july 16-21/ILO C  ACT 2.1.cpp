#include <iostream>
#include <string>

class fruits {
private:
    std::string frtnme; //stores the fruit name
    double itmprc; //stores the item price
    int itmqt;//stores the quantity

public:
    // the constructor
    fruits(std::string name = "Unknown Item", double price = 0.0, int qt = 0) {//provided na default values if no arguments are passed
        frtnme = std::move(name); //to avoid unecessary copy ng name
        itmprc = price;
        itmqt = qt;
        std::cout << "Constructor was Called " << frtnme << std::endl; //confirming na constructor is working
    }
    //destructor
    ~fruits() {
        std::cout << "Destructor was Called " << frtnme << std::endl;//confirming that object was destroyed
    }
    //copy constructor
    fruits(const fruits &copyitem) {
        std::cout << "ITEM COPY Constructor was Called" << std::endl;
        frtnme = copyitem.frtnme; //copying the name
        itmprc = copyitem.itmprc; //copying the price
        itmqt = copyitem.itmqt; //copying the quantity
    }
    //copy assignment operator
    fruits& operator=(const fruits &copyitem) {
        std::cout << "Copy Assignment Constructor was called" << std::endl;
        if (this != &copyitem) { // prevention ng object to be copied to itself
            frtnme = copyitem.frtnme;
            itmprc = copyitem.itmprc;
            itmqt = copyitem.itmqt;
        }
        return *this; //returns the current objects
    }

    // Getters(reading only from the privates)(returns the names, price, and quantity)
    std::string getName() const { return frtnme; }
    double getPrice() const { return itmprc; }
    int getQty() const { return itmqt; }

    // Calculate Sum
    double calculateSum() const {
        return itmprc * itmqt; //price times quantity = total price for that
    }

    // Display details
    void deteyls() const {
        std::cout << "[Fruit] " << frtnme << " | PHP " << itmprc<< " x " << itmqt<< " = PHP " << calculateSum() << std::endl;
    }
};

class vegetables {
private:
    std::string vegnme; //stores the vegetable name
    double itmprc; //stores the price
    int itmqt; //stores the quantity

public:
    //constructor
    vegetables(std::string name = "Unknown Item", double price = 0.0, int qt = 0) {
        vegnme = std::move(name);
        itmprc = price;
        itmqt = qt;
        std::cout << "Constructor was Called " << vegnme << std::endl;
    }
    //destructor
    ~vegetables() {
        std::cout << "Destructor was Called " << vegnme << std::endl;
    }
//copy constructor
    vegetables(const vegetables &copyitem) {
        std::cout << "ITEM COPY Constructor was Called" << std::endl;
        vegnme = copyitem.vegnme;
        itmprc = copyitem.itmprc;
        itmqt = copyitem.itmqt;
    }
// copy assignment constructor
    vegetables& operator=(const vegetables &copyitem) {
        std::cout << "Copy Assignment Constructor was called" << std::endl;
        if (this != &copyitem) {
            vegnme = copyitem.vegnme;
            itmprc = copyitem.itmprc;
            itmqt = copyitem.itmqt;
        }
        return *this;
    }

    // Getters(returns the name, price, and quantity)
    std::string getName() const { return vegnme; }
    double getPrice() const { return itmprc; }
    int getQty() const { return itmqt; }

    // Calculate Sum
    double calculateSum() const {
        return itmprc * itmqt;
    }

    // Display details
    void deteyls() const {
        std::cout << "[Vegetable] " << vegnme << " | PHP " << itmprc<< " x " << itmqt<< " = PHP " << calculateSum() << std::endl;
    }
};

// the vegetable class was basically copy paste of the fruits, so the explanation was almost the same

// fucntion for calculating the total expenses(combi ng fruits and vege)
double Ttlsum(fruits list1[], size_t size1, vegetables* list2[], size_t size2) {
    double total = 0.0;
    for (size_t i = 0; i < size1; i++) {
        total += list1[i].calculateSum(); // adds the fruits total
    }
    for (size_t i = 0; i < size2; i++) {
        if (list2[i] != nullptr) { //to skip the deleted slots
            total += list2[i]->calculateSum(); //adds the vegetable total
        }
    }
    return total;
}
int main() {
    const size_t frtcnt = 2; //number of fruit item
    const size_t vegcnt = 2; //number of vegetable item

    fruits frtlst[frtcnt] = {//array of fruits
        fruits("Apple", 10, 7),
        fruits("Banana", 10, 8)
    };

    vegetables* veglst[vegcnt] = { //heap array para mabura si lettuce
        new vegetables("Brocoli", 60, 12),
        new vegetables("Lettuce", 50, 10)
    };


    std::cout << "\n|--Jenna's Grocery List--|" << std::endl;
    std::cout << "\nFRUITS: " << std::endl;

    for (size_t i = 0; i < frtcnt; i++) {
        frtlst[i].deteyls(); //displays all fruit items
    }

    std::cout << "\nVEGETABLES" << std::endl;
    for (size_t i = 0; i < vegcnt; i++) {
        veglst[i]->deteyls();//display all vegetable items
    }

    // Delete Lettuce or the keyword "Lettuce" need to be exact capitalization(frees the heap memory)
    for (size_t i = 0; i < vegcnt; i++) {
        if (veglst[i] != nullptr && veglst[i]->getName() == "Lettuce") {
            delete veglst[i]; //deallocate heap memory
            veglst[i] = nullptr; //setting it into a nullpointer
            break; //stops the loop once a lettuce or the lettuce was found
        }
    }

    std::cout << "\nVEGETABLES AFTER DELETION" << std::endl;
    for (size_t i = 0; i < vegcnt; i++) {
        if (veglst[i] != nullptr) {
            veglst[i]->deteyls(); //displays the remaining vegetable in the list
        }
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "     UPDATED RECEIPT     " << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\n-- FRUITS --" << std::endl; //to display again the fruits(no changes)
    for (size_t i = 0; i < frtcnt; i++) {
        frtlst[i].deteyls();
    }

    std::cout << "\n-- VEGETABLES --" << std::endl; //display the changed vegtable list
    for (size_t i = 0; i < vegcnt; i++) {
        if (veglst[i] != nullptr) {
            veglst[i]->deteyls();
        }
    }

    std::cout << "========================================" << std::endl;
    //calculate and display the updated total after the removal of lettuce
    std::cout << "UPDATED TOTAL: PHP " << Ttlsum(frtlst, frtcnt, veglst, vegcnt) << std::endl;
    std::cout << "========================================" << std::endl;

    for (size_t i = 0; i < vegcnt; i++) { // deallocation of the vegetables because it is in the heap
        if (veglst[i] != nullptr) {
            delete veglst[i];
            veglst[i] = nullptr;
        }
    }
    return 0;
}