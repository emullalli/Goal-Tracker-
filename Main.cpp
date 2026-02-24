/*
*Author: Elektra Mullalli
*Creation Date: 02/21/2026
*Modification Date: 02/24/2026
*Purpose: The purpose of this program is for tracking your goals when life gets busy and hectic.
*		  When you are feeling down and want an affrimation to keep going you use this program.
*         If youre curious of your glow stat this program provides you a percentage.
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

// the blueprint for a goal

class Goal
{
private:
	string name;
	bool completed;
public:
	Goal(string n)
	{
		name = n;
		completed = false;
	}

	void markComplete()
	{
		completed = true;
	}

	bool isCompleted()
	{
		return completed;
	}

	string getName()
	{
		return name;
	}
};

// this is the design of the trackern that will be printed

void showHeader()
{
	cout << "====================================" << endl;
	cout << "       ~*~ GLOW UP TRACKER ~*~" << endl;
	cout << "====================================" << endl;
}

void showAffrimation()
{						//            [0]                               [1]                     [2]                                 [3]                               [4]                        5 elements in total   //
	string affirmation[] = {"you are literally unstopable.", "Discipline is self-love.", "Small habits build big glow.", "Romanticize your productivity", "Main character energy activated" };

	int size = 5;
	int randomIndex = rand() % size;   // this is generating random numbers this is saying rand() % 5 which will give 0, 1, 2, 3, 4
									  // so randomIndex is some number between 0-4 our array size

	cout << "~*~ Daily Affirmation ~*~" << endl;
	cout << affirmation[randomIndex] << endl;

}

int main()
{
	srand(time(0));  // we are generating a random number generator that will give the user different affrimations each time they run it
	vector<Goal> goals; // this is the vector that the users goals will be stored in
	int choice;

	while (true) // keep running program and displaying menu till user quits
	{
		showHeader(); // activate the header/menu from earlier

		//user picks from these list of choices

		cout << "1. Add Goal <3" << endl;
		cout << "2. Complete Goal " << endl;
		cout << "3. Delete Goal " << endl;
		cout << "4. View Glow Stats " << endl;
		cout << "5. Daily Affirmation " << endl;
		cout << "6. Exit " << endl;
		cout << "Choose: " << endl;
		cin >> choice;

		if (choice == 1)  // if user picks choice 1
		{
			cin.ignore(); // clears out any leftover characters
			string name;
			cout << "Enter new glow goal: ";
			getline(cin, name);  // reads entire line the user types and stores it into name
			goals.push_back(Goal(name)); // adds the goal to the vector goals which will store the goal in there
			cout << "Goal added " << endl;
		}

		else if (choice == 2) // if user picks choice 2
		{
			if (goals.empty()) // if the vector has no elements in it do not continue
			{
				cout << "No goals yet " << endl;
				continue;
			}
			for (int i = 0; i < goals.size(); i++) // for loop to access the vector
			{
				cout << i + 1 << ". " << goals[i].getName();
				if (goals[i].isCompleted())
				{
					cout << "  (Done)";  // if the goal is completed (done) will be marked next to it
				}
				cout << endl;
			}

			int num;
			cout << "Which goal did you complete? " << endl; // user picks which goal they completed
			cin >> num;

			if (num >= 1 && num <= goals.size()) // if the number is between these limits
			{
				goals[num - 1].markComplete(); // [num - 1] is used here since the user sees the list start at 1 while the vector starts at 0
				cout << "Period. Completed " << endl; // so, if user picks 1 we can access index 0
			}
			else
			{
				cout << "Invalid choice." << endl;
			}
		}
		else if (choice == 3) // deleting a goal
		{
			if (goals.empty())
			{
				cout << "No goals to delete." << endl; // safety measure in case there is no goals to erase
				continue;
			}
			for (int i = 0; i < goals.size(); i++)
			{
				cout << i + 1 << ". " << goals[i].getName() << endl;
			}
			int num;
			cout << "Which goal do you want to delete? ";
			cin >> num;

			if (num >= 1 && num <= goals.size())
			{
				goals.erase(goals.begin() + (num - 1)); // this is removing the element from the vector
				cout << "Deleted. Clean slate energy " << endl;
			}
			else
			{
				cout << "Invalid choice" << endl;
			}
		}
		else if (choice == 4) // gives the glow percentage
		{
			if (goals.empty())
			{
				cout << "No goals yet!" << endl;
				continue;
			}
			int completedCount = 0;

			for (int i = 0; i < goals.size(); i++) 
			{
				if (goals[i].isCompleted())
				{
					completedCount++;
				}
			}
			double percent = (double)completedCount / goals.size() * 100; // calculates the glow percentage 
				// using double ^ so we dont cause a integer divison
			cout << "Glow Progress: " << percent << "% " << endl;

			if (percent == 100) 
			{
				cout << " THAT GIRL ENERGY." << endl;
			}
			else if (percent >= 50)
			{
				cout << " Soft Productivity Queen." << endl;
			}
			else
			{
				cout << " In Your Rest Era." << endl;
			}
		}
		else if (choice == 5) // showing random affirmation 
		{
			showAffrimation();
		}
		else if (choice == 6) // exit option
		{
			cout << "Stay glowing " << endl;
			break;
		}
		else
		{
			cout << "Invalid choice." << endl;

		}
	}
	system("pause");
	return 0;
}