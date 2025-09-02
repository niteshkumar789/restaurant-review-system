/*  UML Diagram

    +----------------+
    |     User       |
    +----------------+
    | - id: int      |
    | - name: string |
    +----------------+

    +-----------------------+
    |      Dish             |
    +-----------------------+
    | - id: int             |
    | - name: string        |
    | - restaurant: string  |
    +-----------------------+

    +----------------------+
    |       Review         |
    +----------------------+
    | - id: int            |
    | - userId: int        |
    | - dishId: int        |
    | - rating: int        |
    | - comment: string    |
    +----------------------+

    +--------------------------+
    |      IdGenerator         |
    +--------------------------+
    | - counter: atomic<int>   |
    +--------------------------+
    | + next(): int            |
    +--------------------------+

    +---------------------------------------------------------+
    |                   ReviewSystem                          |
    +---------------------------------------------------------+
    | - userIds: IdGenerator                                  |
    | - dishIds: IdGenerator                                  |
    | - reviewIds: IdGenerator                                |
    | - users: map<int, User>                                 |
    | - dishes: map<int, Dish>                                |
    | - reviewsByDish: map<int, vector<Review>>               |
    | - likesByDish: map<int, set<int>>                       |
    +---------------------------------------------------------+
    | + addUser(name: string): int                            |
    | + addDish(name: string, restaurant: string): int        |
    | + addReview(userId, dishId, rating, comment): int       |
    | + getReviews(dishId: int): vector<Review>               |
    | + likeDish(userId, dishId)                              |
    | + unlikeDish(userId, dishId)                            |
    | + likeCount(dishId): int                                |
    | + averageRating(dishId): optional<double>               |
    | + printDishSummary(dishId)                              |
    +---------------------------------------------------------+
*/

/*  restaurant-review-system
    │
    ├─ restaurant-review/
    │   ├─ main.cpp
    │   ├─ core/           (domain objects)
    │   │   ├── User.h
    │   │   ├── Dish.h
    │   │   └── Review.h
    │   │
    │   ├─ service/        (business logic)
    │   │   └── ReviewSystem.h
    │   │
    │   └─ util/
    │        └── IdGenerator.h
    │
    ├─ README.md
    └─ LICENSE.txt
*/

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
