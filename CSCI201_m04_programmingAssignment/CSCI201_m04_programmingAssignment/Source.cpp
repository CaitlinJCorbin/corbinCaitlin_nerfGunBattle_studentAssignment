//////////////////////////////////////////
//	Caitlin J. Corbin					//
//	M04 Programming Assignment			//
//	"Simulate a Nerf Gun Battle"		//
//////////////////////////////////////////

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class nerfGun {
protected:
	string model;
	int range;
	int capacity;
	int darts;
public:

	nerfGun(string Model, int Range, int Count) {

		this->model = Model;
		this->range = Range;

		if (Count > 144) {
			cout << "Trying to store with capacity > 144" << endl;
			cout << "Capacity should be <= 144" << endl;
			cout << "Default capacity sets to 144" << endl << endl;
			capacity = 144;
		}
		else capacity = Count;

		darts = capacity;
	};

	// Getters //
	string getModel() {
		return model;
	};

	int getRange() {
		return range;
	};

	int getCapacity() {
		return capacity;
	};

	int getDartCount() {
		return darts;
	};

	// Setters //
	void setDartCount(int x) {
		darts = x;
	};

	void fire();
	void reload(int quantity);

	friend ostream& operator<<(ostream& output, const nerfGun& gun);			// Declaration

	nerfGun& operator+=(const nerfGun& gun) {									// Overloaded +=
		this->darts += gun.darts;
		return *this;
	};
		
	bool operator==(const nerfGun& other) const									// Overloaded ==
	{
		return darts == other.darts;
	}

	int operator>(const nerfGun& other) const									// Overloaded >
	{
		return darts > other.darts;
	}

	nerfGun& operator--(int) {													// Overloaded --
		--darts;
		return *this;
	}
};

void nerfGun::fire() {															// Fire function
	darts--;
}

void nerfGun::reload(int quantity) {											// Reload function				
	int dart = getDartCount() + quantity;
	if (dart <= getCapacity()) {
		darts = dart;
	}	else
		darts = getCapacity();
	cout << "Too many darts" << endl;
};

void compare(int compare1, int compare2) {										// Compare function
	if (compare1 > compare2) { cout << compare1 << " more darts than " << compare2; }
	else cout << compare2 << " more darts than " << compare1;
};

//// ostream& operator--(ostream& g, nerfGun& gun) { };								// Overloaded --



ostream& operator<<(ostream& g, nerfGun& gun) {										// Overloaded << 
	cout << " Model: " << gun.getModel() << endl;
	cout << " Range: " << gun.getRange() << endl;
	cout << " Capacity: " << gun.getCapacity() << endl;
	cout << " Darts: " << gun.getDartCount() << endl;
	return g;
};

int main() {

	nerfGun gun1( "Sky Shooter", 50, 144);											// My objects
	nerfGun gun2( "Space Rocket", 40, 144);
	nerfGun gun3( "Snow Blaster", 30, 144);
	nerfGun gun4( "Water pistol", 20, 144);

	vector<nerfGun> myGun;															// My vector
	myGun.push_back(gun1);
	myGun.push_back(gun2);
	myGun.push_back(gun3);
	myGun.push_back(gun4);

	for (int i = 0; i < myGun.size(); i++) {										// Printing data
		cout << myGun[i] << endl;
	};

	cout << gun1.getModel() << " is firing!";										// Gun 1 firing
	while (gun1.getDartCount() > 20) {
		gun1--;
	};
	cout << endl; cout << gun1.getModel() << " now has " << gun1.getDartCount() << " darts" << endl << endl;

	cout << gun4.getModel() << " is firing!";										// Gun 4 firing
	while (gun4.getDartCount() > 5) {
		gun4--;
	};
	cout << endl; cout << gun4.getModel() << " now has " << gun4.getDartCount() << " darts" << endl;				

	cout << endl << "Current stats of 1 and 2: " << gun1.getDartCount() << " " << gun2.getDartCount() << endl;		// Add gun 2 darts to gun 1
	cout << "Adding " << gun2.getModel() << " darts to " << gun1.getModel() << endl;
	gun1 += gun2;
	cout << "Current stats of 1 and 2: " << gun1.getDartCount() << " " << gun2.getDartCount() << endl << endl;


	if (gun2 > gun3) { cout << gun2.getModel() << " has more darts than " << gun3.getModel(); }						// Comparing dart count
	else cout << gun3.getModel() << " has more darts than " << gun2.getModel();



	system("pause>0");

}