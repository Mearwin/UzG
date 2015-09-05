#ifndef NOEUD_H
#define NOEUD_H


class Noeud
{
    public:
        Noeud(int x, int y, char nature, double l, double cout_H);
        Noeud(int x, int y, char nature, double l);
        Noeud();

        Noeud* predecesseur;
        int x;
        int y;
        int nature;
        double l;
        double cout_H;
        double distance(Noeud* n);
        bool is_Noeud(Noeud n);

        virtual ~Noeud();
    protected:
    private:
};

#endif // NOEUD_H
