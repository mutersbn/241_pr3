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

	// *** ITEM NAME *** //
	success = 0;
	while(!success){
		printf("What would you like to add? (basketballs, iron..)\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%s", &in_ProductName);
		printf("product name: %s\n", in_ProductName);

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

	// *** ITEM AMOUNT *** //
	success = 0;
	while(!success){
		printf("How many of this item would you like to add? (10, 2.5..)\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%f", &in_QuantityValue);
		printf("quantity value: %.2f\n", in_QuantityValue);

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			success = 1;
			current->next->quantity_value = in_QuantityValue;
		}
	}

	// *** ITEM UNIT *** //
	success = 0;
	while(!success){
		printf("What is this item's unit? (kg, lbs..)\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%s", &in_QuantityUnit);
		//printf("quantity unit: %s\n", in_QuantityUnit);

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			success = 1;
			strcpy(current->next->quantity_unit, in_QuantityUnit);
		}
	}

	// *** ITEM PRICE *** //
	success = 0;
	while(!success){
		printf("What is the price per unit? (4.49, 0.80..)\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%f", &in_PriceValue);

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			success = 1;
			current->next->price_value = in_PriceValue;
		}
	}

	// *** PRICE UNIT *** //
	success = 0;
	while(!success){
		printf("What is the price unit? (USD, EUR..)\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%s", &in_PriceUnit);

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			success = 1;
			strcpy(current->next->price_unit, in_PriceUnit);
		}
	}

	current->next->next = NULL;
	printf("Item added to store.\n");
}

void RemoveItem(product *node)
{

}

float PurchaseProducts(product *head)
{
	float quantity;
	char in_ProductName[N], yn[2];
	bool product_found = false;
				
	// *** ITEM NAME *** //
	success = 0;
	while(!success){
		printf("What would you like to purchase?\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%s", &in_ProductName);
		printf("product name: %s\n", in_ProductName);

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			success = 1; // exit loop
		}
	}
	
	// Loop through all nodes in the system
	while(current != NULL)
	{
		// If the current node is the product being purchased
		if(current->name == in_ProductName)
		{
			// *** NUMBER BEING PURCHASED *** //
			success = 0;
			while(!success){
				printf("How many would you like to purchase?\t");
				// Read the user's input into line[]
				// Then verify that it was read correctly
				fgets(line, sizeof(line), stdin);
				sscanf_result = sscanf(line, "%f", &quantity);

				// If not read correctly, loop back and try again
				if((sscanf_result == 0) || (sscanf_result == EOF))
				{
					printf("Please try an appropriate input.\n");
					success = 0;
				} else
				{
					RemoveItem(in_ProductName, quantity);
					success = 1;
				}
			}
			product_found = true;
		}
		current = current->next;
	}

	if(!product_found)
	{
		printf("There is no product in our store called %s.\n",in_ProductName);
		printf("Would you like to choose another product? (y or n) ");
		// *** NUMBER BEING PURCHASED *** //
		success = 0;
		while(!success){
			printf("How many would you like to purchase?\t");
			// Read the user's input into line[]
			// Then verify that it was read correctly
			fgets(line, sizeof(line), stdin);
			sscanf_result = sscanf(line, "%s", &yn);

			// If not read correctly, loop back and try again
			if((sscanf_result == 0) || (sscanf_result == EOF))
			{
				printf("Please try an appropriate input.\n");
				success = 0;
			} else
			{
				if(yn == "y")
				{
					PurchaseProducts(head);
				}
				success = 1;
			}
		}
	}
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
