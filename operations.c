#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "operations.h"

float total_income = 0;

// ptr is being added to node
void CreateStore(product ** head)
{
	printf("\nCreating linked list with base content.\n");

	FILE * fp;
	char line[100], data_name[N], data_quantity_unit[N], data_price_unit[N];
	float data_quantity_value, data_price_value;
	int sscanf_result = 1, count = 0;
	product * current = *head;

	// Open the file
	fp = fopen("data", "r");
	
	// If opening the file doesn't work, return a NULL head
	if(fp == NULL)
	{
		printf("Unable to open file \"data\"\n");
		return;
	} else
	{
		printf("The file is now open.\n");
		// Read data into a linked list
		
		while(sscanf_result && fgets(line, sizeof(line), fp))
		{	
			sscanf_result = sscanf(line, "%s %f %s %f %s", &data_name,
					&data_quantity_value, &data_quantity_unit,
					&data_price_value, &data_price_unit);

			product * node = (product*)malloc(sizeof(product));
			strcpy(node->name, data_name);
			node->quantity_value = data_quantity_value;
			strcpy(node->quantity_unit, data_quantity_unit);
			node->price_value = data_price_value;
			strcpy(node->price_unit, data_price_unit);
			node->next = NULL;

			// If we're adding the first node...
			if(*head == NULL)
			{
				current = *head = node;
			} else // Anywhere but the first node, move to the next.
			{
				current = current->next = node;
			}
			count++;
		}
		if(count>0)
		{
			printf("Added %d items to the store.\n", count);
		}
		fclose(fp);
	}
}

// head = the head of our linked list
void AddProduct(product ** head)
{
	int success = 0, sscanf_result = 0;
	char in_ProductName[N], in_QuantityUnit[N], in_PriceUnit[N], line[N];
	float in_QuantityValue, in_PriceValue;
	FILE *fp;

	fp = fopen("data", "a");
	
	// Allocate memory for this new node
	// Set a node as a marker to traverse the list
	product * current = (product*)malloc(sizeof(product));
	product * last = *head;

	// *** ITEM NAME *** //
	success = 0;
	while(!success){
		printf("What would you like to add? (basketballs, iron..)\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%s", &in_ProductName);

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			// If we have a name, look to add. 
			// 1. If a product already exists
			// 2. If the product DOESN'T already exist
			//current = FindProduct(head, in_ProductName);
			if(FindProduct(head, in_ProductName) != NULL)
			{
				current = FindProduct(head, in_ProductName);
				printf("This product already exists!\n");
				// *** ITEM AMOUNT *** //
				success = 0;
				while(1){
					printf("How many of this item would you like to add? (10, 2.5..)\t");
					// Read the user's input into line[]
					// Then verify that it was read correctly
					fgets(line, sizeof(line), stdin);
					sscanf_result = sscanf(line, "%f", &in_QuantityValue);

					// If not read correctly, loop back and try again
					if((sscanf_result == 0) || (sscanf_result == EOF))
					{
						printf("Please try an appropriate input.\n");
					} else
					{
						current->quantity_value += in_QuantityValue;
						fprintf(fp, "%.2f", in_QuantityValue);
						fprintf(fp, " ");
						return;
					}
				}

			}

			strcpy(current->name, in_ProductName);
			fputs(in_ProductName, fp);
			fprintf(fp, " ");
			success = 1;
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

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			success = 1;
			current->quantity_value = in_QuantityValue;
			fprintf(fp, "%.2f", in_QuantityValue);
			fprintf(fp, " ");
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

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("Please try an appropriate input.\n");
			success = 0;
		} else
		{
			success = 1;
			strcpy(current->quantity_unit, in_QuantityUnit);
			fputs(in_QuantityUnit, fp);
			fprintf(fp, " ");
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
			current->price_value = in_PriceValue;
			fprintf(fp, "%.2f", in_PriceValue);
			fprintf(fp, " ");
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
			strcpy(current->price_unit, in_PriceUnit);
			fputs(in_PriceUnit, fp);
			fputs("\n", fp);
			fclose(fp);
		}
	}

	current->next = NULL;

	// If the list is empty
	// Then set our new node to be the head
	if(*head == NULL)
	{
		*head = current;
		printf("Item added to store.");
		return;
	}

	// If the list is NOT empty, traverse to the end
	while (last->next != NULL)
	{
		last = last->next;
	}
	
	// When the last->next node is NULL, replace with the current node
	last->next = current;

	printf("Item added to store.\n");
	return;
}

