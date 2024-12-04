#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Button
{
   int id;
   string name;
   Button(int id, const string& name) : id(id), name(name) {}

   bool operator<(const Button& other) const
   {
       return id < other.id;
   }
   bool operator==(const Button& other) const
   {
       return id == other.id;
   }
};

void printButtons(const vector<Button>& buttons)
{
   for (const auto& button : buttons)
   {
       cout << "ID: " << button.id << ", Name: " << button.name << endl;
   }
}

int main()
{
   vector<Button> buttons1 = { {1, "Button1"}, {3, "Button3"}, {5, "Button5"} };
   vector<Button> buttons2 = { {2, "Button2"}, {4, "Button4"}, {6, "Button6"} };

   sort(buttons1.begin(), buttons1.end());
   sort(buttons2.begin(), buttons2.end());

   cout << "Buttons in Order 1:" << endl;
   printButtons(buttons1);

   cout << "Buttons in Order 2:" << endl;
   printButtons(buttons2);

   vector<Button> combinedButtons;
   combinedButtons.reserve(buttons1.size() + buttons2.size());
   merge(buttons1.begin(), buttons1.end(), buttons2.begin(), buttons2.end(), back_inserter(combinedButtons));

   cout << "Combined Buttons:" << endl;
   printButtons(combinedButtons);

   int searchId = 4;
   auto foundButton = find(combinedButtons.begin(), combinedButtons.end(), Button(searchId, ""));

   if (foundButton != combinedButtons.end())
   {
       cout << "Found button with ID " << searchId << ":" << endl;
       cout << "ID: " << foundButton->id << ", Name: " << foundButton->name << endl;
   }
   else
   {
       cout << "Button with ID " << searchId << " not found." << endl;
   }
   return 0;
}