#ifndef launcher_h
#define lahuncher_h
							// #################### Simulation Launcher #################### //

void launcher() {
	vector<int> tempArr;
	int foodType;
	string foodName;
	int* petPoints;

	heading("Simulation Launcher");
	putchar('\n');
	cout << "Connecting..." << endl;
	cout << "Accessing the data..." << endl;
	cout << "Checking the status of simulation..." << endl;
	putchar('\n');
	separator(100);
	putchar('\n');
	if (simulationStatus) {
		petPoints = new int[totalPets];
		cout << "The Virtual Simulation is Live..." << endl;
		cout << "Initializing the launch protocols, double-checking every detail to ensure a flawless start..." << endl;
		cout << "Thank you for your patience during the initialization process!" << endl;
		text("Welcome aboard! We're ready for an exciting journey ahead!");
		do {
			heading("Virtual Simulation");
			goBack = false;
			cout << "\nPlease choose your action number from the following list:" << endl;
			cout << "1- Current Adopted Pets" << endl;
			cout << "2- Adopt a Pet" << endl;
			cout << "3- Abandon a Pet" << endl;
			cout << "4- Caress your Adopted Pets" << endl;
			cout << "5- Pet Adoption History" << endl;
			cout << "0- Navigate/Go Back" << endl;
			cin >> actionNo;
			switch (actionNo) {
				case 1:
					subHeading("Current Adopted Pets");
					cout << "\nUnlocked Pets: " << playersPetsDatabase[ID] << endl;
					cout << "Current Adopted Pets: " << currentAdoptedPets << endl;
					
					if (currentAdoptedPets > 0) {
						cout << "\nCurrent Adopted pets:" << endl;
						for (int i = 0, j = 1; i < totalAdoptedPets; i++) {
							if (adoptedPets[i][4] == "Adopted") {
								separator(50);
								cout << "Pet # " << j << endl;
								cout << "Name: " << adoptedPets[i][0] << endl;
								cout << "Species: " << adoptedPets[i][1] << endl;
								cout << "Condition: " << adoptedPets[i][2] << endl;
								cout << "Mood: " << adoptedPets[i][3] << endl;
								cout << "Status: " << adoptedPets[i][4] << endl;
								j++;
							}
						}
					}
					else {
						cout << "\nYou have not adopted any Pet currently, Please adopt a pet first!" << endl;
					}
					break;
				case 2:
					subHeading("Adopt a Pet");
					cout << "\nTotal Pets available: " << totalPets << endl;
					cout << "Unlocked Pets: " << playersPetsDatabase[ID] << endl;
					cout << "Current Adopted Pets: " << currentAdoptedPets << endl;
					if (totalPets > 0) {
						cout << "\nDetails of all Available Pets:" << endl;
						for (int i = 0; i < totalPets; i++) {
							separator(50);
							cout << "Pet # " << i + 1 << endl;
							cout << "Name: " << petsCollection[i][0] << endl;
							cout << "Species: " << petsCollection[i][1] << endl;
							cout << "Condition: " << petsCollection[i][2] << endl;
							cout << "Mood: " << petsCollection[i][3] << endl;
							cout << "Status: " << petsCollection[i][4] << endl;
						}
						if (currentAdoptedPets < playersPetsDatabase[ID]) {
							do {
								cout << "\nAdopt Pet # ";
								cin >> number;
								if (number < 1 || number > totalPets) {
									cout << "Please enter a valid Pet number from the above list!" << endl;
								}
								else {
									break;
								}
							} while (true);
							number--;
							petData = { petsCollection[number][0], petsCollection[number][1], petsCollection[number][2], petsCollection[number][3], "Adopted" };
							adoptedPets.push_back(petData);
							cout << "\nYou have successfully adopted " << adoptedPets[totalAdoptedPets][0] << "!" << endl;
							currentAdoptedPets++;
							totalAdoptedPets++;
						}
						else {
							cout << "\nYou have reached your Adoption limit, Please increase your level to unlock more Pets!" << endl;
						}
					}
					else {
						cout << "No Pet is currently available for adoption!" << endl;
					}
					break;
				case 3:
					subHeading("Abandon a Pet");
					cout << "Current Adopted Pets: " << currentAdoptedPets << endl;
					if (currentAdoptedPets > 0) {
						cout << "\nCurrent Adopted pets:" << endl;
						for (int i = 0, j = 1; i < totalAdoptedPets; i++) {
							if (adoptedPets[i][4] == "Adopted") {
								tempArr.push_back(i);
								separator(50);
								cout << "Pet # " << j << endl;
								cout << "Name: " << adoptedPets[i][0] << endl;
								cout << "Species: " << adoptedPets[i][1] << endl;
								cout << "Condition: " << adoptedPets[i][2] << endl;
								cout << "Mood: " << adoptedPets[i][3] << endl;
								cout << "Status: " << adoptedPets[i][4] << endl;
								j++;
							}
						}
						do {
							cout << "\nAbandon Pet # ";
							cin >> number;
							if (number < 1 || number > tempArr.size()) {
								cout << "Please enter a valid Pet number from the above list!" << endl;
							}
							else {
								break;
							}
						} while (true);
						number--;
						adoptedPets[tempArr[number]][4] = "Abandoned";
						cout << "\nYou have successfully abandoned " << adoptedPets[tempArr[number]][0] << "!" << endl;
						currentAdoptedPets--;
						tempArr.clear();
					}
					else {
						cout << "\nYou have not adopted any Pet currently, Please adopt a pet first!" << endl;
					}
					break;
				case 4:
					do {
						subHeading("Adopted Pets Care");
						goBack = true;
						if (currentAdoptedPets > 0) {
							goBack = false;
							cout << "\nPlease choose your action number from the following list:" << endl;
							cout << "1- Conduct a detailed Checkup of your Pets" << endl;
							cout << "2- Change a Pet's Name" << endl;
							cout << "3- Play with a Pet" << endl;
							cout << "4- Feed a Pet" << endl;
							cout << "5- Put a Pet to sleep" << endl;
							cout << "6- Wake up a Pet" << endl;
							cout << "0- Navigate/Go Back" << endl;
							cin >> actionNo;
							switch (actionNo) {
								case 1:
									subHeading("Pets Checkup");
									cout << "\nConducting a thorough checkup of your Pets...Please wait..." << endl;
									cout << "Checkup Done...Generating the report..." << endl;
									cout << "Here is the detailed report:" << endl;
									for (int i = 0; i < totalAdoptedPets; i++) {
										if (adoptedPets[i][4] == "Adopted") {
											separator(50);
											cout << "\nID: " << i << endl;
											cout << "Name: " << adoptedPets[i][0] << endl;
											cout << "Species: " << adoptedPets[i][1] << endl;
											cout << "Condition: " << adoptedPets[i][2] << endl;
											cout << "Mood: " << adoptedPets[i][3] << endl;
											cout << "Points: " << 0 << endl;	// petPoints[i]
										}
									}
									separator(100);
									cout << "\nFeed your Pets on time and play with them to keep them Happy..." << endl;
									cout << "Happy Pets will give you points which will increase your level so that you can adopt more pets!" << endl;
									break;
								case 2:
									subHeading("Change Pet's name");
									cout << "\nPlease enter the ID of Pet from detailed Checkup that you want to rename!" << endl;
									cout << "Pet ID: ";
									cin >> number;
									if (number >= 0 && number < totalAdoptedPets && adoptedPets[number][4] == "Adopted") {
										cout << "\nPlease enter the new name of Pet ID " << number << endl;
										cout << "Current name: " << adoptedPets[number][0] << endl;
										cout << "You can type 'cancel' instead of new Name to cancel this process!" << endl;
										cout << "New Name: ";
										cin >> name;
										if (name == "cancel") {
											cout << "\nPet Renaming Process has been canceled by the user!" << endl;
										}
										else {
											adoptedPets[number][0] = name;
											cout << "\nPet ID " << number << " has been renamed to " << name << "!" << endl;
										}
									}
									else {
										cout << "\nPlease enter a valid Pet ID from the detailed checkup!" << endl;
									}
									break;
								case 3:
									subHeading("Play Games with Pet");
									cout << "\nPlay at least 3 games with you Pet to make it Happy!" << endl;
									cout << "Hungry Pets won't Play Games until Fed properly!" << endl;
									cout << "\nPlease enter the ID of Pet from detailed Checkup that you want to play with!" << endl;
									cout << "Pet ID: ";
									cin >> number;
									if (number >= 0 && number < totalAdoptedPets && adoptedPets[number][4] == "Adopted") {
										if(adoptedPets[number][2] == "Hungry"){
											cout << "\n" << adoptedPets[number][0] << " is Hungry, Please feed it first!" << endl;
										}
										else 
										{
											do {
												goBack = false;
												separator(100);
												subHeading("Pet Games Menu");
												cout << "\nPlease select the number of a game to start playing with " << adoptedPets[number][0] << "!" << endl;
												cout << "1- Guess the Number" << endl;
												cout << "2- Rock, Paper, Scissors" << endl;
												cout << "3- Dice Roller" << endl;
												cout << "0- Navigate/Go Back" << endl;
												cin >> choiceNo;
												switch (choiceNo) {
													case 1:
														guessNumber(100);
														break;
													case 2:
														RPS();
														break;
													case 3:
														diceRoller();
														break;
													case 0:
														goBack = true;
														putchar('\n');
														break;
													default:
														cout << "\nPlease enter a valid choice number!" << endl;
												}
											} while (!goBack);
											goBack = false;
											if (adoptedPets[number][3] == "Happy" && petPoints[number] < 3) {
												petPoints[number]++;
											}	//	################## Continue Here
										}
									}
									else {
										cout << "\nPlease enter a valid Pet ID from the detailed checkup!" << endl;
									}
									break;
								case 4:
									subHeading("Feed Pet");
									cout << "\nPlease enter the ID of Pet from detailed Checkup that you want to feed!" << endl;
									cout << "Pet ID: ";
									cin >> number;
									if (number >= 0 && number < totalAdoptedPets && adoptedPets[number][4] == "Adopted") {
										if (adoptedPets[number][2] == "Hungry") {
											cout << "\nPlease enter the following details of the food that you wanna give to " << adoptedPets[number][0] << "!" << endl;
											cout << "Food type: (1- Edible 0- Drinkable) ";
											cin >> foodType;
											cout << "Food name: ";
											cin >> foodName;
											foodName = ((foodType) ? "Eating " : "Drinking ") + foodName;
											adoptedPets[number][2] = foodName;
											cout << "\nFeeding " << adoptedPets[number][0] << "..." << endl;
											cout << adoptedPets[number][0] << " is now " << adoptedPets[number][2] << "!" << endl;
										}
										else {
											cout << "\n" << adoptedPets[number][0] << " is not Hungry at the moment, Please feed it later when Hungry!" << endl;
										}
									}
									else {
										cout << "\nPlease enter a valid Pet ID from the detailed checkup!" << endl;
									}
									break;
								case 5:
									subHeading("Put Pet to Sleep");
									cout << "\nPlease enter the ID of Pet from detailed Checkup that you wanna put to Sleep!" << endl;
									cout << "Pet ID: ";
									cin >> number;
									if (number >= 0 && number < totalAdoptedPets && adoptedPets[number][4] == "Adopted") {
										if (adoptedPets[number][2] == "Sleeping") {
											cout << "\n" << adoptedPets[number][0] << " is already asleep!" << endl;
										}
										else if (adoptedPets[number][2] == "Hungry") {
											cout << "\n" << adoptedPets[number][0] << " is Hungry and cannot sleep with an empty stomach, Please feed it first!" << endl;
										}
										else {
											cout << "\nMaking perfect Sleep Conditions for " << adoptedPets[number][0] << "..." << endl;
											adoptedPets[number][2] = "Sleeping";
											cout << adoptedPets[number][0] << " is now " << adoptedPets[number][2] << "!" << endl;
										}
									}
									else {
										cout << "\nPlease enter a valid Pet ID from the detailed checkup!" << endl;
									}
									break;
								case 6:
									subHeading("Wake up Pet");
									cout << "\nPlease enter the ID of Pet from detailed Checkup that you wanna Wake Up!" << endl;
									cout << "Pet ID: ";
									cin >> number;
									if (number >= 0 && number < totalAdoptedPets && adoptedPets[number][4] == "Adopted") {
										if (adoptedPets[number][2] != "Sleeping") {
											cout << "\n" << adoptedPets[number][0] << " is awake already!" << endl;
										}
										else {
											cout << "\nTrying to Wake Up " << adoptedPets[number][0] << "..." << endl;
											adoptedPets[number][2] = "Awake";
											cout << adoptedPets[number][0] << " is now " << adoptedPets[number][2] << "!" << endl;
										}
									}
									else {
										cout << "\nPlease enter a valid Pet ID from the detailed checkup!" << endl;
									}
									break;
								case 0:
									goBack = true;
									putchar('\n');
									break;
								default:
									cout << "\nPlease enter a valid choice number!" << endl;
							}
							if (!goBack) { separator(100); }
						}
						else {
							cout << "\nYou have not adopted any Pet currently, Please adopt a pet first!" << endl;
						}
						} while (!goBack);
						goBack = false;
					break;
				case 5:
					subHeading("Pet Adoption History");
					cout << "\nUnlocked Pets: " << playersPetsDatabase[ID] << endl;
					cout << "Total Adopted Pets: " << totalAdoptedPets << endl;

					if (totalAdoptedPets > 0) {
						cout << "\nYour Pet Adoption History:" << endl;
						for (int i = 0; i < totalAdoptedPets; i++) {
							separator(50);
							cout << "Pet # " << i + 1 << endl;
							cout << "Name: " << adoptedPets[i][0] << endl;
							cout << "Species: " << adoptedPets[i][1] << endl;
							cout << "Condition: " << adoptedPets[i][2] << endl;
							cout << "Mood: " << adoptedPets[i][3] << endl;
							cout << "Status: " << adoptedPets[i][4] << endl;
						}
					}
					else {
						cout << "\nYou have not adopted any Pet yet, Please adopt a pet first!" << endl;
					}
					break;
				case 0:
					goBack = true;
					putchar('\n');
					break;
				default:
					cout << "\nPlease enter a valid choice number!" << endl;
			}
			separator(100);
		} while (!goBack);
	}
	else {
		cout << "The Simulation is currently stopped for maintenance, Please wait in the lobby or comeback later!" << endl;
		system("pause");
		separator(100);
	}
}

#endif