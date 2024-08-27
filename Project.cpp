#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

using namespace std;
class Queue
{
	public:
		string data;
		Queue* next;
		Queue* current;
		Queue* head;
		Queue* front;
		Queue()
		{
			current=NULL;
			head=NULL;
		}
		int isEmpty()
		{
			if(head==NULL)
			{
				return 1;
			}
			return 0;
		}
		int isFull()
		{
			Queue* ptr=new Queue();
			if(ptr==NULL)
			{
				return 1;
			}
			return 0;
		}
		int enqueue(string d)
		{
			int b=0;
			if(isFull())
			{
				cout<<"\nQueue is Full";
			}
			else
			{
				Queue* node=new Queue();
				node->data=d;
				node->next=NULL;
				Queue* q=front;
				if(head==NULL)
				{
					head=node;
					front=current=head;
				}
				else
				{
	           	    do
					   {
	        		if(q->data==d)
					{
		     		cout<<"\nCan't insert because of duplicate name \n";
			    	b++;
			    	q=q->next;
		        	}
		        	else
					{
		        	q=q->next;
		            }
	            	}while(q!=current->next);
                	if(b==0)
					{
					current->next=node;
					current=node;
					node->next=front;
				    }
				}
			}
			return b;
		}
		
		
		string dequeue()
		{
			if(isEmpty())
			{
				cout<<"\nQueue is empty so no element can't be removed\n";
			}
			else
			{
			Queue* ptr=front;
			string a=ptr->data;
			front=front->next;
			current->next=front;
			
			delete(ptr);
			return a;
	    	}
		}
		void display()
		{
			ofstream record;
			ifstream inrecord;
			record.open("Record.txt");
			record<<endl<<endl<<"********************************************************"<<endl;
			record<<"         People to become Leader"<<endl;
			record<<"********************************************************"<<endl;
			Queue *p=front;
			int i=1;
        	do
			{
		       record<<i<<". "<<p->data<<endl;
		       p=p->next;
		       i++;
         	}while(p!=current->next);
         	record.close();
			inrecord.open("Record.txt",ios::app);
			string s;
			while(inrecord.eof()==0)
			{
				getline(inrecord,s);
				cout<<s<<endl;
			}
			inrecord.close();
		}	
		void move_next()
		{
			front=front->next;
        	current=current->next;
        }
};
int main()
{
    system("color 80");
	char arr[]={'L','E','A','D','E','R',' ','F','I','N','D','I','N','G',' ','S','Y','S','T','E','M'};
	//char array[] = {"LEADER FINDING TECHNIQUE"}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		cout<<arr[i];
		Sleep(30);
	}
	Sleep(2000);
	getch();
	system("cls");
	
	Queue e;
	ofstream out;
	ifstream in;
	ofstream eout;
	ifstream ein;
	int m,i,n=0;
	string d;
	
    m=(rand() % 10) + 1;
	string a;
	int c=0;
	int de=0;
	int z;
	while(z!=3)
	{
		cout<<"\nPress 1 to add list of people : ";
		cout<<"\nPress 2 if you want to find leader from the name of person added in file : ";
		cout<<"\nPress 3 to exit : ";
		cin>>z;
		if(z==1)
		{
			
	       cout<<endl<<"                                  NUMBER OF PEOPLE TO BECOME LEADER";
	       cout<<"\n\n\n\n\n\n\n  Enter the number of people that wanted to become leader : ";
	       cin>>n;
	       srand(time(0));  
           getch();
        	system("cls");
			cout<<endl<<"                                  LIST OF PEOPLE TO BECOME LEADER\n\n\n\n";
        	for(i=1;i<=n;i++)
         	{
            	cout<<"Enter name of person "<<i<<" : ";
        	    cin>>a;
	            c=e.enqueue(a);
	        if(c==1)
			{
	      	n++;
	    	de++;
	     	}
	}
	getch();
	system("cls");
	
	e.display();
	
	getch();
	system("cls"); 
	break;
		}
		else if(z==2)
		{
			ifstream list;
			in.open("List.txt");
        	string s1;
        	int a2=-1;
      	while(in.eof()==0)
	    {
	    	getline(in,s1);
	    	n++;
	    	c=e.enqueue(s1);
	    	if(c==1)
			{
	      	n++;
	    	de++;
	     	}
		}
		e.display();
		in.close();
		break;
     	}
		else if(z==3)
		{
			break;
		}
	}
	
	eout.open("EliminationRecord.txt");
	eout<<endl<<endl<<"********************************************************"<<endl;
	eout<<"                    Elimination Order"<<endl;
	eout<<"********************************************************"<<endl;
	int b=n-de;
	eout<<"\nOrder : "<<m<<endl;
	while(b>1)
	{
		for(i=1;i<=m;i++)
		{
			e.move_next();
		}
		d=e.dequeue();
		eout<<d<<endl;
		b--;
	}
	d=e.dequeue();
	eout.close();
	
	out.open("WinningRecord.txt");
	out<<endl<<endl<<"********************************************************"<<endl;
	out<<"                    Winning Person"<<endl;
	out<<"********************************************************"<<endl;
	out<<"Winner  :  "<<d<<endl;
	out.close();
	in.open("WinningRecord.txt",ios::app);
	string s;
	while(in.eof()==0)
	{
		getline(in,s);
		cout<<s<<endl;
	}
	in.close();
	
	getch();
	system("cls");
	
	int f;
	do
	{
	cout<<"\n\n\n\nPress 1 to see that how the people are eliminated using Josephus problem solver ";
    cout<<"\nPress 2 to exit : ";
    cin>>f;
	if(f==1)
	{
	getch();
	system("cls");
	ein.open("EliminationRecord.txt",ios::app);
	string st;
	while(ein.eof()==0)
	{
		getline(ein,st);
		cout<<st<<endl;
	}
	ein.close();
	
	getch();
	system("cls");	
    }
    else if(f==2)
	{
    	cout<<"\n\n\n\n\n\n\n\n\n\n                                You exited!!!"<<endl;
    	exit(0);
	}
    }while(f!=2);
    return 0;
}