void RemoveItem(product **head, product *node)
{
	FILE *fp1, *fp2;
	char data_name[N], line[100], c;

	fp1 = fopen("data", "r");
	if(fp1==NULL){return;}
	fp2 = fopen("copy", "w");
	if(fp2==NULL){return;} 

	while(fgets(line, sizeof(line), fp1) != NULL)
	{
		sscanf(line, "%s", &data_name);
	
		if(strcmp(node->name, data_name))
		{	
			fputs(line, fp2);
		}
	}

	fclose(fp1);
	fclose(fp2);

	remove("data");
	rename("copy", "data");

	product * temp = *head;
	product * prev;
	
	// If the list is empty
	if(*head == NULL)
	{
		printf("The list is empty. Could not remove your item.\n");
		return;
	}

	// If the head is the node we're removing
	if(temp != NULL && temp->name == node->name)
	{
		printf("Removed the product named %s.\n", temp->name);
		*head = temp->next;
		free(temp);
		return;
	}

	// Search for the node:
	// 	Keep going until the current node is the node to remove
	while(temp != NULL && temp->name != node->name)
	{
		prev = temp; // Keep track of the previous node
		temp = temp->next; 
	}

	// If we got to the end of the list without finding it
	if(temp == NULL)
	{
		printf("Could not find your item!\n");
		return;
	}

	// If we did find it, though...
	prev->next = temp->next;
	free(temp);

	printf("Removed the product named %s.\n", node->name);	
}

