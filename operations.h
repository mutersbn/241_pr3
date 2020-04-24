#define N 20
extern float total_income;

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

void CreateStore();
void AddProduct(product **head);
void RemoveItem(product **head, product *node);
void PurchaseProducts(product **head);
void CheckPrice(product **head);
void ShowProducts(product *head);
void Clean();
product * FindProduct(product **head, char name[]);
void PrintProduct(product *node);
void Inventory(product **head);
int LoadData(char inf[], product **head);
int SaveData(char outf[], product *head);
int DoIt(char data[]);
