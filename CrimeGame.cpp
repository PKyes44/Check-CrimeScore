#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

int main() {
	char name[10] = { NULL }, Crimename[10] = { NULL };
	int CrimeScore = 0, CheckNEXT = 0;
	// �޸��忡 ��ϵ� �̸�
	char Tempname[255] = {NULL};
	// �޸��忡 ��ϵ� �̸��� ���� ����
	char* Temp[255] = { NULL };
	char TEST_txt[255] = { NULL };
	// ���� �� �� ��ġ
	int seek = 0;
	// ���� �� �� ��ġ
	int seek2 = 0;
	char buf[15] = { NULL }, *ptr = {NULL};
	// ����ȭ ����
	int txtScore = 0;
	// ����ȭ ����
	char Temp_txtScore[10] = { NULL };
	// ����ȭ ������ �����ͷ� ��ȯ
	char *Temp_txtScore2 = { NULL };
	
	int age = 0;
	float Height = 0;
	float Weight = 0;

	while (1) {
		printf("�̸� : ");
		scanf_s("%s", name, sizeof(name));


		printf("���� : ");
		scanf_s("%d", &age);


		printf("Ű : ");
		scanf_s("%f", &Height);
			
		printf("������ : ");
		scanf_s("%f", &Weight);

		// �˸� �Է¹ޱ� �� �˸� �´� ���� �Ҵ�
		while (1) {
			printf("�˸� : ");
			scanf_s("%s", Crimename, sizeof(Crimename));

			if (strcmp(Crimename, "����") == 0) {
				CrimeScore = 1;
				break;
			}
			else if (strcmp(Crimename, "���") == 0) {
				CrimeScore = 2;
				break;
			}
			else if (strcmp(Crimename, "����") == 0) {
				CrimeScore = 3;
				break;
			}
			else
			{
				printf("�ٽ� �Է��ϼ���\n");
			}
		}

		// ���� �Ҵ�
		FILE* fp = fopen("���˱��.txt", "r+");
		// ����ִ��� üũ
		fread(TEST_txt, sizeof(TEST_txt), 1, fp);
		// ������ �� ������ �̵�
		fseek(fp, 0, SEEK_SET);
		// ���� �ȿ� ������� ���� ���
		if (strcmp(TEST_txt, "") != 0) {
			for (int i = 0; feof(fp) == 0; i++) {
				// ������ ���� ��� ������
				if (feof(fp) == 1) {
					break;
				}

				// ���� �� �� ��ġ ���
				seek = ftell(fp);

				// �ؽ�Ʈ �б�
				memset(Tempname, NULL, sizeof(Tempname));
				fgets(Tempname, sizeof(Tempname), fp);

				// ������ ���� ��� ������
				if (strcmp(Tempname, "") == 0) {
					break;
				}

				// ���� �� �� ��ġ ���
				seek2 = ftell(fp);

				// �ؽ�Ʈ �ڸ���
				Temp[i] = strtok(Tempname, " ");
				Temp[i] = strtok(NULL, "\n");

				// ����� �̸��� ��ϵǾ� �ִ� �̸��� ���� ���
				if (strcmp(Tempname, name) == 0) {
					// �ؽ�Ʈ �ڿ� �ִ� ����(����) ����ȭ
					txtScore = atoi(Temp[i]);
					// ������ �߰�
					CrimeScore += txtScore;

					// ������ ����ȭ
					itoa(CrimeScore, Temp_txtScore, 10);

					// �� �� ù��° ���ڷ� ���ư���
					fseek(fp, seek, 0);

					// �� �� �б�
					fgets(buf, sizeof(buf), fp);

					//�������� ��ȯ
					Temp_txtScore2 = Temp_txtScore;

					// Ŀ�� ��ġ ã�� �� ������ ���� �� ����
					ptr = strstr(buf, Tempname);
					memcpy(ptr, Temp_txtScore2, sizeof(Temp_txtScore2));
						//���ڿ���			Tempname = "Tempname(�̸�) buf(����)"
					strcat(Tempname, " ");
					strcat(Tempname, buf);

					// �� ���ٷ� �̵�
					fseek(fp, seek, 0);

					// ���� ����
					fprintf(fp, Tempname);
					fflush(fp);

					break;
				}
				else {
					// �� �ѱ�
					fseek(fp, seek2, 0);
				}
			}
			// ��ϵǾ� ���� ���� �̸��̸� ���
			if (feof(fp) == 1 || strcmp(Tempname, "") == 0) {
				FILE* fp = fopen("���˱��.txt", "a");
				fprintf(fp, "%s %d\n", name, CrimeScore);
				fclose(fp);
			}
			fclose(fp);
		}

		//��������� ���
		else {
			FILE* fp = fopen("���˱��.txt", "a");
			fprintf(fp, "%s %d\n", name, CrimeScore);
			fclose(fp);
		}

		printf("\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
		printf("\n���� : %s\n���� : %d\nŰ : % .1f\n������ : % .1f\n�˸� : %s\n�������� : %d", name, age,Height,Weight,Crimename, CrimeScore);
		printf("\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

		printf("\n\n����Ͻðڽ��ϱ�? 1 / 2\n : ");

		scanf_s("%d", &CheckNEXT);
		if (CheckNEXT >= 2) {
			break;
		}
		else {
			// CMD Ŭ���� �� ������ �ʱ�ȭ
			system("cls");
			CheckNEXT = 0;
			CrimeScore = 0;
			memset(buf, NULL, sizeof(buf));
			memset(TEST_txt, NULL, sizeof(TEST_txt));
		}
	}
	return 0;
}