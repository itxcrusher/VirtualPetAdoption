#include "../../Production/Crusher.h"
#include "global.h"
#include "pet.h"
#include "player.h"
#include "simulation.h"
#include "account.h"
#include "launcher.h"

void owner();
void player();

int main() {
    bool greet = true;
    startPetsCollection();
    startPlayersDatabase(); // Hassaan, 123
    startOwnerData();   // Hassaan, 123

    while (true) {
        if (greet || logout) {
            welcome("Virtual Pet Care Simulation");
            separator(100);
            cout << "| A virtual pet care simulation where players can adopt and take care of virtual pets!" << endl;
            cout << "| Owner can turn on/off the simulation and make any necessary changes to the data at anytime!" << endl;
            cout << "| Players can create accounts in a simulation, adopt pets and take care of them!" << endl;
            separator(100);
            greet = false;
            logout = false;
        }
        heading("Please Choose your Role to continue:");
        cout << "\n1 = Owner\n2 = Player\n0 = Exit" << endl;
        cout << "Choice Number: ";
        cin >> choiceNo;

        switch (choiceNo) {
        case 1:
            owner();
            break;
        case 2:
            player();
            break;
        case 0:
            putchar('\n');
            farewell();
            putchar('\n');
            return 0;
        default:
            cout << "\nInvalid choice number!" << endl;
        }
        if (logout) {
            system("pause");
            system("cls");
        }
    }
}

void owner() {
    isCanceled = false;
    accountType = "Owner";
    text("Authentication Required, Please enter your credentials...");
    
    enterID(totalOwners, accountType);

    if (!isCanceled) {
        do {
            invalid = false;
            cout << "\nYou can type 'cancel' instead of password to cancel the SignIn Process!" << endl;
            hiddenPassword();
            if (password == "cancel") {
                isCanceled = true;
                break;
            }
            else {
                isAuth = authStatic(ID, ownerData, password);

                if (isAuth) {
                    separator(100);
                    welcomeMsg = "Welcome to the Dashboard " + ownerData[ID][0] + "!";
                    do {
                        heading(welcomeMsg);
                        logout = false;
                        cout << "\nPlease choose your action number from the following list:" << endl;
                        cout << "1- Mannage Pets" << endl;
                        cout << "2- Mannage Players" << endl;
                        cout << "3- Manage Virtual Simulation" << endl;
                        cout << "4- Mannage your Account" << endl;
                        cout << "0- Logout" << endl;
                        cout << "Action Number: ";
                        cin >> actionNo;
                        switch (actionNo) {
                        case 1:
                            petManagement();
                            break;
                        case 2:
                            playerManagement();
                            break;
                        case 3:
                            simulationManagement();
                            break;
                        case 4:
                            accountManagement();
                            break;
                        case 0:
                            doLogout();
                            break;
                        default:
                            cout << "\nPlease enter a valid choice number!" << endl;
                        }
                    } while (!logout);
                }
                else {
                    cout << "\nInvalid Password, Please try again!" << endl;
                    invalid = true;
                }
            }
        } while (invalid);
    }
    if(isCanceled){
        putchar('\n');
        separator(100);
        cout << "\nSignIn Process cancelled by the user!" << endl;
        cout << "Redirecting back to the Home page...Please wait..." << endl;
    }
}

void player() {
    totalAdoptedPets = 0;
    accountType = "Player";
    isAuth = false;
    do {
        goBack = false;
        text("A Simulation Player Account is required to continue, Please choose one of the following:");
        putchar('\n');
        cout << "1- Sign Up/Create a new Account" << endl;
        cout << "2- Sign In/Log In to an existing Account" << endl;
        cout << "0- Go back to Switch Roles" << endl;
        cout << "Choice Number: ";
        cin >> choiceNo;

        switch (choiceNo) {
            case 1:
                signUp();
                if (isCanceled) {
                    cout << "\nAccount creation process canceled by the user!" << endl;
                    cout << "Redirecting back to the menu...Please wait..." << endl;
                    break; 
                }
                else { 
                    cout << "\nRedirecting to the LogIn screen...Please wait..." << endl;
                }
            case 2:
                signIn();
                if (isCanceled) {
                    cout << "\nSignIn Process cancelled by the user!" << endl;
                }
                if (isAuth) {
                    cout << "\nAuthentication Successful!" << endl;
                    cout << "Accessing Data and Logging in...Please wait..." << endl;
                }
                else {
                    cout << "Redirecting back to the menu...Please wait..." << endl;
                }
                break;
            case 0:
                goBack = true;
                putchar('\n');
                separator(100);
                continue;
                break;
            default:
                cout << "\nPlease enter a valid choice number!" << endl;
        }
    } while (!goBack && !isAuth);

    if (isAuth) {
        separator(100);
        welcomeMsg = "Welcome to the Dashboard " + playersDatabase[ID][0] + "!";
        do {
            heading(welcomeMsg);
            logout = false;
            cout << "\nPlease choose your action number from the following list:" << endl;
            cout << "1- Launch Simulation" << endl;
            cout << "2- Customize Simulation Settings" << endl;
            cout << "3- Change Account Settings" << endl;
            cout << "0- Logout" << endl;
            cout << "Action Number: ";
            cin >> actionNo;
            switch (actionNo) {
            case 1:
                launcher();
                break;
            case 2:
                customizeSimulation();
                break;
            case 3:
                accountManagement();
                break;
            case 0:
                doLogout();
                break;
            default:
                cout << "\nPlease enter a valid choice number!" << endl;
            }
        } while (!logout);
    }
}