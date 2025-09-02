# 🍽️ Restaurant Review System (C++)

A simple `low-level design (LLD)` implementation of a restaurant review system in C++.  
It allows users to `register`, `add dishes`, `write reviews`, like/unlike dishes, and `view summaries` with `average ratings` and `like counts`.

---

## 📂 Project Structure

    restaurant-review-system
    │
    ├─ restaurant-review/
    │   ├─ main.cpp (Example usage)
    │   ├─ core/           (domain models)
    │   │   ├── User.h
    │   │   ├── Dish.h
    │   │   └── Review.h
    │   │
    │   ├─ service/        (business logic)
    │   │   └── ReviewSystem.h
    │   │
    │   └─ util/ (Utility classes)
    │        └── IdGenerator.h
    │
    ├─ README.md
    └─ LICENSE.txt

---

## ✨ Features

- **User Management**: Add users with unique IDs.  
- **Dish Management**: Add dishes with unique IDs.  
- **Review System**: Users can add reviews (rating + comment) for dishes.  
- **Likes System**: Users can like/unlike dishes.  
- **Analytics**:  
  - View number of likes for each dish.  
  - Compute average rating of a dish.  
- **Summary Printing**: Print dish details, likes, and ratings.  

---

## 🛠️ Installation & Compilation
Make sure you have **g++** (C++17 or later) installed.    

- Clone this repository: `git clone https://github.com/your-username/restaurant-review-system.git`
- Directory: `cd restaurant-review-system`
- Compile: `g++ -std=c++17 main.cpp -o review_app`
- Run: `./review_app`

---

## ▶️ Example Output

    Dish: Margherita Pizza @ Luigi's
    Likes: 2
    Avg rating: 4.5

    Dish: Dragon Roll @ Sakura
    Likes: 1
    Avg rating: 4

---

## 🧩 UML Class Diagram

    +----------------+        +-----------------------+        +----------------------+
    |     User       |        |        Dish           |        |       Review         |
    +----------------+        +-----------------------+        +----------------------+
    | - id: int      |        | - id: int             |        | - id: int            |
    | - name: string |        | - name: string        |        | - userId: int        |
    +----------------+        | - restaurant: string  |        | - dishId: int        |
                              +-----------------------+        | - rating: int        |
                                                               | - comment: string    |
                                                               +----------------------+

    +--------------------------+        +-----------------------------------------------------+
    |      IdGenerator         |        |                   ReviewSystem                      |
    +--------------------------+        +-----------------------------------------------------+
    | - counter: atomic<int>   |        | - userIds: IdGenerator                              |
    | + next(): int            |        | - dishIds: IdGenerator                              |
    +--------------------------+        | - reviewIds: IdGenerator                            |
                                        | - users: map<int, User>                             |
                                        | - dishes: map<int, Dish>                            |
                                        | - reviewsByDish: map<int, vector<Review>>           |
                                        | - likesByDish: map<int, set<int>>                   |
                                        +-----------------------------------------------------+
                                        | + addUser(name: string): int                        |
                                        | + addDish(name: string, restaurant: string): int    |
                                        | + addReview(userId, dishId, rating, comment): int   |
                                        | + getReviews(dishId: int): vector<Review>           |
                                        | + likeDish(userId, dishId)                          |
                                        | + unlikeDish(userId, dishId)                        |
                                        | + likeCount(dishId): int                            |
                                        | + averageRating(dishId): double                     |
                                        | + printDishSummary(dishId)                          |
                                        +-----------------------------------------------------+

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to open a PR or raise an issue.

---

## 📜 License

This project is `licensed` under the `MIT License`.

---

## ✨ Author
`Nitesh Kumar` 3rd Year B.Tech (CSE)
