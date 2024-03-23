#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
//-------------------------定义一个链式表------------------------- 
template <class T>
struct LinkNode
{
	LinkNode<T> * next = NULL;  //定义指针域，并初始化为空指针 
	T data;   //定义数据域
};
template <class T>
class Link
{
	private:
		LinkNode<T> * head; //定义链表头指针
	public:
    	Link(); 
    	~Link();  
    	int length();
    	int search(T & x);
    	bool isEmpty();
    	bool isFull();
    	void makeEmpty();
    	bool getData(int index, T & x);
    	bool setData(int index, T & x);
    	bool insert(int index, T & x);
    	bool remove(int index, T & x);
    	void output();
};
template <class T>
Link<T>::Link()
{
	head = new LinkNode<T>;  // 构造函数 
}
template <class T>
Link<T>::~Link()
{   //析构函数 
	makeEmpty();  //置空链表 
	delete head;  //删除头结点 
}
template <class T>
int Link<T>::length()
{   
	LinkNode<T> * n = head->next;
	int count = 0;
	while(n != NULL)
	{
		n = n->next;
		count++;
	}
	return count;   //返回链表的长度 
} 
template <class T>
int Link<T>::search(T & x)   //搜索含数据x的元素 
{                       
	LinkNode<T> *  n = head->next;
	int i = 0;
	while(n != NULL){
		if(n->data == x)
			return i;  //搜索成功，返回x对应的元素的索引 
		n = n->next;
		i++;    
	}
	return -1;  //搜索失败，返回-1 
}
template <class T>
bool Link<T>::isEmpty()
{
	return head->next == NULL ? true : false;   //判断链表是否满了，如果满了，则返回true；如果不满，则返回false 
} 
template <class T>
bool Link<T>::isFull()
{
	return false;
}
template <class T>
void Link<T>::makeEmpty()
{  // 置空链表 
	LinkNode<T> * n;
	while(head->next != NULL)
	{   //判断链表是否为空，如果不为空，则删除所有结点 
		n = head->next;
		head->next = n->next;   //保存被删结点，从链表里面删除结点 
		delete n;   // 删除全部结点 
	} 
}
template <class T>
bool Link<T>::getData(int index, T & x)
{    //取出下标为index的元素的值 
	LinkNode<T> * n = head->next;
	for(int i = 0; i <= index; i++)
	{
		if(n == NULL)
			return false;
		if(i == index)
		{
		 	x = n->data;
			return true; 
		}
		n = n->next;
	}
	return false;
}
template <class T>
bool Link<T>::setData(int index, T & x)
{   //用x代替下标为index的元素的值 
	LinkNode<T> * n = head->next;
	for(int i = 0; i<= index; i++)
	{
		if(n == NULL)
			return false;
		if(i == index)
		{
			n->data = x;
			return true;
		} 
		n = n->next;
	}
	return false;
}
template <class T>
bool Link<T>::insert(int index, T & x)
{   //在索引为index的元素后面插入新元素x 
	LinkNode<T> * n = head;
	for(int i = 0; i <= index; i++)
	{
		if(n == NULL)
			return false;
		if(i == index)
		{
			LinkNode<T> * m = new LinkNode<T>;
			m->data = x;
			m->next = n->next;
			n->next = m;
			return true;
		}
		n = n->next;
	}
	return false;
}
template <class T>
bool Link<T>::remove(int index, T & x)
{  //删除索引为index的元素，x保存该元素的值 
	LinkNode<T> * n = head;
	for(int i = 0; i <= index; i++)
	{
		if(n == NULL)
		{
			return false;
		}
		if(i == index)
		{
		 	LinkNode<T> * m = n->next;
			x = m->data;
			n->next = m->next;
			delete m;
			m = NULL;
			return true; 
		}
		n = n->next;
	} 
	return false;
} 
template <class T>
void Link<T>::output()
{  //输出链表 
	LinkNode<T> * n = head->next;
	while(n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	} 
	cout << endl;
}

