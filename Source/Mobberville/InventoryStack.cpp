#include "InventoryStack.h"

bool FInventoryStack::IsEmpty()
{
	return count <= 0 && item == nullptr;
}
