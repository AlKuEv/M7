#ifndef INTARRAY_H
#define INTARRAY_H



class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length) :
        m_length{ length }
    {
        if (length <= 0)
        {
            throw"bad_length";
        }
        if (length > 0)
            m_data = new int[length] {};
    }

    IntArray(const IntArray& a)
    {
        reallocate(a.getLength());
        for (int index{ 0 }; index < m_length; ++index)
            m_data[index] = a.m_data[index];
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        if (index >= 0 && index < m_length)
        {
            return m_data[index];
        }
    }

    void reallocate(int newLength)
    {
        erase();

        if (newLength <= 0)
            return;

        m_data = new int[newLength];
        m_length = newLength;
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            throw"недопустимое значение для контейнера\n";
            erase();
            return;
        }


        int* data{ new int[newLength] };

        if (m_length > 0)
        {

            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
            if (newLength > m_length)
            {
                for (int CH = m_length; CH < newLength; ++CH)
                    data[CH] = CH + 1;
            }
            for (int index{ 0 }; index < elementsToCopy; ++index)
                data[index] = m_data[index];
           
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;

    }

    IntArray& operator=(const IntArray& a)
    {
        if (&a == this)
            return *this;

        reallocate(a.getLength());

        for (int index{ 0 }; index < m_length; ++index)
            m_data[index] = a.m_data[index];

        return *this;
    }

    void insertBefore(int index)
    {
        int sizedata = _msize(m_data) / sizeof(int);
        if (index > 0 || index > sizedata)
        {
            throw"такой ячейки нет\n";
        }
        int value;
        std::cout << "Введите новое число\n";
            std::cin >> value;
        m_data[index] = value;
    }

    void remove(int index)
    {
        int sizedata = _msize(m_data) / sizeof(int);
        if (index<0 || index>(sizedata)-1)
        {
            throw"такой ячейки нет\n";
        }

        if (m_length == 1)
        {
            erase();
            return;
        }

        int* data{ new int[m_length - 1] };

        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];

        for (int after{ index + 1 }; after < m_length; ++after)
            data[after - 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        --m_length;
    }
    int getLength() const { return m_length; }
    int insertAtBeginning(int value)
    {
        m_data[0] = value;
        return 0;
    }
    int insertAtEnd(int value)
    {
        int index = (_msize(m_data) / sizeof(int)) - 1;
        m_data[index] = value;
        return 0;
    }
    int getSize()
    {
        int sizedata = _msize(m_data) / sizeof(int);
        std::cout << "Размер контейнера: " << sizedata << "\n";
        return 0;
    }
};

#endif