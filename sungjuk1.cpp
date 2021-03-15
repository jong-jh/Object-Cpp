/**************************************************/
/*             HW#1 : C++ 시작하기                                                   */
/*  작성자 : 정종현                                날짜 : 2021년 3월 10일  */
/*                                                                                                     */
/* 문제 정의 :                                                                                 */
/*                - - - - - - -                                                                      */
/*************************************************/
#include<iostream>
#include<string>
using namespace std;//

struct Subject{// 과목 정보
    char SubName[30];//과목이름
    int Hakjum;     //과목 학점수
    char Grade[10]; //과목 등급
    float GPA;      //과목 평점
};

struct Student{//학생 정보
    char StdName[30];//학생 이름
    int StdNum;     //학번
    Subject Sub[3]; //과목
    float AveGPA;   //교과목 평균 평점
};

int menu(); //메뉴 출력 함수

void menu_1(struct Student*); //메뉴 1번 실행 함수
void menu_2(struct Student*); //메뉴 2번 실행 함수
void convert_GPA(struct Student*);//과목 등급 -> 평점 변환 함수


int main(){//main 함수
    Student Std[2];//2명의 학생을 받을 크기가 2인 구조체 배열 선언

while(1){
int num=menu();//메뉴 출력 및 기능 선택
if (num==3) {break;}//3번을 누르면 while루프 탈출

switch(num){
  case 1:
    cout<<"\n1번이 선택되었습니다."<<endl<<endl;
    menu_1(Std);//구조체 배열을 함수에 전달
    break;
  case 2:
    cout<<"\n2번이 선택되었습니다.\n\n";
    convert_GPA(Std); //학점 변환 함수 실행
    menu_2(Std); //메뉴 2 실행
    break;
  }
}


}




int menu(){//메뉴출력 함수
  cout<<"~~~~menu~~~~"<<endl;
  cout<<"1. 학생 성적 입력"<<endl;
  cout<<"2. 전체 학생 성적 보기"<<endl;
  cout<<"3. 프로그램 종료"<<endl<<endl;
  cout<<"원하는 기능을 입력하세요 : ";
  int num;
  cin>>num;//번호를 입력받는다
  
  if(num<=3) //예외처리
    return num;
  else{//3보다 큰 숫자를 입력하면
      cout<<"다른 번호를 입력해주세요"<<endl<<endl;
      menu(); //메뉴를 다시 불러오기
  }
}

void convert_GPA(struct Student* st){//학점 GPA 변환 함수
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
    
    (st+i)->AveGPA+=((st+i)->Sub[j].GPA)*((st+i)->Sub[j].Hakjum); //과목별 평점을 AveGPA에 합산한다.
    }
    (st+i)->AveGPA=((st+i)->AveGPA)/(((st+i)->Sub[0].Hakjum)+((st+i)->Sub[1].Hakjum)+((st+i)->Sub[2].Hakjum));//AveGPA의 값을 전체학점수로 나누어 평균을 구한다.
  }
}

void menu_1(struct Student* st){//학생 성접 입력 함수
    for(int i=0;i<2;i++){//2명의 학생을 입력하기 때문에 2번 반복
      cout<<i+1<<"번째 학생 이름과 학번을 입력하세요.\n"<<endl;
      cout<<"이름 : ";
      cin>>(st+i)->StdName;//구조체 배열의 레퍼런스 표현
      cout<<"학번 : "; 
      cin>>(st+i)->StdNum;
      cout<<"\n\n";
        
      cout<<"수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요."<<endl<<endl;
  int j=0;
        for(j=0;j<3;j++){//성적[0],[1],[2]에 받는다.
            
            cout<<"교과목명 : ";
            cin>>(st+i)->Sub[j].SubName;
            cout<<"과목학점수 (숫자 입력!!) : ";
            cin>>(st+i)->Sub[j].Hakjum;
            cout<<"과목등급(A+ ~ F) :";
            cin>>(st+i)->Sub[j].Grade;
            cout<<"\n";
        }
    }

    cout<<"\n입력이 완료 되었습니다\n"<<endl;
}

void menu_2(struct Student* st){
cout.width(30); cout.fill(' ');
cout<<"전체 학생 성적 보기"<<endl;//2번 메뉴 기능 설명
cout.width(70); cout.fill('='); cout<<'='; //밑줄 출력
cout<<endl;

for(int i=0;i<2;i++){
  cout<<"이름 : "<<(st+i)->StdName<<"  학번 : "<<(st+i)->StdNum<<endl;
  cout.width(50); cout.fill('='); cout<<'='<<endl; //밑줄 출력 공간 50, 공백 = 출력
  cout.width(20); cout.fill(' '); cout<<"과목명 "; //공백 빈칸 출력
  cout.width(10); cout<<"과목학점 ";
  cout.width(10); cout<<"과목등급 ";
  cout.width(10); cout<<"과목평점 "<<endl;
  cout.width(50); cout.fill('='); cout<<'='<<endl; //밑줄 출력
  for(int j=0;j<3;j++){
    cout.width(20); cout.fill(' '); cout<<(st+i)->Sub[j].SubName; //과목 출력
    cout.width(10); cout<<(st+i)->Sub[j].Hakjum;
    cout.width(10); cout<<(st+i)->Sub[j].Grade;
    cout.width(10); cout<<((st+i)->Sub[j].GPA)*((st+i)->Sub[j].Hakjum)<<endl;
    }
  cout.width(50); cout.fill('='); cout<<'='<<endl; //밑줄 출력
  cout.width(35); cout.fill(' '); cout<<"평균평점";
  cout.width(10); cout.fill(' '); cout<<(st+i)->AveGPA<<endl;//평균평점 출력
  }

}

