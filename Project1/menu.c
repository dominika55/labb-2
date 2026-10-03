#include <stdio.h>
#include <locale.h>


#define SIZE 10
#define DAY 1
#define HOUR 8

#define ITEM_EMPTY    0
#define ITEM_WOOD     1
#define ITEM_STONE    2
#define ITEM_SEEDS    3
#define ITEM_BERRIES  4
#define ITEM_WATER    5
#define ITEM_SAND     6
#define ITEM_STICK    7
#define ITEM_COAL     8
#define ITEM_BARK     9

int main() {
    setlocale(LC_ALL, "");

    int current_day = DAY, current_hour = HOUR;

    int inventory[SIZE] = {
           ITEM_EMPTY,   ITEM_WOOD, ITEM_STONE,  ITEM_SEEDS,
           ITEM_BERRIES,  ITEM_WATER, ITEM_SAND, ITEM_STICK,
           ITEM_COAL,  ITEM_BARK };

    char names[SIZE][100] = {
        "пусто", "дерево", "камень", "семена",
        "ягоды", "вода", "песок", "палка", "уголь",
        "кора"
    };

    int menu_item;

    while (1) {

        printf("0. Выход\n");
        printf("1. Посмотреть время\n");
        printf("2. Промотать время\n");
        printf("3. Посмотреть инвентарь\n");
        printf("4. Положить предмет в слот\n");
        printf("5. Выбросить предмет\n");
        printf("6. Устранение дубликатов \n");

        if (scanf_s("%d", &menu_item) != 1) {
            printf("Ошибка: введите одно целое число.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (menu_item)
        {

        case 0:
            return 0;

        case 1:
            printf("Текущее время: День %d, %02d:00\n", current_day, current_hour);
            break;

        case 2: {
            int work_hours;

            printf("Введите кол-во часов на работу");

            if (scanf_s("%d", &work_hours) != 1) {
                printf("Ошибка: введите одно целое число.\n");
                while (getchar() != '\n');
                continue;
            }

            current_hour += work_hours;

            if (current_hour >= 24) current_day += current_hour / 24;
            current_hour %= 24;

            printf("Текущее время: День %d, %02d:00\n", current_day, current_hour);
            break;
        }

        case 3:
            for (int i = 0; i < SIZE; ++i) {
                if (i == SIZE - 1) printf("Слот %d: [%d] (%s)\n", i, inventory[i], names[inventory[i]]);
                else printf("Слот %d: [%d] (%s), ", i, inventory[i], names[inventory[i]]);
            }
            printf("\n");
            break;

        case 4: {
            int index;
            int ID;
            
            printf("Введите индекс слота (от 0 до 9) и ID предмета\n");
            
            if (scanf_s("%d %d", &index, &ID) != 2) {
                printf("Ошибка: введите два целых числа.\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (index >= 0 && index < SIZE && ID >= 0 && ID < SIZE) inventory[index] = ID;
            break;
        }

        case 5: {
            int index_slot;
            
            printf("Введите индекс слота от 0 до 9\n");
            
            if (scanf_s("%d", &index_slot) != 1) {
                printf("Ошибка: введите одно целое число.\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (index_slot >= 0 && index_slot < SIZE) inventory[index_slot] = 0;
            break;

        case 6: {
            
            for (int i = 0; i < SIZE; ++i) {
                printf("Слот %d: [%d] (%s)\n", i, inventory[i], names[inventory[i]]);
            }

            int array[SIZE] = {0};
            for (int i = 0; i < SIZE; ++i) {

                if (inventory[i] == ITEM_EMPTY) {
                    continue;
                }

                if (array[inventory[i]] == 1) {
                    inventory[i] = ITEM_EMPTY;
                }

                else {
                    array[inventory[i]] = 1;
                }
            }
            printf("\n");
            for (int i = 0; i < SIZE; ++i) {
                printf("Слот %d: [%d] (%s)\n", i, inventory[i], names[inventory[i]]);
            }
            break;
        }
            
        default:
            printf("Неизвестный пункт меню!\n");
            break;
        }
    }
}
