#include <map>

enum class TaskStatus {
	NEW,          // �����
	IN_PROGRESS,  // � ����������
	TESTING,      // �� ������������
	DONE          // ���������
};

using namespace std;
using TasksInfo = map<TaskStatus, int>;