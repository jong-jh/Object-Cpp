/*******************************************************************************************************************************/
/*             HW#1 : C++ �����ϱ�                                                   */
/*  �ۼ��� : ������                                ��¥ : 2021�� 3�� 12��  */
/*                                                                                                     */
/* ���� ���� : �л� ������ �����ϴ� ����ü Student �� ���� �� ���� ������ �Է��ϴ� Subject����ü�� �̟G��  */
/*            �� ���� �л��� ���� ������ ������ �Է¹��� �� ������ ������ ȯ���� ���� ������ ������ ��� ������ ��¹޴� ����   */
/*            ����ü�� �Լ����ڷ� �޾�, ����ü �迭�� ���۷����� �����ϱ� ���� ǥ���� �ֿ� ����*/
/******************************************************************************************************************************/
#include<iostream>
#include<string> //string ���ڿ��� ����ϱ� ���� ����Ͽ���.
using namespace std;

/*�л� ������ �� ������ ���� ������ ��� ����ü�� �������ش�
struct Student �� struct Subject �迭�� ���������ν�
���� Subject�� �������� �ʾƵ� �� �л��� ���� ���������� ���� �� �ְ� �ȴ�.
*/
struct Subject{// ���� ����
    char SubName[30];//�����̸�
    int Hakjum;     //���� ������
    string Grade; //���� ���, char Grade[10]���� ������, string�Լ��� compare ����� �̿��ϱ� ���� string���� ����
    float GPA;      //���� ����
};

struct Student{//�л� ����
    char StdName[30];//�л� �̸�
    int StdNum;     //�й�
    Subject Sub[3]; //����
    float AveGPA;   //������ ��� ����
    //int sample; //������ �׸� nan �� ������ ���� �ǹ̾��� ���� �ϳ� ����
};

/*����ϴ� �Լ� ����*/
int menu(); //�޴� ��� �� ��ȣ�� �Է´� �Լ�
void menu_1(struct Student*); //�޴� 1�� ���� �Լ�
void menu_2(struct Student*); //�޴� 2�� ���� �Լ�
void convert_GPA(struct Student*);//���� ��� -> ���� ��ȯ �Լ�



