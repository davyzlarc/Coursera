//Реализуйте класс TeamTasks, позволяющий хранить статистику по статусам задач команды разработчиков :

/*
// Перечислимый тип для статуса задачи
enum class TaskStatus {
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const;

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person);

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(
		const string& person, int task_count);
};
*/

//Метод PerformPersonTasks должен реализовывать следующий алгоритм :
// - Рассмотрим все невыполненные задачи разработчика person.
// - Упорядочим их по статусам : сначала все задачи в статусе NEW, затем все задачи в статусе IN_PROGRESS и, наконец,
//   задачи в статусе TESTING.
// - Рассмотрим первые task_count задач и переведём каждую из них в следующий статус в соответствии с естественным
//   порядком : NEW → IN_PROGRESS → TESTING → DONE.
// - Вернём кортеж из двух элементов : информацию о статусах обновившихся задач(включая те, которые оказались в статусе DONE)
//   и информацию о статусах остальных не выполненных задач.
// 
//В случае отсутствия разработчика с именем person метод PerformPersonTasks должен вернуть кортеж из двух пустых TasksInfo
//
//Гарантируется, что task_count является положительным числом.Если task_count превышает текущее количество невыполненных 
//задач разработчика, достаточно считать, что task_count равен количеству невыполненных задач : дважды обновлять статус 
//какой - либо задачи в этом случае не нужно.
//
//Кроме того, гарантируется, что метод GetPersonTasksInfo не будет вызван для разработчика, не имеющего задач.
//
//Пример работы метода PerformPersonTasks:
//Предположим, что у конкретного разработчика имеется 10 задач со следующими статусами :
//
//NEW — 3
//IN_PROGRESS — 2
//TESTING — 4
//DONE — 1
// 
//Поступает команда PerformPersonTasks с параметром task_count = 4, что означает обновление статуса для 3 задач
//c NEW до IN_PROGRESS и для 1 задачи с IN_PROGRESS до TESTING.
//Если выписать статусы всех задач по порядку, а обновляемые заключить в квадратные скобки, то изменение можно изобразить следующим образом :
//
//[NEW, NEW, NEW, IN_PROGRESS, ] IN_PROGRESS, TESTING, TESTING, TESTING, TESTING, DONE
//
//==>
//
//[IN_PROGRESS, IN_PROGRESS, IN_PROGRESS, TESTING, ] IN_PROGRESS, TESTING, TESTING, TESTING, TESTING, DONE
//
//Таким образом, новые статусы задач будут следующими :
//
//IN_PROGRESS — 3 обновлённых, 1 старая
//TESTING — 1 обновлённая, 4 старых
//DONE — 1 старая
// 
//В этом случае необходимо вернуть кортеж из 2 словарей :
//
//Обновлённые задачи : IN_PROGRESS — 3, TESTING — 1.
//Необновлённые задачи, исключая выполненные : IN_PROGRESS — 1, TESTING — 4.
//  
//Ни один из словарей не должен содержать лишних элементов, то есть статусов, которым соответствует ноль задач.
//
//По условию, DONE задачи не нужно возвращать в необновлённых задачах(untouched_tasks).
//
//Примечание:
//Обновление словаря одновременно с итерированием по нему может привести к непредсказуемым последствиям.
//При возникновении такой необходимости рекомендуется сначала в отдельном временном словаре собрать информацию
//об обновлениях, а затем применить их к основному словарю.
//
//Пример кода:

/*
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
	  ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
	  ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
	  ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
	tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
	  tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
	  tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
*/

//Вывод:
//Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
//Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
//Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
//Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
//Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
//Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done

//Пояснение:
//В этой задаче вам надо прислать на проверку файл с реализацией класса TeamTasks. Этот файл не должен содержать 
//определения типов TaskStatus и TasksInfo.В противном случае вы получите ошибку компиляции.
//
//Гарантируется, что типы TaskStatus и TasksInfo объявлены в точности так же, как в коде выше.

