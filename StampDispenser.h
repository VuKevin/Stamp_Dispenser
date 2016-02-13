// Programmer Name: Kevin Vu
// Date: 1/28/2016
// Laserfiche® Coding Challenge: Stamp Dispenser
#pragma once
#include <stdlib.h>
#include <vector>
namespace Laserfiche
{
	/// <summary>
	/// Facilitates dispensing stamps for a postage stamp machine.
	/// </summary>
	class StampDispenser
	{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="StampDispenser"/> class that will be 
			/// able to dispense the given types of stamps.
			/// </summary>
			/// <param name="stampDenominations">
			/// The values of the types of stamps that the machine has.  
			/// Should be sorted in descending order and contain at least a 1.
			/// </param>
			/// <param name="numStampDenominations">
			/// The number of types of stamps in the stampDenominations array. 
			/// </param>
			StampDispenser(const int* stampDenominations, size_t numStampDenominations);

			/// <summary>
			/// Returns the minimum number of stamps that the machine can dispense to
			/// fill the given request.
			/// </summary>
			/// <param name="request">
			/// The total value of the stamps to be dispensed.
			/// </param>
			/// <returns>
			/// The minimum number of stamps needed to fill the given request.
			/// </returns>
			int CalcNumStampsToFillRequest(int request);

			/// <summary>
			/// Destructor
			/// </summary>
			~StampDispenser();
		private:
			/// <summary>
			/// Private variables detailing the Stamp denominations and the size of the list
			/// </summary>
			int *stampCollection;
			int collectionSize;

			/// <summary>
			/// Function to fetch the lowest (best) combination of denominations
			/// </summary>
			int whatIsMinCombo(std::vector<int> denominationSets);
	};
}
