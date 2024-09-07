#include<iostream>
using namespace std;

const int MAX = 100;
int id[MAX];
string brand[MAX];
string name[MAX];
double wholesale[MAX];
double salePrice[MAX];
int stock[MAX];
int used = 0;

//Hardcoding in products
void currentProducts()
{
    //Kraft Mac and Cheese
    id[0] = 1;
    brand[0] = "Kraft";
    name[0] = "Mac&Cheese";
    wholesale[0] = 3.99;
    salePrice[0] = 4.99;
    stock[0] = 150;
    used += 1;
    
    //Chips Ahoy Cookies
    id[1] = 2;
    brand[1] = "ChipsAhoy";
    name[1] = "Cookies";
    wholesale[1] = 6.59;
    salePrice[1] = 7.99;
    stock[1] = 200;
    used+= 1;    
}

//Adding a new product to the inventory 
void newProduct()
{
    if (used + 1 > 100)
    {
        cout << "You have reached the limit for products";
    }
    else
    {
        cout << "Enter brand name: ";
        cin >> brand[used];

        cout << "Enter product name: ";
        cin >> name[used];

        cout << "Enter wholesale price: ";
        cin >> wholesale[used];

        cout << "Enter sale price: ";
        cin >> salePrice[used];

        cout << "Enter stock of product: ";
        cin >> stock[used];

        id[used] = id[used - 1]+ 1;
    }
}

//Check to see if ID is valid
bool validID(int theID)
{
    bool validity = false;

    for (int i = 0; i < used; i++)
    {
        if (id[i] == theID)
        {
            validity = true;
        }
    }

    return validity;
}

//Searching for index of a product based on ID
int searchID(int idToSearch)
{
    int finalId;
    for (int i = 0; i < used; i++)
    {
        if (id[i] == idToSearch)
        {
            finalId = i;
        }
    }

    return finalId;
}

// Remove a product based on its ID
void removeProduct()
{
    int idToRemove; 

    cout << "Enter ID of Product to Remove it: ";
    cin >> idToRemove;

    while(1)
    {
        if (validID(idToRemove) == false)
        {
            cout << "Try again. Enter a valid ID: ";
            cin >> idToRemove;
        }
        else
        {
            break;
        }
    }

    cout << "The brand is " << brand[idToRemove - 1] << endl;
    cout << "The product is " << name[idToRemove - 1] << endl;

    for (int i = searchID(idToRemove) + 1; i < used; i++)
    {
        id[i - 1] = id[i];
        brand[i - 1] = brand[i];
        name[i - 1] = name[i];
        wholesale[i - 1] = wholesale[i];
        salePrice[i - 1] = salePrice[i];
        stock[i - 1] = stock[i];
    }
    used -= 1;

    cout << "Removal was successful" << endl;
}

// Update Wholesale price
void updateWholesale()
{
    int idToUpdateW;
    double newWholesale;

    cout << "Enter ID of product to update its wholesale price: ";
    cin >> idToUpdateW;

    while(1)
    {
        if (validID(idToUpdateW) == false)
        {
            cout << "Try again. Enter a valid ID: ";
            cin >> idToUpdateW;
        }
        else
        {
            break;
        }
    }

    int theID = searchID(idToUpdateW);

    cout << "The brand is " << brand[theID] << endl;
    cout << "The product is " << name[theID] << endl;
    cout << "The current wholesale price is " << wholesale[theID] << endl;
    
    cout << "Enter new wholesale price for product: ";
    cin >> newWholesale;
    wholesale[theID] = newWholesale;
}

// Update sale price
void updateSale()
{
    int idToUpdateSale;
    double newSale;

    cout << "Enter ID of product to update its sale price: ";
    cin >> idToUpdateSale;

    while(1)
    {
        if (validID(idToUpdateSale) == false)
        {
            cout << "Try again. Enter a valid ID: ";
            cin >> idToUpdateSale;
        }
        else
        {
            break;
        }
    }

    int theID = searchID(idToUpdateSale);

    cout << "The brand is " << brand[theID] << endl;
    cout << "The product is " << name[theID] << endl;
    cout << "The current sale price is " << salePrice[theID] << endl;

    cout << "Enter new sale price for product: ";
    cin >> newSale;
    salePrice[theID] = newSale;
}

