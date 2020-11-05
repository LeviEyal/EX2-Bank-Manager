#define COL 50
#define RAW 2

extern double bank[RAW][COL];

void open(double amount);
void balance(int account);
void deposit(int account, double amount);
void withdrawal(int account, double amount);
void close(int account);
void addInterest(double interest);
void printAll();
void exit();
