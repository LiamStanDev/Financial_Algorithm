//
// Created by 林大中 on .
//

#include "RandomSample.h"
double normalRV(){
    // random device
    std::random_device rd;

    // random generator
    std::mt19937 generator(rd());

    // distribution
    std::normal_distribution<double> norm(0.0, 1.0);

    // random sample
    double x = norm(generator);
    return x;
}

std::vector<double> generateNormalRVs(int n){
    std::vector<double> normals;

    for (int i = 0; i < n / 2; i++){
        normals.push_back(normalRV());
    }
    for (int i = n / 2; i < n; i++){
        normals.push_back(-normals.at(i - n / 2));
    }

    return normals;
}
