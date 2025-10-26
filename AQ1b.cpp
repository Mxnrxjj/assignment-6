#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node *next;
	struct node *prev;
};

class DoublyLinkedList
{
	struct node *head;
	public:
		DoublyLinkedList()
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
				mynode->prev = NULL;
			}
			return mynode;
		}
		
		void insertion_at_beg()
		{
			struct node *newnode = createNode();
			if(head == NULL)
			{
				head = newnode;
			}
			else
			{
				newnode->next = head;
				head->prev = newnode;
				head = newnode;
			}
			cout<<"\nNew Node "<<newnode->info<<" Added Successfully At The Beginning Of List\n";
		}
		
		void traversing()
		{
			if(head == NULL)
			{
				cout<<"\nUnderflow\n";
				return;
			}
			struct node *temp;
			temp = head;
			cout<<"\n----DOUBLY LINKED LIST----\n";
			while(temp != NULL)
			{
				cout<<temp->info;
				if(temp->next != NULL)
					cout<<" <=> ";
				temp = temp->next;
			}
		}
		
		void insertion_at_end()
		{
			struct node *newnode = createNode();
			if(head == NULL)
			{
				head = newnode;
			}
			else
			{
				struct node *temp1;
				temp1 = head;
				while(temp1->next != NULL)
				{
					temp1 = temp1->next;
				}
				temp1->next = newnode;
				newnode->prev = temp1;
			}
			cout<<"\nNew Node "<<newnode->info<<" Added Successfully At The Ending Of List\n";			
		}
		
	    void insertAfter(int key) 
		{
	        if(!head) 
			{ cout<<"List empty\n"; return; }
	        node* t = head;
	        while(t != NULL)
	        {
	            if (t->info == key) {
	                node* n = createNode();
	                n->next = t->next;
	                n->prev = t;
	                if(t->next != NULL)
	                    t->next->prev = n;
	                t->next = n;
	                cout<<"Inserted after "<<key<<"\n";
	                return;
	            }
	            t = t->next;
	        }
	        cout<<"Value not found\n";
	    }
	    
	    void insertBefore(int key) {
	        if(!head) { cout<<"List empty\n"; return; }
	        node* t = head;
	        while(t != NULL)
	        {
	            if (t->info == key) {
	                node* n = createNode();
	                n->next = t;
	                n->prev = t->prev;
	                if(t->prev != NULL)
	                    t->prev->next = n;
	                else
	                    head = n;
	                t->prev = n;
	                cout<<"Inserted before "<<key<<"\n";
	                return;
	            }
	            t = t->next;
	        }
	        cout<<"Value not found\n";
	    }
		
		void deletion_from_beg()
		{
			if(head == NULL)
			{
				cout<<"\nUnderflow\n";
				return;
			}
			struct node *temp2;
			temp2 = head;
			if(temp2->next == NULL)
			{
				head = NULL;
			}
			else
			{
				head = temp2->next;
				head->prev = NULL;
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
			
			struct node *temp1;
			temp1 = head;
			while(temp1->next != NULL)
			{
				temp1 = temp1->next;
			}
			if(temp1->prev == NULL)
				head = NULL;
			else
				temp1->prev->next = NULL;
			
			cout<<"\nElement "<<temp1->info<<" Deleted Successfully From The Ending Of List\n";
			delete temp1;
		}
		
		int getLength()
		{
			struct node *temp1;
			temp1 = head;
			int count = 0;
			while(temp1 != NULL)
			{
				count++;
				temp1 = temp1->next;
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
				struct node *temp1;
				temp1 = head;
				while(i<loc-1)
				{
					temp1 = temp1->next;
					i++;
				}
				newnode->next = temp1->next;
				newnode->prev = temp1;
				temp1->next->prev = newnode;
				temp1->next = newnode;
				cout<<"\nElement "<<newnode->info<<" Inserted successdully at "<<loc<<" location";
			}
		}
		
		void deletion_from_loc()
		{
			int loc, total;
			total = getLength();
			cout<<"\nEnter Location To Delete : ";
			cin>>loc;
			
			if(loc<1 || loc > total)
				cout<<"\nOut Of Range";
			else if(loc==1)
				deletion_from_beg();
			else if(loc==total)
				deletion_from_end();
			else
			{
				int i = 1;
				struct node *temp1;
				temp1 = head;
				while(i<loc)
				{
					temp1 = temp1->next;
					i++;
				}
				temp1->prev->next = temp1->next;
				temp1->next->prev = temp1->prev;
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
			while(temp1!=NULL)
			{
				if(temp1->info==el)
				{
					cout<<"\nElement found : "<<i;
					flag=1;
				}
				i++;
				temp1 = temp1->next;
			}
			if(flag==0)
			{
				cout<<"\nNot Found";
			}
		}
		
};

int main()
{
	DoublyLinkedList obj;
	int ch;
  	 while(true)
  	 {
  	 	cout<<"\n----- Options ------";
  	 	cout<<"\n1.  Insertion At Loc";
  	 	cout<<"\n2.  Deletion At Loc";
  	 	cout<<"\n3.  Insertion After Node";
  	 	cout<<"\n4.  Insertion Before Node";
  	 	cout<<"\n5.  Searching";
  	 	cout<<"\n6.  Traversing";
  	 	cout<<"\n7.  Exit"; 
  	 	cout<<"\nEnter Choice : ";
  	 	cin>>ch;
		if(ch==1)
		{
			obj.insertion_at_loc();
		}
		else if(ch==2)
		{
			obj.deletion_from_loc();
		}
		else if(ch==3)
		{
			int key;
			cout<<"Enter Node To Be Inserted After : ";
			cin>>key;
			obj.insertAfter(key);
		}
		else if(ch==4)
		{
			int key;
			cout<<"Enter Node To Be Inserted Before : ";
			cin>>key;
			obj.insertBefore(key);
		}
		else if(ch==5)
		{
			obj.searching();
		}
		else if(ch==6)
		{
			obj.traversing();
		}
		else if(ch==7)
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

