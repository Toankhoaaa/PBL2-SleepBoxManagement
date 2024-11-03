#include <string>
using namespace std;
class login
{
    string username;
    string password;
public:
    login();
    ~login();
    int authenticate(string, string);
};