#pragma once

#include <vector>
#include <iostream>
#include "MusicalKeys.h"

enum IndexConvert
{
	first = 0,
	second = 1,
	third = 2,
	fourth = 3,
	fifth = 4,
	sixth = 5,
	seventh = 6,
	ninth = 7,
	eleventh = 8,
	thirteenth = 9,

	ADD_FOR_FLAT = 10,

	flat_second = 11,
	flat_third = 12,
	flat_fourth = 13,
	flat_fifth = 14,
	flat_sixth = 15,
	flat_seventh = 16,
	flat_ninth = 17,

	ADD_FOR_SHARP = 20,
	
	sharp_second = 21,
	sharp_third = 22,
	sharp_fourth = 23,
	sharp_fifth = 24,
	sharp_sixth = 25,
	sharp_seventh = 26,
	sharp_ninth = 27,

	ADD_FOR_FLAT_FLAT = 30,

	flat_flat_seventh = 36,

	EMPTY = 40
};

class Chord
{
private:
	std::vector<MusicalKeys> chordNotes;

public:
	Chord(std::vector<IndexConvert> & chord_indexes_arg, MusicalKeys key_arg) :
		chordNotes()
	{
		std::cout << "Starting constructor!" << std::endl;

		// get the index of the key in the key generator array...
		int key_index = mkey::findIndex(key_arg);

		for (int noteIndex = 0; noteIndex < chord_indexes_arg.size(); noteIndex++)
		{
			switch (chord_indexes_arg[noteIndex])
			{

				// complete major notes
			case first:
				chordNotes.push_back(KeyGenArray[key_index]);
				break;
			case second:
				chordNotes.push_back(KeyGenArray[key_index + 2]);
				break;
			case third:
				chordNotes.push_back(KeyGenArray[key_index + 4]);
				break;
			case fourth:
				chordNotes.push_back(KeyGenArray[key_index + 5]);
				break;
			case fifth:
				chordNotes.push_back(KeyGenArray[key_index + 7]);
				break;
			case sixth:
				chordNotes.push_back(KeyGenArray[key_index + 9]);
				break;
			case seventh:
				chordNotes.push_back(KeyGenArray[key_index + 11]);
				break;
			case ninth:
				chordNotes.push_back(KeyGenArray[key_index + 2]);
				break;
			case eleventh:
				chordNotes.push_back(KeyGenArray[key_index + 5]);
				break;
			case thirteenth:
				chordNotes.push_back(KeyGenArray[key_index + 9]);
				break;

				// flatted notes
			case flat_second:
				chordNotes.push_back(KeyGenArray[key_index + 1]);
				break;
			case flat_third:
				chordNotes.push_back(KeyGenArray[key_index + 3]);
				break;
			case flat_fourth:
				chordNotes.push_back(KeyGenArray[key_index + 4]);
				break;
			case flat_fifth:
				chordNotes.push_back(KeyGenArray[key_index + 6]);
				break;
			case flat_sixth:
				chordNotes.push_back(KeyGenArray[key_index + 8]);
				break;
			case flat_seventh:
				chordNotes.push_back(KeyGenArray[key_index + 10]);
				break;

				//sharped 
			case sharp_second:
				chordNotes.push_back(KeyGenArray[key_index + 3]);
				break;
			case sharp_third:
				chordNotes.push_back(KeyGenArray[key_index + 5]);
				break;
			case sharp_fourth:
				chordNotes.push_back(KeyGenArray[key_index + 6]);
				break;
			case sharp_fifth:
				chordNotes.push_back(KeyGenArray[key_index + 8]);
				break;
			case sharp_sixth:
				chordNotes.push_back(KeyGenArray[key_index + 10]);
				break;
			case sharp_seventh:
				chordNotes.push_back(KeyGenArray[key_index + 12]);
				break;
			default:
				std::cout << "Motha Fucka broke in the switch!" << std::endl;
				break;
			}
		}
	}

	const int getSize() // get the size of the chordNotes vector
	{
		return chordNotes.size();
	}

	MusicalKeys& operator[](const unsigned int& index) // retrieve a specific element in the chord notes vector
	{
		return chordNotes[index];
	}
};

namespace chord
{
	bool search_chord(Chord& chord_arg, const MusicalKeys& key_arg)
	{
		for (int index = 0; index < chord_arg.getSize(); index++)
		{
			if (chord_arg[index] == key_arg)
				return true;
		}
		return false;
	}

	void print_chord(Chord& chord_arg)
	{
		for (int index = 0; index < chord_arg.getSize(); index++)
		{
			std::cout << "Element #" << index + 1 << ": ";
			mkey::print_note(chord_arg[index]);
			std::cout << "\n";
		}
	}
}
