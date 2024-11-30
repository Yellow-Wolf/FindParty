#include <iostream>
#include <string>
#include <json/json.h>

using namespace std;

int main() {
 // Предположим, что у вас есть JSON-строка из Python:
  string json_data = "[{\"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\"}, {\"name\": \"Jane Doe\", \"age\": 25, \"city\": \"London\"}]";

  // Парсинг JSON-строки
  Json::Reader reader;
  Json::Value root;
  if (!reader.parse(json_data, root)) {
    cerr << "Ошибка парсинга JSON: " << reader.getFormattedErrorMessages() << endl;
    return 1;
  }

  // Доступ к массиву объектов
  Json::Value& arr = root;

  // Ввод данных от пользователя
  int choice;
  cout << "Выберите действие:\n";
  cout << "1. Изменить значение поля\n";
  cout << "2. Добавить новый объект\n";
  cout << "3. Удалить объект\n";
  cout << "Введите номер: ";
  cin >> choice;

  if (choice == 1) {
    int index, field;
    string new_value;
    cout << "Введите индекс объекта (начиная с 0): ";
    cin >> index;
    cout << "Введите номер поля:\n";
    cout << "1. name\n";
    cout << "2. age\n";
    cout << "3. city\n";
    cout << "Введите номер: ";
    cin >> field;
    cout << "Введите новое значение: ";
    cin >> new_value;
    
    if (index >= 0 && index < arr.size() && field >= 1 && field <= 3) {
      switch (field) {
        case 1:
          arr[index]["name"] = new_value;
          break;
        case 2:
          arr[index]["age"] = new_value; // Преобразуем строку в число, если нужно
          break;
        case 3:
          arr[index]["city"] = new_value;
          break;
      }
    } else {
      cerr << "Неверный индекс или номер поля\n";
    }
  } else if (choice == 2) {
    // Добавление нового объекта
    Json::Value new_obj;
    cout << "Введите имя: ";
    cin >> new_obj["name"];
    cout << "Введите возраст: ";
    cin >> new_obj["age"];
    cout << "Введите город: ";
    cin >> new_obj["city"];
    arr.append(new_obj);
  }  if (choice == 3) {
    // Удаление объекта
    int index;
    cout << "Введите индекс объекта (начиная с 0) для удаления: ";
    cin >> index;
    if (index >= 0 && index < arr.size()) {
      Json::Value removed; //  Создаем объект для хранения удаленного элемента
      arr.removeIndex(index, &removed); // Используем указатель &removed
      // Если нужно, можно использовать removed для каких-то действий
    } else {
      cerr << "Неверный индекс\n";
    }
  } else {
    cerr << "Неверный выбор.\n";
  }

  // Сериализация JSON обратно в строку
  Json::StyledStreamWriter writer;
  stringstream ss; // Используем stringstream для вывода
  writer.write(ss, root); // Пишем в stringstream
  string output = ss.str(); // Получаем результат в виде строки
  
  cout << output << endl;
  
  return 0;
}