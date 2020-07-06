#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
    float w;
    std::cout << "¿Cuántos gramos de mermelada quieres preparar?" <<std::endl;
    std::cin >> w;
    std::vector<std::string> ingredients;

    w = w / 2;
    while(true) {
        std::string ingredient;
        float x;
        if (w > 0)
        {
            std::cout << "Introduce un nuevo ingrediente o q para terminar:" <<std::endl;
            std::cin >> ingredient;
            if (ingredient == "q") {
                break;
            }

            if (std::find(ingredients.begin(), ingredients.end(), ingredient) != ingredients.end()) {
                std::cout << "Este ingrediente ya ha sido usado, por favor, agregue uno distinto" <<std::endl;
            } else {
                std::cout << "Introduce la cantidad en g de dicho ingrediente, por completar: "
                            << w <<std::endl;
                std::cin >> x;
                w -= x;
                if (w < 0) {
                    std::cout << "El peso de los ingredientes excede el peso de la mermelada que quieres preparar" <<std::endl;
                    w += x;
                    continue;
                } 
                ingredients.push_back(ingredient);
            }
        } else
        {
            break;
        }
        
    }
    std::cout << "Tu mermelada tiene: Maracuyá";
        for (auto& ingredient : ingredients) {
            std::cout << ", " << ingredient;
        }   
    return 0;
}
