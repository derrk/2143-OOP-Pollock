#include<iostream>
#include<map>
#include<fstream>
#include<vector>
#include<sstream>


using namespace std;

class Countries
{
private:


    string countryInits;
    string countryName;
    string outlineShape;
    string outlineColour;

public:


    Countries()
    {
        countryInits = countryName = outlineColour = outlineShape = 'a';

    }


    Countries(string countryInits, string Name, string color, string shape)
    {
        countryName = Name;
        countryInits = countryInits;
        outlineColour = color;
        outlineShape = shape;

    }


    Countries(const Countries& other)
    {
        this->countryInits = other.countryInits;
        this->countryName = other.countryName;
        this->outlineColour = other.outlineColour;
        this->outlineShape = other.outlineShape;
    }


    ~Countries() 
	{

	};

    void setInits(string countryInits)
    {
        countryInits = countryInits;
    }

    void setOutlineColour(string color)
    {
        outlineColour = color;
    }

    void SetShape(string shape)
    {
        outlineShape = shape;
    }

    string GetShape()
    {
        return outlineShape;
    }

    string GetoutlineColour()
    {
        return outlineColour;
    }

    void SetCountryName(string Name)
    {
        countryName = Name;
    }

    string GetCountryName()
    {
        return countryName;
    }

    string getInits()
    {
        return countryInits;
    }

	// output operator overload
    friend ostream& operator<<(ostream& outfile, Countries& other)
    {
        //setup for graphviz
        return outfile << other.countryInits << "[label =" << " \" "
            << other.countryName << " \" " << "color = " <<
            other.outlineColour << " shape = " <<
            other.outlineShape << "]" << '\n';
    }

    friend istream& operator>>(istream& infile, Countries& Countries)
    {
        return infile >> Countries.countryInits >> Countries.countryName >> 
            Countries.outlineColour >> Countries.outlineShape;
        
    }
};
// class for edge pointers
class edgePtrs
{
	private:
    string Country1;
    string Country2;
    int edgeLength;
public:
    edgePtrs()
    {
        Country1 = Country2 = "Name";
        edgeLength = 0;

    }


    edgePtrs(string first, string second, int length)
    {
        Country1 = first;
        Country2 = second;
        edgeLength = length;
    }


    friend ostream& operator<<(ostream& outfile, edgePtrs& other)
    {
        return outfile << other.Country1 << "->" << other.Country2 <<
            "[ label =" << " \" " << other.edgeLength << "\" ];" << '\n';
    }
};

int main()
{
	// open input and output file
    ifstream infile;
    infile.open("inpt.txt");
    ofstream outfile;
    outfile.open("output.txt");
    

    vector<edgePtrs*> EDGES;                 // vector of edgeLength pointers.
    edgePtrs* Links;                      // pointer to edges.
    Countries Country;                // create object call Country

    int NumCountries, EdgeNumbers,edges;
    string GraphDesign = "", Country1, Country2;

    infile >> GraphDesign;                           // Read in the graph type.
    outfile << GraphDesign << "\n{ " << "\n";           // Display the graph Type.
    infile >> NumCountries;

    // Read in number of Country.
    while (!infile.eof())     // while not end of file
    {
        for (int i = 0; i < NumCountries;i++)
        {
            infile >> Country;
            // read in the node and print it out
            outfile << Country;
        }

        infile >> EdgeNumbers;                                 // read in the number of edges
        outfile << "\n\n";

        for (int i = 0; i < EdgeNumbers;i++)
        {
            infile >> Country1 >> Country2 >> edges;
            Links = new edgePtrs(Country1, Country2, edges);
            EDGES.push_back(Links);                    // store in the vector
        }

        for (int i = 0; i < EDGES.size(); i++)
        {
            outfile << *EDGES[i];                      // print out each line
        }
        outfile << "}" << endl;
    }

    infile.close();
    outfile.close();
    return 0;

}