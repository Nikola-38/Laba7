#include <iostream>
#include <vector>


using namespace std;

// Рекурсивная функция для раскраски графа в минимальное количество цветов
bool graphColoringRecursive(vector<vector<int>>& adjMatrix, vector<int>& colors, int i, int n, int maxColor) {
    // Если все узлы раскрашены, значит раскраска завершена
    if (i == n) {
        return true;
    }

    // Перебираем возможные цвета для текущего 
    for (int color = 1; color <= maxColor; color++) {
        // Проверяем, что текущий цвет не используется соседними 
        bool isColorAvailable = true;
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1 && colors[j] == color) {
                isColorAvailable = false;
                break;
            }
        }

        // Если цвет доступен, назначаем его текущему и рекурсивно переходим к следующему
        if (isColorAvailable) {
            colors[i] = color;
            if (graphColoringRecursive(adjMatrix, colors, i + 1, n, maxColor)) {
                return true;
            }
            // Если не удалось раскрасить граф, возвращаем текущему узлу значение 0
            colors[i] = 0;
        }
    }
    
    // Если ни один из цветов не подошел, возвращаем false
    return false;
}


// Функция для раскраски графа в минимальное количество цветов
int graphColoring(vector<vector<int>>& adjMatrix, int n) {
    // Создаем вектор для хранения цветов стран
    vector<int> colors(n, 0);

    // Рекурсивно раскрашиваем граф, начиная с максимально возможного количества цветов
    for (int maxColor = 1; ; maxColor++) {
        if (graphColoringRecursive(adjMatrix, colors, 0, n, maxColor)) {
            return maxColor;
        }
    }
}

int main() {
    system("chcp 65001");

    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int numCountries = adjacencyMatrix.size();

    // Вызываем функцию раскраски графа
    int minColors = graphColoring(adjacencyMatrix, numCountries);

    cout << "Минимальное количество цветов для раскраски карты: " << minColors << endl;

    return 0;
}
