#ifndef global_h
#define global_h

//                              ########### Global Declarations and Functions ###########

// Declare Simulation Variables
bool simulationStatus = true, simulationUpdate = false, accessSimulation = false;
// Declare Owners Database
const int totalOwners = 2, ownerAttributes = 2; // Name, Password
string ownerData[totalOwners][ownerAttributes] = {};
string accountType;
// Declare Players Database
int totalPlayers = 0;
const int playerAttributes = 3; // Name, Password, Status
vector<array<string, playerAttributes>> playersDatabase;
array<string, playerAttributes> playerData = {};
// Declare Pets Collection
int maxPets = 5, totalPets = 3;
const int petAttributes = 5;    // Name, Species, Condition, Mood, Status
string** petsCollection = new string * [maxPets];
string** increasedPetsCollection;
// Declare Pets of Players
vector<int> playersPetsDatabase;
int playerPets = 0;
int totalAdoptedPets = 0, currentAdoptedPets = 0;
vector<array<string, petAttributes>> adoptedPets;
array<string, petAttributes> petData = {};


// LogIn ID for both Owner and Player
void enterID(int total, string type) {
    do {
        invalid = false;
        cout << "\nYou can enter -1 instead of ID to cancel the SignIn Process!" << endl;
        cout << "ID: ";
        cin >> ID;
        if (ID == -1) {
            isCanceled = true;
            break;
        }
        if (ID < 0 || ID >= total) {
            cout << "\nNo "<<type<<" Account with Account ID: " << ID << ", found in the Database, Please enter a valid " << type << " Account ID!" << endl;
            invalid = true;
        }
    } while (invalid);
}

// Retrieve Data from Database
string getData(int attribute) {
    if (accountType == "Owner") {
        return ownerData[ID][attribute];
    }
    else {
        return playersDatabase[ID][attribute];
    }
}

// Update Data in Database
void setData(int attribute, string value) {
    if (accountType == "Owner") {
        ownerData[ID][attribute] = value;
    }
    else {
        playersDatabase[ID][attribute] = value;
    }
}

#endif