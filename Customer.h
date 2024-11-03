#include <string>
#include "Room.h"
using namespace std;

class Customer : public Person, public Room{
    protected:
        string makh;
        string SDT;
        string MAIL;
        string MAQL;
        int datebirthday;
        int monthbirthday;
        int yearbirthday;
    public:
        Customer();
        ~Customer();
        bool KtraNV(string);
        void Input();
};