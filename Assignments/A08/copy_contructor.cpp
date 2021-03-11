#include <iostream>
#include <vector>

using namespace std;

/**
 * This is an implementation of our multi color colorpalette class. 
 * 
 * The Addition of vector has been made to be able to store each instance
 * of a color into. The set size for the palette is 10 just for simplicity
 * but that can be changed
 */
class ColorPalette{
    int r;              //int 0-255 red
    int g;              //int 0-255 green
    int b;              //int 0-255 blue
    int size;          // colorpalette will hold 10 colors
    
public: 
    vector<ColorPalette>palette;         // vector to hold colors

    ColorPalette();             // default constructor
    ColorPalette(int);          // overloaded 1
    ColorPalette(int,int,int);  // overloaded 2
    ColorPalette(const ColorPalette&); // copy constructor
    ~ColorPalette();            // destructor

    void SetR(int);         // setter red
    void SetG(int);         // setter green
    void SetB(int);         // setter blue
     

    int GetR();             // getter red
    int GetG();             // getter green
    int GetB();             // getter blue

    void GrayScale();       // averages colors

    // print to stdout
    friend ostream& operator<<(ostream&,const ColorPalette&);

    // add (mix) two colors
    ColorPalette operator+(const ColorPalette& );

};

ColorPalette ColorPalette::operator+(const ColorPalette& rhs){
    int r = (this->r + rhs.r) / 2;
    int g = (this->g + rhs.g) / 2;
    int b = (this->b + rhs.b) / 2;

    return *this;
}

ColorPalette::ColorPalette(){
    size = 10;
    r = g = b = 0;
}

ColorPalette::ColorPalette(int color){
    size = 10;
    r = g = b = color;
}

ColorPalette::ColorPalette(int _r,int _g, int _b){
    size = 10;
    r = _r;
    g = _g;
    b = _b;
}

ostream& operator<<(ostream& os,const ColorPalette& rhs){
    os<<"["<<rhs.r<<","<<rhs.g<<","<<rhs.b<<"]";
    return os;
}
// copy contructor containing loop to store colors in the vector palette
ColorPalette::ColorPalette(const ColorPalette& other){
        size = other.size;

        for(int i=0;i<size;i++){
            // push back other colorpalette into vector
            palette.push_back(other);
        }
}
int main() 
{
    ColorPalette Color1(255,200,11);
    ColorPalette Color2(100,14,123);
    ColorPalette Color3 = Color1 + Color2;
    cout<<Color3<<endl;

    return 0;
}