#pragma once
#include "MusicalKeys.h"
#include <iostream>

namespace
{
	const int SCALE_SIZE = 8;
	const int PENTATONIC_SCALE_SIZE = 6;

	class Scale
	{
	private:

	protected:
		int scaleSize;

		MusicalKeys* scalePtr;

	public:
		Scale() {}

		Scale(int size) : scaleSize(size)
		{
			scalePtr = new MusicalKeys[scaleSize];
			for (int index = 0; index < scaleSize; index++)
			{
				scalePtr[index] = MIDDLE_EMPTY;
			}
		}

		virtual ~Scale()
		{
			delete[] scalePtr;
			//std::cout << "DELETED scalePtr!" << std::endl;
		}

		virtual const int getSize()
		{
			return scaleSize;
		}

		MusicalKeys& operator[] (const unsigned int& index)
		{
			return scalePtr[index];
		}

		Scale& operator=(Scale& right)
		{
			scaleSize = right.scaleSize;
			for (int index = 0; index < scaleSize; index++)
			{
				this->operator[](index) = right[index];
			}
			return *this;
		}
	};

	class MajorScale : public Scale
	{
	private:

	public:
		MajorScale() : Scale(SCALE_SIZE) {}

		MajorScale(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[7] = KeyGenArray[saveIndex = saveIndex + 1];
		}

	};

	class MinorScale : public Scale
	{
	public:
		MinorScale() : Scale(SCALE_SIZE) {}

		MinorScale(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[7] = KeyGenArray[saveIndex = saveIndex + 2];
		}
	};

	class MajorPentatonic : public Scale
	{
	public:
		MajorPentatonic() : Scale(PENTATONIC_SCALE_SIZE) {}

		MajorPentatonic(MusicalKeys key_arg) : Scale(PENTATONIC_SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 3];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 3];
		}
	};

	class MajorPentNoThirdAddFourth : public Scale 
	{
	public:
		MajorPentNoThirdAddFourth() : Scale(PENTATONIC_SCALE_SIZE) {}

		MajorPentNoThirdAddFourth(MusicalKeys key_arg) : Scale(PENTATONIC_SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 3];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[tonicIndex];
		}
	};

	class MinorPentatonic : public Scale
	{
	public:
		MinorPentatonic() : Scale(PENTATONIC_SCALE_SIZE) {}

		MinorPentatonic(MusicalKeys key_arg) : Scale(PENTATONIC_SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 3];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 3];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
		}
	};

	class LydianMode : public Scale
	{
	public:
		LydianMode() : Scale(SCALE_SIZE) {}

		LydianMode(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[7] = KeyGenArray[tonicIndex];
		}
	};

	class Dorian : public Scale
	{
	public:
		Dorian() : Scale(SCALE_SIZE) {}

		Dorian(MusicalKeys key_arg) : Scale(SCALE_SIZE) // 1 2 b3 4 5 6 b7 
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[7] = KeyGenArray[tonicIndex];
		}
	};

	class Aeolian : public Scale
	{
	public:
		Aeolian() : Scale(SCALE_SIZE) {}

		Aeolian(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[7] = KeyGenArray[tonicIndex];
		}
	};

	class LocrianMode : public Scale // 1 b2 b3 4 b5 b6 b7 1
	{
	public:
		LocrianMode() : Scale(SCALE_SIZE) {}

		LocrianMode(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[7] = KeyGenArray[saveIndex = saveIndex + 2];
		}
	};

	class MelodicMinor : public Scale
	{
	public:
		MelodicMinor() : Scale(SCALE_SIZE) {}

		MelodicMinor(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[7] = KeyGenArray[tonicIndex];
		}
	};

	class MixolydianMode : public Scale
	{
	public:
		MixolydianMode() : Scale(SCALE_SIZE) {}

		MixolydianMode(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[7] = KeyGenArray[tonicIndex];
		}
	};

	class MixolydianSharpFourMode : public Scale
	{
	public:
		MixolydianSharpFourMode() : Scale(SCALE_SIZE) {}

		MixolydianSharpFourMode(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[7] = KeyGenArray[saveIndex = saveIndex + 2];
		}
	};

	class WholeTone : public Scale // 1 2 3 b5 s5 b7 1
	{
	public:
		WholeTone() : Scale(SCALE_SIZE - 1) {}

		WholeTone(MusicalKeys key_arg) : Scale(SCALE_SIZE - 1)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
		}
	};

	class DiminishedWholeTone : public Scale // 1 b2 b3 3 b5 #5 b7 1
	{
	public:

		DiminishedWholeTone() : Scale(SCALE_SIZE) {}

		DiminishedWholeTone(MusicalKeys key_arg) : Scale(SCALE_SIZE)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[7] = KeyGenArray[saveIndex = saveIndex + 2];
		}
	};

	class HalfWholeDiminished : public Scale // 1 b2 b3 3 b5 5 6 b7 1
	{
	public:

		HalfWholeDiminished() : Scale(SCALE_SIZE + 1) {}

		HalfWholeDiminished(MusicalKeys key_arg) : Scale(SCALE_SIZE + 1)
		{
			int saveIndex = mkey::findIndex(key_arg);
			int tonicIndex = saveIndex;

			scalePtr[0] = KeyGenArray[tonicIndex];
			scalePtr[1] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[2] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[3] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[4] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[5] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[6] = KeyGenArray[saveIndex = saveIndex + 2];
			scalePtr[7] = KeyGenArray[saveIndex = saveIndex + 1];
			scalePtr[8] = KeyGenArray[saveIndex = saveIndex + 2];
		}
	};


}

namespace scale
{
	void print_scale(Scale& scale)
	{
		for (int index = 0; index < scale.getSize(); index++)
		{
			std::cout << "Note #" << index + 1 << ": ";
			mkey::print_note(scale[index]);
			std::cout << '\n';
		}
	}

	bool search_scale(Scale& scale, const MusicalKeys& key_arg)
	{
		bool found = false;
		int scaleIndex = 0;
		while (scaleIndex < scale.getSize() - 1 && found == false)
		{
			if (key_arg == scale[scaleIndex])
			{
				found = true;
			}
			else
				scaleIndex++;
		}

		return found;
	}

	void reset_scale(Scale& scale)
	{
		for (int index = 0; index < scale.getSize(); index++)
		{
			scale[index] = MIDDLE_EMPTY;
		}
	}
}