void PurchaseProducts(product **head)
{
	float quantity=0, total=0;
	int success = 0, sscanf_result = 0;
	char in_ProductName[N], yn[2], line[N];

	product * temp = *head;
				
	// *** ITEM NAME *** //
	success = 0;
	while(!success){
		printf("What would you like to purchase?\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%s", &in_ProductName);

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

	// If the list is empty
	if(*head == NULL)
	{
		printf("The list is empty. Cannot find your item.\n");
		return;
	}

	// If the head is the node we want to purchase from
	if (temp != NULL && strcmp(temp->name, in_ProductName) == 0)
	{
		// *** NUMBER BEING PURCHASED *** //
		success = 0;
		while(1){
			printf("How many would you like to purchase?\t");
			// Read the user's input into line[]
			// Then verify that it was read correctly
			fgets(line, sizeof(line), stdin);
			sscanf_result = sscanf(line, "%f", &quantity);

			// If not read correctly, or quantity is negative, loop back and try again
			if((sscanf_result == 0) || (sscanf_result == EOF) || quantity < 0)
			{
				printf("Please try an appropriate input.\n");
			} else
			{	
				// If user requesting too much of this item
				if(temp->quantity_value - quantity <= 0)
				{
					total = temp->quantity_value * temp->price_value;
					printf("We did not have the full amount requested.\n");
					printf("You have purchased %.2f of the product named %s.\n", temp->quantity_value, temp->name);
					printf("Your total is %.2f %s\n", total, temp->price_unit);
					total_income += total;

					RemoveItem(head, temp);
					return;
				}

				// If user request will leave some of product in store
				temp->quantity_value -= quantity;
				total = temp->price_value * quantity;
				printf("You purchased %.2f of the product named %s.\n", quantity, temp->name);
				printf("Your total is %.2f %s\n", total, temp->price_unit);
				total_income += total;
				*head = temp;
				return;
			}
		}	
	}
	
	// Loop through all nodes in the system, looking for the name
	while(temp != NULL && strcmp(temp->name, in_ProductName))
	{
		PrintProduct(temp);
		temp = temp->next;
	}

	// If we got to the end of the list, then we didn't find it
	if(temp == NULL)
	{
		printf("There is no product in our store called %s.\n",in_ProductName);

		// *** RETRY y OR n *** //
		success = 0;
		while(1){
			printf("Would you like to choose another product? (y or n) \t");
			// Read the user's input into line[]
			// Then verify that it was read correctly
			fgets(line, sizeof(line), stdin);
			sscanf_result = sscanf(line, "%s", &yn);

			// If not read correctly, loop back and try again
			if((sscanf_result == 0) || (sscanf_result == EOF) || ((strcmp(yn, "y")) && (strcmp(yn, "n"))))
			{
				printf("Please try an appropriate input.\n");
			} else
			{
				if(!strcmp(yn, "y"))
				{
					PurchaseProducts(head);
				}
				return;
			}
		}
	}
	
	// If we found the product
	// *** NUMBER BEING PURCHASED *** //
	while(1){
		printf("How many would you like to purchase?\t");
		// Read the user's input into line[]
		// Then verify that it was read correctly
		fgets(line, sizeof(line), stdin);
		sscanf_result = sscanf(line, "%f", &quantity);

		// If not read correctly, loop back and try again
		if((sscanf_result == 0) || (sscanf_result == EOF) || (quantity < 0))
		{
			printf("Please try an appropriate input.\n");
		} else
		{
			// If user requesting too much of this item
			if(temp->quantity_value - quantity <= 0)
			{
				total = temp->quantity_value * temp->price_value;
				printf("We did not have the full amount requested.\n");
				printf("You have purchased %.2f of the product named %s.\n", temp->quantity_value, temp->name);
				printf("Your total is %.2f %s\n", total, temp->price_unit);
				total_income += total;
				RemoveItem(head, temp);
				return;
			}

			// If user request will leave some of product in store
			temp->quantity_value -= quantity;
			total = temp->price_value * quantity;
			printf("You purchased %.2f of the product named %s.\n", quantity, temp->name);
			printf("Your total is %.2f %s\n", total, temp->price_unit);
			total_income += total;
			return;
		}
	}
}

void CheckPrice(product **head)
{
	product * current;
	current = FindProduct(head, "");
	printf("The price for %s is %.2f %s per %s.\n", current->name,
			current->price_value, current->price_unit, current->quantity_unit);
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

product * FindProduct(product **head, char item_name[])
{
	char in_ProductName[N], line[N];
	strcpy(in_ProductName, item_name);
	int success, sscanf_result;

	product * current = *head;

	// If list is empty, return it back
	if(*head == NULL)
	{
		printf("This list is empty.\n");
		return *head;
	}
	// *** ITEM NAME *** //
	while(1){
		// If the passed item name is an empty string, then ask the user
		if(!strcmp(in_ProductName, ""))
		{
			printf("What product are you looking for?\t");
			// Read the user's input into line[]
			// Then verify that it was read correctly
			fgets(line, sizeof(line), stdin);
			sscanf_result = sscanf(line, "%s", &in_ProductName);

			// If not read correctly, loop back and try again
			if((sscanf_result == 0) || (sscanf_result == EOF))
			{
				printf("Please try an appropriate input.\n");
			} 
		}else
		{
			while(current != NULL)
			{
				// If the current name is the product we're looking for
				if(!strcmp(current->name, in_ProductName))
				{
					return current;
				}
				current = current->next;
			}

			//printf("Could not find the item %s\n", in_ProductName);
			return NULL;
		}
	}
	
}

void PrintProduct(product *node)
{
	if(node != NULL)
	{
		printf("Product Name: %s\n", node->name);
		printf("Quantity: %.2f\n", node->quantity_value);
		printf("Units: %s\n", node->quantity_unit);
		printf("Price: %.2f\n", node->price_value);
		printf("Price Unit: %s\n", node->price_unit);
		printf("---------------------------\n");
	}
}

void Inventory(product **head)
{
	printf("Total amount money made so far: %.2f\n", total_income);
	printf("--------------------------------------\n");
	printf("Available Products in store:\n");
	printf("--------------------------------------\n");
	ShowProducts(*head);
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
