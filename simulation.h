#ifndef simulation_h
#define simulation_h

                        // #################### Simulation Management, Updates and Customization #################### //

// Manage Simulation
void simulationManagement(){
    do{
        heading("Simulation Management");
        goBack = false;
        cout<<"\nPlease choose your action number from the following list:"<<endl;
        cout<<"1- Start the Simulation"<<endl;
        cout<<"2- Stop the Simulation"<<endl;
        cout<<"0- Navigate/Go Back"<<endl;
        cin>>actionNo;
        switch(actionNo){
            case 1:
                subHeading("Start Simulation");
                if(!simulationStatus){
                    simulationStatus = true;
                    cout<<"\nThe Simulation has been started successfully!"<<endl;
                }else{
                    cout<<"\nThe Simulation is already running!"<<endl;
                }
                separator(50);
                break;
            case 2:
                subHeading("Stop Simulation");
                if(simulationStatus){
                    simulationStatus = false;
                    cout<<"\nThe Simulation has been stopped successfully!"<<endl;
                }else{
                    cout<<"\nThe Simulation is already off!"<<endl;
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

// Simulation Update
void updateProbability(){
    int number = getRandom(5);
    simulationUpdate = (number == 1) ? true : false;
}
void updateProcess(){
    int number;
    putchar('\n');
    separator(100);
    cout<<"Checking for Updates...\n"<<endl;
    if(simulationUpdate){
        cout<<"New Update Found...Do you want to update the Simulation?"<<endl;
        cout<<"Press 1 to update now or Press any other number to skip and do it later!"<<endl;
        cin>>number;
        if(number == 1){
            subHeading("Simulation Update");
            cout<<"\nPlease sit back and have some coffee while we download and update the resources for you!"<<endl;
            cout<<"Checking for any Compatibility issues..."<<endl;
            cout<<"Downloading new Content..."<<endl;
            cout<<"Merging with previous files..."<<endl;
            cout<<"Finalizing the update..."<<endl;
            simulationUpdate = false;
            putchar('\n');
            separator(100);
        }
    }
    if(!simulationUpdate){
        cout<<"The Simulation is Up-to-date, you are good to go!"<<endl;
    }
    separator(100);
}

// Customize Simulation
void customizeSimulation() {
    do {
        string word, sentence;
        heading("Customize Simulation");
        goBack = false;
        cout << "\nPlease choose your action number from the following list:" << endl;
        cout << "1- Check Simulation Status" << endl;
        cout << "2- Check for Updates" << endl;
        cout << "0- Navigate/Go Back" << endl;
        cin >> actionNo;
        switch (actionNo) {
            case 1:
                subHeading("Simulation Status");
                if (simulationStatus) {
                    word = "Online";
                    sentence = "The Simulation is currently running, you can go and have fun!";
                }
                else {
                    word = "Offline";
                    sentence = "The Simulation is currently stopped for maintenance, Please wait or comeback later!";
                }
                cout << "\nCurrent Simulation Status: " << word << "\n" << sentence << endl;
                separator(100);
                break;
            case 2:
                updateProbability();
                updateProcess();
                break;
            case 0:
                goBack = true;
                putchar('\n');
                separator(100);
                break;
            default:
                cout << "\nPlease enter a valid choice number!\n" << endl;
        }
    } while (!goBack);
}
#endif