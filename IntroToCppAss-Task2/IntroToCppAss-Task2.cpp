// IntroToCppAss-Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;

int linearSearch(int[], int, int);
void bubbleSort(int[], int);
int binarySearch(int[], int, int);
void pointerSwap(int*, int*);

//Make a struct that represents a Mob, it should have an attack skill, 
//a damage rating, a name and health.Write a function that determines the outcome of a battle by passing two Mobs by reference.
struct Mob {
	int attackSkill;
	int damageRating;
	string name;
	int health;
	Mob(int attackSkill, int damageRating, string name, int health) 
	{
		this->attackSkill = attackSkill;
		this->damageRating = damageRating;
		this->name = name;
		this->health = health;
	}
	
};

void fight(Mob&, Mob&);
int main()
{
	int array[20] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };//initial array
	int length = sizeof(array) / sizeof(array[0]);
	cout << "3 is at position " << linearSearch(array, length, 3) << " in the array \n";
	assert(linearSearch(array, length, 3) == 2);
	cout << "7 is at position " << linearSearch(array, length, 7) << " in the array \n";
	assert(linearSearch(array, length, 7) == 11);
	cout << "67 is at position " << linearSearch(array, length, 67) << " in the array \n";
	assert(linearSearch(array, length, 67) == 0);
	cout << "88 is at position " << linearSearch(array, length, 88) << " in the array \n";
	assert(linearSearch(array, length, 88) == -1);

	bubbleSort(array, length);//sorting array

	cout << "3 is at position " << linearSearch(array, length, 11) << " in the array \n";
	assert(binarySearch(array, length, 11) == 4);
	cout << "7 is at position " << linearSearch(array, length, 23) << " in the array \n";
	assert(binarySearch(array, length, 23) == 8);
	cout << "67 is at position " << linearSearch(array, length, 97) << " in the array \n";
	assert(binarySearch(array, length, 97) == 19);
	cout << "88 is at position " << linearSearch(array, length, 88) << " in the array \n";
	assert(binarySearch(array, length, 88) == -1);

	/*Write a loop that asks the user for a value and then calls your function to search for that value in the sorted array.
		If your function finds the value, tell the user at which index it found it*/
	cout << "insert number to search for: ";
	int searchValue;
	cin >> searchValue; //not entirely certain why this task asks for a loop? maybe they meant the if else or the loop I already have inside the function?
	if (binarySearch(array, length, searchValue) >= 0)
		cout << "Your value was found at: " << binarySearch(array, length, searchValue) << endl;
	else
		cout << "Your value was not found." << endl;
	
	pointerSwap(&array[0], &array[1]);

	Mob goblin(10, 5, "Goblin", 10 );
	Mob unicorn(15, 3, "Unicorn", 20);
	while (goblin.health > 0 && unicorn.health > 0)//mob fight, there can be only one
	{
		fight(goblin, unicorn);
	}
	
}
/*
You will write a function that performs a linear search through an integer array by passing the target value, 
and the array, as function arguments.The function will return the index where the target is found, otherwise it will return -1.*/
int linearSearch(int array[], int size, int findNumber)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == findNumber)//if the number is found
		{
			return i;//return the index of the number
			break;
		};
	}
	return -1;
}

//Using the tutorials you will write a function that performs an ‘in - place’ bubble sort by passing an array of integers to it.Sort in ascending order(smallest to largest).
// You do not need to return any values from the function.
//You may NOT use any built - in sorting algorithms.
void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)//a bubble sort is a nested for loop, one pass through the array is not enough to sort all the elements
	{
		for (int j = 0; j < size; j++)//the inner loop performs comparisons and swaps within each pass
		{
			
			if (array[j] < array[j - 1])//this will check if the current value is smaller than the previous value
			{
				assert(array[j] <= array[j - 1]);//we were told to use asserts() that checks the first value of the pair is always less than the second value
				swap(array[j], array[j - 1]);//this swaps the values fast, this is sorta shortcutting it, 
				//I have no idea if this uses more memory but to do but the other way is a bit longer in code
			}
				
		}
	}
	/*for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}*/
}
//You will implement a function that searches a sorted array for a given value. Pass the target value and the array to your function and return 
// the index where the value was found if it exists in the array. If it is not in the array return -1.
//You must implement binary search for this exercise.Do NOT implement linear search.Do NOT use any built - in library functions.
int binarySearch(int array[], int size, int findNumber)
{
	int leftNum = 0;//left value
	int rightNum = size - 1;//right value
	int mid;//middle value value gets initialized at the start of the loop
	while (leftNum <= rightNum)
	{
		mid = (leftNum + rightNum) / 2;
		/*cout << "left: " << leftNum << endl;
		cout << "right: " << rightNum << endl;
		cout << "mid: " << mid << endl;
		cout << "middle value is: " << array[mid] << endl;*/
		if (array[mid] == findNumber)//if current value matches return its location in the array, if there's duplicate(s) though it wil likely never be found unless we remove values
		{
			return mid;
		}
		
		if (array[mid] < findNumber)//if the current number is less than the number we're looking for we then need to shrink the array in half and search to the right of it in the array
		{
			leftNum = mid + 1;//set the leftnum to the current mid and move the leftnum up an array index
		}
		else //if the current number is greater than the number we're looking for we search the left side of the array
		{
			rightNum = mid - 1;//set the rightnum to the current mid move the rightnum down an array index
		}
	}//loop still breaks if left and right number invitably meet with no matches
	return -1;
}

//You will write a function to swap the value of two integers.You will do this by passing pointers to those integers into the function and 
//performing the swap through pointer manipulation.Your function will not return any values.
void pointerSwap(int* num1, int* num2)
{
	// store the value pointed to by num1 in temp
	int temp = *num1;
	//assign the value pointed by num2 to the location pointed to by num1
	*num1 = *num2;
	//assign the value pointed to in temp to the location pointed to by num2
	*num2 = temp;
}

//In the battle function make each Mob perform an attack on the other by using their attack skills to determine the outcome somehow.How is up to you,
// but some form of simulated dice roll using randomness is suggested(think tabletop RPGs).
//Based on the attack outcome, apply any damage according to the damage value and adjust the health of the target Mob.
//Output a relevant string to the console using the Mob’s names 
void fight(Mob& fighter1, Mob& fighter2)
{
	srand(time(0));
	int fighter1HitVal = (rand() % 101) + fighter1.attackSkill;//generate a numbe between 0 and 100 and add attack skill
	int fighter2HitVal = (rand() % 101) + fighter2.attackSkill;
	if (fighter1HitVal > fighter2HitVal)
	{
		fighter2.health -= fighter1.damageRating;//apply damage to fighter 2 if they lose the skill check
		cout << fighter2.name << " has taken " << fighter1.damageRating << " points of damage" << endl;
		cout << fighter2.name << " now has " << fighter2.health << " health left" << endl;
		if (fighter2.health <= 0)
			cout << fighter2.name << " has been slain" << endl;
	}
	else if (fighter1HitVal < fighter2HitVal)
	{
		fighter1.health -= fighter2.damageRating;//apply damage to fighter 1 if they lose the skill check
		cout << fighter1.name << " has taken " << fighter2.damageRating << " points of damage" << endl;
		cout << fighter1.name << " now has " << fighter1.health << " health left" << endl;
		if (fighter1.health <= 0)
			cout << fighter1.name << " has been slain" << endl;
	}
	else//we'll call it a draw
	{
		cout << fighter1.name << " and " << fighter2.name << " deflect each other's attacks and no damage is applied" << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
