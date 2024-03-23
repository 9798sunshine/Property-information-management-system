#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
//-------------------------����һ����ʽ��------------------------- 
template <class T>
struct LinkNode
{
	LinkNode<T> * next = NULL;  //����ָ���򣬲���ʼ��Ϊ��ָ�� 
	T data;   //����������
};
template <class T>
class Link
{
	private:
		LinkNode<T> * head; //��������ͷָ��
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
	head = new LinkNode<T>;  // ���캯�� 
}
template <class T>
Link<T>::~Link()
{   //�������� 
	makeEmpty();  //�ÿ����� 
	delete head;  //ɾ��ͷ��� 
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
	return count;   //��������ĳ��� 
} 
template <class T>
int Link<T>::search(T & x)   //����������x��Ԫ�� 
{                       
	LinkNode<T> *  n = head->next;
	int i = 0;
	while(n != NULL){
		if(n->data == x)
			return i;  //�����ɹ�������x��Ӧ��Ԫ�ص����� 
		n = n->next;
		i++;    
	}
	return -1;  //����ʧ�ܣ�����-1 
}
template <class T>
bool Link<T>::isEmpty()
{
	return head->next == NULL ? true : false;   //�ж������Ƿ����ˣ�������ˣ��򷵻�true������������򷵻�false 
} 
template <class T>
bool Link<T>::isFull()
{
	return false;
}
template <class T>
void Link<T>::makeEmpty()
{  // �ÿ����� 
	LinkNode<T> * n;
	while(head->next != NULL)
	{   //�ж������Ƿ�Ϊ�գ������Ϊ�գ���ɾ�����н�� 
		n = head->next;
		head->next = n->next;   //���汻ɾ��㣬����������ɾ����� 
		delete n;   // ɾ��ȫ����� 
	} 
}
template <class T>
bool Link<T>::getData(int index, T & x)
{    //ȡ���±�Ϊindex��Ԫ�ص�ֵ 
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
{   //��x�����±�Ϊindex��Ԫ�ص�ֵ 
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
{   //������Ϊindex��Ԫ�غ��������Ԫ��x 
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
{  //ɾ������Ϊindex��Ԫ�أ�x�����Ԫ�ص�ֵ 
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
{  //������� 
	LinkNode<T> * n = head->next;
	while(n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	} 
	cout << endl;
}

//-------------------------ҵ���Ļ�����Ϣ------------------------- 
class Owner
{
	private:
		char name[20];  //ҵ�������� 
		int age;  //ҵ�������� 
		char sex[4];  //ҵ�����Ա�
		int year;  //ҵ���Ѿ�ס������
		int amount; //ҵ���Ҿ�ס������
		char number[20]; //ҵ���ĵ绰���� 
		int door; //ҵ�������ڵ�¥�� 
		char car[4]; //�Ƿ��г�
		char marriage[4]; //����״�����Ƿ��� 
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
		void output(); //������ 
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
	cout << "��ҵ������������ " << name << endl;
	cout << "��" << name << "�����䡿�� " << age << endl;
	cout << "��" << name << "���Ա𡿣� " << sex << endl;
	cout << "��" << name << "���Ѿ�ס���ޡ��� " << year << endl;
	cout << "��" << name << "�ļ�ͥ�������� "  << amount << endl;
	cout << "��" << name << "�ĵ绰���롿�� "  << number << endl;
	cout << "��" << name << "���ڵ�¥����Ԫ���� " << door << endl;
	cout << "��" << name << "���Ƿ��г����� " << car << endl;
	cout << "��" << name << "�Ƿ���䡿�� " << marriage << endl; 
}
//-------------------------��ҳ����ʾ------------------------- 
class Show
{
	private:
		Link <Owner> owns;
	public:
		Show();
		void mainShow();  //��ҳ�� 
		void key();  //��ҳ���ϵ�ѡ����ת 
		void infoShow();  // չʾҵ����Ϣ 
		void putShow(); //���ҵ����Ϣ 
		void reShow(); //�޸�ҵ����Ϣ 
		void delShow(); //ɾ��ҵ����Ϣ
		void help();  //����ҳ���£�1��~��5����ط������һ������ 
		void save(); //����ҵ������Ϣ
		void read(); //��ȡҵ������Ϣ 
}; 
Show::Show()
{
	mainShow();
}
void Show::mainShow()
{
	cout << endl;
	cout << "\t\t\t*********************��ҳ��*********************" << endl;
	cout << endl; 
	cout << "\t\t\t*            �� (1) ���ҵ����Ϣ ��            *"<< endl;
	cout << "\t\t\t*            �� (2) �޸�ҵ����Ϣ ��            *"<< endl; 
	cout << "\t\t\t*            �� (3) ɾ��ҵ����Ϣ ��            *"<< endl; 
	cout << "\t\t\t*            �� (4) ��ѯҵ����Ϣ ��            *"<< endl;  
	cout << "\t\t\t*            ����5��  ������Ϣ   ��            *"<< endl; 
	cout << "\t\t\t*            �� (6) ��ȡ��ʷ��Ϣ ��            *"<< endl;  
	cout << "\t\t\t*            �� (7)   �����˵�   ��            *"<< endl;  
	cout << "\t\t\t*            ����8���˳�����ϵͳ ��            *\n"<< endl; 
	cout << "\t\t\t************************************************ "<< endl; 
	cout << endl;
	cout << "\t�ڴ���������ָ� " ; 
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
			cout << "\t-��-��-��-��-����л��ʹ�ñ�ϵͳ-��-��-��-��-��" << endl;
			exit(0);
			break;
	}
} 
void Show::putShow()
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(1) ���ҵ����Ϣ---------------------------->\n" << endl;
	char name[20];  
	int age;  
	char sex[4];  
	int year;  
	int amount; 
	char number[20]; 
	int door; 
	char car[4]; 
	char marriage[4];
	int size = 0; //���ڼ�¼����ӵ�ҵ������ 
	while(true)
	{
		cout << "��     ����     ���� ";	
		cin >> name;
		cout << "��     ����     ���� " ;
		cin >> age; 
		cout << "��     �Ա�     ���� " ;
		cin >> sex;
		cout << "��  �Ѿ�ס����  ���� " ;
		cin >> year;
		cout << "��   ��ͥ����   ���� " ;
		cin >> amount;
		cout << "��   �绰����   ���� " ;
		cin >> number;
		cout << "�� ����¥����Ԫ ���� " ;
		cin >> door; 
		cout << "��   �Ƿ��г�   ���� " ;
		cin >> car;
		cout << "��   �Ƿ����   ���� " ;
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
		cout << "�����ٴ�ȷ�ϣ��Ƿ񽫴���ҵ����Ϣ¼��ϵͳ����y/n���� "; 
		cin >> ind;
		if( ind == 'y' || ind == 'Y')   //ʵ��Ӧ���У�ż�����Сдy��ɴ�дY�����Դ˴����ô�Сд���� 
		{								
			owns.insert(size, owner);
			char ins;
			cout << "����ܰ��ʾ�����Ƿ���������һ��ҵ����Ϣ����y/n���� " ;  
			cin >> ins;
			cout << endl;
			if(ins == 'y' || ins == 'Y')
			{ 
 				cout << "Ŀǰ����� " << size+1 << " λҵ������Ϣ��" << endl;   //��Ϊs�Ǵ�0��ʼ�ӵģ�����ͳ������ӵ�ҵ������ʱ��Ҫ�ټ�1 
				cout << "��������룬���ҵ����Ϣ��" << endl;
				size++; 
				cout << endl; 
			}   
			else
			{ 
				cout << "��ѡ����ǡ�n���������������󣬲��������һ��ҵ����Ϣ" << endl; 
				cout << endl;
				cout << "����� " << size+1 << " λҵ������Ϣ��" << endl;
				cout << "������������ҳ�棡" << endl;
				cout << endl;
				system("pause");
				break;
			}
		}
		else 
		{
			cout << "��ѡ����ǡ�n���������������󣬲�¼�����ҵ����Ϣ" << endl; 
			if(size >= 0)
			{
				cout << "�����"  << size << "λҵ������Ϣ��" << endl; 
			}
			cout << endl;
			cout << "������������ҳ�棡" << endl;
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
	cout << "\t\t\t<----------------------------(2) �޸�ҵ����Ϣ---------------------------->\n" << endl;
	int size = owns.length();
	if(size == 0)
	{
		cout << endl; 
		cout << "����ܰ��ʾ����ϵͳ��δ�洢�κ�ҵ����Ϣ���뷵������ҳ�����ҵ����Ϣ��" << endl;
		cout << "������������ҳ�棡" << endl;
		cout << endl;
		system("pause");
		mainShow();
	}
	else 
	{
		cout << "����ܰ��ʾ������ҳ��Ϊҵ����Ϣ�޸�ҳ�棬�޸Ĺ�����������ϸ���������������Ϣ¼��ʧ����ɲ���Ҫ����ʧ\n" << endl;
		cout << "���޸�ҵ����Ϣʱ��Ϊ�˱��ڶ�λ��Ҫ�޸ĵ�ҵ����Ϣ����������ҵ���������� ";
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
				cout << "-��-��-��-��-��-��-��-��������ϢΪҵ�� " << ni << " ��¼�����Ϣ-��-��-��-��-��-��-��-��" << endl; 
				owner.output();
				upd = i;
				cout << "-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��\n" << endl;
				cout << "����ܰ��ʾ��������ȷ�Ϻã�������Ϣ�Ƿ�����Ҫ�޸ĵĵط���y/n����" ;
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
					cout << "���ܹ���Ҫ�޸�ҵ���ļ�����Ϣ������ֻ�޸�1����������1�����޸Ķ�����������2���� ";
					int a;
					cin >> a;
					cout << endl;
					if(a == 1)
					{
						cout << "����Ҫ�޸�ҵ����������Ϣ��" << endl;
						cout << "   ��������������������������������������������������������������������"  << endl; 
						cout << "  |\t a: �޸�����           b: �޸�����       c�� �޸��Ա�            | "<< endl;
						cout << "  |\t d: �޸��Ѿ�ס����     e: �޸ļ�ͥ����   f�� �޸ĵ绰����        | "<< endl;
						cout << "  |\t j: �޸�����¥����Ԫ   h: �޸��Ƿ��г�   i�� �޸��Ƿ����        | "<< endl;  
						cout << "   ��������������������������������������������������������������������"  << endl; 
						cout << "�������ֶ�ǰ��Ӧ����ĸ�� "; 
						char ch;
						cin >> ch;
						switch(ch)
						{
							case 'a':
								cout << "ҵ��" << ni << "��������Ϊ�� ";
								cin >> name;
								owner.setName(name);
								break;
							case 'b':
								cout << "ҵ��" << ni << "�������Ϊ�� ";
								cin >> age;
								owner.setAge(age);
								break; 
							case 'c':
								cout << "ҵ��" << ni << "���Ա��Ϊ�� ";
								cin >> sex;
								owner.setSex(sex);
								break; 
							case 'd':
								cout << "ҵ��" << ni << "���Ѿ�ס���޸�Ϊ�� ";
								cin >> year;
								owner.setYear(year);
								break; 
							case 'e': 
								cout << "ҵ��" << ni << "�ļ�ͥ������Ϊ�� ";
								cin >> amount;
								owner.setAmount(amount);
								break;
							case 'f': 
								cout << "ҵ��" << ni << "�ĵ绰�����Ϊ�� ";
								cin >> number;
								owner.setNumber(number);
								break; 
							case 'j': 
								cout << "ҵ��" << ni << "����¥����Ԫ��Ϊ�� ";
								cin >> door;
								owner.setDoor(door);
								break;
							case 'h': 
								cout << "ҵ��" << ni << "�Ƿ��г���Ϊ�� ";
								cin >> car;
								owner.setCar(car);
								break;
							case 'i': 
								cout << "ҵ��" << ni << "�Ƿ�����Ϊ�� ";
								cin >> marriage;
								owner.setMarriage(marriage);
								break; 
						}
					} 
					else if(a == 2)
					{
						cout << "����ܰ��ʾ������������Ҫ�޸ĵ���Ϣ�϶࣬������������ҵ����������Ϣ��ϵͳ���������޸ĺ��ҵ����Ϣ\n" << endl;
						cout << "ҵ��" << ni << "��������Ϊ�� ";
						cin >> name;
						owner.setName(name);
						cout << "ҵ��" << ni << "�������Ϊ�� ";
						cin >> age;
						owner.setAge(age);
						cout << "ҵ��" << ni << "���Ա��Ϊ�� ";
						cin >> sex;
						owner.setSex(sex);
						cout << "ҵ��" << ni << "���Ѿ�ס���޸�Ϊ�� ";
						cin >> year;
						owner.setYear(year);
						cout << "ҵ��" << ni << "�ļ�ͥ������Ϊ�� ";
						cin >> amount;
						owner.setAmount(amount);
						cout << "ҵ��" << ni << "�ĵ绰�����Ϊ�� ";
						cin >> number;
						owner.setNumber(number);
						cout << "ҵ��" << ni << "����¥����Ԫ��Ϊ�� ";
						cin >> door;
						owner.setDoor(door);
						cout << "ҵ��" << ni << "�Ƿ��г���Ϊ�� ";
						cin >> car;
						owner.setCar(car);
						cout << "ҵ��" << ni << "�Ƿ�����Ϊ�� ";
						cin >> marriage;
						owner.setMarriage(marriage);
					}
					cout << endl; 
					cout << "ȷ���޸ģ���y/n��" ;
					char ins;
					cin >> ins;
					if(ins == 'y' || ins == 'Y')
					{
						owns.setData(upd,owner); 
						cout << "�޸���ϣ�" << endl;
						cout << "������������ҳ�棡" << endl;
						cout << endl;
						system("pause");
						break; 
						mainShow();
					}
					else
					{
						cout << endl; 
						cout << "��ѡ����ǡ�n���������������󣬱��β�ִ���޸Ĳ���" << endl; 
						cout << endl;
						cout << "������������ҳ�棡" << endl;
						cout << endl;
						system("pause");  
					} 
	 			}
	 			else
				{
				 	cout << endl; 
					cout << "��ѡ����ǡ�n���������������󣬱��β�ִ���޸Ĳ���" << endl; 
					cout << endl;
					cout << "������������ҳ�棡" << endl;
					cout << endl;
					system("pause"); 
				}
			}
			if(i == size-1 && upd == -1)
			{
				cout << endl;      //�ж��Ƿ����ҵ����Ϣ 
				cout << "���޴��ˣ�\n" << endl; 
				cout << "����ܰ��ʾ�����������޸ģ�������1�������������޸ģ�������2�� " ;
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
					cout << "��ѡ���˽��������޸ģ�������������ҳ�棡" << endl;
					cout << endl;
					system("pause");
				break;
					mainShow(); 
				}
				else
				{
					cout << "������Ĳ���1��2������������������룡" << endl;
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
	cout << "\t\t\t<----------------------------(3) ɾ��ҵ����Ϣ---------------------------->\n" << endl;
	cout << endl; 
	int size = owns.length();
	if(size == 0)
	{
		cout << endl; 
		cout << "����ܰ��ʾ����ϵͳ��δ�洢�κ�ҵ����Ϣ���뷵������ҳ�����ҵ����Ϣ��" << endl;
		cout << "������������ҳ�棡" << endl;
		cout << endl;
		system("pause");
		mainShow();
	}
	else 
	{
		cout << "����ܰ��ʾ������ҳ��Ϊҵ����Ϣɾ��ҳ�棬ɾ��ǰ����ȷ����Ҫɾ����ҵ��������ȷ��������ɾ " << endl;
  	    cout << endl;
		cout << "��ɾ��ҵ����Ϣʱ��Ϊ�˱��ڶ�λ��Ҫɾ����ҵ����Ϣ����������ҵ���������� ";
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
				cout << "-��-��-��-��-��������ϢΪҵ��" << ni << "��¼�����Ϣ-��-��-��-��-��" << endl; 
				owner.output();
				del = i;
				cout << "-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��\n" << endl;
				cout << "����ܰ��ʾ��������ȷ�Ϻã������ҵ����Ϣ�Ƿ�Ҫɾ����y/n��" ;
				char ins;
				cin >> ins;
				if(ins == 'y' || ins == 'Y')
				{
					Owner owner;
					owns.remove(del,owner); 
				 	cout << endl;
					cout << "ɾ����ɣ�" << endl;
					cout << "������������ҳ�棡" << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					cout << endl; 
					cout << "��ѡ����ǡ�n���������������󣬱��β�ִ��ɾ������" << endl; 
					cout << endl;
					cout << "������������ҳ�棡" << endl;
					cout << endl;
					system("pause"); 
				}
			}
			else if(i == size-1 && del == -1)
			{
				cout << endl; 
				cout << "���޴��ˣ�\n" << endl; 
				cout << "����ܰ��ʾ����������ɾ����������1������������ɾ����������2�� " ;
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
					cout << "��ѡ���˽�������ɾ����������������ҳ�棡" << endl;
					cout << endl;
					system("pause");
					break;
					mainShow(); 
				}
				else 
				{
					cout << "������Ĳ���1��2������������������룡" << endl;
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
	cout << "\t\t\t<----------------------------(4) ��ѯҵ����Ϣ---------------------------->\n" << endl;
	int size = owns.length();
	if(size == 0)
	{
		cout << endl; 
		cout << "����ܰ��ʾ����ϵͳ��δ�洢�κ�ҵ����Ϣ���뷵������ҳ�����ҵ����Ϣ��" << endl;
		cout << "������������ҳ�棡" << endl;
		cout << endl;
		system("pause");
		mainShow();
	}
	else 
	{
		cout << "�����Ҫ��ѯϵͳ������ҵ������Ϣ��������1�������Ҫ��ѯ����ҵ������Ϣ��������2��" ;
 	 	int ind;
		cin >> ind;
		if(ind == 1)
		{ 
			cout << endl;
			cout <<"******  �̲�ѯ����ҵ����Ϣ ******\n" << endl;  
			for(int i = 0; i < size; i++)
			{
				Owner owner;
				owns.getData(i, owner);
				owner.output(); 
				cout << endl; 
			}
			cout << endl; 
			cout << "����Ϊ���е�ҵ����Ϣ��\n" << endl; 
			cout << endl;
			cout << "��ѯ��ϣ�" << endl;
			cout << "������������ҳ�棡" << endl;
			cout << endl;
			system("pause");
		}
		else if(ind == 2)
		{
			cout << endl;
			cout << "****** �̲�ѯ����ҵ����Ϣ ******\n" << endl;
			cout << "����ѯҵ����Ϣʱ��Ϊ�˱��ڶ�λ��Ҫ��ѯ��ҵ����Ϣ����������ҵ���������� ";
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
					cout << "ҵ��" << ni << "����Ϣ����\n" << endl; 
					cout << "��ѯ��ϣ�" << endl;
					cout << "������������ҳ�棡" << endl;
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
						cout << "���޴��ˣ�\n" << endl;
						cout << "����ܰ��ʾ������������ѯ��������1�����������β�ѯ��������2�� " ;
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
							cout << "��ѡ���˽������β�ѯ��������������ҳ�棡" << endl;
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
			cout << "������Ĳ���1��2������������������룡" << endl;
			system("pause");
			infoShow(); 
		}
	}
}
void Show::help()
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(7)   �����˵�  ---------------------------->\n" << endl;
	cout << "����ܰ��ʾ������ҳ��Ϊ����ҳ�棬��������κε��ɻ󣬿��ԴӴ�ҳ���²�ѯ�����Ϣ����������ɻ�ף��ʹ����죡\n"  << endl;
	cout << "��ʹ��ǰ�᡿��" << endl;
	cout << "����ҳ��ǰ����Ҫ������ȷ���û��������룬Ϊ��ȷ����Ϣ����˽����ϵͳ���õ��û�����������Ψһ��Ŷ��\n" << endl; 
	cout << "��ע�������\n" << endl;
	cout << "1�������롰���䡱�����Ѿ�ס���ޡ���ʱ��������������Ĭ�ϵ�λΪ�꣨year����\n" << endl;
	cout << "2���绰���������ҵ�����ֻ����룬Ҳ������ҵ�����е��������룻\n" << endl;
	cout << "3�������¥����Ԫ��ʱ��Ϊ��ͳһ��ʽ�������飬�����������ڡ�021101������ʽ��" << endl;
	cout << "�����У�02��ʾҵ�����ڵ�¥������ʾ�ڼ�����11��ʾҵ���ҵ�¥�㣬��ʾ�ڼ��㣻01��ʾͬ����ҵ�����ڵķ��䣬��ʾ�ڼ�����\n" << endl; 
	cout << "4����Ƿ��г����͡��Ƿ���䡱ʱ������ǡ��򡮷񡯣���Ҫ�������Ĵʣ�\n" << endl;
	cout << "����Ϊ�������˵����ڵ�ȫ�����ݡ�\n" << endl;
	cout << "������������ҳ�棡" << endl;
	cout << endl;
	system("pause");
}
void Show::save()  //�����ļ���¼ 
{
	system("cls");
	cout << endl;
	cout << "\t\t\t<----------------------------(5)  ������Ϣ  ---------------------------->\n" << endl;	
	ofstream out;
	out.open("��ҵ������Ϣ����ϵͳ - ҵ����Ϣ.txt", ios::app);
	if (!out.is_open()) {
		cout << "�ļ��޷��򿪣�" << endl;
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
		out << "��     ����     ���� " << name << endl;
		out << "��     ����     ���� " << owner.getAge() << endl;
		owner.getSex(sex);
		out << "��     �Ա�     ���� " <<  sex << endl;
		out << "��  �Ѿ�ס����  ���� " << owner.getYear() << endl;
		out << "��   ��ͥ����   ���� " << owner.getAmount() << endl;
		owner.getNumber(number);
		out << "��   �绰����   ���� " << number << endl; 
		out << "�� ����¥����Ԫ ���� " << owner.getDoor() << endl;
		owner.getCar(car);
		out << "��   �Ƿ��г�   ���� " << car << endl;
		owner.getMarriage(marriage);
		out << "��   �Ƿ����   ���� " << marriage << endl; 
		out << endl;
	}
		out.close();  
		cout << endl;
		cout << "-��-��-��-��-��-���ѳɹ���������ҵ����Ϣ��-��-��-��-��-��-��\n" << endl;
		system("pause");  
}
void Show::read()  //��ȡ�ļ���¼ 
{
	system("cls"); 
	cout << endl;
	cout << "\t\t\t<----------------------------(6) ��ȡ��ʷ��Ϣ ---------------------------->\n" << endl;
	ifstream in;
	in.open("��ҵ������Ϣ����ϵͳ - ҵ����Ϣ.txt", ios::app);
	if (!in.is_open()) {
		cout << "�ļ��޷��򿪣�" << endl;
		return;
	} 
	char se[300];
	while(!in.eof())
	{
		in.getline(se,100);
		cout << se << endl;
	}
	in.close(); 
	cout << "-��-��-��-��-��-���ѳɹ���ȡ����ҵ����Ϣ��-��-��-��-��-��-��\n" << endl;
	system("pause");
} 
void enter() //��¼ҳ������ 
{
	string account, password;
	cout << endl;
	cout << "\t\t\t\t �� �û��� ���� ";
	cin >> account;
	if(account != "����")
	{
		cout << endl;
		cout << "\t\t\t\t���û������ܷ��ʱ�ϵͳ����������ȷ���û�����\n" << endl;	 
		enter(); 
	}
	else
	{
		cout << "\t\t\t\t ��  ����  ���� ";
		cin >> password;
		if(password == "202115110")
		{
			cout << "\n \t\t\t\t\t��¼�ɹ���" << endl;
			system("pause");
		} 
		else 
		{
			while(password != "202115110")
			{
				cout << endl;
				cout << "\t\t\t\t�����벻ƥ��������û�������������ȷ�����룡\n" << endl;
				cout << "\t\t\t\t ��  ����  ���� ";
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
	cout << "\t\t* * * * * * * * * *��ӭ��ʹ����ҵ������Ϣ����ϵͳ* * * * * * * * * *\n" << endl; 
	cout << endl; 
	cout << "\t \t \t* *����ϵͳ֮ǰ������������ȷ���û��������� * *" << endl;
	cout << endl;
	mainPoint();
	return 0;
}
