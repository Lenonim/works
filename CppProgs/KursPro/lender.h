#pragma once

struct lander // ��������� ������ � ������ 
{
	unsigned int index; // ������ ��� ��������� ������ � �������� ������ � �������� (4 �������)
	char Name[26]; // �������� ������
	char HauptStadt[26]; // �������� �������
	unsigned int Nas; // ����������� ���������
	unsigned int Terr; // ������� ������
	char VAL[4]; // ��� ������ ������
	unsigned int Nas_pro_Terr; // �������������� ���� - ��������� ���������
};