// Programmer Name: Kevin Vu
// Date: 1/28/2016
// Laserfiche® Coding Challenge: Stamp Dispenser
#include "StampDispenser.h"
namespace Laserfiche
{
	// Constructor
	StampDispenser::StampDispenser(const int * stampDenominations, size_t numStampDenominations)
	{
		stampCollection = new int[numStampDenominations];
		collectionSize = numStampDenominations;
		// Initialize the values in the stampCollection Array
		// Reverse initialization to support an ascending order
		for (int index = collectionSize - 1; index >= 0; index--)
		{
			stampCollection[collectionSize - index - 1] = stampDenominations[index];
		}
	
	}

	// Calculates the minimum number of Stamps required to fill the Request
	// By incrementally determining if a value from the Stamp collection
	// Is able to be used as one of the denominations of the request
	// Algorithm based off Dynamic Programming Coin problem, for example.
	int StampDispenser::CalcNumStampsToFillRequest(int request)
	{
		int result;
		int *optimalNumStamps = new int[request + 1];
		optimalNumStamps[0] = 0;
		int index1 = 1;
		while (index1 <= request)
		{
			// Create a int class of vectors to store possible sets of working denominations
			std::vector<int> denominationSets;
			int index2 = 0;
			while (index2 < collectionSize)
			{
				if (stampCollection[index2] <= index1)
					denominationSets.insert(denominationSets.end(), 
						optimalNumStamps[index1 - stampCollection[index2]] + 1);
				index2++;
			}
			optimalNumStamps[index1] = whatIsMinCombo(denominationSets);
			index1++;
		}
		result = optimalNumStamps[request];
		return result;
	}

	StampDispenser::~StampDispenser()
	{
		delete[] stampCollection;
	}

	// Fetches the smallest number from the vector
	int StampDispenser::whatIsMinCombo(std::vector<int> denominationSets)
	{
		int smallestNum = denominationSets[0];
		int index = 1;
		// Hoisted/Code Movement to avoid multiple calls to size()
		int denomSetsSize = denominationSets.size();
		while (index < denomSetsSize)
		{
			// If the smallestNum isn't really the smallestNum
			// Replace it with the next small number
			if (smallestNum > denominationSets[index]){
				smallestNum = denominationSets[index];
			}
			index++;
		}
		return smallestNum;
	}
}
