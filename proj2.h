#ifndef __PROJ2_H__
#define __PROJ2_H__

class piece {
    public:
        piece(int a, int b, int p) {
            this->a = a;
            this->b = b;
            this->p = p;
        }
        int getA() { return this->a; }
        int getB() { return this->b; }
        int getP() { return this->p; }
        void setP(int p) { this->p = p; }
    private:
        int a;
        int b;
        int p;
};

#endif