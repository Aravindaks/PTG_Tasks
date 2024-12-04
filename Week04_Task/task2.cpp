#include <iostream> 

#include <vector> 

#include <set> 

#include <string> 

#include <algorithm> 

using namespace std; 

  

int main() 

{ 

    vector<string> dynamic; 

    set<string> stat_wed; 

    vector<string> combined; 

     

    dynamic.push_back("Speedometer"); 

    dynamic.emplace_back("Tachometer"); 

     

    stat_wed.insert("Logo"); 

    stat_wed.insert("WarningLights"); 

     

    cout<<"Dynamic widgets are :\n"; 

    for(auto it : dynamic){ 

        cout<<it<<endl; 

    } 

    cout<<endl; 

     

    auto it = stat_wed.find("WarningLights"); 

    if(it != stat_wed.end()){ 

        cout<<"The specific element is found : "<<*it<<endl; 

    } 

    else{ 

        cout<<"The specific element is not found.\n"; 

    } 

    cout<<endl; 

     

    combined.resize(dynamic.size()+stat_wed.size()); 

     

    copy(dynamic.begin(),dynamic.end(),combined.begin()); 

    copy(stat_wed.begin(),stat_wed.end(),combined.begin()+dynamic.size()); 

     

    cout<<"Outputs of combined wedgets: \n"; 

    for(auto it1 : combined){ 

        cout<<it1<<endl; 

    } 

    cout<<endl; 

     

    string find_wed; 

    cout<<"enter specific wedget to find from above wedgets: \n"; 

    cin>>find_wed; 

     

    auto found_wed= find(combined.begin(),combined.end(),find_wed); 

     

    if(found_wed != combined.end()){ 

        cout<<"The entered wedget is found i.e: "<<*found_wed<<" At index: "<<found_wed-combined.begin()<<endl; 

    } 

    else{ 

        cout<<"The entered wedget is not found.\n"; 

    } 

     

    return 0; 

} 