// Update stock number of a product
void updateStock()
{
    int idToUpdateStock;
    int newStock;

    cout << "Enter ID of product to update its stock price: ";
    cin >> idToUpdateStock;

    while(1)
    {
        if (validID(idToUpdateStock) == false)
        {
            cout << "Try again. Enter a valid ID: ";
            cin >> idToUpdateStock;
        }
        else
        {
            break;
        }
    }

    int theID = searchID(idToUpdateStock);

    cout << "The brand is " << brand[theID] << endl;
    cout << "The product is " << name[theID] << endl;
    cout << "The current stock is " << stock[theID] << endl;

    cout << "Enter new stock price for product: ";
    cin >> newStock;
    stock[theID] = newStock;
}

// Check to see if a product is low in stock
void lowInStock()
{
    cout << "Products low in stock: " << endl;
    
    cout << "ID: "; 
    for (int i = 0; i < used; i++)
    {
        if (stock[i] < 10)
        {
            cout << id[i] << " ";
        }
    }
    cout << "\n";

    cout << "Brand: ";
    for (int i = 0; i < used; i++)
    {
        if (stock[i] < 10)
        {
            cout << brand[i] << " ";
        }
    }
    cout << "\n";

    cout << "Product: ";
    for (int i = 0; i < used; i++)
    {
        if (stock[i] < 10)
        {
            cout << name[i] << " ";
        }
    }
    cout << "\n";

    cout << "Stock: ";
    for (int i = 0; i < used; i++)
    {
        if (stock[i] < 10)
        {
            cout << stock[i] << " ";
        }
    }
    cout << "\n";
}

// Displays each product and its brand, wholesale price, sale price, and stock
void display()
{
    cout << "\n";
    
    cout << "ID: "; 
    for (int i = 0; i < used; i++)
    {
        cout << id[i] << ", ";
    }
    cout << "\n";

    cout << "Brand: ";
    for (int i = 0; i < used; i++)
    {
        cout << brand[i] << ", ";
    }
    cout << "\n";

    cout << "Product: ";
    for (int i = 0; i < used; i++)
    {
        cout << name[i] << ", ";
    }
    cout << "\n";

    cout << "Wholesale Price: ";
    for (int i = 0; i < used; i++)
    {
        cout << wholesale[i] << ", ";
    }
    cout << "\n";

    cout << "Sale Price: ";
    for (int i = 0; i < used; i++)
    {
        cout << salePrice[i] << ", ";
    }
    cout << "\n";

    cout << "Stock: ";
    for (int i = 0; i < used; i++)
    {
        cout << stock[i] << ", ";
    }

    cout << "\n";
}

// Calculates total profits of all products and stock
void profits()
{
    double sum;
    for (int i = 0; i < used; i ++)
    {
        sum += (salePrice[i] * stock[i]);
    }
    cout << "Sum of the total profits is " << sum << endl;
}

int main()
{
    currentProducts();
    
    cout << "*** Grocery Product Managment System ***" << endl;
    
    while(1)
    {
        int menuOption;
        cout << "\n";
        cout << "*** MENU ***" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Remove a product" << endl;
        cout << "3. Update a product's wholesale price" << endl;
        cout << "4. Update a product's sale price" << endl;
        cout << "5. Update a product's stock" << endl;
        cout << "6. Check if a product is low in stock (<10)" << endl;    
        cout << "7. Display all products" << endl;
        cout << "8. Calculate the total profit of the products" << endl;
        cout << "9. Quit" << endl;
        
        cout << "Select an option: ";
        cin >> menuOption;

        if (menuOption == 9)
        {
            cout << "Goodbye";
            break;
        }

        switch (menuOption)
        {
            case 1:
                newProduct();
                used += 1;
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateWholesale();
                break;
            case 4:
                updateSale();
                break;
            case 5:
                updateStock();
                break;
            case 6:
                lowInStock();
                break;
            case 7:
                display();
                break;
            case 8:
                profits();
                break;
        }
    }
}