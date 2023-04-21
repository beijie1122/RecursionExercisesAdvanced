#include <iostream>
#include <vector>

void PrintArrayRecursion(int input[], int Size, int Index)
{
	if (Index == Size)
	{
		return;
	}
	std::cout << input[Index] << std::endl;

	PrintArrayRecursion(input, Size, Index + 1);
}

void ReversePrintArrayRecursion(int input[], int Size, int Index)
{
	if (Index == 0)
	{
		return;
	}
	std::cout << input[Index] << std::endl;

	PrintArrayRecursion(input, Size, Index -1);
}

void ReverseAccordingtoClass(int input[])
{
	if (input[0] == '\0')
	{
		return;
	}
	ReverseAccordingtoClass(input + 1);
	std::cout << input[0];
}

void ArrayLengthRecursion(int input[], int Size, int Index, int &Length)
{
	if (Index == Size)
	{
		return;
	}
	else
	{
		Length++;
	}
	ArrayLengthRecursion(input, Size, Index + 1, Length);
}

int ArrayLengthVidVersion(char input[])
{
	if (input[0] == '\0')
	{
		return 0;
	}

	int SmallLength = ArrayLengthVidVersion(input + 1);
	return 1 + SmallLength;
}

void ModifyRecursion(char input[], int ValuetoChange, int ChangedValue)
{
	if (input[0] == '\0')
	{
		return;
	}
	if (input[0] == ValuetoChange)
	{
		input[0] = ChangedValue;
	}
	ModifyRecursion(input + 1, ValuetoChange, ChangedValue);

}

void PrintCharArrayVid(char input[])
{
	if (input[0] == '\0')
	{
		return;
	}
	std::cout << input[0];
	PrintCharArrayVid(input + 1);
}

void RemoveElementinArray(char input[])
{
	if (input[0] == '\0')
	{
		return;
	}
	if (input[0] != 'a')
	{
		RemoveElementinArray(input + 1);
	}
	else
	{
		for (size_t i = 0; input[i] != '\0'; i++)
		{
			input[i] = input[i + 1];
		}
		RemoveElementinArray(input);
	}
}

void RemoveConsecutiveElements(char input[])
{
	if (input[0] == '\0') 
	{
		return;
	}
	if (input[0] != input[1])
	{
		RemoveConsecutiveElements(input + 1);
	}
	else
	{
		for (size_t i = 0; input[i] != '\0'; i++)
		{
			input[i] = input[i + 1];
		}
		RemoveConsecutiveElements(input);
	}

}

void PrintSubs(std::string InputString, std::string OutputString)
{
	if (InputString.length() == 0)
	{
		std::cout << OutputString << std::endl;
		return;
	}
	PrintSubs(InputString.substr(1), OutputString);
	PrintSubs(InputString.substr(1), OutputString + InputString[0]);
	

}

void StoreSubs(std::string InputString, std::string OutputString, std::vector<std::string> &StoreVector)
{
	if (InputString.length() == 0)
	{
		std::cout << OutputString << std::endl;
		StoreVector.push_back(OutputString);
		return;
	}
	StoreSubs(InputString.substr(1), OutputString + InputString[0], StoreVector);
	StoreSubs(InputString.substr(1), OutputString, StoreVector);
	


}


int main()
{
	const int ArraySize{ 10 };
	int TestArray[ArraySize]{1,2,3,4,5};
	char CharArray[ArraySize]{'a','b','c','c','c','e','f'};
	int ArrayLength{};
	std::string InputString{ "abc" };
	std::string OutputString{};
	std::vector<std::string> OutputVector{};

	PrintArrayRecursion(TestArray, ArraySize, 0);

	//ReversePrintArrayRecursion(TestArray, ArraySize, ArraySize - 1);
	
	//ReverseAccordingtoClass(TestArray);

	ArrayLengthRecursion(TestArray, ArraySize, 0, ArrayLength);
	std::cout << "Array Length: " << ArrayLength << std::endl;

	int L = ArrayLengthVidVersion(CharArray);
	std::cout << L << std::endl;

	ModifyRecursion(CharArray, 'e', 'f');
	PrintCharArrayVid(CharArray);
	//RemoveElementinArray(CharArray);
	RemoveConsecutiveElements(CharArray);
	printf("\n");
	PrintCharArrayVid(CharArray);

	PrintSubs(InputString, OutputString);
	StoreSubs(InputString, OutputString, OutputVector);
	printf("Output Vector: ");
	std::cout << OutputVector.size();
	for (size_t i = 0; i < OutputVector.size(); i++)
	{
		std::cout << OutputVector.at(i);
	}
	

	return 0;

}