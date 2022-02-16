#include "block.cpp"

//subclasses for each tetris shape

class shapeL : public block
{
    public:
        shapeL();
        void form(float size);
        void rotate();
};

class shapeJ : public block
{
    public:
        shapeJ();
        void form(float size);
};

class shapeI : public block
{
    public:
        shapeI();
        void form(float size);
};

class shapeT : public block
{
    public:
        shapeT();
        void form(float size);
};

class shapeS : public block
{
    public:
        shapeS();
        void form(float size);
};

class shapeZ : public block
{
    public:
        shapeZ();
        void form(float size);
};

class shapeO : public block
{
    public:
        shapeO();
        void form(float size);
};
