/****************************************************************************************
 * Name: Gavriel Schneider
 *
 * This program receives coordinates from the user and then calculates the radius, area
 * and circumference for two circles: one outside of the rectangle, and one inside.
 * (The rectangle is discovered via the coordinates
 ***************************************************************************************/

#include <iostream>
#include <cmath>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	double x1, y1, x2, y2, x, y, perimeter1, perimeter2, radius1, radius2 ;
    double area1, area2, pi = 3.1415 ;

    cin >> x1 >> y1 >> x2 >> y2 ;

    // Small circle
    radius1 = (y1 - y2) /2 ;
    area1 = pi * (radius1 * radius1) ;
    perimeter1 = 2 * pi * radius1 ;

    // Big circle
    x = x1 - x2 ;
    y = y1 - y2 ;
    radius2 = (sqrt((x * x) + (y * y))) /2 ;
    area2 = pi * (radius2 * radius2) ;
    perimeter2 = 2 * pi * radius2 ;

    cout << radius1 << " " << area1 << " " << perimeter1 << endl ;
    cout << radius2 << " " << area2 << " " << perimeter2 << endl ;

    return 0 ;
}

