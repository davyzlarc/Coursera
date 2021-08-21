#include <map>

enum class TaskStatus {
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

using namespace std;
using TasksInfo = map<TaskStatus, int>;