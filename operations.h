#define N 20

struct Product
{
	char name[N];
	float quantity_value;
	char quantity_unit[N];
	float price_value;
	char price_unit[N];
	struct product *next;
};
typedef struct Product product;

product * CreateStore();
void AddProduct(product **l, product *node);
void RemoveItem(product *l, product *node);
float PurchaseProducts(product *l, char product[], float q);
void CheckPrice();
void ShowProducts(product *l);
void Clean();
void FindProduct(product *l, char p[]);
void Inventory();
int LoadData(char inf[], product **l);
int SaveData(char outf[], product *l);
int DoIt(char data[]);