int main(){
  /* 2���� �л��� ������ �ޱ� ������ ũ�� 2�� Student ����ü �迭�� �����Ѵ�(Student Std[2];)
  main���� ������ while(1) �ȿ���, ����ڿ��� '3'�� �Է¹ޱ� �� ���� ����ȴ�.
  switch���� ����Ͽ� num�� 1���� ����� ���̽�, 2���� ����� ���̽��� ��������, 
  3���� �Է¹����� while���� ������ ������ ���� �Է����� �ʾҴ�.
  */
  Student Std[2];//2���� �л��� ���� ũ�Ⱑ 2�� ����ü �迭 ����
  
  Std[1].AveGPA=0.0;//����ü�� ������ �׸��� Std[1].AveGPA�� �����Ⱚ�� ����, ��� ��¹��� nan�� �߻��� �ʱ�ȭ�� ���־����� �߻����� �ʾҴ�.

while(1){
  int num=menu();//�޴� ��� �� ��� ����
  if (num==3) {cout<<"���α׷��� ����Ǿ����ϴ�"; break;}//3���� ������ while���� Ż��

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
return 0;
}




int menu(){//�޴���� �Լ�
/*�޴�����Լ��� �޴����� ����� �� ����ڿ��� �޴���뿡 ���� num�� �Է¹޾�
  �Է¹��� num�� return ���ش�.
  ����� ����� ���ڸ� �Է¹��� ��, �ٸ� ���ڸ� �Է��϶�� ����� ��� �� menu����� ������״�.
*/
  cout<<"~~~~menu~~~~"<<endl;//�޴��� ���
  cout<<"1. �л� ���� �Է�"<<endl;
  cout<<"2. ��ü �л� ���� ����"<<endl;
  cout<<"3. ���α׷� ����"<<endl<<endl;
  cout<<"���ϴ� ����� �Է��ϼ��� : ";
  int num;
  cin>>num;//��ȣ�� �Է¹޴´�
  
  if(num<=3) //����ó�� 3���� ���� ���� �Է��ϸ� �״�� �����Ѵ�.
    return num;
  else{//3���� ū ���ڸ� �Է��ϸ�
      cout<<"�ٸ� ��ȣ�� �Է����ּ���"<<endl<<endl;
      menu(); //�޴��� �ٽ� �ҷ�����
  }
}


void convert_GPA(struct Student* st){//���� GPA ��ȯ �Լ�
/* ������ ����ڿ��� �Է��� ���� �� ���ڿ��� �Է��� �ޱ� ������, ���α׷����� ����
  ���ڿ��� ���� ������ �Է����־���.
  2�� for���� �����, �� �л��� ������ȯ�� ������ �� ���� �л��� ������ȯ�� �����Ѵ�.
  �����Է��� ���� �� �빮�ڿ� �ҹ��� ������� �ޱ� ���� OR�����ڸ� ����Ͽ���.

  2��° for�� �ȿ����� �Է¹��� ������ AveGPA�� �����Ͽ� for���� Ż������ ��
  ������ ��(������ ��)���� ��ü �������� ������ GPA�� ����� �����־���.
*/

  for(int i=0;i<2;i++){

    for(int j=0;j<3;j++){//string �Լ��� ���ڿ� �� ����� compare ���
    if(st[0].Sub[j].Grade.compare("A+")==0||(st+i)->Sub[j].Grade.compare("a+")==0)
      (st+i)->Sub[j].GPA=4.5;//a+ Ȥ�� A+�� �Է��ϸ� ����ü�� GPA�� 4.5���� �Է�
    else if((st+i)->Sub[j].Grade.compare("A")==0||(st+i)->Sub[j].Grade.compare("a")==0)
      (st+i)->Sub[j].GPA=4.0;//��ҹ��� ������� ������ �ޱ����� OR������ ���
    else if((st+i)->Sub[j].Grade.compare("B+")==0||(st+i)->Sub[j].Grade.compare("b+")==0)
      (st+i)->Sub[j].GPA=3.5;
    else if((st+i)->Sub[j].Grade.compare("B")==0||(st+i)->Sub[j].Grade.compare("b")==0)
      (st+i)->Sub[j].GPA=3.0;
    else if((st+i)->Sub[j].Grade.compare("C+")==0||(st+i)->Sub[j].Grade.compare("c+")==0)
      (st+i)->Sub[j].GPA=2.5;
    else if((st+i)->Sub[j].Grade.compare("C")==0||(st+i)->Sub[j].Grade.compare("c")==0)
      (st+i)->Sub[j].GPA=2.0;
    else if((st+i)->Sub[j].Grade.compare("D+")==0||(st+i)->Sub[j].Grade.compare("d+")==0)
      (st+i)->Sub[j].GPA=1.5;
    else if((st+i)->Sub[j].Grade.compare("D")==0||(st+i)->Sub[j].Grade.compare("d")==0)
      (st+i)->Sub[j].GPA=1.0;
    else if ((st+i)->Sub[j].Grade.compare("F")==0||(st+i)->Sub[j].Grade.compare("f")==0)
      {(st+i)->Sub[j].GPA=0.0;}
    
    (st+i)->AveGPA+=((st+i)->Sub[j].GPA)*((st+i)->Sub[j].Hakjum); //���� ������ AveGPA�� �ջ��Ѵ�.(GPA�� ��)=(n�� ���� GPA����)*(n�� ���� ���� ��) * n
    }
    (st+i)->AveGPA=((st+i)->AveGPA)/(((st+i)->Sub[0].Hakjum)+((st+i)->Sub[1].Hakjum)+((st+i)->Sub[2].Hakjum));//AveGPA�� ���� (��ü������)�� ������ ����� ���Ѵ�.
  }
}




void menu_1(struct Student* st){//�л� ���� �Է� �Լ�
  /*menu 1���� ����� ����ڰ� ���� �л��� ������ ������ �Է��� �� �ְ� ���ִ� ���̴�.
    �� �л��� ������ �����Է��� ������ ���� �л��� ������ �Է��ϴ� �����̴�.
    ����ü�迭�� �ּҰ� �̿��� �Է��� �ޱ� ����, ����ü �ּҿ� �����ϴ� ǥ���� �߿��ϴ�.
    
  */

    for(int i=0;i<2;i++){//2���� �л��� �Է��ϱ� ������ 2�� �ݺ�
      cout<<i+1<<"��° �л� �̸��� �й��� �Է��ϼ���.\n"<<endl;
      cout<<"�̸� : ";
      cin>>(st+i)->StdName;//����ü �迭�� �ּҿ� �����ϴ� ǥ��, �л��� �̸��� �Է�
      cout<<"�й� : "; 
      cin>>(st+i)->StdNum;//�л��� �й��� �Է�
      cout<<"\n\n";
        
      cout<<"������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���."<<endl<<endl;
  int j=0;
        for(j=0;j<3;j++){//����[0],[1],[2]�� �޴´�.
            
            cout<<"������� : ";
            cin>>(st+i)->Sub[j].SubName;// ����� �Է�
            cout<<"���������� (���� �Է�!!) : "; //���ڸ� �Է����� ������ ���α׷��� �� �������� �ʱ� ������ ������ ���־���.
            cin>>(st+i)->Sub[j].Hakjum;// �ش� ������ ���� �� �Է�
            cout<<"������(A+ ~ F) :";
            cin>>(st+i)->Sub[j].Grade; //�ش� ������ ���� �Է�
            cout<<"\n";
        }
    }

    cout<<"\n�Է��� �Ϸ� �Ǿ����ϴ�\n"<<endl;
}


void menu_2(struct Student* st){
/*�޴� 2���� �Է¹��� �л����� ������ ������ ������ִ� ����� �Ѵ�.
  ���� �����ϰ� ����ϱ� ���� cout�� width�� fill�� ����� ĭ�� �����, ������ ä���־���.
 */

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
    cout.width(10); cout<<(st+i)->Sub[j].Hakjum; //�������� �� ���
    cout.width(10); cout<<(st+i)->Sub[j].Grade; // ������ ���
    cout.width(10); cout<<((st+i)->Sub[j].GPA)*((st+i)->Sub[j].Hakjum)<<endl; //����� ���� * ���� �� -> �������� ���
    }
  cout.width(50); cout.fill('='); cout<<'='<<endl; //���� ���
  cout.width(35); cout.fill(' '); cout<<"�������";
  cout.precision(2); cout<<fixed; cout.width(10); cout.fill(' '); cout<<(st+i)->AveGPA<<endl;//������� ���, �Ҽ��� ���� 2�ڸ��� ����ϵ��� ����.
  cout<<endl;
  cout.width(70); cout.fill('='); cout<<'='<<endl; //���� ���
  }

}

