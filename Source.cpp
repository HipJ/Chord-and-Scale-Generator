#include <string>
#include <iostream>
#include <vector>
#include "Scales.h"
#include "Guitar.h"
#include "Chord.h"
#include "MusicalKeys.h"

/*
	WHAT I LEARNED FROM THIS PROGRAM!!!
	- I HAVE TO FIND A PRACTICAL WAY OF GETTING USER INPUT
		AND PRODUCING THE RESULTS THAT I WANT -BEFORE-
		I START PROGRAMMING

	- I ENDED UP WITH HUNDREDS OF LINES OF EXTRA CODE AND SPENT WAY MORE TIME
		THAN EXPECTED...

	- 
*/
int main()
{
	/*
	std::vector<IndexConvert> vectorOfChordPositions;
	vectorOfChordPositions.push_back(first);

	Chord MajorC(vectorOfChordPositions, C);

	chord::print_chord(MajorC);
	Guitar guitar;
	guitar.fillChord(MajorC);
	guitar.print();
	*/

	int user_int_var;
	std::cout << "ENTER IN THE KEY OF THE SCALE/CHORD YOU'D LIKE TO GENERATE: ";
	std::cin >> user_int_var;
	MusicalKeys user_key_var = static_cast<MusicalKeys>(user_int_var);
	mkey::print_note(user_key_var);

	std::cout << '\n';
	std::cout << "Enter in the notes of the scale you'd like to generate \n\n";
	std::cout << "first = 0, \nsecond = 1, \nthird = 2, \nfourth = 3, \nfifth = 4, \nsixth = 5, \nseventh = 6, \nninth = 7, \neleventh = 8, \nthirteenth = 9\n";
	std::cout << "-FLATTED NOTES-\n\n";
	std::cout << "flat_second = 11, \nflat_third = 12, \nflat_fourth = 13, \nflat_fifth = 14, \nflat_sixth = 15, \nflat_seventh = 16, \nflat_ninth = 17\n";
	std::cout << "-SHARPED NOTES-\n\n";
	std::cout << "sharp_second = 21, \nsharp_third = 22, \nsharp_fourth = 23, \nsharp_fifth = 24, \nsharp_sixth = 25, \nsharp_seventh = 26, \nsharp_ninth = 27\n";
	
	std::vector<IndexConvert> vectorOfChordPositions;
	int index = 0;

	char yesOrNo = 0;
	std::cout << "Enter the note positions you'd like to generate!\n";
	while (std::cin >> index)
	{
		vectorOfChordPositions.push_back(static_cast<IndexConvert>(index));
		std::cout << "Continue? : ";
		std::cin.ignore();
		std::cin.get(yesOrNo);
		if ('Y' == toupper(yesOrNo))
		{
			continue;
		}
		else
			break;
	}

	Guitar guitar;
	Chord majorA(vectorOfChordPositions, user_key_var);
	guitar.fillChord(majorA);
	guitar.print();

	return 0;
}
