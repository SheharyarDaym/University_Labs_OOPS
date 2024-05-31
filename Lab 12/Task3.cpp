#include<iostream>
using namespace std;

#define MAX_ITEMS 50

class Item{
protected:
    string itemName;
    int quantity;
    double price;
public:
    Item(string itemName="", int quantity=0, double price=0.0){
        this->itemName = itemName;
        this->price = price;
        this->quantity = quantity;
    }
    void setItemName(string itemName){
        this->itemName = itemName;
    }
    string getItemName()const{
        return itemName;
    }
    void setQuantity(int quantity){
        this->quantity = quantity;
    }
    int getQuantity(){
        return quantity;
    }
    void setPrice(double price){
        this->price = price;
    }
    double getPrice(){
        return price;
    }

    void updateQuantity(int newQuantity){
        if(newQuantity < 0){
            throw "Quantity is negative";
        }
        quantity = newQuantity;
    }

    void updatePrice(double newPrice){
        if(newPrice < 0){
            throw "Price is negative";
        }
        price = newPrice;
    }
};

class Inventory{
protected:
    Item items[MAX_ITEMS];
    int itemCount;
public:
    Inventory() : itemCount(0) {}

    void addItem(const Item& newitem){
        if(itemCount < MAX_ITEMS){
            items[itemCount] = newitem;
            itemCount++;
        }
        else{
            throw "Inventory is full";            
        }
        if(items[itemCount].getItemName() == newitem.getItemName()){
            throw "Same name already exists";
        } 
    }

    void removeItem(const string& itemName){
        for(int i=0; i<itemCount; i++){
            if(items[i].getItemName() == itemName){
                items[i].setPrice(0.0);
                items[i].setItemName("");
                items[i].setQuantity(0);
                itemCount--;
            }
            if(i == itemCount-1 && items[i].getItemName() != itemName){
                throw "Item is not found";
            }
        }
    }

    void updateItemQuantity(const string& itemName, int newQuantity){
        if(newQuantity < 0){
            throw "Quantity is negative";
        }

        for(int i=0; i<itemCount; i++){
            if(items[i].getItemName() == itemName){
                items[i].setQuantity(newQuantity);
            }

            if(i == itemCount-1 && items[i].getItemName() != itemName){
                throw "Item is not found";
            }
        }
    }

    void updateItemPrice(const string& itemName, double newPrice){
        if(newPrice < 0){
            throw "Price is negative";
        }

        for(int i=0; i<itemCount; i++){
            if(items[i].getItemName() == itemName){
                items[i].setPrice(newPrice);
            }

            if(i == itemCount-1 && items[i].getItemName() != itemName){
                throw "Item is not found";
            }
        }

    }

    Item getItem(const string& itemName){
        for(int i=0; i<itemCount; i++){
            if(items[i].getItemName() == itemName){
                return items[i];
            }
            if(i == itemCount-1 && items[i].getItemName() != itemName){
                throw "Item is not found";
            }
        }
        return items[0];
    }

    void printInventory(){
        if(itemCount == 0){
            cout << "Inventory is empty" << endl;
            return;
        }
        for(int i=0; i<itemCount; i++){
            cout << "-------------" << "Item " << i+1 << "-------------" << endl;
            cout << items[i].getItemName() << endl;
            cout << items[i].getQuantity() << endl;
            cout << items[i].getPrice() << endl << endl;
            cout << "--------------------------------------------------" << endl << endl;
        }
    }

};

class InventoryFullException : public runtime_error{
public:
    InventoryFullException() : runtime_error("Inventory is full") {}
};

class ItemNotFoundException : public runtime_error{
public:
    ItemNotFoundException(const string itemName) : runtime_error("Item'" + itemName + "'not found") {}
};

class InvalidItemOperationException : public runtime_error{
public:
    InvalidItemOperationException(const string message) : runtime_error(message) {}
};


void displayMenu(){
    cout << "\n----------Inventory Management System----------" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Update Item Quantity" << endl;
    cout << "4. Update Item Price" << endl;
    cout << "5. Search Item" << endl;
    cout << "6. Print Inventory" << endl;
    cout << "7. Exit" << endl;
}

int main(){
    Inventory inventory;


    int choice;
    string itemName;
    int quantity;
    double price;

    while(choice != 7){
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;


        switch (choice)
        {

        case 1:{
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, itemName);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            try
            {
                inventory.addItem(Item(itemName, quantity, price));
                cout << "\nItem added successfully." << endl;
            }
            catch (const exception &e)
            {
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;
        

        case 2:{
            cin.ignore();
            cout << "Enter item name to remove: ";
            getline(cin, itemName);
            try
            {
                inventory.removeItem(itemName);
                cout << "\nItem removed successfully." << endl;
            }
            catch (const exception &e)
            {
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        // Update Item Quantity
        case 3:{
            cin.ignore();
            cout << "Enter item name to update quantity: ";
            getline(cin, itemName);
            cout << "Enter new quantity: ";
            cin >> quantity;
            try{
                inventory.updateItemQuantity(itemName, quantity);
                cout << "\nItem quantity updated successfully." << endl;
            }
            catch (const exception &e){
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        case 4:{
            cin.ignore();
            cout << "Enter item name to update price: ";
            getline(cin, itemName);
            cout << "Enter new price: ";
            cin >> price;
            try{
                inventory.updateItemPrice(itemName, price);
                cout << "\nItem price updated successfully." << endl;
            }
            catch (const exception &e){
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        case 5:{
            cin.ignore();
            cout << "Enter item name to search: ";
            getline(cin, itemName);
            try{
                Item item = inventory.getItem(itemName);
                cout << "Item found:" << endl;
                cout << "  - Name: " << item.getItemName() << endl;
                cout << "  - Quantity: " << item.getQuantity() << endl;
                cout << "  - Price: " << item.getPrice() << " Rs" << endl;
            }
            catch (const exception &e){
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        case 6:{
            inventory.printInventory();
        }
        break;

        case 7:{

            cout << "Exiting Inventory Management System." << endl;
        }
        break;

        default:
            cout << "Invalid choice. Enter Again." << endl;
        }
    }

    return 0;
}