#include "struct.cpp"
#include <iostream>
#include <tuple>
#include <vector>

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const
	{
		return data.at(person);
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person)
	{
		if (data.count(person) == 0 || data.at(person).count(TaskStatus::NEW) == 0)
		{
			data[person][TaskStatus::NEW] = 0;
		}
		data.at(person).at(TaskStatus::NEW)++;
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
	{
		TasksInfo updated, untouched;
		if (data.count(person) != 0)
		{
			InitializeAllItems(person);
			TasksInfo buff = data.at(person);
			size_t vec_size = 4;
			vector <int> vec_updated(vec_size), vec_untouched;
			for (const auto& item : buff)
				vec_untouched.push_back(item.second);

			bool done = false;
			size_t index_untouched;
			for (size_t i = 0; i < vec_size - 1 && !done; i++)
			{
				int num = vec_untouched.at(i);
				vec_untouched.at(i) -= task_count;
				if (vec_untouched.at(i) < 0)
				{
					task_count = abs(vec_untouched.at(i));
					vec_untouched.at(i) = 0;
					vec_updated.at(i + 1) = num;
				}
				else
				{
					index_untouched = i;
					done = true;
					vec_updated.at(i + 1) = task_count;
				}
			}

			size_t i = 0;
			for (auto& item : buff)
			{
				item.second = vec_untouched.at(i) + vec_updated.at(i);

				if (vec_untouched.at(i) != 0 && i >= index_untouched && i != vec_size - 1)
					untouched.insert(make_pair(item.first, vec_untouched.at(i)));
				if (vec_updated.at(i) != 0)
					updated.insert(make_pair(item.first, vec_updated.at(i)));
				i++;
			}

			data.at(person) = buff;
			RemoveZeroValues(person);
		}

		return { updated, untouched };
	}

private:
	map <string, TasksInfo> data;

	TaskStatus Next(const TaskStatus& i)
	{
		return static_cast<TaskStatus>(static_cast<int>(i) + 1);
	}

	void InitializeAllItems(const string& person)
	{
		bool last = false;
		for (auto i = TaskStatus::NEW; !last; i = Next(i))
		{
			if (data.at(person).count(i) == 0)
				data.at(person).insert(make_pair(i, 0));
			if (i == TaskStatus::DONE)
				last = true;
		}
	}

	void RemoveZeroValues(const string& person)
	{
		bool last = false;
		for (auto i = TaskStatus::NEW; !last; i = Next(i))
		{
			if (data.at(person).at(i) == 0)
				data.at(person).erase(i);
			if (i == TaskStatus::DONE)
				last = true;
		}
	}
};


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

void Add(TeamTasks& tasks, const string& person, const int& num)
{
	for (int i = 0; i < num; ++i) {
		tasks.AddNewTask(person);
	}
}

void Get(TeamTasks& tasks, const string& person)
{
	cout << person << "'s tasks: ";
	const TasksInfo tass = tasks.GetPersonTasksInfo(person);
	PrintTasksInfo(tasks.GetPersonTasksInfo(person));
	cout << endl;
}

void Perform(TeamTasks& tasks, const string& person, const int& num)
{
	cout << "PerformPersonTasks " << person << " " << num << endl;

	TasksInfo updated_tasks, untouched_tasks;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks(person, num);
	cout << "Updated " << person << "'s tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched " << person << "'s tasks: ";
	PrintTasksInfo(untouched_tasks);

	cout << endl;
}

int main()
{
	TeamTasks tasks;
	//Add(tasks, "Ilia", 1);
	//Add(tasks, "Ivan", 3);
	//Get(tasks, "Ilia");
	//Get(tasks, "Ivan");
	//Perform(tasks, "Ivan", 2);
	//Perform(tasks, "Ivan", 2);

	Add(tasks, "Alice", 5);
	Perform(tasks, "Alice", 5);
	Perform(tasks, "Alice", 5);
	Perform(tasks, "Alice", 1);
	Add(tasks, "Alice", 5);
	Perform(tasks, "Alice", 2);
	Get(tasks, "Alice");
	Perform(tasks, "Alice", 4);
	Get(tasks, "Alice");
	return 0;
}