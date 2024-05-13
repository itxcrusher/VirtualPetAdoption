#ifndef player_h
#define player_h

                       // #################### Players Database Initialization and Players Management #################### //

// Initialize Players Database
void startPlayersDatabase(){
    // Player # 1
    playerData =  {"Hassaan", "123", "Active"};
    playersDatabase.push_back(playerData);
    playerPets = 1;
    playersPetsDatabase.push_back(playerPets);
    // Player # 2
    playerData =  {"Ali", "Ali", "Active"};
    playersDatabase.push_back(playerData);
    playerPets = 2;
    playersPetsDatabase.push_back(playerPets);
    // Player # 3
    playerData =  {"Hamza", "Hamza", "Active"};
    playersDatabase.push_back(playerData);
    playerPets = 1;
    playersPetsDatabase.push_back(playerPets);
    totalPlayers = 3;
}

// Manage Players
void playerManagement(){
    do{
        heading("Player management");
        goBack = false;
        cout<<"\nPlease choose your action number from the following list:"<<endl;
        cout<<"1- Get the details of all the players from the Database"<<endl;
        cout<<"2- Create a new Player account"<<endl;
        cout<<"3- Change the status of a Player's Account"<<endl;
        cout<<"0- Navigate/Go Back"<<endl;
        cin>>actionNo;
        switch(actionNo){
            case 1:
                subHeading("Our Players Database");
                putchar('\n');
                cout<<"Total Number of Players: "<<totalPlayers<<endl;
                if(totalPlayers > 0){
                    for(int i=0; i<totalPlayers; i++){
                        separator(50);
                        cout<<"Player # "<<i+1<<endl;
                        cout<<"ID: "<<i<<endl;
                        cout<<"Name: "<<playersDatabase[i][0]<<endl;
                        cout<<"Status: "<<playersDatabase[i][2]<<endl;
                        cout<<"Pets: "<<playersPetsDatabase[i]<<endl;
                    }
                }else{
                    cout<<"No Player Account found in the Database, Please add an account first!"<<endl;
                }
                separator(50);
                break;
            case 2:
                subHeading("Create new Player Account");
                putchar('\n');
                cout<<"Please enter the following details of Player # "<<totalPlayers+1<<endl;
                cout<<"Name: ";
                cin>>playerData[0];
                hiddenPassword();
                playerData[1] = password;
                playersDatabase.push_back(playerData);
                cout<<"No of Pets: ";
                cin>>playerPets;
                playersPetsDatabase.push_back(playerPets);
                putchar('\n');
                cout<<"A new Player account with an ID: "<<totalPlayers<<", and Account Status: "<<playersDatabase[totalPlayers][2]<<", has been created Successfully!"<<endl;
                totalPlayers++;
                separator(50);
                break;
            case 3:
                subHeading("Change the Status of an Account");
                putchar('\n');
                if(totalPlayers > 0){
                    int ID;
                    cout<<totalPlayers<<" Players found in the Database, Please enter an Account ID to continue!"<<endl;
                    cout<<"Account ID: ";
                    cin>>ID;
                    if(ID < totalPlayers){
                        cout<<"\nFollowing are the details of Account ID: "<<ID<<endl;
                        cout<<"Player Name: "<<playersDatabase[ID][0]<<endl;
                        cout<<"Current Status: "<<playersDatabase[ID][2]<<endl;
                        cout<<"\nPlease enter the new status of Account ID: "<<ID<<endl;
                        cin>>playersDatabase[ID][2];
                        cout<<"\nThe Status of Account ID: "<<ID<<" has been changed to "<<playersDatabase[ID][2]<<" Successfully!"<<endl;
                    }else{
                        cout<<"\nNo Player Account with Account ID: "<<ID<<", found in the Database, Please enter a valid Player Account ID!"<<endl;
                    }
                }else{
                    cout<<"No Player Account found in the Database, Please add an account first!"<<endl;
                }
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

#endif