#include "cuhre/Integration.hpp"
#include "cuhre/Region.hpp"
#include "GenzMalik/GM2D.hpp"
#include "GenzMalik/Cube.hpp"
#include <iostream>
#include <array>
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iomanip>

int main(){
    
    double exponent = 3; // A parameter used in the integrand. 

    
    std::array<double, 4> region_info{0.0, 5.0, 2.0, 10.0};
    std::array<double, 2> center{(region_info.at(0)+region_info.at(1))/2.0, (region_info.at(2)+region_info.at(3))/2.0};
    std::array<double, 2> width{region_info.at(1)-region_info.at(0), region_info.at(3)-region_info.at(2)};
    Region<2> cur_region(center, width); // Using two N dimension vectors, where the first for the center and the second for the width of the integration region.

    auto foo = [&](const std::array<double, 2>& input){
        double ret_val = std::exp( - input.at(0) * std::pow( input.at(1), exponent));
        return ret_val;
    };
    double estimated_error {0.0};
    int num_func_eval{0};
    auto parallel = IntegrationStrategy::parallel; // 

    auto integral = Integration<2>::integrate(foo, cur_region, estimated_error, num_func_eval, parallel, 1e-6, 500, 100000);
    std::cout << std::setprecision(15)<< "The numerical integral using Cuhre method is " << integral << ", with an estimated error " << estimated_error << " after " << num_func_eval << " function calls\n";

    CUBE::Cube<double, 2> cube2 = CUBE::make_cube_2D<double>(0.0, 5.0, 2.0, 10.0); // GenzMalik Rule now supports 2D and 3D integration.
    auto foo_GM = [&](const double& x, const double& y){
        double ret_val = std::exp( - x * std::pow( y, exponent));
        return ret_val; 
    };
    unsigned int num_func_eval2{0};
    auto integral_2 =  GM::GM2D<double>::integrate(foo_GM, cube2, 1e-6, estimated_error, 20000,  num_func_eval2); 
    std::cout << std::setprecision(15)<< "The numerical integral using Genz Malik method is " << integral_2 << ", with an estimated error " << estimated_error << " after " << num_func_eval2 << " function calls\n";
    return 0;
}
