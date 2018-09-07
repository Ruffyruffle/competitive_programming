// ECOO Question 4

#include <fstream>
#include <algorithm>
#include <map>

struct Rectangle
{
    int x;
    int y;
    int width;
    int height;
};

std::map<int, int> fib_sequence;

int fib(int n)
{
    if(fib_sequence.find(n) != fib_sequence.end())
    {
        return fib_sequence[n];
    }

    if(n <= 2)
    {
        return 1;
    }

    int new_fib = fib(n - 1) + fib(n - 2);
    fib_sequence[n] = new_fib;
    return new_fib;
}

bool inside_rect(Rectangle rect, int x, int y)
{
    return (x >= rect.x && x <= (rect.x + rect.width) && y >= rect.y && y <= (rect.y + rect.height));
}

Rectangle build_rect(Rectangle rect, int add_fib, int direction)
{
    if(direction == 0)
    {
        return {rect.x - add_fib, rect.y, rect.width + add_fib, rect.height};
    }

    if(direction == 1)
    {
        return {rect.x, rect.y, rect.width, rect.height + add_fib};
    }

    if(direction == 2)
    {
        return {rect.x, rect.y, rect.width + add_fib, rect.height};
    }

    return {rect.x, rect.y - add_fib, rect.width, rect.height + add_fib};
}

void execute(int px, int py)
{
    int direction = -1;
    Rectangle bounding_box = {0, -1, 1, 1};
    int n = 1;

    bool inside = false;
    while(!inside)
    {
        if(!inside_rect(bounding_box, px, py))
        {
            direction = (direction + 1) % 4;
            n += 1;
            bounding_box = build_rect(bounding_box, fib(n), direction);
        }
        else
        {
            inside = true;
        }
    }

    std::cout << n << "\n";
}

int main(int argc, char** argv)
{
    std::ifstream input_file("DATA41.txt");
    if(!input_file)
    {
        // We couldn't read the file.
        exit(1);
    }

    int x, y;
    while(input_file >> x >> y)
    {
        execute(x, y);
    }
}
