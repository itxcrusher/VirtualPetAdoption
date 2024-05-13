#ifndef pet_h
#define pet_h

                       // #################### Pets Database Initialization and Pets Management #################### //

// Initialize pets Collection
void startPetsCollection(){
    for(int i=0; i<maxPets; i++){
        petsCollection[i] = new string[petAttributes];
    }
    // Pet # 1
    petsCollection[0][0] = "Max";
    petsCollection[0][1] = "Dog";
    petsCollection[0][2] = "Sleeping";  // Condition: Sleeping, Eating, Drinking, Playing, Hungry
    petsCollection[0][3] = "Happy";     // Mood: Happy, Sad, Angry
    petsCollection[0][4] = "Available"; // Status: Available, Unavailable, Adopted, Abandoned
    // Pet # 2
    petsCollection[1][0] = "Oliver";
    petsCollection[1][1] = "Cat";
    petsCollection[1][2] = "Hungry";
    petsCollection[1][3] = "Angry";
    petsCollection[1][4] = "Available";
    // Pet # 3
    petsCollection[2][0] = "Tweety";
    petsCollection[2][1] = "Bird";
    petsCollection[2][2] = "Playing";
    petsCollection[2][3] = "Sad";
    petsCollection[2][4] = "Available";
}

// Manage Pets
void petManagement(){
    do{
        heading("Pet management");
        goBack = false;
        cout<<"\nPlease choose your action number from the following list:"<<endl;
        cout<<"1- Get the list of available Pets from the collection"<<endl;
        cout<<"2- Add a new Pet to collection"<<endl;
        cout<<"3- Remove a pet from the collection"<<endl;
        cout<<"4- Increase the Pet Collection Space"<<endl;
        cout<<"0- Navigate/Go Back"<<endl;
        cin>>actionNo;
        switch(actionNo){
            case 1:
                subHeading("Our Pet Collection");
                putchar('\n');
                cout<<"Number of Available Pets: "<<totalPets<<endl;
                cout<<"Pets Collection Space: "<<maxPets<<endl;
                if(totalPets > 0){
                    for(int i=0; i<totalPets; i++){
                        separator(50);
                        cout<<"Pet # "<<i+1<<endl;
                        cout<<"Name: "<<petsCollection[i][0]<<endl;
                        cout<<"Species: "<<petsCollection[i][1]<<endl;
                        cout<<"Condition: "<<petsCollection[i][2]<<endl;
                        cout<<"Mood: "<<petsCollection[i][3]<<endl;
                        cout << "Status: " << petsCollection[i][4] << endl;
                    }
                }else{
                    cout<<"No Pet found in our Collection, Please add a pet first!"<<endl;
                }
                separator(50);
                break;
            case 2:
                subHeading("Add new Pet");
                putchar('\n');
                if(totalPets < maxPets){
                    totalPets++;
                    cout<<"Please enter the following details of Pet # "<<totalPets<<endl;
                    cout<<"Name: ";
                    cin>>petsCollection[totalPets-1][0];
                    cout<<"Species: ";
                    cin>>petsCollection[totalPets-1][1];
                    cout<<"Condition: ";
                    cin>>petsCollection[totalPets-1][2];
                    cout<<"Mood: ";
                    cin>>petsCollection[totalPets-1][3];
                    cout << "Status: ";
                    cin >> petsCollection[totalPets - 1][4];
                    putchar('\n');
                    cout<<petsCollection[totalPets-1][0]<<" has been added to the Collection Successfully!"<<endl;
                }else{
                    cout<<"Max Pet Limit has been Reached, Please increase the collection Space first!"<<endl;
                }
                separator(50);
                break;
            case 3:
                subHeading("Remove a Pet");
                putchar('\n');
                if(totalPets > 0){
                    int petNo;
                    cout<<totalPets<<" Pets are currently in our collection, Please enter a pet number to remove from the collection!"<<endl;
                    cout<<"Remove Pet # ";
                    cin>>petNo;
                    delete[] petsCollection[petNo-1];
                    for(int i=petNo-1; i<totalPets; i++){
                        petsCollection[i] = petsCollection[i+1];
                    }
                    cout<<"Pet # "<<petNo<<" has been removed from our Collection Successfully!"<<endl;
                    totalPets--;
                }else{
                    cout<<"There is no Pet in our Collection, Please add a pet first!"<<endl;
                }
                separator(50);
                break;
            case 4:
                subHeading("Increase Collection Space");
                putchar('\n');
                cout<<"Old Collection Space: "<<maxPets<<endl;
                cout<<"Expanding the collection area...Please Wait..."<<endl;

                maxPets += 5;
                increasedPetsCollection = new string* [maxPets];
                for(int i=0; i<totalPets; i++){
                    increasedPetsCollection[i] = petsCollection[i];
                }
                delete[] petsCollection;
                petsCollection = increasedPetsCollection;

                cout<<"The Collection area has been expanded by 5!"<<endl;
                cout<<"New Collection Space: "<<maxPets<<endl;
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