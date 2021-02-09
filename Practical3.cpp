#include<iostream>
 #include<cstdlib>
 #include<string>
 #include<cstdio>
 using namespace std;
 const int TABLE_SIZE = 128;

 class HashEntry
 {
 public:
 int key;
 int value;
 HashEntry(int key, int value)
 {
 this->key = key;
 this->value = value;
 }
 };

 class HashMap
 {
 private:
 HashEntry **table;
 public:
 HashMap()
 {
 table = new HashEntry * [TABLE_SIZE];
 for (int i = 0; i< TABLE_SIZE; i++)
 {
 table[i] = NULL;
 }
 }
 int HashFunc(int key)
 {
 return key % TABLE_SIZE;
 }
 void Insert(int key, int value)
 {
 int hash = HashFunc(key);
 while (table[hash] != NULL && table[hash]->key != key)
 {
 hash = HashFunc(hash + 1);
 }
 if (table[hash] != NULL)
 delete table[hash];
 table[hash] = new HashEntry(key, value);
 }
 int Search(int key)
 {
 int hash = HashFunc(key);
 while (table[hash] != NULL && table[hash]->key != key)
 {
 hash = HashFunc(hash + 1);
 }
 if (table[hash] == NULL)
 return -1;
 else
 return table[hash]->value;
 }


 };
 int main()
 {
 HashMap hash;
 int key, value;
 int choice;
 while (1)
 {
 cout<<"\n----------------------"<<endl;
 cout<<"Operations on Hash Table"<<endl;
 cout<<"\n----------------------"<<endl;
 cout<<"1.Insert element into the table"<<endl;
 cout<<"2.Search element from the key"<<endl;
 cout<<"4.Exit"<<endl;
 cout<<"Enter your choice: ";
 cin>>choice;
 switch(choice)
 {
 case 1:
 cout<<"Enter element to be inserted: ";
 cin>>value;
 cout<<"Enter key at which element to be inserted: ";
 cin>>key;
 hash.Insert(key, value);
 break;
 case 2:
 cout<<"Enter key of the element to be searched: ";
 cin>>key;
 if (hash.Search(key) == -1)
 {
 cout<<"No element found at key "<<key<<endl;
 continue;
 }
 else
 {
     cout<<"------------------------------------\n";
 cout<<"Element at key "<<key<<" : ";
 cout<<hash.Search(key)<<endl;
 }
 break;
 case 3:
 exit(1);
 default:
 cout<<"\nEnter correct option\n";
 }
 }
 return 0;
 }
