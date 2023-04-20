#include <iostream>

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



int main()
{
	const int ArraySize{ 5 };
	int TestArray[ArraySize]{ 1, 2, 3, 4, 5 };

	PrintArrayRecursion(TestArray, ArraySize, 0);

	ReversePrintArrayRecursion(TestArray, ArraySize, ArraySize - 1);

	return 0;

}