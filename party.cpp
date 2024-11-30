#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  // Инициализируем вектор массивов данных
  std::vector<json> partyData = {
    {
      {"Название вечеринки": "Ночь диско",
       "Желаемый возраст": "25-35",
       "Жанры": {"Диско", "80е"},
       "Активности": {"Танцы", "Караоке"},
       "Место": "Клуб"}
    },
    {
      {"Название вечеринки": "Рок-концерт",
       "Желаемый возраст": "18-30",
       "Жанры": {"Рок", "Метал"},
       "Активности": {"Концерт"},
       "Место": "Стадион"}
    }
  };

  // Редактирование темы
  std::string newName;
  int partyIndex;
  std::cout << "Введите индекс вечеринки для редактирования (от 0): ";
  std::cin >> partyIndex;
  std::cout << "Введите новое название вечеринки: ";
  std::cin.ignore(); // Очистка буфера ввода
  std::getline(std::cin, newName);
  partyData[partyIndex]["Название вечеринки"] = newName;
  std::cout << "Название вечеринки изменено.\n";

  // Добавление новых данных
  json newPartyData = {
    {"Название вечеринки": "Вечеринка в стиле 90х",
     "Желаемый возраст": "20-40",
     "Жанры": {"Рэп", "Поп"},
     "Активности": {"Танцы", "Игра в настольные игры"},
     "Место": "Бар"}
  };
  partyData.push_back(newPartyData);
  std::cout << "Новая вечеринка добавлена.\n";

  // Удаление массива данных
  int indexToDelete;
  std::cout << "Введите индекс вечеринки для удаления (от 0): ";
  std::cin >> indexToDelete;
  partyData.erase(partyData.begin() + indexToDelete);
  std::cout << "Вечеринка удалена.\n";

  // Вывод всех данных
  for (const auto& party : partyData) {
    std::cout << party.dump(4) << "\n";
  }

  return 0;
}