/*
 * task1.c
 *
 *  Created on: Nov 12, 2013
 *      Author: ravi
 */
//============================================================================
// Name        : TextAdventure.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;


//Functions
void atUbahn2();
void atUbahn();


int getInput(string *options, int n)
{
	bool valid = false;
	int index = 0;
	string answer ;
	while(!valid)
	{
		getline(cin,answer);
		//check if input is in list of possible answers
		for(int i = 0; i<n;i++)
		{
			if(!answer.compare(options[i]))
			{
				index = i;
				valid = 1;
			}
			//if strings match, set flag to valid and set the found index appropriately
		}

		if (!valid)
		{
			cout << "Input not valid. Please retry "<<endl;
		}
	}

	return index;

}


void lab()
{
	cout << "Congratulations! You made it to the lab!!! And more" <<endl;
	cout<<"important: with your brilliant outward appearance you got +1"<<endl;
	cout <<" at that hot girl! To be continued …. "<<endl;
}

void faillab()
{
	cout <<" Not only you came late to the lab, which annoys your prof"<<endl;
	cout <<" you also failed in impressing your favorite girl, nor did you "<<endl;
	cout <<" have any fun (party ..)…"<<endl;
	cout <<" Total goals achieved: 0 of 3.. Please try again!"<<endl;
}



void brushTeeth()
{
	cout<<"You invest time into brushing your teeth like nobody has ever done it"<<endl;
	cout<<" .A test on the dog lets you being confident to be successful."<<endl;
	cout <<" Go to the lab now or use your new confidence to go to a crazy party"<<endl;
	cout <<" in Studentenstadt? (lab/party)"<<endl;

	string options[] = {"lab","party"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		lab();
		break;
	case 1:
		cout <<" Good decision.. .. ..."<<endl;
		atUbahn();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}

void doenerProblem()
{
	cout<<"You eat the doener, smell terribly and head towards the laboratory. "<<endl;
	cout<<"You remember, that your lab partner is a super nice girl that you "<<endl;
	cout<<"like to impress. Brushing your teeth would be an option "<<endl;
	cout<<"before talking to her. Brush teeth and come even later for the lab?"<<endl;
	cout<<"(yes/no)"<<endl;
	string options[] = {"yes","no"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		brushTeeth();
		break;
	case 1:
		faillab();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}


void suite()
{
	cout<<"You choose the black suite with red tie and white shirt."<<endl;
	cout <<"Looking awesome you think about your situation: Spend the rest of"<<endl;
	cout<<" the day in the lab, or go for a suite-up party in Munich downtown?"<<endl;
	cout << "(lab/party)";

	string options[] = {"lab","party"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		lab();
		break;
	case 1:
		cout <<" Good decision.. .. ..."<<endl;
		atUbahn();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}

void salad()
{
	cout<<"You pay your last euros on that premium salad and really enjoy it."<<endl;
	cout<<"Unfortunately some of the white sauce got onto your t-shirt. "<<endl;
	cout<<"Normally you do not care, but your lab partner today is a lovely girl "<<endl;
	cout<<"and you like to impress her"<<endl;
	cout<<"You remember that in your closet in university you still have your suite."<<endl;
	cout<<"Spend time to change cloth?"<<endl;
	cout<<"(suite/dirty)"<<endl;

	string options[] = {"suite","dirty"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		suite();
		break;
	case 1:
		faillab();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}


void eat()
{
	cout<<"You decide to eat. You can either get a Doener with plenty "<<endl;
	cout<<"of onion and garlic which is the quick and cheap solution, "<<endl;
	cout<<"or you get some premium vegetarian Caesar's salad with shrimps."<<endl;
	cout<<" What do you buy?"<<endl;
	cout<<"(doener/salad)"<<endl;
	string options[] = {"doener","salad"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		doenerProblem();
		break;
	case 1:
		salad();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}

void enterHall()
{
	cout<<"You enter the hall, and suffer from severe hunger. You feel that"<<endl;
	cout << "not eating now will result in a black-out. What do you do?"<<endl;
	cout << "(eat/go to lab)"<<endl;
	string options[] = {"eat","go to lab"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		eat();
		break;
	case 1:
		cout <<" Right before you enter the lab you fade and loose consciousness"<<endl;
		cout <<". They bring you to the hospital where you have to stay exactly "<<endl;
		cout<<" 6 days and 20 hour. "<<endl;
		cout <<" Leaving the hospital you notice that it is the perfect time to"<<endl;
		cout <<" go to the lab course. You go into U6 and head towards Garching"<<endl;
		atUbahn2();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}


void leavingStation()
{
	cout<<"After leaving the subway station you suffer from hunger.  However,"<<endl;
	cout<<" you have to get to the lab as soon as possible. What do you want to"<<endl;
	cout<<" do next?  (eat/enter hall)"<<endl;

	string options[] = {"eat","enter hall"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		eat();
		break;
	case 1:
		enterHall();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}



void atUbahn2()
{
	cout<<"One hour later, you’ve just re-arrived at the final destination Garching"<<endl;
	cout<<"Forschungszentrum."<<endl<< "Do you want to leave?"<<endl;
	cout<<"(yes/no)?"<<endl;
	string options[] = {"yes","no"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		leavingStation();
		break;
	case 1:
		atUbahn2();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}



void atUbahn()
{
	cout<<"After an exhaustive party last night you are sitting in the sub"<<endl;
	cout<<"which just reached the final destination Garching Forschungszentrum."<<endl;
	cout<<"Do you want to leave?  (no/yes)"<<endl;
	string options[] = {"yes please","no"};
	int choice = getInput(options,2);

	switch (choice){
	case 0:
		leavingStation();
		break;
	case 1:
		atUbahn2();
		break;
	default:
		cout << "ERROR in atUBAHN" <<endl;
		break;
	}
}




int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	atUbahn();
	return 0;
}




