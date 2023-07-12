#include "InventoryStack.h"

bool FInventoryStack::IsEmpty() const
{
	return count <= 0 && item == nullptr;
}
