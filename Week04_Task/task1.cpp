#include<iostream> 

#include<vector> 

#include <algorithm> 

using namespace std; 

 

struct Control{ 

    public: 

    int id; 

    string type; 

    string state; 

     

    Control(int id, string type, string state):id(id),type(type),state(state){} 

     

    bool operator==(const Control& other) const { 

        return id == other.id; 

    } 

    bool operator==(const string& state) const { 

        return this->state == state; 

    } 

}; 

void displayControls(const Control& control){ 

    cout << control.id << "." <<control.type << " " << control.state << endl; 

} 

  

int main() 

{ 

   vector<Control> vec; 

  

  vec.emplace_back(1,"button","visible"); 

  vec.push_back({2,"slider","invisible"}); 

  vec.emplace_back(3,"button","visible"); 

  vec.emplace_back(4,"slider","disabled"); 

  vec.emplace_back(5,"button","disabled"); 

  vec.emplace_back(6,"button","invisible"); 

  vec.emplace_back(7,"slider","invisible"); 

  vec.emplace_back(8,"slider","visible"); 

  vec.emplace_back(9,"button","invisible"); 

  vec.push_back({10,"slider","disabled"}); 

  

   for(const auto& c : vec){ 

      displayControls(c); 

   } 

    

   int findId; 

   cout<<"enter id to find specific control"<<endl; 

   cin>>findId; 

    

    auto it=find(vec.begin(),vec.end(),Control(findId, "", "")); 

     

    if(it != vec.end()){ 

       cout << "Control with ID " << findId << " found: "<<endl; 

       displayControls(*it); 

    } 

    else{ 

        cout << "Control with ID " << findId << " not found."<<endl; 

    } 

     

    auto it1= find_if(vec.begin(), vec.end(),[](const Control& con){ 

        return con.state == "invisible"; 

    }); 

     

    if(it1 != vec.end()){ 

        cout<<"first invisible Control is \n"; 

        displayControls(*it1); 

    } 

    else{ 

        cout<<"No invisible Controls are found \n"; 

    } 

  

    auto adj_state= adjacent_find(vec.begin(),vec.end(),[](const Control& x, const Control& y){ 

        return x.state == y.state; 

    }); 

    if(adj_state != vec.end()){ 

        cout<<"Two Adjacent state are : \n"; 

        cout<<adj_state->id << " & "<< adj_state->id+1<<endl; 

        displayControls(*adj_state); 

    }else{ 

        cout<<"There are no adjacent states in this Control"<<endl; 

    } 

     

    auto count_visible = count(vec.begin(), vec.end(),"visible"); 

    if(count_visible != 0){ 

        cout<<"No of visible counts are :"<<count_visible<<endl; 

    } 

    else{ 

        cout<<"There are no visible states in Controls\n"; 

    } 

     

    auto sliders_disabled= count_if(vec.begin(),vec.end(),[](const Control& con){ 

        return con.type == "slider" && con.state == "disabled"; 

    }); 

    if(sliders_disabled != 0){ 

        cout<<"The number of Controls with slider type:"<<sliders_disabled<<endl; 

    } 

    else{ 

        cout<<"There are no slider types in Control \n"; 

    } 

     

    auto equal_subranges= equal(vec.begin(),vec.begin()+4, vec.begin()+5); 

    if(equal_subranges){ 

        cout<<"The two subranges are same \n"; 

    } 

    else{ 

        cout<<"The subranges are not same \n"; 

    } 

    return 0; 

} 