#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

// ptr is being added to node
product * CreateStore(product * ptr, product * node)
{
	printf("\nCreating linked list with base content.\n");
	/*	
	strcpy(ptr->name, "Product1");
	ptr->quantity_value = 10;
	strcpy(ptr->quantity_unit, "Kilograms");
	ptr->price_value = 100;
	strcpy(ptr->price_unit, "Yen");
	ptr->next = NULL;
	*/

	//printf("Store created.");
	ShowProducts(ptr);
	return ptr;
}

void AddProduct(product * ptr, product *node)
{
	
}

void RemoveItem(product *head, product *node)
{

}

float PurchaseProducts(product *head, char product_name[], float q)
{
	float price = 0;
	printf("Would like to purchase %.2f %ss.\n", q, product_name);
	price = q * head->price_value;
	return price;
}

void CheckPrice()
{

}

void ShowProducts(product *head)
{
	product * current = head;
	if(current == NULL){
		printf("Nothing is currently in the store.\n");
	}
	while(current != NULL)
	{
		printf("Product Name: %s\n", current->name);
		printf("Quantity: %f\n", current->quantity_value);
		printf("Units: %s\n", current->quantity_unit);
		printf("Price: %f\n", current->price_value);
		printf("Price Unit: %f\n", current->price_unit);
		current = current->next;
	}
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
