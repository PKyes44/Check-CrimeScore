#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

int main() {
	char name[10] = { NULL }, Crimename[10] = { NULL };
	int CrimeScore = 0, CheckNEXT = 0;
	// 메모장에 기록된 이름
	char Tempname[255] = {NULL};
	// 메모장에 기록된 이름에 대한 점수
	char* Temp[255] = { NULL };
	char TEST_txt[255] = { NULL };
	// 줄의 맨 앞 위치
	int seek = 0;
	// 줄의 맨 뒤 위치
	int seek2 = 0;
	char buf[15] = { NULL }, *ptr = {NULL};
	// 정수화 점수
	int txtScore = 0;
	// 문자화 점수
	char Temp_txtScore[10] = { NULL };
	// 문자화 점수를 포인터로 변환
	char *Temp_txtScore2 = { NULL };
	
	int age = 0;
	float Height = 0;
	float Weight = 0;

	while (1) {
		printf("이름 : ");
		scanf_s("%s", name, sizeof(name));


		printf("나이 : ");
		scanf_s("%d", &age);


		printf("키 : ");
		scanf_s("%f", &Height);
			
		printf("몸무게 : ");
		scanf_s("%f", &Weight);

		// 죄명 입력받기 후 죄명에 맞는 점수 할당
		while (1) {
			printf("죄명 : ");
			scanf_s("%s", Crimename, sizeof(Crimename));

			if (strcmp(Crimename, "절도") == 0) {
				CrimeScore = 1;
				break;
			}
			else if (strcmp(Crimename, "사기") == 0) {
				CrimeScore = 2;
				break;
			}
			else if (strcmp(Crimename, "살인") == 0) {
				CrimeScore = 3;
				break;
			}
			else
			{
				printf("다시 입력하세요\n");
			}
		}

		// 파일 할당
		FILE* fp = fopen("범죄기록.txt", "r+");
		// 비어있는지 체크
		fread(TEST_txt, sizeof(TEST_txt), 1, fp);
		// 포인터 맨 앞으로 이동
		fseek(fp, 0, SEEK_SET);
		// 파일 안에 비어있지 않을 경우
		if (strcmp(TEST_txt, "") != 0) {
			for (int i = 0; feof(fp) == 0; i++) {
				// 파일의 끝일 경우 나가기
				if (feof(fp) == 1) {
					break;
				}

				// 줄의 맨 앞 위치 기록
				seek = ftell(fp);

				// 텍스트 읽기
				memset(Tempname, NULL, sizeof(Tempname));
				fgets(Tempname, sizeof(Tempname), fp);

				// 파일의 끝일 경우 나가기
				if (strcmp(Tempname, "") == 0) {
					break;
				}

				// 줄의 맨 뒤 위치 기록
				seek2 = ftell(fp);

				// 텍스트 자르기
				Temp[i] = strtok(Tempname, " ");
				Temp[i] = strtok(NULL, "\n");

				// 사용자 이름과 기록되어 있는 이름이 같을 경우
				if (strcmp(Tempname, name) == 0) {
					// 텍스트 뒤에 있던 문자(점수) 정수화
					txtScore = atoi(Temp[i]);
					// 점수에 추가
					CrimeScore += txtScore;

					// 점수를 문자화
					itoa(CrimeScore, Temp_txtScore, 10);

					// 그 줄 첫번째 글자로 돌아가기
					fseek(fp, seek, 0);

					// 그 줄 읽기
					fgets(buf, sizeof(buf), fp);

					//변수형식 변환
					Temp_txtScore2 = Temp_txtScore;

					// 커서 위치 찾은 후 변수에 수정 및 저장
					ptr = strstr(buf, Tempname);
					memcpy(ptr, Temp_txtScore2, sizeof(Temp_txtScore2));
						//문자연결			Tempname = "Tempname(이름) buf(점수)"
					strcat(Tempname, " ");
					strcat(Tempname, buf);

					// 맨 앞줄로 이동
					fseek(fp, seek, 0);

					// 파일 수정
					fprintf(fp, Tempname);
					fflush(fp);

					break;
				}
				else {
					// 줄 넘김
					fseek(fp, seek2, 0);
				}
			}
			// 기록되어 있지 않은 이름이면 기록
			if (feof(fp) == 1 || strcmp(Tempname, "") == 0) {
				FILE* fp = fopen("범죄기록.txt", "a");
				fprintf(fp, "%s %d\n", name, CrimeScore);
				fclose(fp);
			}
			fclose(fp);
		}

		//비어있으면 기록
		else {
			FILE* fp = fopen("범죄기록.txt", "a");
			fprintf(fp, "%s %d\n", name, CrimeScore);
			fclose(fp);
		}

		printf("\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
		printf("\n성명 : %s\n나이 : %d\n키 : % .1f\n몸무게 : % .1f\n죄목 : %s\n범죄점수 : %d", name, age,Height,Weight,Crimename, CrimeScore);
		printf("\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

		printf("\n\n계속하시겠습니까? 1 / 2\n : ");

		scanf_s("%d", &CheckNEXT);
		if (CheckNEXT >= 2) {
			break;
		}
		else {
			// CMD 클리어 후 변수들 초기화
			system("cls");
			CheckNEXT = 0;
			CrimeScore = 0;
			memset(buf, NULL, sizeof(buf));
			memset(TEST_txt, NULL, sizeof(TEST_txt));
		}
	}
	return 0;
}