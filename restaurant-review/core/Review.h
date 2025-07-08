#ifndef REVIEW_H
#define REVIEW_H

#include <string>
struct Review {
    int    id;
    int    userId;
    int    dishId;
    int    rating;
    std::string comment;
};
#endif