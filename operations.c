#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

product * head = NULL;
product * node = NULL;

struct Product * CreateStore()
{
	printf("\nCreating linked list with empty headnode.\n");
	product * ptr = (product*)malloc(sizeof(product));
	if(ptr == NULL)
	{
		printf("\nNode creation failed.\n");
		return NULL;
	}

	strcpy(ptr->name, "Product1");
	ptr->quantity_value = 10;
	strcpy(ptr->quantity_unit, "Kilograms");
	ptr->price_value = 100;
	strcpy(ptr->price_unit, "Yen");
	ptr->next = NULL;

	head = node = ptr;

	printf("Store created.");
	return ptr;
}

void AddProduct(product **head, product *node)
{
	
}

void RemoveItem(product *head, product *node)
{

}

float PurchaseProducts(product *head, char product_name[], float q)
{
	return 0.0;
}

void CheckPrice()
{

}

void ShowProducts(product *head)
{

}

void Clean()
{

}

void FindProduct(product *head, char p[])
{

}

void Inventory()
{

}

int LoadData(char inf[], product **head)
{
	return 1;
}

int SaveData(char outf[], product *head)
{
	return 2;
}

int DoIt(char data[])
{
	return 3;
}
