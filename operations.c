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
	success = false;
	printf("What would you like to add? (basketballs, iron..)");
	do{
		success = scanf("%s", &in_ProductName);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}

	}while(!success);

	success = false;
	printf("How many would you like to add? (10, 2.5)");
	do{
		success = scanf("%s", &quantity);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}

	}while(!success);
	
	success = false;
	printf("What is this item's quantity unit? (lbs, kg..)");
	do{
		success = scanf("%s", &unit);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}

	}while(!success);
	
	success = false;
	printf("What is the price per unit? (4.49, 0.80..)");
	do{
		success = scanf("%s", &price);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}

	}while(!success);
	
	success = false;
	printf("What is the price's unit? (USD, YEN..) ");
	do{
		success = scanf("%s", &price_unit);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}else{
			
		}

	}while(!success);
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
