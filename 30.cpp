#include <iostream>

using std::cin;
using std::cout;

class ITEMINFO{
    private:
        int ICode;
        char Item[15];
        unsigned int Price;
        unsigned int Qty;
        int Discount;
        float Netprice;

        void __init__(){
            ICode = 0;
            Price = 0;
            Qty = 0;
            Netprice = 0;
            Discount = 0;
            strcpy(Item, "");
        }

        void FindDisc(){
            if (Qty <= 10)
                Discount = 0;
            else if (Qty <= 20)
                Discount = 15;
            else if (Qty >= 20)
                Discount = 20;
            Netprice = Price * Qty * (100-Discount) / 100;
        }

    public:
        ITEMINFO(){
            __init__();
        }

        void Buy(){
            gets(Item);
            cout << "Enter ICode : ";
            cin >> ICode;
            cin.ignore();
            cout << "Enter Item : ";
            gets(Item);
            cout << "Enter Price : ";
            cin >> Price;
            cout << "Enter Qty : ";
            cin >> Qty;
            FindDisc();
        }
    
        void ShowAll(){
            cout << "-----------------------------------------------------------------\n";
            cout << "Icode\tItem\t\tPrice\tQty\tDiscount\tNet Price\n";
            cout << "-----------------------------------------------------------------\n";
            cout << ICode << '\t' << Item << '\t' << Price << '\t' << Qty << '\t'
                 << Discount << '%' << "\t\t" << Netprice << '\n';
            cout << "-----------------------------------------------------------------\n";
        }
};

int main(){
    ITEMINFO iteminfo;
    iteminfo.Buy();
    iteminfo.ShowAll();
    return 0;
}
