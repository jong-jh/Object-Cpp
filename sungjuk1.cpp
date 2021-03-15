/**************************************************/
/*             HW#1 : C++ �����ϱ�                                                   */
/*  �ۼ��� : ������                                ��¥ : 2021�� 3�� 10��  */
/*                                                                                                     */
/* ���� ���� :                                                                                 */
/*                - - - - - - -                                                                      */
/*************************************************/
#include<iostream>
#include<string>
using namespace std;//

struct Subject{// ���� ����
    char SubName[30];//�����̸�
    int Hakjum;     //���� ������
    char Grade[10]; //���� ���
    float GPA;      //���� ����
};

struct Student{//�л� ����
    char StdName[30];//�л� �̸�
    int StdNum;     //�й�
    Subject Sub[3]; //����
    float AveGPA;   //������ ��� ����
};

int menu(); //�޴� ��� �Լ�

void menu_1(struct Student*); //�޴� 1�� ���� �Լ�
void menu_2(struct Student*); //�޴� 2�� ���� �Լ�
void convert_GPA(struct Student*);//���� ��� -> ���� ��ȯ �Լ�


int main(){//main �Լ�
    Student Std[2];//2���� �л��� ���� ũ�Ⱑ 2�� ����ü �迭 ����

while(1){
int num=menu();//�޴� ��� �� ��� ����
if (num==3) {break;}//3���� ������ while���� Ż��

switch(num){
  case 1:
    cout<<"\n1���� ���õǾ����ϴ�."<<endl<<endl;
    menu_1(Std);//����ü �迭�� �Լ��� ����
    break;
  case 2:
    cout<<"\n2���� ���õǾ����ϴ�.\n\n";
    convert_GPA(Std); //���� ��ȯ �Լ� ����
    menu_2(Std); //�޴� 2 ����
    break;
  }
}


}




int menu(){//�޴���� �Լ�
  cout<<"~~~~menu~~~~"<<endl;
  cout<<"1. �л� ���� �Է�"<<endl;
  cout<<"2. ��ü �л� ���� ����"<<endl;
  cout<<"3. ���α׷� ����"<<endl<<endl;
  cout<<"���ϴ� ����� �Է��ϼ��� : ";
  int num;
  cin>>num;//��ȣ�� �Է¹޴´�
  
  if(num<=3) //����ó��
    return num;
  else{//3���� ū ���ڸ� �Է��ϸ�
      cout<<"�ٸ� ��ȣ�� �Է����ּ���"<<endl<<endl;
      menu(); //�޴��� �ٽ� �ҷ�����
  }
}

void convert_GPA(struct Student* st){//���� GPA ��ȯ �Լ�
  for(int i=0;i<2;i++){

    for(int j=0;j<3;j++){
    if((st+i)->Sub[j].Grade=="a+"||(st+i)->Sub[j].Grade=="A+")
      (st+i)->Sub[j].GPA=4.5;
    else if((st+i)->Sub[j].Grade=="a0"||(st+i)->Sub[j].Grade=="A0")
      (st+i)->Sub[j].GPA=4.0;
    else if((st+i)->Sub[j].Grade=="b+"||(st+i)->Sub[j].Grade=="B+")
      (st+i)->Sub[j].GPA=3.5;
    else if((st+i)->Sub[j].Grade=="b0"||(st+i)->Sub[j].Grade=="B0")
      (st+i)->Sub[j].GPA=3.0;
    else if((st+i)->Sub[j].Grade=="c+"||(st+i)->Sub[j].Grade=="C+")
      (st+i)->Sub[j].GPA=2.5;
    else if((st+i)->Sub[j].Grade=="c0"||(st+i)->Sub[j].Grade=="C0")
      (st+i)->Sub[j].GPA=2.0;
    else if((st+i)->Sub[j].Grade=="d+"||(st+i)->Sub[j].Grade=="D+")
      (st+i)->Sub[j].GPA=1.5;
    else if((st+i)->Sub[j].Grade=="d0"||(st+i)->Sub[j].Grade=="D0")
      (st+i)->Sub[j].GPA=1.0;
    else if((st+i)->Sub[j].Grade=="f"||(st+i)->Sub[j].Grade=="F")
      {(st+i)->Sub[j].GPA=0.0;}
    
    (st+i)->AveGPA+=((st+i)->Sub[j].GPA)*((st+i)->Sub[j].Hakjum); //���� ������ AveGPA�� �ջ��Ѵ�.
    }
    (st+i)->AveGPA=((st+i)->AveGPA)/(((st+i)->Sub[0].Hakjum)+((st+i)->Sub[1].Hakjum)+((st+i)->Sub[2].Hakjum));//AveGPA�� ���� ��ü�������� ������ ����� ���Ѵ�.
  }
}

void menu_1(struct Student* st){//�л� ���� �Է� �Լ�
    for(int i=0;i<2;i++){//2���� �л��� �Է��ϱ� ������ 2�� �ݺ�
      cout<<i+1<<"��° �л� �̸��� �й��� �Է��ϼ���.\n"<<endl;
      cout<<"�̸� : ";
      cin>>(st+i)->StdName;//����ü �迭�� ���۷��� ǥ��
      cout<<"�й� : "; 
      cin>>(st+i)->StdNum;
      cout<<"\n\n";
        
      cout<<"������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���."<<endl<<endl;
  int j=0;
        for(j=0;j<3;j++){//����[0],[1],[2]�� �޴´�.
            
            cout<<"������� : ";
            cin>>(st+i)->Sub[j].SubName;
            cout<<"���������� (���� �Է�!!) : ";
            cin>>(st+i)->Sub[j].Hakjum;
            cout<<"������(A+ ~ F) :";
            cin>>(st+i)->Sub[j].Grade;
            cout<<"\n";
        }
    }

    cout<<"\n�Է��� �Ϸ� �Ǿ����ϴ�\n"<<endl;
}

void menu_2(struct Student* st){
cout.width(30); cout.fill(' ');
cout<<"��ü �л� ���� ����"<<endl;//2�� �޴� ��� ����
cout.width(70); cout.fill('='); cout<<'='; //���� ���
cout<<endl;

for(int i=0;i<2;i++){
  cout<<"�̸� : "<<(st+i)->StdName<<"  �й� : "<<(st+i)->StdNum<<endl;
  cout.width(50); cout.fill('='); cout<<'='<<endl; //���� ��� ���� 50, ���� = ���
  cout.width(20); cout.fill(' '); cout<<"����� "; //���� ��ĭ ���
  cout.width(10); cout<<"�������� ";
  cout.width(10); cout<<"������ ";
  cout.width(10); cout<<"�������� "<<endl;
  cout.width(50); cout.fill('='); cout<<'='<<endl; //���� ���
  for(int j=0;j<3;j++){
    cout.width(20); cout.fill(' '); cout<<(st+i)->Sub[j].SubName; //���� ���
    cout.width(10); cout<<(st+i)->Sub[j].Hakjum;
    cout.width(10); cout<<(st+i)->Sub[j].Grade;
    cout.width(10); cout<<((st+i)->Sub[j].GPA)*((st+i)->Sub[j].Hakjum)<<endl;
    }
  cout.width(50); cout.fill('='); cout<<'='<<endl; //���� ���
  cout.width(35); cout.fill(' '); cout<<"�������";
  cout.width(10); cout.fill(' '); cout<<(st+i)->AveGPA<<endl;//������� ���
  }

}

