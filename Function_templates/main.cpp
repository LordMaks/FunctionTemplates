#include <iostream>
#include <new>
using namespace std;

template <typename K>

class Queue
{
private:

    K* p;
    int count;

public:

    Queue()
    {
        count = 0;
    }


    Queue(const Queue& obj)
    {

        count = obj.count;

        try 
        {

            p = new K[count];

            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        }
        catch (bad_alloc e)
        {

            cout << e.what() << endl;
            count = 0;
        }
    }

    void push(K item)
    {
        K* p2;
        p2 = p;

        try 
        {
            p = new K[count + 1];

            for (int i = 0; i < count; i++)
                p[i] = p2[i];


            p[count] = item;

            count++;


            if (count > 1)
                delete[] p2;
        }
        catch (bad_alloc e)
        {

            cout << e.what() << endl;


            p = p2;
        }
    }


    K pop()
    {
        if (count == 0)
            return 0;


        K item;

        item = p[0];


        try 
        {
            K* p2;


            p2 = new K[count - 1];

            count--;

            for (int i = 0; i < count; i++)
                p2[i] = p[i + 1];

            if (count > 0)
                delete[] p;

            p = p2;

            return item;
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }

    Queue& operator=(const Queue& obj)
    {
        K* p2;

        try 
        {
            p2 = new K[obj.count];

            if (count > 0)
                delete[] p;

            p = p2;
            count = obj.count;

            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
        }
        return *this;
    }

    ~Queue()
    {
        if (count > 0)
            delete[] p;
    }

    K GetItem()
    {
        if (count > 0)
            return p[0];
        else
            return 0;
    }

    void clear()
    {
        if (count > 0)
        {
            delete[] p;
            count = 0;
        }
    }

    bool IsEmpty()
    {
        return count == 0;
    }


    int GetN()
    {
        return count;
    }

    void print(const char* objName)
    {
        cout << "Object: " << objName << endl;
        for (int i = 0; i < count; i++)
            cout << p[i] << "\t";
        cout << endl;
        cout << "---------------------" << endl;
    }
};

int main() {
    Queue<int> Q1;
    Q1.print("Q1");

    Q1.push(4);
    Q1.print("Q1");

    Q1.push(-2);
    Q1.push(10);
    Q1.push(34);
    Q1.print("Q1");

    int d;
    d = Q1.GetItem();
    cout << "d = " << d << endl;

    Q1.print("Q1");

    Queue<int> Q2 = Q1;
    Q2.print("Q2");

    Queue<int> Q3;
    Q3 = Q1 = Q2;
    Q1.push(244);
    Q2.push(777);

    Q1.print("Q1");
    Q2.print("Q2");
    Q3.print("Q3");

    Q2.clear();
    if (Q2.IsEmpty())
        cout << "OK" << endl;
    else
        cout << "NO" << endl;

    cout << "n = " << Q3.GetN() << endl;
}
