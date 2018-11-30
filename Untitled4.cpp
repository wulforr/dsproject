#include<bits/stdc++.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
using namespace std;


//Memory Flow----------------------------------------------------------------------------------Memory flow

struct Node *root = NULL;
struct Node1 *root1 = NULL;
int score=0;
int array1[] = {1,5,15,55,240,50,202,40,98,105,304,48,91,398,201,108,38,130,204,379,69,158,192,274,498,22};
char array2[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','m','n','b','v','c','x','z'};
 
struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 

 
int height(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

 
int max(int a, int b) 
{ 
	if(a>b)
	return a;
	else
	return b; 
} 


struct Node* newNode(int key) 
{ 
	struct Node* node = (struct Node*) 
						malloc(sizeof(struct Node)); 
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;//adding the node at leaf
	return(node); 
} 



struct Node *rightRotate(struct Node *y) 
{ 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 
 
	x->right = y; 
	y->left = T2; 

	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	return x; 
} 




struct Node *leftRotate(struct Node *x) 
{ 
	struct Node *y = x->right; 
	struct Node *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	return y; 
} 



int getBalance(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 



struct Node* insert(struct Node* node, int key) 
{ 
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else  
		return node; 

	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	int balance = getBalance(node); 

	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	return node; 
} 

void preOrder(struct Node *root) 
{ 
	if(root != NULL) 
	{ 
		cout<<root->key<<" "<<endl; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 


bool search(int data,struct Node * root)
{
	if(root == NULL)
    {
        return false;
    }
    else if(data < root->key)
    {
        return search(data, root->left);
    }
    else if(root->key < data)
    {
        return search(data, root->right);
    }
    else if(root->key==data)
    {
        return true;
    }
    else 
	{
    	return false;
	}
}







struct Node1 
{ 
	char key; 
	struct Node1 *left; 
	struct Node1 *right; 
	int height; 
}; 

 
int height(struct Node1 *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 


struct Node1* newNode(char key) 
{ 
	struct Node1* node = (struct Node1*) 
						malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1;
	return(node); 
} 



struct Node1 *rightRotate(struct Node1 *y) 
{ 
	struct Node1 *x = y->left; 
	struct Node1 *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	return x; 
} 




struct Node1 *leftRotate(struct Node1 *x) 
{ 
	struct Node1 *y = x->right; 
	struct Node1 *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	return y; 
} 



int getBalance(struct Node1 *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 



struct Node1* insert(struct Node1* node, char key) 
{ 
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else 
		return node; 

	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	int balance = getBalance(node); 

	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	return node; 
} 

void preOrder(struct Node1 *root) 
{ 
	if(root != NULL) 
	{ 
		cout<<root->key<<" "<<endl; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 


bool search(char data,struct Node1 * root)
{
	if(root == NULL)
    {
        return false;
    }
    else if(data < root->key)
    {
        return search(data, root->left);
    }
    else if(root->key < data)
    {
        return search(data, root->right);
    }
    else if(root->key==data)
    {
        return true;
    }
    else 
	{
    	return false;
	}
}

int game()
{
	int i=0,score=0,j,k;
	
	while(i!=1){
		system("cls");
		cout<<"\t\tMEMORY GAME\t\t"<<endl;
	cout<<"\tHas this number appeared before?"<<endl;
		srand(time(0));
		int index=rand()%26;
		int choice=(rand()%2)+1;
		switch(choice)
		{
    		case 1 : { int number=array1[index];
    		cout<<"\n\t\t\t"<<number<<endl;
			if(search(number,root))
			{
				j=1;
			}
			else
			{
				j=2;
				root=insert(root,number);
			}
			cout<<"\n\t\t\t"<<"1.Yes"<<endl;
			cout<<"\n\t\t\t"<<"2.NO"<<endl;
			cin>>k;
			if((j==1 && k==1) ||(j==2 && k==2))
			{
				cout<<"Correct answer"<<endl;
				score++;
			}
			else
			{
				cout<<"Wrong answer"<<endl;
				score--;
				i=1;
			}
	    
    		break;
   		}
    	case 2 : 
		{
			char character=array2[index];
    		cout<<"\n\t\t\t"<<character<<endl;
    
    		if(search(character,root1))
			{
				j=1;
			}
			else
			{
				j=2;
				root1=insert(root1,character);
			}
			cout<<"\n\t\t\t"<<"1.Yes"<<endl;
			cout<<"\n\t\t\t"<<"2.NO"<<endl;
			cin>>k;
			if((j==1 && k==1) ||(j==2 && k==2))
			{
				cout<<"Correct answer"<<endl;
				score++;
			}
			else
			{
				cout<<"Wrong answer"<<endl;
				score--;
				i=1;
			}
	
    		break;
    		}
    	default : cout<<"error";
    	break;
		}
	}
	return score;
}

void setscore(string name,int score){
	string fname;
int fscore;
ifstream finhigh;
finhigh.open("flowhigh.txt");
finhigh>>fname;
finhigh>>fscore;
if(score>fscore){

ofstream fouth;
fouth.open("flowhigh.txt");

fouth<<name<<endl;
fouth<<score<<endl;
}

}


//---------------------------------------------Quiz-------------------------------Quiz--------------------------------------Quiz------------------------------------------------

struct node{
	float score;
	string name;
	node* next;
}*head,*temp;

void insert(string value,float score)
    {
     node *newnode;
    newnode=new node;
    newnode->name=value;
    newnode->score=score;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
       temp=head;
       while(temp->score>score && temp->next->score>score)
       {
       	
            temp=temp->next;
            
       }
       newnode->next=temp->next;
       temp->next=newnode;
       
    }
    

}

void maininsert(string name,float data){
	string fname;
	float fscore;

	
	ifstream finhigh;
	finhigh.open("high.txt");
	while(finhigh.eof()==0){
		finhigh>>fname;
		finhigh>>fscore;
		
		insert(fname,fscore);
		
		
		
	}
	insert(name,data);
	ofstream fouthigh;
	fouthigh.open("high.txt");
	temp=head;
	while(temp->next!=NULL){
		fouthigh<<temp->name;
		fouthigh<<temp->score;
		temp=temp->next;
		
		}
	
}

void timer(){
	int j;
	printf("\t\t\t\t\t\t");
	for(j=5;j>=1;j--)
                  {
                  	
                      printf("%d",j);
                      Sleep(1000);
                      printf("\b");
                  }
}

class user
{
	string name;
	int age;
	float score;
	float time;
	int count;	
	int correctAnsCount;
	queue <char> userQ;
	public:
		user(){
			score=0;
			time=0;
			count=0;
			correctAnsCount=0;
		}
	void setName(string n){
		this->name=n;
	}
			
	string getName(){
		return name;
	}
	void setAge(int a){
		this->age=a;
	}
	int getAge(){
		return age;
	}	
	void setcount(int c){
		this->count+=c;
	}
	int getcount(){
		return count;
	}	
	
	void setScore(float s){
		score+=s;
	}
	
	float getScore(){
		return score;
	}
	
	void setTime(float t){
		time+=t;
	}
	float getTime(){
		return time;
	}
	void setCorrectAnsCount(int c){
		correctAnsCount+=c;
	}
	int getCorrectAnsCount(){
		return correctAnsCount;
	}
	
	void setuserQ(char y,char c){
		userQ.push(y);
		userQ.push(c);
	}
	
	char getuserQ(){
		return userQ.front();
	}
	
	void Qpop(){
		userQ.pop();
	}
};

class question1
{
	public:
		
char question[100];
char yourAnswer;
char correctAnswer[10];
queue <char> yourQ;
queue <char> correctQ;
time_t start_t,end_t;
double diff_t;
//float score;


question1(int category,int k,user u){
	ifstream fin1;
		if(category==1)
	  {
	  
      fin1.open("gk.txt");
}
		if(category==2)
	  {
	  
      fin1.open("anime.txt");
}
int z;
for(z=0;z<k;z++){

int j;
for(j=0;j<=6;j++){
            fin1.getline(question,100);
            }
        }
      while(fin1.eof() ==0){
      	if(k<5){
      		k++;
      	int i;
      	time(&start_t);
            for(i=0;i<=5;i++){
            fin1.getline(question,100);
            cout<<question<<endl;
            }
            fin1.getline(question,100);
            correctQ.push(question[0]);
            cout<<"Press x to exit!\n";
            timer();
            cout<<"your response:";
            cin>>yourAnswer;
            if(yourAnswer=='x'){
            	
            	ofstream foutresume;
            	foutresume.open("resume.txt");
            	foutresume<<u.getName()<<endl;
            	foutresume<<category<<endl;
            	foutresume<<u.getcount()<<endl;
            	foutresume<<u.getCorrectAnsCount()<<endl;
            	foutresume<<u.getTime()<<endl;
            	
            	foutresume<<u.getAge()<<endl;
            	foutresume<<u.getScore()<<endl;
            	while(!yourQ.empty()){
      			foutresume<<yourQ.front()<<endl;
      			foutresume<<correctQ.front()<<endl;
      			yourQ.pop();
      			correctQ.pop();
				  }
            	exit(1);
			}
			else{
			u.setcount(1);
			time(&end_t);
	  		diff_t=difftime(end_t,start_t);
	  		u.setTime(diff_t-5);
			cout<<"\t\t\t\t\t\t";
            yourQ.push(yourAnswer);
            if(yourAnswer==question[0])
            {	
            	u.setScore(15-diff_t);
                cout<<"CORRECT!\n\n";
                //correctAnsCount++;
                u.setCorrectAnsCount(1);
            }
            else
                cout<<"Wrong!!!\n\t\t\t\t\t\tThe correct answer is:"<<question[0]<<"\n"<<endl;
            }
        }
      }
      
	  
    fin1.close();
	system("cls");
      cout<<"\t\tyour Answers:\t";
      cout<<"\t\tcorrect Answers:\n";
if(u.getuserQ()){
	while(u.getuserQ()){
	  //cout<<"\t\t"<<u.getuserQ()<<"\t\t"<<endl;
	  u.Qpop();
      //cout<<u.getuserQ()<<endl;
      //u.Qpop();
	}
	
}
      while(!correctQ.empty()){
      cout<<"\t\t"<<yourQ.front()<<"\t\t";
      cout<<correctQ.front()<<endl;
      yourQ.pop();
      correctQ.pop();

      }
      ofstream foutresu;
			int asd=1;
            	foutresu.open("resume.txt");
            	foutresu<<asd<<endl;
            
      cout<<"\nUsername:"<<u.getName()
      	  <<"\nAge:"<<u.getAge()
	  	  <<"\nNumber of correct answer:"<<u.getCorrectAnsCount()
      	  <<"\nTime taken:"<<u.getTime()
      	  <<"\nScore:"<<u.getScore()<<endl;
				maininsert(u.getName(),u.getScore());
				
		}


};






int main()
{
int po;
started:	
	system("cls");
	cout<<"\t\t\tChoose Game"<<endl;
	cout<<"\t\t1. Quiz"<<endl;
	cout<<"\t\t2. Memory flow"<<endl;
	cout<<"\t\t3. Exit"<<endl;
	cin>>po;
	switch(po)
	{
		case 1:
			{
				user u;
	string name;
	int age,choice1;
	
	system("COLOR FC");
    puts("\n\t\t WELCOME TO THE QUIZ") ;
    puts("\n\t\t-------------------------------");
	
	mainstart:
	cout<<"Enter username:";
	cin>>name;
	cout<<"\nEnter age:";
	cin>>age;
	
	u.setName(name);
	u.setAge(age);
	system("cls");
	
	int f;
	ifstream fouthigh;
	fouthigh.open("resume.txt");
	
	startQuiz:
		fouthigh>>f;
		if(f!=1){
		
	cout<<"\n\t\t 1.Resume game";
	cout<<"\n\t\t 2. Start game";
    cout<<"\n\t\t 3. View high score";
    cout<<"\n\t\t 4. Help";
    cout<<"\n\t\t 5. Quit";
    cout<<"\n\t\t-------------------------------\n\n\t\t";
    cin>>choice1;
    switch(choice1)
    {
    	case 1:{
    		int catg,count,correctAnsCount;
    		float time,score;
    		string name;
    		int age,i;
    		char your,correct;
    		ifstream finresume;
    		finresume.open("resume.txt");
    		finresume>>catg;
    		finresume>>count;
    		finresume>>correctAnsCount;
    		finresume>>time;
    		finresume>>name;
    		finresume>>age;
    		finresume>>score;
    		for(i=0;i<count;i++){
    			finresume>>your;
    			finresume>>correct;
    			u.setuserQ(your,correct);
			}
    		
    	//	cout<<catg<<"\n"<<count<<"\n"<<correctAnsCount<<"\n"<<time<<"\n"<<name<<"\n"<<age<<"\n";
    		u.setcount(count);
    		u.setCorrectAnsCount(correctAnsCount);
    		u.setTime(time);
    		u.setName(name);
    		u.setAge(age);
    		u.setScore(score);
    		
    		question1 q1(catg,count,u);
    		
    		
			break;
		}
		case 2:{
			cout<<"1.GK"<<endl;
			cout<<"2.Anime"<<endl;
			int i;
			cin>>i;
			question1 q1(i,0,u);
			break;
		}
		case 3:{
			cout<<"High Score\n";
			string uname;
			float uscore;
			ifstream finhs;
			finhs.open("high.txt");
			if(finhs){
			cout<<"Name\t\t:\t\tScore\n";
			while(finhs.eof()==0){
				finhs>>uname;
				finhs>>uscore;
				
				cout<<uname<<"\t\t:\t\t"<<uscore<<endl;
				
			}
		}
			break;
		}
		case 4:{
			char line2[100];
			int i;
        	cout<<"HELP\n";
        	ifstream fin1;
        	fin1.open("help.txt");
			system("cls");
         	while (fin1) {
        		
        		for(i=0;i<13;i++){
        		fin1.getline(line2,100);
        		cout <<"\n\t\t"<< line2;
        	}
        		}
        	cout<<"Press any key to go back!";
        	char c;
        	c=getch();
        	if(c){
        			system("cls");
        			goto startQuiz;
			}
        	
        		
			break;
		}
    	case 5:{
    		exit(1);
			break;
		}	
	}
}
else{

	cout<<"\n\t\t 1. Start game";
    cout<<"\n\t\t 2. View high score";
    cout<<"\n\t\t 3. Help";
    cout<<"\n\t\t 4. Quit";
    cout<<"\n\t\t-------------------------------\n\n\t\t";
    cin>>choice1;
    
	switch(choice1){
	
	case 1:{
			cout<<"1.GK"<<endl;
			cout<<"2.Anime"<<endl;
			int i;
			cin>>i;
			question1 q1(i,0,u);
			break;
		}
		case 2:{
			cout<<"High Score\n";
			string uname;
			float uscore;
			ifstream finhs;
			finhs.open("high.txt");
			if(finhs){
			cout<<"Name\t\t:\t\tScore\n";
			while(finhs.eof()==0){
				finhs>>uname;
				finhs>>uscore;
				
				cout<<uname<<"\t\t:\t\t"<<uscore<<endl;
				
			}
		}
			break;
		}
		case 3:{
			char line2[100];
			int i;
        	cout<<"HELP\n";
        	ifstream fin1;
        	fin1.open("help.txt");
			system("cls");
         	while (fin1) {
        		
        		for(i=0;i<13;i++){
        		fin1.getline(line2,100);
        		cout <<"\n\t\t"<< line2;
        	}
        		}
        	cout<<"Press any key to go back!";
        	char c;
        	c=getch();
        	if(c){
        			system("cls");
        			goto startQuiz;
			}
        	
        		
			break;
		}
    	case 4:{
    		exit(1);
			break;
			}	
		}
	}

	
	cout<<"Press 1 to go back\n";
	cout<<"Press 2 to exit";
	
        	int c;
        	cin>>c;
        	if(c==1){
        			system("cls");
        			goto mainstart;
			}
			else{
			
				break;
			}
			break;
		}
		case 2:
			{
				string name,data;
cout<<"Enter Name:";
cin>>name;

int i=0,j,k,n,data1;
start1: cout<<"\t\t MAIN MENU \t\t"<<endl;
cout<<"\t 1.Start Game"<<endl;
cout<<"\t 2.High score"<<endl;
cout<<"\t 3.Help"<<endl;
cout<<"\t 4.Exit"<<endl;
cin>>n;
switch(n)
{
	case 1:
	{
		score=game();
		flag: preOrder(root);
preOrder(root1);
cout<<"\n\t\t HI "<<name<<" your score is:"<<score<<endl;
 

setscore(name,score);

flag1: cout<<"1. Restart Game"<<endl;
cout<<"2. Main screen"<<endl;
int p;
cin>>p;
if(p==1)
{
	root=NULL;
	root1=NULL;
	score=game();
	goto flag;
	
}
else if(p==2)
{
	goto started;
	
}
else
{
	cout<<"Wrong Choice"<<endl;
	cout<<"choose again"<<endl;
	goto flag1;
}
		break;
	}
	case 2:{
		int pq;
		string fname;
		int fscore;
		ifstream finh;
		finh.open("flowhigh.txt");
		
		
		finh>>fname;
		finh>>fscore;
		cout<<"\t\tName\t:\tScore\n";
		cout<<"\t\t"<<fname<<"\t:\t"<<fscore<<endl<<endl;
		cout<<"1.Main Menu"<<endl;
		cout<<"2.Exit"<<endl;
seter:		cin>>pq;
		if(pq==1)
		goto start1;
		else if(pq==2)
		break;
		else
		{
			cout<<"wrong choice select again";
			goto seter;
		}
	}
	case 3:{
		cout<<"This is help";
		break;
	}
	case 4:{
		goto started;
	}
	default: cout<<"Wrong Choice";
}



				break;
			}
		case 3:
			{
				return 0;
			}
		default : 
			{
				cout<<"Enter Correct choice"<<endl;
				break;
			}
		}
		return 0;
	}
