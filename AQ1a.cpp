#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node *next;
};

class CircularLinkedList
{
	struct node *head;
	public:
		CircularLinkedList()
		{
			head = NULL;
		}
		
		struct node* createNode()
		{
			struct node *mynode = new node;
			if(mynode==NULL)
			{
				cout<<"\nOverflow\n";
			}
			else
			{
				cout<<"\nEnter Information : ";
				cin>>mynode->info;
				mynode->next = NULL;
			}
			return mynode;
		}
		
		void insertion_at_beg()
		{
			struct node *newnode = createNode();
			if(head == NULL)
			{
				head = newnode;
				newnode->next = head;
			}
			else
			{
				struct node *temp1;
				temp1 = head;
				while(temp1->next!=head)
				{
					temp1 = temp1->next;
				}
				newnode->next = head;
				head = newnode;
				temp1->next = head;
			}
			cout<<"\nNew Node "<<newnode->info<<" Added Successfully At The Beginning Of List\n";
		}
		
		void insertion_at_end()
		{
			struct node *newnode = createNode();
			if(head == NULL)
			{
				head = newnode;
				newnode->next = head;
			}
			else
			{
				struct node *temp1;
				temp1 = head;
				while(temp1->next != head)
				{
					temp1 = temp1->next;
				}
				newnode->next = head;
				temp1->next = newnode;
			}
			cout<<"\nNew Node "<<newnode->info<<" Added Successfully At The Ending Of List\n";			
		}
		
	    void insertAfter(int key) 
		{
	        if(!head) 
			{ cout<<"List empty\n"; return; }
	        node* t = head;
	        do{
	            if (t->info == key) {
	                node* n = createNode();
	                n->next = t->next; t->next = n;
	                cout<<"Inserted after "<<key<<"\n";
	                return;
	            }
	            t = t->next;
	        } while(t != head);
	        cout<<"Value not found\n";
	    }
	    
	    void insertBefore(int key) {
	        if(!head) { cout<<"List empty\n"; return; }
	    node* t = head; node* p = NULL;
	        do {
	            if (t->info == key) {
	                node* n = createNode();
	                if (!p) {
	                    node* last = head;
	                    while (last->next != head) last = last->next;
	                    n->next = head; last->next = n; head = n;
	                } else {
	                    p->next = n; n->next = t;
	                }
	                cout<<"Inserted before "<<key<<"\n";
	                return;
	            }
	            p = t; t = t->next;
	        } while (t != head);
	        cout<<"Value not found\n";
	    }
		
		void deletion_from_beg()
		{
			if(head == NULL)
			{
				cout<<"\nUnderflow\n";
				return;
			}
			struct node *temp1, *temp2;
			temp2 = head;
			if(temp2->next==head)
			{
				head = NULL;
			}
			else
			{
				temp1 = head;
				while(temp1->next!=head)
				{
					temp1 = temp1->next;
				}
				temp1->next = temp2->next;
				head = temp2->next;
			}
			
			cout<<"\nElement "<<temp2->info<<" Deleted Successfully From The Beginning Of List\n";
			delete temp2;
		}
		
		void deletion_from_end()
		{
			if(head == NULL)
			{
				cout<<"\nUnderflow\n";
				return;
			}
			
			struct node *temp1, *temp2;
			temp1 = head;
			temp2 = NULL;
			while(temp1->next!=head)
			{
				temp2 = temp1;
				temp1 = temp1->next;
			}
			if(temp2 == NULL)
				head = NULL;
			else
				temp2->next = head;
			
			cout<<"\nElement "<<temp1->info<<" Deleted Successfully From The Ending Of List\n";
			delete temp1;
		}
		
		int getLength()
		{
			struct node *temp1;
			temp1 = head;
			int count = 1;
			if(head == NULL)
			{
				return 0;
			}
			while(temp1->next!=head)
			{
				temp1 = temp1->next;
				count++;
			}
			return count;
		}
		
		void insertion_at_loc()
		{
			int loc, total;
			total = getLength();
			cout<<"\nEnter Location To Insert : ";
			cin>>loc;
			
			if(loc<1 || loc > total+1)
				cout<<"\nOut Of Range";
			else if(loc==1)
				insertion_at_beg();
			else if(loc==total+1)
				insertion_at_end();
			else
			{
				struct node *newnode = createNode();
				int i = 1;
				struct node *temp1, *temp2;
				temp1 = head;
				temp2 = NULL;
				while(i<loc)
				{
					temp2 = temp1;
					temp1 = temp1->next;
					i++;
				}
				temp2->next = newnode;
				newnode->next = temp1;
				cout<<"\nElement "<<newnode->info<<" Inserted successdully at "<<loc<<" location";
			}
		}
		
		void deletion_from_loc()
		{
			int loc, total;
			total = getLength();
			cout<<"\nEnter Location To Delete : ";
			cin>>loc;
			
			if(loc<1 || loc > total+1)
				cout<<"\nOut Of Range";
			else if(loc==1)
				deletion_from_beg();
			else if(loc==total)
				deletion_from_end();
			else
			{
				int i = 1;
				struct node *temp1, *temp2;
				temp1 = head;
				temp2 = NULL;
				while(i<loc)
				{
					temp2 = temp1;
					temp1 = temp1->next;
					i++;
				}
				temp2->next = temp1->next;
				cout<<"\nElement "<<temp1->info<<" Deleted successfully at "<<loc<<" location";
				delete temp1;
			}
		}
		
		void searching()
		{
			int flag,el,i;
			cout<<"Enter element to search : ";
			cin>>el;
			
			struct node *temp1;
			temp1 = head;
			i=1;
			flag=0;
			while(temp1->next!=head)
			{
				if(temp1->info==el)
				{
					cout<<"\nElement found : "<<i;
					flag=1; //found
				}
				i++;
				temp1 = temp1->next;
			}
			if(temp1->info==el)
			{
				cout<<"\nElement found : "<<i;
				flag=1; //found
			}
			if(flag==0)
			{
				cout<<"\nNot Found";
			}
		}
		
};

int main()
{
	CircularLinkedList obj;
	int ch;
  	 while(true)
  	 {
  	 	cout<<"\n----- Options ------";
  	 	cout<<"\n1.  Insertion At Loc";
  	 	cout<<"\n2.  Insertion After";
  	 	cout<<"\n3.  Insertion Before";
  	 	cout<<"\n4.  Deletion At Loc";
  	 	cout<<"\n3.  Searching";
  	 	cout<<"\n4. Exit"; 
  	 	cout<<"\nEnter Choice : ";
  	 	cin>>ch;
		if(ch==1)
		{
			obj.insertion_at_loc();
		}
		else if(ch==2)
		{
			int key;
			cout<<"Enter Node To Be Inserted After : ";
			cin>>key;
			obj.insertAfter(key);
		}
		else if(ch==3)
		{
			int key;
			cout<<"Enter Node To Be Inserted Before : ";
			cin>>key;
			obj.insertBefore(key);
		}
		else if(ch==4)
		{
			obj.deletion_from_loc();
		}
		else if(ch==5)
		{
			obj.searching();
		}
		else if(ch==4)
		{
			cout<<"\nExiting...";
			break;
		}
		else
		{
			cout<<"\nInvalid choice";
		}
	} 
	
	return 0;
}
