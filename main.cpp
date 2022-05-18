#include <iostream>
#include <string>
using namespace std;

struct date{
  int year;
  int month;
  int day;
  int hour;
  int min;
};

enum category{
  novel, fantasy, biography, poetry, crime, mistery, classic, drama, psychological, aventure
};

struct bookInfo {
  int book_id;
  string title;
  int volume;
  string author;
  int stock;
  category genre;
};

struct clientInfo {
  int client_id;
  string name;
  string surname;
  string address; 
  int phone_no;
  int nid;
  string email;
  bool active=false;
  bool havebook=false;
};

enum status{handed,not_handed};

struct transactionInfo{
  int tr_id;
  int book_id;
  int client_id;
  date start_date;
  date end_date;
  status handed;
  bool active=false ;
  string booktitle ;
  int status;
};

bookInfo book[100];            
clientInfo client[100];        
transactionInfo transaction[100];
int bnr=0;
int cnr=0;
int trnr=0 ;
int trid=0;

void Menu();                           
void goTOmenu();               
void add(int booknr);      
void add();  
void deactivateClient();              
void pickBook();                       
void handBook();                       
void clientHistory();                     
void badClient();                      
int turn(int n);

int main(){
Menu();
return 0;
}

void Menu(){ 
  int nr;
  cout<<"MENU"<<endl 
      <<"1. Add new book"<<endl
      <<"2. Add new client"<<endl
      <<"3. Deactivate client"<<endl 
      <<"4. Pick a book"<<endl
      <<"5. Hand in the book"<<endl
      <<"6. Client transactions"<<endl
      <<"7. Bad clients"<<endl;
  cin>>nr;
  if(nr==1){
    bnr++ ;
    add(bnr) ;
  }
  if(nr==2){
    cnr++ ;
    add() ;
  }
  if(nr==3){
    deactivateClient();
  }
  if(nr==4){
    trnr++ ;
    pickBook();
  }
  if(nr==5){
    handBook();
  }
  if(nr==6){
    clientHistory();
  }
  if(nr==7){
    badClient();
  } 
}

void goTOmenu(){
  int nr;
  cout<<"Enter 0 to go to menu";
  cin>>nr;
  if (nr==0){
    Menu() ;
  }
  else{
    cout<<"Please enter a valid number"<<endl ;
    goTOmenu();//recursive call
  }
}

int turn(int n){ 
 cout<<"Enter the book genre:";
  cin>>n;
  switch(n){
    case 1:cout<<"novel";
             break;
    case 2:cout<<"fantasy";
             break;
    case 3:cout<<"biography";
             break;      
    case 4:cout<<"poetry";
             break;   
    case 5:cout<<"crime";
             break; 
    case 6:cout<<"mistery";
             break; 
    case 7:cout<<"classic";
             break; 
    case 8:cout<<"drama";
             break; 
    case 9:cout<<"psychological";
             break; 
    case 10:cout<<"aventure";
             break; 
               default:cout<<"Error!";
                break;  
       }   
    return 0;        
}

int bookGenre(bookInfo type,category n){
   if(type.genre==n){ 
   return type.genre;
   }
   return 0;
}

 void add(int booknr){
 int name,n;
 cout<<"Enter the book id:";
 cin>>book[booknr].book_id;
 cout<<"Enter the title of the book:";
 cin>>book[booknr].title;
 cout<<"Enter the volume of the book:";
 cin>>book[booknr].volume;
 cout<<"Enter the author of the book:";
 cin>>book[booknr].author;
 cout<<"Enter the stock of the book";
 cin>>book[booknr].stock;
 cout<<"Enter the genre of the book:(1-novel, 2-fantasy, 3-biography, 4-poetry, 5-crime, 6-mistery, 7-classic, 8-drama, 9-psychologocal, 10-aventure)"<<endl;
 cin>>name;
 cout<<turn(n)<<endl;
 cout<<"The book is now registered"<<endl;
 goTOmenu();
}

void add(){
  cout<<"Enter the client id:";
  cin>>client[cnr].client_id;
  cout<<"Enter the name and surname of the client:";
  cin>>client[cnr].name>>client[cnr].surname;
  cout<<"Enter the address of the client:";
  cin>>client[cnr].address;
  cout<<"Enter the nid of the client:";
  cin>>client[cnr].nid;
  cout<<"Enter the phone_no of the client:";
  cin>>client[cnr].phone_no;
  cout<<"Enter the email of the client:";
  cin>>client[cnr].email;
  client[cnr].active=true;
  goTOmenu(); 
}

void deactivateClient()
{
  int ID;
  cout<<"Enter the client ID:";
  cin>>ID;
  for (int i=1 ; i<100 ;i++)
   { 
    if (client[i].client_id==ID)
    {
      if (client[i].active==false)
      {
        cout<<"This client is deactivated"<<endl; 
         goTOmenu();
      }

      if (client[i].havebook==true)
      {
        cout<<"Please hand in your book fistly."<<endl;
         goTOmenu();
      }
      else
      client[i].active=false ;
      cout<<"This account has been deactivated"<<endl;
       goTOmenu();
    }
    if (client[i].client_id!=ID)
      break;
  }
  cout<<"Please enter a valid client id!"<<endl;
  Menu();
}

