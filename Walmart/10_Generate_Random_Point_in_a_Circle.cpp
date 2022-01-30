// https://leetcode.com/problems/generate-random-point-in-a-circle/

class Solution
{
    double R, X, Y;

public:
    Solution(double radius, double x_center, double y_center) : R(radius), X(x_center), Y(y_center)
    {
        srand(time(0));
    }
    double random()
    {
        return (double)rand() / RAND_MAX; // for generating random points between 0 to 1
    }
    vector<double> randPoint()
    {
        vector<double> randomPoint(2);
        double len = sqrt(random()) * R, deg = 2 * M_PI * random();
        randomPoint[0] = X + len * cos(deg);
        randomPoint[1] = Y + len * sin(deg);
        return randomPoint;
    }
};