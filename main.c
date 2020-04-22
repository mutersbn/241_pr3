/*
 * Author: Noah Mutersbaugh
 * Description: Grocery Store Management
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

product * head = NULL;
product * current = NULL;

int main()
{
	head = CreateStore();
	int selection;

	printf("\nWelcome to Noah Mutersbaugh's grocery store!\n");
	printf("Please let me know what you want to do by typing one of the numbers\n");
	printf("===================================================================\n");
	printf("1: Add product to store              2: Purchase product from store\n");
	printf("3: Check price of a product          4: Show products in the store\n");
	printf("5: Clean up a product from store     6: Find product\n");
	printf("7: Inventory                         8: Done for today\n");
	printf("What do you want to do?\n");
	do{
		if(scanf("%d", &selection) == 1)
		{
			switch(selection)
			{
				case 1:
					printf("1: Add product to store\n");
					AddProduct(product **head, product *current);
					break;
				case 2:
					printf("2: Purchase product from store\n");
					float num = PurchaseProducts(product *head, char product[],float q);
					break;
				case 3:
					printf("3: Check price of a product\n");
					CheckPrice();
					break;
				case 4:
					printf("4: Show products in the store\n");
					ShowProducts(product *head);
					break;
				case 5:
					printf("5: Clean up a product from store\n");
					Clean();
					break;
				case 6:
					printf("6: Find product\n");
					FindProduct(product *store, char p[]);
					break;
				case 7:
					printf("7: Inventory\n");
					Inventory();
					break;
				case 8:
					printf("8: Thank you for stopping by!\n");
					exit(0);
					break;
				default:
					printf("This is not a valid selection, please try again!\n");
			}
		}
	} while(1);

	return 0;
}
