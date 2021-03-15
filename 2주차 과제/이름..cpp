#include <iostream>
using namespace std;

float TotalGrade(struct Student*);

	struct Subject {   // 과목 정보
		char SubName[30];   // 과목이름
		int Hakjum;   // 과목학점
		char Grade[10];   // 과목등급
		float GPA;   // 과목 평점
	};

	struct Student {   // 학생 정보
		char StdName[30];    // 학생이름
		int Hakbun;    // 학번
		Subject Sub[3];   // 과목
		float AveGPA;   // 교과목 평균 평점
	};

int main(void) {

	

     struct Student student[2];

	while (1) {

		cout << "===== 메뉴 =====\n";
		cout << "1.  학생 성적 입력\n";
		cout << "2.  전체 학생 성적 보기\n";
		cout << "3.  프로그램 종료\n\n";
		cout << "원하는 기능을 입력하세요 : ";

		int num;
		cin >> num;

		if (num == 1) {

			for (int j = 1; j < 3; j++) {
				cout << "* " << j << " 번째 학생 이름과 학번을 입력하세요.\n";
				cout << "이름 : ";

				if (j == 1) {
					cin >> student[0].StdName;
					cout << "학번 : ";
					cin >> student[0].Hakbun;
					cout << "\n\n\n\n";
					cout << "* 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
				}

				else if (j == 2) {
					cin >> student[1].StdName;
					cout << "학번 : ";
					cin >> student[1].Hakbun;
					cout << "\n\n\n\n";
					cout << "* 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
				}

				if (j == 1) {
					for (int i = 0; i < 3; i++) {
						cout << "교과목명 : ";
						cin >> student[0].Sub[i].SubName;
						cout << "과목학점수 : ";
						cin >> student[0].Sub[i].Hakjum;
						cout << "과목등급<A+ ~ F> : ";
						cin >> student[0].Sub[i].Grade;
						cout << '\n';
					}
					cout << "\n\n\n\n";
				}

				else if (j == 2) {
					for (int i = 0; i < 3; i++) {
						cout << "교과목명 : ";
						cin >> student[1].Sub[i].SubName;
						cout << "과목학점수 : ";
						cin >> student[1].Sub[i].Hakjum;
						cout << "과목등급<A+ ~ F> : ";
						cin >> student[1].Sub[i].Grade;
						cout << '\n';
					}
				}
			}
		}

		else if (num == 2) {

		TotalGrade(student);

		cout << "\n";
		cout << "            전체 학생 성적 보기\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "이름 : " << student[0].StdName << "  학번 : " << student[0].Hakbun << "\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "             과목명  과목학점  과목등급  과목평점 \n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "           " << student[0].Sub[0].SubName << "      " << student[0].Sub[0].Hakjum << "             " << student[0].Sub[0].Grade << "          " << student[0].Sub[0].GPA<<"\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "                               평균평점        "<<student[0].AveGPA<<"\n";
		cout << "이름 : " << student[1].StdName << "  학번 : " << student[1].Hakbun << "\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "             과목명  과목학점  과목등급  과목평점 \n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "           " << student[1].Sub[0].SubName << "      " << student[1].Sub[0].Hakjum << "             " << student[1].Sub[0].Grade << "          " << student[0].Sub[0].GPA << "\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "                               평균평점        " << student[1].AveGPA << "\n";
		}

		else if (num == 3) {
			cout << "\n";
			cout << "프로그램을 종료합니다.";
			break;
		}
	}
	}
	


float TotalGrade(struct Student* student) {
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {

			switch ((student+i)->Sub[j].Grade)
			{
			case "A+": student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 4.5;
				break;
			case 'a+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 4.5;
				break;
			case 'A0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 4.0;
				break;
			case 'a0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 4.0;
				break;
			case 'B+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 3.5;
				break;
			case 'b+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 3.5;
				break;
			case 'B0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 3.0;
				break;
			case 'b0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 3.0;
				break;
			case 'C+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 2.5;
				break;
			case 'c+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 2.5;
				break;
			case 'C0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 2.0;
				break;
			case 'c0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 2.0;
				break;
			case 'D+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 1.5;
				break;
			case 'd+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 1.5;
				break;
			case 'D0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 1.0;
				break;
			case 'd0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 1.0;
				break;
			case 'F': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 0.0;
				break;
			case 'f': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 0.0;
				break;
			}
		}
	}
	student[0].AveGPA = (student[0].Sub[0].GPA + student[0].Sub[1].GPA + student[0].Sub[2].GPA) / (student[0].Sub[0].Hakjum + student[0].Sub[1].Hakjum + student[0].Sub[2].Hakjum);
	student[1].AveGPA = (student[1].Sub[0].GPA + student[1].Sub[1].GPA + student[1].Sub[2].GPA) / (student[1].Sub[0].Hakjum + student[1].Sub[1].Hakjum + student[1].Sub[2].Hakjum);
}