#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Button
{
public:

    void updateMode(const string& mode)
    {
        if (mode == "Night")
        {
            cout << "Button: Switching to Night Mode visuals." << endl;
        }
        else
        {
            cout << "Button: Switching to Day Mode visuals." << endl;
        }
    }
};


class System 
{
private:
    string currentMode = "Day";
    Button button;

public:
    void changeMode(const string& newMode)
    {
        currentMode = newMode;

        cout << "System: Mode changed to " << currentMode << "." << endl;

        button.updateMode(currentMode);
    }
};

int main()
{
    System system;

    system.changeMode("Night");

    system.changeMode("Day");
    return 0;
}