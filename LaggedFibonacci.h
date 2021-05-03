/*

bu program lagged fibonacci methodunu kullanarak
mouse click saat ve pozisyonuyla elde edilmiþ seedleri kullanarak
random numberlar generate eder

*/

//https://www.cplusplus.com/reference/cstdlib/rand/
//https://www.w3schools.com/cpp/cpp_files.asp
//http://www.cplusplus.com/reference/fstream/ofstream/open/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

	unsigned long long int seeds[7]; //initial seeds (they are all positive anyways, good to have a bigger range data type)
	long long int randomNum; //positive or negative random number
	int randMax = 32767;

	//random number between 0 and randMax
	long long int randomNumber(); 
	//random number with ending range ( 0 < randomNumber < range)
	long long int randomNumber(int range);
	//random number with starting and ending range ( rangeI < randomNumber < randomL)
	long long int randomNumber(int rangeI, int rangeL);
	//opens the seed file and fill the seed array with the numbers from the file
	void seedArray(); 
	//deletes the first element in the array, shift all elements to one left index and adds the newly created random number to the last index 
	void changeArray();
	//adds the new seeds array to the seeds file to use it for the next time the program launches
	void fileChanger(); 
	//random  number generator with no parameter
	long long int Random();
	//random number gneerator with 1 parameter
	long long int Random(int range);
	//Random number generator with 2 parameter
	long long int Random(int rangeI,int rangeL);





	void seedArray()
	{
		// Read from the seed text file
		ifstream mySeedsFile("C:/Users/aleyn/Desktop/Seeds.txt");
		int i = 0;
		string myText;

		// Use a while loop together with the getline() function to read the file line by line
		while (getline(mySeedsFile, myText)) {
			// Output the text from the file
			seeds[i++] = stoull(myText); //convert into unsigned long long int number	
		}

		//close the file 
		mySeedsFile.close();

	}

	long long int randomNumber()
	{
		randomNum = ((seeds[2]%randMax) + (seeds[6]%randMax)) %randMax;

		return randomNum;
	}

	long long int randomNumber(int range)
	{
		randomNum = ((seeds[2] % range) + (seeds[6] % range)) % range;
		return randomNum;
	}

	long long int randomNumber(int rangeI, int rangeL)
	{
		randomNum = ((seeds[2] % rangeL) + (seeds[6] % rangeL)) % rangeL;
		while (randomNum <= rangeI)
			randomNum += rangeI;

		return randomNum;

	}

	void changeArray()
	{
		for (size_t i = 0; i < 6; i++)
		{
			seeds[i] = seeds[i + 1]; //shift to left by one (all elements except the last one since there is no 8th element(aka index 7)
		}
		seeds[6] = randomNum; //puts the newly created random number to the seeds array as the last item


	}

	void fileChanger()
	{
		ofstream mySeedsFile;

		//first clean the file content
		mySeedsFile.open("C:/Users/aleyn/Desktop/Seeds.txt");
		mySeedsFile.close();

		//open it again this time put the new seed array into the file
		mySeedsFile.open("C:/Users/aleyn/Desktop/Seeds.txt");

		for (size_t i = 0; i < 7; i++)
		{
			mySeedsFile << seeds[i] << endl;

		}

		mySeedsFile.close();

	}

	//functions to be used in main

	long long int Random()
	{
		//starts with opening the seed file and initializing the seed array
		seedArray();
		//generates the random number
		randomNumber();
		//changes the array with the newly generated random number
		changeArray();
		//changes the seed file with the new seed array
		fileChanger();

		return randomNum;

	}

	
	long long int Random(int range)
	{
		//starts with opening the seed file and initializing the seed array
		seedArray();
		//generates the random number
		randomNumber(range);
		//changes the array with the newly generated random number
		changeArray();
		//changes the seed file with the new seed array
		fileChanger();

		return randomNum;
	}

	long long int Random(int rangeI, int rangeL)
	{
		//starts with opening the seed file and initializing the seed array
		seedArray();
		//generates the random number
		randomNumber(rangeI,rangeL);
		//changes the array with the newly generated random number
		changeArray();
		//changes the seed file with the new seed array
		fileChanger();

		return randomNum;
	}






	//just for checking 
	void checkSeeds()
	{
		for (size_t i = 0; i < 7; i++)
		{
			cout << seeds[i]<< endl;
		}
	}
	

	


