#pragma once
#include "lender.h" // ����������� ���������

void SortieranDaten(lander*& land , int& Kapazitat); // ����������
int HeranSortierung(lander*& land , int i, int j); // ������ ��� ����������
void ZuruckSortierung(lander*& land , int& Kapazitat); // �������� ��� ����������
void SortierungNachVeranderungen(lander*& land , int& K); // ��������� ��������-�������� ������