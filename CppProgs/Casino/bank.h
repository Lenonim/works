#pragma once
#include "classes_for_casino.h" // ��� ������������� ������ � ������ 

void money_status(Gamer& player); // �������� �������
void credit(Gamer& player); // ���������� ������� 
void debt_status(Gamer& player); // �������� ������
void data_status(Gamer& player); // �������� ���������� ������
bool collectors(Gamer& player); // ����� ����������� 
bool money_controle(const int money); // �������� ������� �� ����� ���� 