#include "service/ReviewSystem.h"

int main() {
    ReviewSystem sys;

    int alice = sys.addUser("Alice");
    int bob   = sys.addUser("Bob");

    int pizza = sys.addDish("Margherita Pizza", "Luigi's");
    int sushi = sys.addDish("Dragon Roll",      "Sakura");

    sys.addReview(alice, pizza, 5, "Best pizza in town!");
    sys.addReview(bob,   pizza, 4, "Crust could be crispier.");
    sys.addReview(alice, sushi, 3, "Too much sauce.");
    sys.addReview(bob,   sushi, 5, "Loved it!");

    sys.likeDish(alice, pizza);
    sys.likeDish(bob,   pizza);
    sys.likeDish(alice, sushi);

    sys.printDishSummary(pizza);
    sys.printDishSummary(sushi);

    return 0;
}


// g++ -std=c++17 main.cpp -o review_app
// ./review_app
