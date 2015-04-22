//Singleton pattern

//The singleton pattern enforces the creation of a 
//single object of a class. 

class singleton
{
    singleton(){} //private constructor
    singleton(singleton &);// private copy constructor
    
    ~singleton() { } // a private destructor is not necessary
                     // but is a good practice
    public:
    static singleton* x;
    static singleton * create();
    static void destroy();
};

singleton* singleton::x = nullptr;

singleton * singleton::create()
{
    if(x == nullptr)
        x = new singleton;

    return x;
}

void singleton::destroy()
{
    if(x)
        delete x;

    x == nullptr;
}

int main()
{
    singleton* mySingleton = singleton::create();

    //The following will fail
    //singleton x;
    //singleton* y = new singleton;

    return 0;
}