//-------------------------业主的基本信息------------------------- 
class Owner
{
	private:
		char name[20];  //业主的姓名 
		int age;  //业主的年龄 
		char sex[4];  //业主的性别
		int year;  //业主已居住的年限
		int amount; //业主家居住的人数
		char number[20]; //业主的电话号码 
		int door; //业主的所在的楼栋 
		char car[4]; //是否有车
		char marriage[4]; //婚姻状况，是否结婚 
	public:
		void setName(char name[]);
		char getName(char name[]);
		void setAge(int age);
		int getAge();
		void setSex(char sex[]);
		char getSex(char sex[]);
		void setYear(int year);
		int getYear();
		void setAmount(int amount);
		int getAmount();
		void setNumber(char number[]);
		char getNumber(char number[]); 
		void setDoor(int door);
		int getDoor();
		void setCar(char car[]);
		char getCar(char car[]);
		void setMarriage(char marriage[]);
		char getMarriage(char marriage[]);
		void output(); //输出结果 
}; 
void Owner::setName(char name[])
{
	strcpy(this->name, name);
}
char Owner::getName(char name[])
{       
	strcpy(name, this->name);
}
void Owner::setAge(int age)
{
	this->age = age;
}
int Owner::getAge()
{
	return age;
}
void Owner::setSex(char sex[])
{
	strcpy(this->sex, sex);
}
char Owner::getSex(char sex[])
{
	strcpy(sex, this->sex);
}
void Owner::setYear(int year)
{
	this->year = year;
}
int Owner::getYear()
{
	return year;
}
void Owner::setAmount(int amount)
{
	this->amount = amount;
}
int Owner::getAmount()
{
	return amount;
}
void Owner::setNumber(char number[])
{
	strcpy(this->number, number);
}
char Owner::getNumber(char number[])
{
	strcpy(number, this->number);
}
void Owner::setDoor(int door)
{
	this->door = door;
}
int Owner::getDoor()
{
	return door;
}
void Owner::setCar(char car[])
{
	strcpy(this->car, car);
}
char Owner::getCar(char car[])
{
	strcpy(car, this->car);
}
void Owner::setMarriage(char marriage[])
{
	strcpy(this->marriage, marriage);
}
char Owner::getMarriage(char marriage[])
{
	strcpy(marriage, this->marriage);
}
void Owner::output()
{
	cout << "【业主的姓名】： " << name << endl;
	cout << "【" << name << "的年龄】： " << age << endl;
	cout << "【" << name << "的性别】： " << sex << endl;
	cout << "【" << name << "的已居住年限】： " << year << endl;
	cout << "【" << name << "的家庭人数】： "  << amount << endl;
	cout << "【" << name << "的电话号码】： "  << number << endl;
	cout << "【" << name << "所在的楼栋单元】： " << door << endl;
	cout << "【" << name << "家是否有车】： " << car << endl;
	cout << "【" << name << "是否婚配】： " << marriage << endl; 
}
//-------------------------总页面显示------------------------- 
class Show
{
	private:
		Link <Owner> owns;
	public:
		Show();
		void mainShow();  //主页面 
		void key();  //主页面上的选项跳转 
		void infoShow();  // 展示业主信息 
		void putShow(); //添加业主信息 
		void reShow(); //修改业主信息 
		void delShow(); //删除业主信息
		void help();  //对主页面下（1）~（5）相关服务进行一个解释 
		void save(); //保存业主的信息
		void read(); //读取业主的信息 
}; 
Show::Show()
{
	mainShow();
}
void Show::mainShow()
{
	cout << endl;
	cout << "\t\t\t*********************主页面*********************" << endl;
	cout << endl; 
	cout << "\t\t\t*            【 (1) 添加业主信息 】            *"<< endl;
	cout << "\t\t\t*            【 (2) 修改业主信息 】            *"<< endl; 
	cout << "\t\t\t*            【 (3) 删除业主信息 】            *"<< endl; 
	cout << "\t\t\t*            【 (4) 查询业主信息 】            *"<< endl;  
	cout << "\t\t\t*            【（5）  保存信息   】            *"<< endl; 
	cout << "\t\t\t*            【 (6) 读取历史信息 】            *"<< endl;  
	cout << "\t\t\t*            【 (7)   帮助菜单   】            *"<< endl;  
	cout << "\t\t\t*            【（8）退出管理系统 】            *\n"<< endl; 
	cout << "\t\t\t************************************************ "<< endl; 
	cout << endl;
	cout << "\t在此输入您的指令： " ; 
} 
void Show::key()
{
	int button;
	cin >> button;
	switch(button)
	{
		case 1:	
			putShow();
			break;
		case 2:	
			reShow();
			break;
		case 3:
			delShow();
			break;
		case 4:	
			infoShow();
			break;
		case 5: 
			save();
			break;
		case 6:
			read();
			break; 
		case 7: 
			help();
			break;
		case 8: 
			cout << endl; 
			cout << "\t-·-·-·-·-·感谢您使用本系统-·-·-·-·-·" << endl;
			exit(0);
			break;
	}
} 
void Show::putShow()
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(1) 添加业主信息---------------------------->\n" << endl;
	char name[20];  
	int age;  
	char sex[4];  
	int year;  
	int amount; 
	char number[20]; 
	int door; 
	char car[4]; 
	char marriage[4];
	int size = 0; //用于记录已添加的业主个数 
	while(true)
	{
		cout << "【     姓名     】： ";	
		cin >> name;
		cout << "【     年龄     】： " ;
		cin >> age; 
		cout << "【     性别     】： " ;
		cin >> sex;
		cout << "【  已居住年限  】： " ;
		cin >> year;
		cout << "【   家庭人数   】： " ;
		cin >> amount;
		cout << "【   电话号码   】： " ;
		cin >> number;
		cout << "【 所在楼栋单元 】： " ;
		cin >> door; 
		cout << "【   是否有车   】： " ;
		cin >> car;
		cout << "【   是否婚配   】： " ;
		cin >> marriage;
		Owner owner;
		owner.setName(name);
		owner.setAge(age);
		owner.setSex(sex);
		owner.setYear(year);
		owner.setAmount(amount);
		owner.setNumber(number);
		owner.setDoor(door);
		owner.setCar(car);
		owner.setMarriage(marriage);
		char ind;
		cout << endl; 
		cout << "请您再次确认，是否将此条业主信息录入系统？（y/n）： "; 
		cin >> ind;
		if( ind == 'y' || ind == 'Y')   //实际应用中，偶尔会把小写y打成大写Y，所以此处设置大小写均可 
		{								
			owns.insert(size, owner);
			char ins;
			cout << "【温馨提示】：是否继续添加下一条业主信息？（y/n）： " ;  
			cin >> ins;
			cout << endl;
			if(ins == 'y' || ins == 'Y')
			{ 
 				cout << "目前已添加 " << size+1 << " 位业主的信息！" << endl;   //因为s是从0开始加的，所以统计所添加的业主人数时需要再加1 
				cout << "请继续输入，添加业主信息！" << endl;
				size++; 
				cout << endl; 
			}   
			else
			{ 
				cout << "您选择的是‘n’，按照您的需求，不再添加下一条业主信息" << endl; 
				cout << endl;
				cout << "已添加 " << size+1 << " 位业主的信息！" << endl;
				cout << "即将返回至主页面！" << endl;
				cout << endl;
				system("pause");
				break;
			}
		}
		else 
		{
			cout << "您选择的是‘n’，按照您的需求，不录入此条业主信息" << endl; 
			if(size >= 0)
			{
				cout << "已添加"  << size << "位业主的信息！" << endl; 
			}
			cout << endl;
			cout << "即将返回至主页面！" << endl;
			cout << endl;
			system("pause"); 
			break;
		}
	}
}
void Show::reShow()
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(2) 修改业主信息---------------------------->\n" << endl;
	int size = owns.length();
	if(size == 0)
	{
		cout << endl; 
		cout << "【温馨提示】：系统还未存储任何业主信息！请返回至主页面添加业主信息！" << endl;
		cout << "即将返回至主页面！" << endl;
		cout << endl;
		system("pause");
		mainShow();
	}
	else 
	{
		cout << "【温馨提示】：此页面为业主信息修改页面，修改过程中请您仔细操作，以免造成信息录入失误，造成不必要的损失\n" << endl;
		cout << "您修改业主信息时，为了便于定位所要修改的业主信息，请先输入业主的姓名： ";
		char ni[20];
		cin >> ni;
		int upd = -1; 
		for(int i = 0; i < size ; i++)
		{
			Owner owner;
			owns.getData(i,owner);
			char mi[20];
			owner.getName(mi);
			if(strcmp(ni, mi) == 0)
			{
				cout << endl; 
				cout << "-·-·-·-·-·-·-·-·以下信息为业主 " << ni << " 已录入的信息-·-·-·-·-·-·-·-·" << endl; 
				owner.output();
				upd = i;
				cout << "-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·\n" << endl;
				cout << "【温馨提示】：请您确认好，如上信息是否有需要修改的地方（y/n）：" ;
				char ind;
				cin >> ind;
				if(ind == 'y' || ind == 'Y') 
				{
					Owner owner;
					char name[20];  
					int age;  
					char sex[4];  
					int year;  
					int amount; 
					char number[20]; 
					int door; 
					char car[4]; 
					char marriage[4];
					cout << "您总共需要修改业主的几条信息？（若只修改1条，请输入1；若修改多条，请输入2）： ";
					int a;
					cin >> a;
					cout << endl;
					if(a == 1)
					{
						cout << "您需要修改业主的哪条信息？" << endl;
						cout << "   ——————————————————————————————————"  << endl; 
						cout << "  |\t a: 修改姓名           b: 修改年龄       c： 修改性别            | "<< endl;
						cout << "  |\t d: 修改已居住年限     e: 修改家庭人数   f： 修改电话号码        | "<< endl;
						cout << "  |\t j: 修改所在楼栋单元   h: 修改是否有车   i： 修改是否婚配        | "<< endl;  
						cout << "   ——————————————————————————————————"  << endl; 
						cout << "请输入字段前对应的字母： "; 
						char ch;
						cin >> ch;
						switch(ch)
						{
							case 'a':
								cout << "业主" << ni << "的姓名改为： ";
								cin >> name;
								owner.setName(name);
								break;
							case 'b':
								cout << "业主" << ni << "的年龄改为： ";
								cin >> age;
								owner.setAge(age);
								break; 
							case 'c':
								cout << "业主" << ni << "的性别改为： ";
								cin >> sex;
								owner.setSex(sex);
								break; 
							case 'd':
								cout << "业主" << ni << "的已居住年限改为： ";
								cin >> year;
								owner.setYear(year);
								break; 
							case 'e': 
								cout << "业主" << ni << "的家庭人数改为： ";
								cin >> amount;
								owner.setAmount(amount);
								break;
							case 'f': 
								cout << "业主" << ni << "的电话号码改为： ";
								cin >> number;
								owner.setNumber(number);
								break; 
							case 'j': 
								cout << "业主" << ni << "所在楼栋单元改为： ";
								cin >> door;
								owner.setDoor(door);
								break;
							case 'h': 
								cout << "业主" << ni << "是否有车改为： ";
								cin >> car;
								owner.setCar(car);
								break;
							case 'i': 
								cout << "业主" << ni << "是否婚配改为： ";
								cin >> marriage;
								owner.setMarriage(marriage);
								break; 
						}
					} 
					else if(a == 2)
					{
						cout << "【温馨提示】：鉴于您需要修改的信息较多，请您重新输入业主的所有信息，系统将保存您修改后的业主信息\n" << endl;
						cout << "业主" << ni << "的姓名改为： ";
						cin >> name;
						owner.setName(name);
						cout << "业主" << ni << "的年龄改为： ";
						cin >> age;
						owner.setAge(age);
						cout << "业主" << ni << "的性别改为： ";
						cin >> sex;
						owner.setSex(sex);
						cout << "业主" << ni << "的已居住年限改为： ";
						cin >> year;
						owner.setYear(year);
						cout << "业主" << ni << "的家庭人数改为： ";
						cin >> amount;
						owner.setAmount(amount);
						cout << "业主" << ni << "的电话号码改为： ";
						cin >> number;
						owner.setNumber(number);
						cout << "业主" << ni << "所在楼栋单元改为： ";
						cin >> door;
						owner.setDoor(door);
						cout << "业主" << ni << "是否有车改为： ";
						cin >> car;
						owner.setCar(car);
						cout << "业主" << ni << "是否婚配改为： ";
						cin >> marriage;
						owner.setMarriage(marriage);
					}
					cout << endl; 
					cout << "确认修改？（y/n）" ;
					char ins;
					cin >> ins;
					if(ins == 'y' || ins == 'Y')
					{
						owns.setData(upd,owner); 
						cout << "修改完毕！" << endl;
						cout << "即将返回至主页面！" << endl;
						cout << endl;
						system("pause");
						break; 
						mainShow();
					}
					else
					{
						cout << endl; 
						cout << "您选择的是‘n’，按照您的需求，本次不执行修改操作" << endl; 
						cout << endl;
						cout << "即将返回至主页面！" << endl;
						cout << endl;
						system("pause");  
					} 
	 			}
	 			else
				{
				 	cout << endl; 
					cout << "您选择的是‘n’，按照您的需求，本次不执行修改操作" << endl; 
					cout << endl;
					cout << "即将返回至主页面！" << endl;
					cout << endl;
					system("pause"); 
				}
			}
			if(i == size-1 && upd == -1)
			{
				cout << endl;      //判断是否存在业主信息 
				cout << "查无此人！\n" << endl; 
				cout << "【温馨提示】：若继续修改，请输入1；若结束本次修改，请输入2： " ;
				int inx;
				cin >> inx;
				if(inx == 1)
				{
					reShow();					break;
					mainShow();
				}
				else if(inx == 2)
				{
					cout << endl;
					cout << "您选择了结束本次修改，即将返回至主页面！" << endl;
					cout << endl;
					system("pause");
				break;
					mainShow(); 
				}
				else
				{
					cout << "您输入的不是1或2，输入错误！请重新输入！" << endl;
					system("pause");
					reShow(); 
				}
			}
		}
	}
}
void Show::delShow()
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(3) 删除业主信息---------------------------->\n" << endl;
	cout << endl; 
	int size = owns.length();
	if(size == 0)
	{
		cout << endl; 
		cout << "【温馨提示】：系统还未存储任何业主信息！请返回至主页面添加业主信息！" << endl;
		cout << "即将返回至主页面！" << endl;
		cout << endl;
		system("pause");
		mainShow();
	}
	else 
	{
		cout << "【温馨提示】：此页面为业主信息删除页面，删除前，请确保需要删除的业主名单正确，避免误删 " << endl;
  	    cout << endl;
		cout << "您删除业主信息时，为了便于定位所要删除的业主信息，请先输入业主的姓名： ";
	    char ni[20];
		cin >> ni;
		int del = -1;
		for(int i = 0; i < size; i++)
		{
			Owner owner;
			owns.getData(i,owner);
			char mi[20];
			owner.getName(mi);
			if(strcmp(ni, mi) == 0)
			{
				cout << endl;
				cout << "-·-·-·-·-·以下信息为业主" << ni << "已录入的信息-·-·-·-·-·" << endl; 
				owner.output();
				del = i;
				cout << "-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·\n" << endl;
				cout << "【温馨提示】：请您确认好，上面的业主信息是否要删除（y/n）" ;
				char ins;
				cin >> ins;
				if(ins == 'y' || ins == 'Y')
				{
					Owner owner;
					owns.remove(del,owner); 
				 	cout << endl;
					cout << "删除完成！" << endl;
					cout << "即将返回至主页面！" << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					cout << endl; 
					cout << "您选择的是‘n’，按照您的需求，本次不执行删除操作" << endl; 
					cout << endl;
					cout << "即将返回至主页面！" << endl;
					cout << endl;
					system("pause"); 
				}
			}
			else if(i == size-1 && del == -1)
			{
				cout << endl; 
				cout << "查无此人！\n" << endl; 
				cout << "【温馨提示】：若继续删除，请输入1；若结束本次删除，请输入2： " ;
				int inx;
				cin >> inx;
				if(inx == 1)
				{
					delShow();
					break;
					mainShow();
				}
				else if(inx == 2)
				{
					cout << endl;
					cout << "您选择了结束本次删除，即将返回至主页面！" << endl;
					cout << endl;
					system("pause");
					break;
					mainShow(); 
				}
				else 
				{
					cout << "您输入的不是1或2，输入错误！请重新输入！" << endl;
					system("pause");
					delShow(); 
				}
			}
		}
	}
}
void Show::infoShow()
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(4) 查询业主信息---------------------------->\n" << endl;
	int size = owns.length();
	if(size == 0)
	{
		cout << endl; 
		cout << "【温馨提示】：系统还未存储任何业主信息！请返回至主页面添加业主信息！" << endl;
		cout << "即将返回至主页面！" << endl;
		cout << endl;
		system("pause");
		mainShow();
	}
	else 
	{
		cout << "如果需要查询系统内所有业主的信息，请输入1；如果需要查询单个业主的信息，请输入2：" ;
 	 	int ind;
		cin >> ind;
		if(ind == 1)
		{ 
			cout << endl;
			cout <<"******  √查询所有业主信息 ******\n" << endl;  
			for(int i = 0; i < size; i++)
			{
				Owner owner;
				owns.getData(i, owner);
				owner.output(); 
				cout << endl; 
			}
			cout << endl; 
			cout << "以上为所有的业主信息！\n" << endl; 
			cout << endl;
			cout << "查询完毕！" << endl;
			cout << "即将返回至主页面！" << endl;
			cout << endl;
			system("pause");
		}
		else if(ind == 2)
		{
			cout << endl;
			cout << "****** √查询单个业主信息 ******\n" << endl;
			cout << "您查询业主信息时，为了便于定位所要查询的业主信息，请先输入业主的姓名： ";
			char ni[20];
			cin >> ni;
			int j;
			for(j = 0; j < size; j++)
			{
				Owner owner;
				owns.getData(j, owner);
				char mi[20];
				owner.getName(mi);
				if(strcmp(ni, mi) == 0)
				{
					cout << endl;
					owner.output();
					cout << endl;
					cout << "业主" << ni << "的信息如上\n" << endl; 
					cout << "查询完毕！" << endl;
					cout << "即将返回至主页面！" << endl;
					cout << endl;
					system("pause");
					break;
					mainShow();
				}
				if(j == size-1)
				{
					if(strcmp(ni, mi) == 0)
					{
						return;
					}
					else
					{
						cout << endl; 
						cout << "查无此人！\n" << endl;
						cout << "【温馨提示】：若继续查询，请输入1；若结束本次查询，请输入2： " ;
						int inx;
						cin >> inx;
						if(inx == 1)
						{
							infoShow();
							break;
							mainShow();
						}
						else 
						{
							cout << endl;
							cout << "您选择了结束本次查询，即将返回至主页面！" << endl;
							cout << endl;
							system("pause");
							break;
							mainShow(); 
						}
					} 
				}
			}
		}
		else
		{
			cout << "您输入的不是1或2，输入错误！请重新输入！" << endl;
			system("pause");
			infoShow(); 
		}
	}
}
void Show::help()
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(7)   帮助菜单  ---------------------------->\n" << endl;
	cout << "【温馨提示】：此页面为解释页面，如果您有任何的疑惑，可以从此页面下查询相关信息，解答您的疑惑，祝您使用愉快！\n"  << endl;
	cout << "【使用前提】：" << endl;
	cout << "打开主页面前，需要输入正确的用户名和密码，为了确保信息的隐私，本系统设置的用户名和密码是唯一的哦。\n" << endl; 
	cout << "【注意事项】：\n" << endl;
	cout << "1、您输入“年龄”、“已居住年限”的时候，请输入整数，默认单位为年（year）；\n" << endl;
	cout << "2、电话号码可以填业主的手机号码，也可以填业主家中的座机号码；\n" << endl;
	cout << "3、填“所在楼栋单元”时，为了统一格式，方便检查，请输入类似于‘021101’的形式；" << endl;
	cout << "（其中，02表示业主所在的楼栋，表示第几栋；11表示业主家的楼层，表示第几层；01表示同层内业主所在的房间，表示第几个）\n" << endl; 
	cout << "4、填“是否有车”和“是否婚配”时，请填‘是’或‘否’，不要填其他的词；\n" << endl;
	cout << "以上为【帮助菜单】内的全部内容。\n" << endl;
	cout << "即将返回至主页面！" << endl;
	cout << endl;
	system("pause");
}
void Show::save()  //保存文件记录 
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(5)  保存信息  ---------------------------->\n" << endl;	
	ofstream out;
	out.open("物业基本信息管理系统 - 业主信息.txt", ios::app);
	if (!out.is_open()) {
		cout << "文件无法打开！" << endl;
		system("pause");
		return;
	}
	int size = owns.length();
	char name[20];  
	int age;  
	char sex[4];  
	int year;  
	int amount; 
	char number[20]; 
	int door; 
	char car[4]; 
	char marriage[4];
	for(int i = 0; i < size; i++)
	{
		Owner owner;
		owns.getData(i , owner);
		owner.getName(name);
		out << "【     姓名     】： " << name << endl;
		out << "【     年龄     】： " << owner.getAge() << endl;
		owner.getSex(sex);
		out << "【     性别     】： " <<  sex << endl;
		out << "【  已居住年限  】： " << owner.getYear() << endl;
		out << "【   家庭人数   】： " << owner.getAmount() << endl;
		owner.getNumber(number);
		out << "【   电话号码   】： " << number << endl; 
		out << "【 所在楼栋单元 】： " << owner.getDoor() << endl;
		owner.getCar(car);
		out << "【   是否有车   】： " << car << endl;
		owner.getMarriage(marriage);
		out << "【   是否婚配   】： " << marriage << endl; 
		out << endl;
	}
		out.close();  
		cout << endl;
		cout << "-·-·-·-·-·-·已成功保存所有业主信息！-·-·-·-·-·-·\n" << endl;
		system("pause");  
}
void Show::read()  //读取文件记录 
{
	system("cls"); 
	cout << endl;
	cout << "\t\t\t<----------------------------(6) 读取历史信息 ---------------------------->\n" << endl;
	ifstream in;
	in.open("物业基本信息管理系统 - 业主信息.txt", ios::app);
	if (!in.is_open()) {
		cout << "文件无法打开！" << endl;
		return;
	} 
	char se[300];
	while(!in.eof())
	{
		in.getline(se,100);
		cout << se << endl;
	}
	in.close(); 
	cout << "-·-·-·-·-·-·已成功读取所有业主信息！-·-·-·-·-·-·\n" << endl;
	system("pause");
} 
void enter() //登录页面设置 
{
	string account, password;
	cout << endl;
	cout << "\t\t\t\t 【 用户名 】： ";
	cin >> account;
	if(account != "李婷")
	{
		cout << endl;
		cout << "\t\t\t\t此用户名不能访问本系统！请输入正确的用户名！\n" << endl;	 
		enter(); 
	}
	else
	{
		cout << "\t\t\t\t 【  密码  】： ";
		cin >> password;
		if(password == "202115110")
		{
			cout << "\n \t\t\t\t\t登录成功！" << endl;
			system("pause");
		} 
		else 
		{
			while(password != "202115110")
			{
				cout << endl;
				cout << "\t\t\t\t此密码不匹配输入的用户名！请输入正确的密码！\n" << endl;
				cout << "\t\t\t\t 【  密码  】： ";
				cin >> password;
			}
		}
	}
} 
void mainPoint()
{
	enter();
	Show show;
	while(true)
	{
		system("cls");
		show.mainShow();
		show.key();
	} 
}
int main()
{
	cout << endl;
	cout << "\t\t* * * * * * * * * *欢迎您使用物业基本信息管理系统* * * * * * * * * *\n" << endl; 
	cout << endl; 
	cout << "\t \t \t* *进入系统之前，请您输入正确的用户名和密码 * *" << endl;
	cout << endl;
	mainPoint();
	return 0;
}
