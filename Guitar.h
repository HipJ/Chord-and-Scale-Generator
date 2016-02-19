#pragma once

#include <iostream>
#include <iomanip>
#include "MusicalKeys.h"
#include "Scales.h"
#include "Chord.h"

class Guitar
{
private:
	static const int STRING_SIZE = 23;
	static const int NUM_STRINGS = 6;

	const MusicalKeys firstString[STRING_SIZE] =
	{
		E, F, FsGf, G, GsAf, A, AsBf, B, C, CsDf, D, DsEf, E, F, FsGf, G, GsAf, A, AsBf, B, C, CsDf, D
	};

	const MusicalKeys secondString[STRING_SIZE] =
	{
		B, C, CsDf, D, DsEf, E, F, FsGf, G, GsAf, A, AsBf, B, C, CsDf, D, DsEf, E, F, FsGf, G, GsAf, A
	};

	const MusicalKeys thirdString[STRING_SIZE] =
	{
		G, GsAf, A, AsBf, B, C, CsDf, D, DsEf, E, F, FsGf, G, GsAf, A, AsBf, B, C, CsDf, D, DsEf, E, F
	};

	const MusicalKeys fourthString[STRING_SIZE] =
	{
		D, DsEf, E, F, FsGf, G, GsAf, A, AsBf, B, C, CsDf, D, DsEf, E, F, FsGf, G, GsAf, A, AsBf, B, C
	};

	const MusicalKeys fifthString[STRING_SIZE] =
	{
		A, AsBf, B, C, CsDf, D, DsEf, E, F, FsGf, G, GsAf, A, AsBf, B, C, CsDf, D, DsEf, E, F, FsGf, G
	};

	const MusicalKeys sixthString[STRING_SIZE] =
	{
		E, F, FsGf, G, GsAf, A, AsBf, B, C, CsDf, D, DsEf, E, F, FsGf, G, GsAf, A, AsBf, B, C, CsDf, D
	};

	MusicalKeys textGuitar2D[23][6];
public:
	Guitar()
	{
		for (int fret = 0; fret < STRING_SIZE; fret++)
		{
			textGuitar2D[fret][5] = sixthString[fret];
			textGuitar2D[fret][4] = fifthString[fret];
			textGuitar2D[fret][3] = fourthString[fret];
			textGuitar2D[fret][2] = thirdString[fret];
			textGuitar2D[fret][1] = secondString[fret];
			textGuitar2D[fret][0] = firstString[fret];
		}
	}

	void print()
	{
		for (int fret = 0; fret < STRING_SIZE; fret++)
			std::cout << "  " << fret << "     ";

		std::cout << '\n';

		for (int string = 0; string < NUM_STRINGS; string++)
		{
			for (int fret = 0; fret < STRING_SIZE; fret++)
			{
				mkey::print_note(textGuitar2D[fret][string]);
				std::cout << "   ";
			}
			std::cout << '\n';
		}
	}

	void fillScale(Scale& scale)
	{
		for (int string = 0; string < NUM_STRINGS; string++)
		{
			for (int fret = 0; fret < STRING_SIZE; fret++)
			{
				if (scale::search_scale(scale, textGuitar2D[fret][string]) != true)
					textGuitar2D[fret][string] = static_cast<MusicalKeys>(textGuitar2D[fret][string] + MIDDLE_EMPTY);
			}
		}
	}

	void fillChord(Chord& chord)
	{
		for (int string = 0; string < NUM_STRINGS; string++)
		{
			for (int fret = 0; fret < STRING_SIZE; fret++)
			{
				if (chord::search_chord(chord, textGuitar2D[fret][string]) != true)
					textGuitar2D[fret][string] = static_cast<MusicalKeys>(textGuitar2D[fret][string] + MIDDLE_EMPTY);
			}
		}
	}

	void reset()
	{
		for (int fret = 0; fret < STRING_SIZE; fret++)
		{
			textGuitar2D[fret][5] = sixthString[fret];
			textGuitar2D[fret][4] = fifthString[fret];
			textGuitar2D[fret][3] = fourthString[fret];
			textGuitar2D[fret][2] = thirdString[fret];
			textGuitar2D[fret][1] = secondString[fret];
			textGuitar2D[fret][0] = firstString[fret];
		}
	}
};



