#ifndef account_h
#define account_h

                        // #################### Owner Database Initialization and Accounts Management #################### //

// Initialize Owner Account Data
void startOwnerData(){
    // Owner # 1
    ownerData[0][0] = "Hassaan";
    ownerData[0][1] = "123";
    // Owner # 2
    ownerData[1][0] = "Owner";
    ownerData[1][1] = "Owner";
}

// Manage Account
void accountManagement(){
    do{
        heading("Account Management");
        goBack = false;
        cout<<"\nPlease choose your action number from the following list:"<<endl;
        cout<<"1- Check your Account Details"<<endl;
        cout<<"2- Update your Name"<<endl;
        cout<<"3- Update your Password"<<endl;
        cout<<"0- Navigate/Go Back"<<endl;
        cin>>actionNo;
        switch(actionNo){
            case 1:
                subHeading("Account Details");
                putchar('\n');
                cout<<"Account Type: "<<accountType<<endl;
                cout<<"Account Name: "<< getData(0) <<endl;
                cout<<"Account Password: "<< getData(1) <<endl;
                separator(50);
                break;
            case 2:
                subHeading("Update name");
                putchar('\n');
                cout<<"Please enter your new account Name: ";
                cin>>name;
                setData(0, name);
                cout<<"\nYour account name has been updated successfully!"<<endl;
                separator(50);
                break;
            case 3:
                subHeading("Update Password");
                putchar('\n');
                cout<<"Please enter your new account Password: ";
                hiddenPassword();
                setData(1, password);
                cout<<"\nYour account password has been updated successfully!"<<endl;
                separator(50);
                break;
            case 0:
                goBack = true;
                putchar('\n');
                separator(100);
                break;
            default:
                cout<<"\nPlease enter a valid choice number!\n"<<endl;
        }
    }while(!goBack);
}

                        // #################### Players Account SignUp and LogIn #################### //

// Sign Up
void signUp(){
    heading("Sign Up");
    isCanceled = false;

    cout<<"\nPlease enter the following details to create a new simulation player account:"<<endl;
    cout << "You can type 'cancel' instead of Name or Password to cancel the account creation process!" << endl;
    cout<<"Name: ";
    cin>>playerData[0];

    if (playerData[0] != "cancel") {
        hiddenPassword();
        if (password != "cancel") {
            playerData[1] = password;
            playersDatabase.push_back(playerData);
            playerPets = 1;
            playersPetsDatabase.push_back(playerPets);
            putchar('\n');
            cout<<"\nA new Player Account created Successfully!"<<endl;
            cout<<"Your account ID: "<<totalPlayers<<endl;
            cout<<"Please note that you will need Account ID to Log back into your account later!"<<endl;
            totalPlayers++;
        } else { isCanceled = true; }
    } else { isCanceled = true; }
    separator(100);
}

// Sign In
void signIn(){
    heading("Sign In");
    do{
        isCanceled = false;
        text("Authentication Required, Please enter your credentials...");
        
        enterID(totalPlayers, accountType);

        if (!isCanceled) {
            //invalid = false;
            cout << "\nYou can type 'cancel' instead of password to cancel the SignIn Process!" << endl;
            hiddenPassword();
            if (password == "cancel") {
                isCanceled = true;
                //break;
            }
            else {
                isAuth = authDynamic(ID, playersDatabase, password);

                if (isAuth) {
                    accessSimulation = true;
                }
                else {
                    cout << "\nIncorrect Password, Please try again!" << endl;
                }
            }
        }
    }while(!isCanceled && !isAuth);
    putchar('\n');
    separator(100);
}

#endif