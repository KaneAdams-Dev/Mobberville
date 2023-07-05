#include "InventoryStack.h"

UInventoryStack::UInventoryStack()
{
	
}

UInventoryStack* UInventoryStack::Create(AItem* item, int64 maxSize, int64 size)
{
	UInventoryStack* stack = NewObject<UInventoryStack>();
	stack->item = item;
	stack->maxSize = maxSize;
	stack->size = size;

	stack->ClampSize();
	return stack;
}

void UInventoryStack::ClampSize()
{
	if (maxSize > 0)
	{
		// Clamp size to the max size.
		size = FMath::Clamp(size, 0, maxSize);
	}
	else if (size < 0)
	{
		// No size limit, just make sure size is not below zero.
		size = 0;
	}
}

void UInventoryStack::Add(int64 count)
{
	size += count;
	ClampSize();
}

void UInventoryStack::Remove(int64 count)
{
	size -= count;
	ClampSize();
}

int64 UInventoryStack::GetSize()
{
	return size;
}

int64 UInventoryStack::GetMaxSize()
{
	return maxSize;
}
