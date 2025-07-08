#ifndef REVIEW_SYSTEM_H
#define REVIEW_SYSTEM_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>

#include "../core/User.h"
#include "../core/Dish.h"
#include "../core/Review.h"
#include "../util/IdGenerator.h"

class ReviewSystem {
    IdGenerator userIds, dishIds, reviewIds;

    std::unordered_map<int, User> users;
    std::unordered_map<int, Dish> dishes;
    std::unordered_map<int, std::vector<Review>> reviewsByDish;
    std::unordered_map<int, std::unordered_set<int>> likesByDish;

public:
    int addUser(const std::string& name) {
        int id = userIds.next();
        users[id] = {id, name};
        return id;
    }

    int addDish(const std::string& name, const std::string& restaurant) {
        int id = dishIds.next();
        dishes[id] = {id, name, restaurant};
        return id;
    }

    int addReview(int userId, int dishId, int rating, const std::string& comment) {
        if (!validUser(userId) || !validDish(dishId) || rating < 1 || rating > 5)
            throw std::invalid_argument("Bad review data");

        int id = reviewIds.next();
        reviewsByDish[dishId].push_back({id, userId, dishId, rating, comment});
        return id;
    }

    std::vector<Review> getReviews(int dishId) const {
        if (!validDish(dishId)) return {};
        auto it = reviewsByDish.find(dishId);
        return it == reviewsByDish.end() ? std::vector<Review>{} : it->second;
    }

    void likeDish(int userId, int dishId) {
        if (!validUser(userId) || !validDish(dishId)) return;
        likesByDish[dishId].insert(userId);
    }

    void unlikeDish(int userId, int dishId) {
        if (!validUser(userId) || !validDish(dishId)) return;
        likesByDish[dishId].erase(userId);
    }

    int likeCount(int dishId) const {
        auto it = likesByDish.find(dishId);
        return it == likesByDish.end() ? 0 : static_cast<int>(it->second.size());
    }

    double averageRating(int dishId) const {
        auto rev = getReviews(dishId);
        if (rev.empty()) return -1.0;
        int sum = std::accumulate(rev.begin(), rev.end(), 0,
                                  [](int acc, const Review& r){ return acc + r.rating; });
        return static_cast<double>(sum) / rev.size();
    }

    void printDishSummary(int dishId) const {
        if (!validDish(dishId)) { std::cout << "Dish not found\n"; return; }
        const Dish& d = dishes.at(dishId);
        std::cout << "Dish: " << d.name << " @ " << d.restaurant << '\n';
        std::cout << "Likes: " << likeCount(dishId) << '\n';
        double avg = averageRating(dishId);
        std::cout << "Avg rating: " << (avg >= 0 ? std::to_string(avg) : "N/A") << "\n\n";
    }

private:
    bool validUser(int id) const { return users.count(id); }
    bool validDish(int id) const { return dishes.count(id); }
};
#endif