#include <iostream>

using namespace std;

class Singleton
{
    private:
        static Singleton* instance;
        Singleton(){}
        int x, y, z;
        Singleton(const Singleton& obj) = delete;
    public:
        // Singleton(int x, int y, int z): x(x), y(y), z(z) {}

        static Singleton* getInstance()
        {
            
            if (instance == NULL)
            {
            instance = new Singleton();
            return instance;
            }
            else
            {
            return instance;
            }
        }

        void setValues(int x, int y, int z){
            x = x; y = y; z = z;
        }

};

Singleton* Singleton ::instance = NULL;


int main(){

    return 0;
}