#pragma once
#include <iostream>

enum MusicalKeys
{
	// the different keys
	A = 1,
	AsBf = 2,
	B = 3,
	C = 4,
	CsDf = 5,
	D = 6,
	DsEf = 7,
	E = 8,
	F = 9,
	FsGf = 10,
	G = 11,
	GsAf = 12,

	// var for representing empty
	MIDDLE_EMPTY = 14,

	// the different keys that are not part of the associated scale
	not_A = 15,
	not_AsBf = 16,
	not_B = 17,
	not_C = 18,
	not_CsDf = 19,
	not_D = 20,
	not_DsEf = 21,
	not_E = 22,
	not_F = 23,
	not_FsGf = 24,
	not_G = 25,
	not_GsAf = 26,

	// open notes on guitar
	start_E = 27,
	start_B = 28,
	start_G = 29,
	start_D = 30,
	start_A = 31
};

const int KEYGENSIZE = 24;

const MusicalKeys KeyGenArray[KEYGENSIZE] =
{
	A,		// 0
	AsBf,	// 1
	B,		// 2
	C,		// 3
	CsDf,	// 4
	D,		// 5
	DsEf,	// 6
	E,		// 7
	F,		// 8
	FsGf,	// 9
	G,		// 10
	GsAf,	// 11
	A,		// 12
	AsBf,	// 13
	B,		// 14
	C,		// 15
	CsDf,	// 16
	D,		// 17
	DsEf,	// 18
	E,		// 19
	F,		// 20
	FsGf,	// 21
	G,		// 22
	GsAf	// 23
};

namespace mkey
{
	void print_note(const MusicalKeys& mKNote)
	{
		switch (mKNote)
		{
		case A:
			std::cout << " [A] ";
			break;
		case AsBf:
			std::cout << "[AsBf]";
			break;
		case B:
			std::cout << " [B] ";
			break;
		case C:
			std::cout << " [C] ";
			break;
		case CsDf:
			std::cout << "[CsDf]";
			break;
		case D:
			std::cout << " [D] ";
			break;
		case DsEf:
			std::cout << "[DsEf]";
			break;
		case E:
			std::cout << " [E] ";
			break;
		case F:
			std::cout << " [F] ";
			break;
		case FsGf:
			std::cout << "[FsGf]";
			break;
		case G:
			std::cout << " [G] ";
			break;
		case GsAf:
			std::cout << "[GsAf]";
			break;
		case 13:
			std::cout << "Unlucky shit";
			break;
		case MIDDLE_EMPTY:
			std::cout << "MID_EMP";
			break;
		case not_A:
			std::cout << "  A  ";
			break;
		case not_AsBf:
			std::cout << " AsBf ";
			break;
		case not_B:
			std::cout << "  B  ";
			break;
		case not_C:
			std::cout << "  C  ";
			break;
		case not_CsDf:
			std::cout << " CsDf ";
			break;
		case not_D:
			std::cout << "  D  ";
			break;
		case not_DsEf:
			std::cout << " DsEf ";
			break;
		case not_E:
			std::cout << "  E  ";
			break;
		case not_F:
			std::cout << "  F  ";
			break;
		case not_FsGf:
			std::cout << " FsGf ";
			break;
		case not_G:
			std::cout << "  G  ";
			break;
		case not_GsAf:
			std::cout << " GsAf ";
			break;
		default:
			std::cout << "ERROR: switch_note in MusicalKeys.cpp";
			std::cout << "\tmKNote: " << '(' << mKNote << ')' << '\n';
			break;
		}
	}

	int findIndex(const MusicalKeys& key_arg)
	{
		int index = 0;

		while (index < KEYGENSIZE)
		{
			if (KeyGenArray[index] == key_arg)
				return index;
			index++;
		}
	}
}
