/*
 * Author: Noah Mutersbaugh
 * Description: Grocery Store Management
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "operations.h"

int main()
{
	int selection = 0, sscanf_result = 0;
	char yn, line[N];
	float quantity;
	bool success = false, swExit = false;
	product *head = NULL;
	product *ptr = NULL;

	CreateStore(&head); // set head and current to the first node

	while(!swExit)
	{
		printf("\nWelcome to Noah Mutersbaugh's grocery store!\n");
		printf("Please let me know what you want to do by typing one of the numbers\n");
		printf("===================================================================\n");
		printf("1: Add product to store              2: Purchase product from store\n");
		printf("3: Check price of a product          4: Show products in the store\n");
		printf("5: Clean up a product from store     6: Find product\n");
		printf("7: Inventory                         8: Done for today\n");
		printf("What would you like to do?\n");

		fgets(line, sizeof(line), stdin);
		printf("line: %s\n", line);
		sscanf_result = sscanf(line, "%d", &selection);
	
		// if not an integer or an end-of-line
		if((sscanf_result == 0) || (sscanf_result == EOF))
		{
			printf("sscanf_result: %d\n", sscanf_result);
			printf("This is not a valid selection, please try again!\n");
			selection=0;
		}

		switch(selection)
		{
			case 1:
				printf("1: Add product to store\n");
				AddProduct(&head);
				break;
			case 2:
				printf("2: Purchase product from store\n");
				PurchaseProducts(&head);
				break;
			case 3:
				printf("3: Check price of a product\n");
				CheckPrice(&head);
				break;
			case 4:
				printf("4: Show products in the store\n");
				ShowProducts(head);
				break;
			case 5:
				printf("5: Clean up a product from store\n");
				RemoveItem(&head, FindProduct(&head, ""));
				break;
			case 6:
				printf("6: Find product\n");
				PrintProduct(FindProduct(&head, ""));
				break;
			case 7:
				printf("7: Inventory\n");
				Inventory(&head);
				break;
			case 8:
				printf("8: Thank you for stopping by!\n");
				swExit = true;
				break;
			default:
				break;
		}
		fflush(stdin);
		selection=0;
	}

	free(head);
	free(ptr);

	return 0;
}
