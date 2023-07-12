#include "Item.h"
#include "ItemInstance.h"

bool FItem::operator==(const FItem& other) const
{
	return blueprint == other.blueprint;
}

bool FItem::operator!=(const FItem& other) const
{
	return !(*this == other);
}
