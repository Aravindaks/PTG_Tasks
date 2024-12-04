#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Control
{
	int id; // Unique ID    
	string type; // "button" or "slider"
	string state; // "visible", "invisible", "disabled"
	Control() {}

	Control(int id, string type, string state)
	{
		this->id = id;
		this->type = type;
		this->state = state;
	}

	bool operator==(const Control& other) const {
		return id == other.id; // Compare by id only
	}
	bool operator==(const string& stateVal) const {
		return state == stateVal; // Compare by state only
	}
};
int main()
{
	vector<Control> controlData;

	controlData.push_back({ 1,"Button","Visible" });
	controlData.push_back({ 4,"Button","Disable" });
	controlData.push_back({ 6,"Button","Visible" });
	controlData.push_back({ 2,"Button","Invisible" });
	controlData.push_back({ 3,"Slider","Visible" });
	controlData.push_back({ 9,"Slider","Visible" });
	controlData.push_back({ 8,"Button","Invisible" });
	controlData.push_back({ 5,"Slider","Invisible" });
	controlData.push_back({ 7,"Slider","Disable" });
	controlData.push_back({ 10,"Slider","Disable" });

	for_each(controlData.begin(), controlData.end(), [](Control x)
		{
			cout << x.id << " " << x.type << " " << x.state << " " << endl;
		}
	);

	vector<Control> backupControlData(controlData.size());
	copy(controlData.begin(), controlData.end(), backupControlData.begin());

	cout << "\nBackup Data: " << endl;
	for_each(controlData.begin(), controlData.end(), [](Control x)
		{
			cout << x.id << " " << x.type << " " << x.state << " " << endl;
		}
	);
	cout << "\nModified controlData (after fill):" << endl;
	fill(controlData.begin(), controlData.end(), Control{ 0,"","Disabled" });

	//restoring values //need default constructor
	for (int i = 0; i < controlData.size(); i++)
	{
		controlData[i].id = backupControlData[i].id;
		controlData[i].type = backupControlData[i].type;
		//}

		for_each(controlData.begin(), controlData.end(), [](Control x)
			{
				cout << x.id << " " << x.type << " " << x.state << " " << endl;
			}
		);

		transform(controlData.begin(), controlData.end(), controlData.begin(), [](Control& x)
			{
				x.state = "Invisible";
				return x;
			}
		);
		cout << "\nUsing transform state changed to invisible:" << endl;
		for_each(controlData.begin(), controlData.end(), [](Control x)
			{
				cout << x.id << " " << x.type << " " << x.state << " " << endl;
			}
		);

		/*replace_if(controlData.begin(), controlData.end(), [](Control x)
			{
				return x.state == "Invisible";
			}, [](Control x)
			{
				return x.state = "Enabled";
			}
		);*/

		for_each(controlData.begin(), controlData.end(), [](Control& x)
			{
				cout << x.id << " " << x.type << " " << x.state << " " << endl;
			}
		);
	}
}