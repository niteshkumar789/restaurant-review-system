# 🍽️ Restaurant Review System (C++)

A simple **low-level design (LLD)** implementation of a restaurant review system in C++.  
It allows users to register, add dishes, write reviews, like/unlike dishes, and view summaries with average ratings and like counts.

---

## 📂 Project Structure

restaurant-review-system/
│
├─ core/ # Domain models
│ ├── User.h
│ ├── Dish.h
│ └── Review.h
│
├─ service/ # Business logic
│ └── ReviewSystem.h
│
├─ util/ # Utility classes
│ └── IdGenerator.h
│
├─ main.cpp # Example usage
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

```bash
# Clone this repository
git clone https://github.com/your-username/restaurant-review-system.git
cd restaurant-review-system

# Compile
g++ -std=c++17 main.cpp -o review_app

# Run
./review_app
