#define N 20

struct Product
{
	char name[N];
	float quantity_value;
	char quantity_unit[N];
	float price_value;
	char price_unit[N];
	struct Product * next;
};
typedef struct Product product;

product * CreateStore();
void AddProduct(product *head, product *current);
void RemoveItem(product *head, product *current);
float PurchaseProducts(product *head, char product[], float q);
void CheckPrice();
void ShowProducts(product *head);
void Clean();
void FindProduct(product *head, char p[]);
void Inventory();
int LoadData(char inf[], product **head);
int SaveData(char outf[], product *head);
int DoIt(char data[]);