void pickBook()
{
  int ID;
  string bookTitle;
  cout<<"Enter the client ID"<<endl;
  cin>>ID;
  for (int i=1;i<100;i++)
  {
    if (client[i].client_id==ID)
    {
      if(client[i].havebook==true)
      {
      cout<<"Sorry you already have taken a book from the library, please return the book in order to get the next one."<<endl;
      goTOmenu();
      }
      if (client[i].active==false)
      {
    
      cout<<"Sorry you have to reactivate your account or register for a new one if u have never registered to pick up a book";
      goTOmenu();
      }
      if (client[i].active==true && client[i].havebook==false)
      {
          cout<<"Please enter the book title correctly";
          cin>>bookTitle;
          for (int j=1;j<100;j++)
            { 
              if (bookTitle==book[j].title)
              {
                if (book[j].stock==0)
                {
                  cout<<"Sorry the book is out of stock."<<endl;
                  goTOmenu();
                }
                if (book[j].stock!=0)
                {
                book[j].stock=book[j].stock-1;
                client[i].havebook=true;
                transaction[trnr].book_id=book[j].book_id; 
                transaction[trnr].tr_id=trid++;
                transaction[trnr].client_id=client[i].client_id;
                transaction[trnr].booktitle=book[j].title;
                cout<<"Enter the date the client picked up the book"<<endl;
                cout<<"Enter the year:"<<endl;
                cin>>transaction[trid].end_date.year;
                cout<<"Enter the month:"<<endl;
                cin>>transaction[trid].end_date.month;
                cout<<"Enter the day:"<<endl;
                cin>>transaction[trid].end_date.day;
                cout<<"Enter the hour:"<<endl;
                cin>>transaction[trid].end_date.hour;
                cout<<"Enter the minute:"<<endl;
                cin>>transaction[trid].end_date.min;             
                cout<<"The data is stored. The client can pick up the book."<<endl;
                transaction[trnr].active=true;
                Menu();
                }
              }
            }
              cout<<"Sorry this book is not available, please enter 0 to go back to menu"<<endl;
              cin>>bookTitle;
              if (bookTitle=="0")
              {
                Menu();
              }
      }
    }
    if (client[i].client_id!=ID)
    {
      cout<<"Please enter a valid ID number!"<<endl;
    }
  }
}

void handBook()
{
  int ID;
  cout<<"Enter the client ID"<<endl;
  cin>>ID;
 for(int i=0;i<100;i++)
 {
   if(client[i].client_id==ID && client[i].havebook==true)
   {
     for(int j=0;j<100;j++)
     {
       if(transaction[j].client_id==client[i].client_id && transaction[j].active==true )
       {
            cout<<"Enter the time the book was returned:"<<endl;
            cout<<"Enter the 1)year, 2)month, 3)day, 4)hour, 5)minute:"<<endl;
            cin>>transaction[trid].end_date.year;
            cin>>transaction[trid].end_date.month;
            cin>>transaction[trid].end_date.day;
            cin>>transaction[trid].end_date.hour;
            cin>>transaction[trid].end_date.min;
      transaction[j].status=transaction[j].end_date.year-transaction[j].start_date.year;
         cin>>transaction[j].end_date.day;
         transaction[j].active=false;
         book[i].stock=book[i].stock+1;
         client[i].havebook=false;
         cout<<"Thank you for handing in the book.";
         Menu();
       }
     }
    cout<<"The id is not valid! Type 0 to go back to menu.";
    cin>>ID;
   }
 }
}

void clientHistory()
{
  cout<<"Enter the client id to see transactions";
  int ID;
  cin>>ID;
  for (int i=1;i<100;i++)
  {
    if (transaction[i].client_id==ID)
    {
      cout<<"Enter the date you have taken the book:"<<endl;
            cin>>transaction[trid].start_date.year;
            cin>>transaction[trid].start_date.month;
            cin>>transaction[trid].start_date.month;
            cin>>transaction[trid].start_date.day;
            cin>>transaction[trid].start_date.hour;
            cin>>transaction[trid].start_date.min;
      cout<<"Enter the date you handed in the book:"<<endl;
            cin>>transaction[trid].end_date.year;
            cin>>transaction[trid].end_date.month;
            cin>>transaction[trid].end_date.day;
            cin>>transaction[trid].end_date.hour;
            cin>>transaction[trid].end_date.min;
cout<<"Transaction id: "<<transaction[i].tr_id <<endl;
cout<<"The book name handed on during this period of time: "<<transaction[i].booktitle<<endl << "with ID:" <<transaction[i].book_id <<endl;
    if (transaction[i].client_id!=ID)
    {
      continue;
    }
  }
  goTOmenu();
}
}

void badClient()
{
  for(int i=0;i<100;i++)
  {
    if(client[i].havebook==true)
    { 
     cout<<"Client with name"<<"client[i].name"<<client[i].surname <<"is a bad client"<<endl;
    }
      if(transaction[i].status>3)
    {
      cout<<"The client with tr id"<<transaction[i].client_id<<" is a bad client."<<endl;
    }
  }
   goTOmenu();
}
