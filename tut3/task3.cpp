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

int main() {
    int sceneid = 0, quit = 0, choice;
	string options[2];
	while(!quit) {
		switch(sceneid) {
		    case 0: { // at the ubahn
		        cout<<"After an exhaustive party last night you are sitting in the sub"<<endl;
	            cout<<"which just reached the final destination Garching Forschungszentrum."<<endl;
	            cout<<"Do you want to leave?  (no/yes)"<<endl;
	            options[0] = "yes";
	            options[1] = "no";
	            choice = getInput(options,2);
	            switch (choice){
	            case 0:
		            sceneid = 2; //leave station
		            break;
	            case 1:
		            sceneid = 1; //ubahn again
		            break;
	            default:
		            cout << "ERROR in atUBAHN" <<endl;
		            quit = 1;
		            break;
		        }
		        break;
	        }

	        case 1: { // at the ubahn again
	        	cout<<"One hour later, you’ve just re-arrived at the final destination Garching"<<endl;
	            cout<<"Forschungszentrum."<<endl<< "Do you want to leave?"<<endl;
	            cout<<"(yes/no)?"<<endl;
	            options[0] = "yes";
	            options[1] = "no";
	            choice = getInput(options,2);

	            switch (choice){
	            case 0:
		            sceneid = 2; // leave station
		            break;
	            case 1:
		            sceneid = 1; // ubahn again
		            break;
	            default:
		            cout << "ERROR in atUBAHN" <<endl;
		            quit = 1;
		            break;
	            }
	            break;
            }

            case 2: { // leaving station
            	cout<<"After leaving the subway station you suffer from hunger. However,"<<endl;
	            cout<<" you have to get to the lab as soon as possible. What do you want to"<<endl;
	            cout<<" do next?  (eat/enter hall)"<<endl;
	            options[0] = "eat";
	            options[1] = "enter hall";
	            choice = getInput(options,2);

	            switch (choice){
	            case 0:
		            sceneid = 3; //eat
		            break;
	            case 1:
		            sceneid = 4;  // enter hall
		            break;
	            default:
		            cout << "ERROR in atUBAHN" <<endl;
		            quit = 1;
		            break;
	            }
	            break;
            }
            case 3: { //eat
	            cout<<"You decide to eat. You can either get a Doener with plenty "<<endl;
	            cout<<"of onion and garlic which is the quick and cheap solution, "<<endl;
	            cout<<"or you get some premium vegetarian Caesar's salad with shrimps."<<endl;
	            cout<<" What do you buy?"<<endl;
	            cout<<"(doener/salad)"<<endl;
	            options[0] = "doener";
	            options[1] = "salad";
	            choice = getInput(options,2);

	            switch (choice){
	            case 0:
		            sceneid = 5; //doener
		            break;
	            case 1:
		            sceneid = 6; //salad
		            break;
	            default:
		            quit = 1;
		            cout << "ERROR in atUBAHN" <<endl;
		            break;
	            }
	            break;
            }
            case 4: { // enter hall
            	cout<<"You enter the hall, and suffer from severe hunger. You feel that"<<endl;
	            cout << "not eating now will result in a black-out. What do you do?"<<endl;
	            cout << "(eat/go to lab)"<<endl;
	            options[0] = "eat";
	            options[1] = "go to lab";
	            choice = getInput(options,2);

	            switch (choice){
	            case 0:
		            sceneid = 3; //eat
		            break;
	            case 1:
		            cout <<" Right before you enter the lab you fade and loose consciousness"<<endl;
		            cout <<". They bring you to the hospital where you have to stay exactly "<<endl;
		            cout<<" 6 days and 20 hour. "<<endl;
		            cout <<" Leaving the hospital you notice that it is the perfect time to"<<endl;
		            cout <<" go to the lab course. You go into U6 and head towards Garching"<<endl;
		            sceneid = 1; //ubahn again
		            break;
	            default:
		            cout << "ERROR in atUBAHN" <<endl;
		            quit = 1;
		            break;
	            }
	            break;
            }
            case 5: { // doener
            	cout<<"You eat the doener, smell terribly and head towards the laboratory. "<<endl;
	            cout<<"You remember, that your lab partner is a super nice girl that you "<<endl;
	            cout<<"like to impress. Brushing your teeth would be an option "<<endl;
	            cout<<"before talking to her. Brush teeth and come even later for the lab?"<<endl;
	            cout<<"(yes/no)"<<endl;
	            options[0] = "yes";
	            options[1] = "no";
	            choice = getInput(options,2);

	            switch (choice){
	            case 0:
		            sceneid = 7; //brush teeth
		            break;
	            case 1:
		            sceneid = 8; //fail lab
		            break;
	            default:
		            cout << "ERROR in atUBAHN" <<endl;
		            quit = 1;
		            break;
	            }
	            break;
            }
            case 6: { // salad
            	cout<<"You pay your last euros on that premium salad and really enjoy it."<<endl;
	            cout<<"Unfortunately some of the white sauce got onto your t-shirt. "<<endl;
	            cout<<"Normally you do not care, but your lab partner today is a lovely girl "<<endl;
	            cout<<"and you like to impress her"<<endl;
	            cout<<"You remember that in your closet in university you still have your suite."<<endl;
	            cout<<"Spend time to change cloth?"<<endl;
	            cout<<"(suite/dirty)"<<endl;
	            options[0] = "suite";
	            options[1] = "dirty";
	            choice = getInput(options,2);

	            switch (choice){
	            case 0:
		            sceneid = 9; //suite
		            break;
	            case 1:
		            sceneid = 8; //fail lab
		            break;
	            default:
		            cout << "ERROR in atUBAHN" <<endl;
		            quit = 1;
		            break;
	            }
	            break;
            }
            case 7: { // brush teeth
            	cout<<"You invest time into brushing your teeth like nobody has ever done it"<<endl;
	            cout<<" .A test on the dog lets you being confident to be successful."<<endl;
	            cout <<" Go to the lab now or use your new confidence to go to a crazy party"<<endl;
	            cout <<" in Studentenstadt? (lab/party)"<<endl;
	            options[0] = "lab";
	            options[1] = "party";
	            choice = getInput(options,2);

	            switch (choice){
	            case 0:
		            sceneid = 10; //go to lab
		            break;
	            case 1:
		            cout <<" Good decision.. .. ..."<<endl;
		            sceneid = 0; // ubahn
		            break;
	            default:
		            cout << "ERROR in atUBAHN" <<endl;
		            quit = 1;
		            break;
	            }
	            break;
            }
            case 8: { // fail lab
            	cout <<" Not only you came late to the lab, which annoys your prof"<<endl;
                cout <<" you also failed in impressing your favorite girl, nor did you "<<endl;
	            cout <<" have any fun (party ..)…"<<endl;
	            cout <<" Total goals achieved: 0 of 3.. Please try again!"<<endl;
	            quit = 1;
	            break;
	        }

            case 9: { // suite
            	cout<<"You choose the black suite with red tie and white shirt."<<endl;
	            cout <<"Looking awesome you think about your situation: Spend the rest of"<<endl;
	            cout<<" the day in the lab, or go for a suite-up party in Munich downtown?"<<endl;
	            cout << "(lab/party)"<<endl;
	            options[0] = "lab";
	            options[1] = "party";
	            choice = getInput(options,2);

	            switch (choice){
	            case 0:
		            sceneid = 10; //go to lab
		            break;
	            case 1:
		            cout <<" Good decision.. .. ..."<<endl;
		            sceneid = 0; // at ubahn
 		            break;
	            default:
		            cout << "ERROR in atUBAHN" <<endl;
		            quit = 1;
		            break;
	            }
	            break;
            }
            case 10: { // lab
            	cout << "Congratulations! You made it to the lab!!! And more"<<endl;
	            cout<<"important: with your brilliant outward appearance you got +1"<<endl;
	            cout <<" at that hot girl! To be continued …. "<<endl;
	            quit = 1;
	            break;
            }


	    }
	}

	return 0;
}
