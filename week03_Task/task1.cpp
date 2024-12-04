#include <iostream> 

#include <vector> 

#include <string> 

using namespace std; 

  

struct MenuNode 

{ 

    string data;                 

    vector<MenuNode *> children;  

  

    MenuNode(string itemData) 

    { 

        data = itemData; 

    } 

  

    void addChild(MenuNode *child) 

    { 

        children.push_back(child); 

    } 

}; 

  

void displayMenu(MenuNode *menu, int level = 0) 

{ 

    cout << "== " << menu->data << " ==\n"; 

    if (menu->children.empty()) 

    { 

        cout << "No submenus available.\n"; 

    } 

    else 

    { 

        for (int i = 0; i < menu->children.size(); i++) 

        { 

            cout << i + 1 << ". " << menu->children[i]->data << endl; 

        } 

    } 

} 

  

void navigateMenu(MenuNode *menu) 

{ 

    int choice; 

    while (true) 

    { 

        displayMenu(menu);  

        cout << "Choose an option (enter 0 to go back): "; 

        cin >> choice; 

  

      

        if (choice == 0) 

        { 

            cout << "Going back...\n"; 

            break; 

        } 

  

        if (choice < 1 || choice > menu->children.size()) 

        { 

            cout << "Invalid choice, please try again.\n"; 

        } 

        else 

        { 

            

            cout << "Navigating to " << menu->children[choice - 1]->data << "...\n"; 

            navigateMenu(menu->children[choice - 1]); 

        } 

    } 

} 

  

int main() 

{ 

    

    MenuNode *root = new MenuNode("Main Menu"); 

  

    MenuNode *submenu1 = new MenuNode("Settings"); 

    MenuNode *submenu2 = new MenuNode("Media"); 

  

    root->addChild(submenu1); 

    root->addChild(submenu2); 

  

    MenuNode *submenu1_1 = new MenuNode("Display Settings"); 

    MenuNode *submenu1_2 = new MenuNode("Audio Settings"); 

    submenu1->addChild(submenu1_1); 

    submenu1->addChild(submenu1_2); 

  

    MenuNode *submenu2_1 = new MenuNode("Radio"); 

    MenuNode *submenu2_2 = new MenuNode("Bluetooth Audio"); 

    submenu2->addChild(submenu2_1); 

    submenu2->addChild(submenu2_2); 

    

    cout << "Welcome to the Menu System!\n"; 

    navigateMenu(root); 

  

    delete root; 

    delete submenu1; 

    delete submenu2; 

    delete submenu1_1; 

    delete submenu1_2; 

    delete submenu2_1; 

  

    return 0; 

} 