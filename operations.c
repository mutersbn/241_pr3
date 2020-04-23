#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "operations.h"

// ptr is being added to node
product * CreateStore(product * ptr, product * node)
{
	printf("\nCreating linked list with base content.\n");

	/*
	 * TODO: check file for data, else create head, current, and ptr nodes
	 */

	//printf("Store created.");
	ShowProducts(ptr);
	return ptr;
}

// head = the head of our linked list
void AddProduct(product * head)
{
	int success = 0, sscanf_result = 0;
	char in_ProductName[N], in_QuantityUnit[N], in_PriceUnit[N], line[N];
	float in_QuantityValue, in_PriceValue;
	
	product * current = head;
	
	// Move to the end of the linked list
	while(current->next != NULL)
	{
		current = current->next;
	}
	
	// Allocate memory for the next product
	current->next = (product*)malloc(sizeof(product));

	success = 0;
	printf("What would you like to add? (basketballs, iron..)");
	while(!success){
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%s", &in_ProductName);
		printf("sscanf_result: %d\n", sscanf_result);

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			success = 1;
			strcpy(current->next->name, in_ProductName);
		}
	}
/*
	success = false;
	printf("How many would you like to add? (10, 2.5)");
	do{
		success = scanf("%f", &in_QuantityValue);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}else
		{
			current->next->quantity_value = in_QuantityValue;
		}

	}while(!success);
	
	success = false;
	printf("What is this item's quantity unit? (lbs, kg..)");
	do{
		success = scanf("%s", &in_QuantityUnit);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}else
		{
			strcpy(current->next->quantity_unit, in_QuantityUnit);
		}

	}while(!success);
	
	success = false;
	printf("What is the price per unit? (4.49, 0.80..)");
	do{
		success = scanf("%f", &in_PriceValue);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}else
		{
			current->next->price_value = in_PriceValue;
		}

	}while(!success);
	
	success = false;
	printf("What is the price's unit? (USD, YEN..) ");
	do{
		success = scanf("%s", &in_PriceUnit);
		if(!success)
		{
			printf("Please try an appropriate input.\n");
		}else
		{
			strcpy(current->next->price_unit, in_PriceUnit);
		}

	}while(!success);
*/
	current->next->next = NULL;
	printf("Item added to store.\n");
}

void RemoveItem(product *node)
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
		printf("Quantity: %.2f\n", current->quantity_value);
		printf("Units: %s\n", current->quantity_unit);
		printf("Price: %.2f\n", current->price_value);
		printf("Price Unit: %s\n", current->price_unit);
		printf("---------------------------\n");
		
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
