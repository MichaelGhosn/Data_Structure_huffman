#include <iostream>
#include <string>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


struct Node {
	int frequency;
	std::string txt;
	Node* next;
	Node* left;
	Node* right;
	Node* parent;
};

int compare(Node* First, Node* Second) {
	if (First->frequency < Second->frequency) return -1;
	if (First->frequency > Second->frequency) return 1;
	if (First->txt < Second->txt) return -1;
	if (First->txt > Second->txt) return 1;
	return 0;
}

Node* Initialize() {
	return NULL;
}








Node* IncFrequency(Node* Head, char c) {
	// This function searches for the character C in the simply linked list.
	// If it was able to find a node containing this character, it increments it frequency by 1.
	// If no such node exists, it creates a new node and append it to the beginning of the simply linked list, where :
	//		the 'txt' field is equal to the character
	//		the 'frequnecy' field is equal to 1
	//		the 'parent', 'left' and 'right' fields are set to NULL
if(Head==NULL)
{
	cout<<"Head is null so creating LL from scratch..."<<endl;
 
    Node *temp=new Node;
	if(temp==NULL)
	{
		cout<<"Error creating temporary node exit..."<<endl;
		exit(1);
	   }   


   	temp->txt=c;
	temp->next=NULL;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	temp->frequency=1;
	
	Head=temp;
	
	cout<<c<<" added to LL with frequency 1"<<endl;
	return Head;	
	
}


Node *element=new Node;
element=NULL;


for(element=Head;element!=NULL;element=element->next)
{

	if(element->txt[0]==c)
	{
		element->frequency++;
		cout<<c<<" already exists adding 1 to his frequency..."<<endl;
		return Head;
	}
}


	Node *tmp;
	tmp=new Node;
	
	if(tmp==NULL)
    {
    	cout<<"Error with node creation"<<endl;
    	exit(1);
	}
	
	tmp->txt=c;
	tmp->next=NULL;
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->parent=NULL;
	tmp->frequency=1;
	
	
	tmp->next=Head;
	Head=tmp;
	cout<<c<<" is a new element adding it with frequency 1..."<<endl;
	return Head;


}





Node* ReadFile(const char* fileName) {
	// This function reads a file given by its name.
	// It creates a simply linked list containing the letters present in the file along with their frequency of occurence.
	// You can use the previous function : Node* IncFrequency(Node* Head, char c)
	
ifstream myfile;
myfile.open("E://Uni year 2//Data Structure//Huffman Code-20181226//file.txt");
string line;
if(myfile.is_open())
{
	cout<<"Reading from file..."<<endl;
	getline(myfile,line);
	
}
if(myfile.fail())
{
	cout<<"Unable to open file"<<endl;
}

	myfile.close();

Node *head=new Node;
head=Initialize();

int i=0;

while(line[i]!='\0')
{
	//if(line[i]==' ')
	//{
	//	i++;
	//}
	//hayde bass eza ma badna l space w ma3 hayde l if byotla3 l tree metel ma badoun
	head=IncFrequency(head,line[i]);
	i++;
}

return head;

}






void DisplayList(Node* Head) {
	std::cout << std::endl;
	for (Node* curr = Head; curr != NULL; curr = curr->next) {
		std::cout << curr->txt << " : " << curr->frequency << std::endl;
	}
	std::cout << std::endl;
}







void Sort(Node* Head) {
	// This function sorts the simply linked list in ascending order using the Selection Sort algorithm.
	// For this purpose, you may use the already defined function : int compare(Node* First, Node* Second)
	// The compare function compares two nodes according to their frequencies and lexicographic order.
	// The compare function returns -1 if the first node is smaller than the second node.
	// The compare function returns +1 if the first node is larger than the second node.
	// The compare function returns 0 if both nodes are equal.

Node *cur=new Node;
cur=Initialize();
Node *min=new Node;
min=Initialize();
Node *cur1=new Node;
cur1=Initialize();

for(cur=Head;cur->next!=NULL;cur=cur->next)
{
	min=cur;
	for(cur1=cur->next;cur1!=NULL;cur1=cur1->next)
	{
		if(compare(cur1,min)==-1)
		{
			min=cur1;
		}
	}
	
	if(compare(cur,min)==1)
	{
	  int x=min->frequency;
	  min->frequency=cur->frequency;
	  cur->frequency=x;
	  
	  char s=min->txt[0];
	  min->txt[0]=cur->txt[0];
	  cur->txt=s;
	}
	
}

DisplayList(Head);

}




int main(int argc, char** argv) {
	
	const char * c;
	
	Node *test=ReadFile(c);
	
	Node *curr=new Node;
	curr=test;
	
	while(curr!=NULL)
	{
		cout<<curr->frequency<<" "<<curr->txt[0]<<endl;
		curr=curr->next;
	}
	
	Sort(test);

bool search=false;

while(search==false)
{
	cout<<"Search char in LL:"<<endl;
	string ch;
	cin>>ch;
	
	Node *ccc=test;
	
	while(ccc!=NULL)
	{
		if(ccc->txt==ch)
		{
			cout<<"Found!!!"<<endl;
			search=true;
			break;
		}
		
		ccc=ccc->next;
	}
	
}
	
	
	
	return 0;
}
