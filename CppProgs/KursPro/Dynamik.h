#pragma once
#include "lender.h" // ����������� ���������

void AddierenDaten(lander*& land, int& Kapazitat); // ���������� �������
void SubstragierenDaten(lander*& land, int& Kapazitat); // �������� ������� 
void UmSreibenData(lander*& land, int& Kapazitat); // �������������� ������� 
void LesenDaten(lander*& land, int& Kapazitat); // ��������� �������� ������
void SpeichernDatenInTextFile(lander*& land, int& Kapazitat); // ��� ���������� ������ � ��������� ����
void VeranderungZahlDaten(lander*& land, int& Kapazitat, int delta); // ��� ��������� ����������� ������������� �������
void SpeichernDatenInBinFile(lander*& land, int& Kapazitat); // ��� ���������� ������ � �������� ����