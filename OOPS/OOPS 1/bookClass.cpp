#include<iostream>
using namespace std;

class book {
    private:
        string name;
        int price;
        int pages;

    public:

        void setName(string n) {
            name = n;
        };

        void setPrice(int p) {
            price = p;
        }

        void setPages(int p) {
            pages = p;
        }

        string getName() {
            return name;
        };

        int getPrice() {
            return price;
        }

        int getPages() {
            return pages;
        }

        int countBooks(int p) {
            if(pages < p) return 1;
            else return 0;
        }

        bool isBookPresent(string n) {
            if(name == n) return true;
            else return false;
        }
};

int main() {
    book harryPotter;
    harryPotter.setName("Harry potter");
    harryPotter.setPages(584);
    harryPotter.setPrice(4590);

    cout<<harryPotter.countBooks(600)<<endl;
    cout<<harryPotter.isBookPresent("Harry potter")<<endl;

}