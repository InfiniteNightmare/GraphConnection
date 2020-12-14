#include <iostream>
#include <queue>
#include <vector>

#define UDG 0
#define DG 1

class Graph
{
private:
    int n;                                // ������
    int density;                          // �ܶ�
    bool type;                            // ͼ�����ͣ�0:����ͼ��1:����ͼ
    bool is_connected = false;            // �Ƿ���ͨ
    bool is_strongly_connected = false;   // �Ƿ�ǿ��ͨ
    bool is_unilateral_connected = false; // �Ƿ񵥲���ͨ
    bool is_weakly_connected = false;     // �Ƿ�����ͨ
    std::vector<std::vector<bool>> graph; // �ڽӾ���
    void parseGraph();                    // �����ڽӾ����ж�ͼ����ͨ��

public:
    Graph(bool _type, int _n, int _density = 50); // ���ݲ����漴�����ڽӾ���
    Graph();                                      // Ĭ�Ϲ��캯�������ļ��ж�ȡ�ڽӾ���
    void printGraph();                            // ����ڽӾ���
    void printAttr();                             // ���ͼ����ͨ��
};