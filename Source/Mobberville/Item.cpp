#include "Item.h"

bool FItem::operator==(const FItem& other) const
{
	return name.Equals(other.name) && stackSize == other.stackSize;
}

bool FItem::operator!=(const FItem& other) const
{
	return !(*this == other);
}
