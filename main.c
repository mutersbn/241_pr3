/*
 * Author: Noah Mutersbaugh
 * Description: Grocery Store Management
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "operations.h"

product *head = NULL;
product *current = NULL;
product *ptr = NULL;

int main()
{
	int selection;
	char in_ProductName[N], yn;
	float quantity;
	bool success = false;
	
	product * ptr = (product*)malloc(sizeof(product)); //ptr is the node being added
	head = current = ptr = CreateStore(ptr, head); // set head and current to the first node

	printf("\nWelcome to Noah Mutersbaugh's grocery store!\n");
	printf("Please let me know what you want to do by typing one of the numbers\n");
	printf("===================================================================\n");
	printf("1: Add product to store              2: Purchase product from store\n");
	printf("3: Check price of a product          4: Show products in the store\n");
	printf("5: Clean up a product from store     6: Find product\n");
	printf("7: Inventory                         8: Done for today\n");
	printf("What would you like to do?\n");
	do{
		if(scanf("%d", &selection) == 1)
		{
			switch(selection)
			{
				case 1:
					printf("1: Add product to store\n");

					AddProduct(ptr, current);
					break;
				case 2:
					printf("2: Purchase product from store\n");
					
					// Scan until a string is returned
					success = false;
					printf("What would you like to purchase? ");
					do{
						success = scanf("%s", &in_ProductName);
						if(!success)
						{
							printf("Please try an appropriate input.\n");
						}
					}while(!success);
					
					// scan until current node is null
					while(current != NULL)
					{
						if(current->name == in_ProductName)
						{
							success = false; // Reset success determinate
							printf("How many %ss would you like to purchase? ", in_ProductName);
							do{
								success = scanf("%f", &quantity);
							}while(!success);
						}
						current = current->next;
					}

					if(!success)
					{
						printf("There is no product in our store called %s.\n",in_ProductName);
						printf("Would you like to choose another product? (y or n) ");
						success = false;
						do{
							scanf("%c", &yn);
							if(yn == 'y' || yn == 'n')
							{
								success = true;
							} else
							{
								printf("\nInvalid response. Please enter 'y' or 'n'.\n");
							}
						}while(!success);
					}

					
					float price = PurchaseProducts(head, in_ProductName, quantity);
					
					break;
				case 3:
					printf("3: Check price of a product\n");
					CheckPrice();
					break;
				case 4:
					printf("4: Show products in the store\n");
					ShowProducts(head);
					break;
				case 5:
					printf("5: Clean up a product from store\n");
					Clean();
					break;
				case 6:
					printf("6: Find product\n");
					//FindProduct(product *store, char p[]);
					break;
				case 7:
					printf("7: Inventory\n");
					Inventory();
					break;
				case 8:
					free(ptr);
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
