#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Protein {
private:
   string id;
   string name;
   string aminoacid;
   static int protein_count;

public:
    
    //Protein Constructor
    Protein(string,string,string);

    // Destructor
    ~Protein();

    void set_id(string);
    string get_id() const;

    void set_name(const string);
    string get_name() const;

    void set_aminoacid(string);
    string get_aminoacid() const;

    void describe() const;
};

class Gene {
private:
    string id;
    string name;
    string chrom;
    int start;
    int end;
    char strand;
    static int gene_count;

public:
    
    //Gene Constructor
    Gene(string,string, const string, int, int,char);

    ~Gene();

    void set_id(string);
    string get_id() const;

    void set_name(string);
    string get_name() const;

    void set_chrom(string);
    string get_chrom() const;

    void set_start(int);
    int get_start() const;

    void set_end(int);
    int get_end() const;

    void set_strand(char);
    char get_strand() const;

    void describe() const;
};

// ================= Protein =================

int Protein::protein_count=0;
int Gene::gene_count=0;

// Constructor µe initializer list
Protein::Protein(string i, string n, string amin)
    : id(i), name(n), aminoacid(amin) {

    cout << " Protein " << id << " " << name << " " << aminoacid << " created" << endl;
    
    protein_count++;
    cout << "Active proteins: " << protein_count << endl;
}

// Destructor
Protein::~Protein() {
    cout << " Protein " << id << " " << name << " " << aminoacid << " destroyed" << endl;
    protein_count--;
}

void Protein::set_id(string a) {
    id = a;
}

string Protein::get_id() const {
    return id;
}

void Protein::set_name(string str) {
    name = str;
}

string Protein::get_name() const {
    return name;
}

void Protein::set_aminoacid(string amin) {
    aminoacid = amin;
}

string Protein::get_aminoacid() const {
    return aminoacid;
}

void Protein::describe() const {
    cout << "Protein " << name
         << " " << aminoacid << endl;
}

// ================= Gene =================

// Constructor µe initializer list
Gene::Gene(string i,string n,string c,
           int s, int e,char st)
    : id(i), name(n), chrom(c),
      start(s), end(e), strand(st) {
          
    cout << "Gene " << id << " " << name << " " << chrom << " " << start << " " << end << " " << strand << " created" << endl;
    
    gene_count++;
    cout << "Active Genes: " << gene_count << endl;
}

// Destructor
Gene::~Gene() {
    cout << "Gene " << id << " " << name << " " << chrom << " " << start << " " << end << " " << strand << " destroyed" << endl;
    gene_count--;
}

void Gene::set_id(string b) {
    id = b;
}

string Gene::get_id() const {
    return id;
}

void Gene::set_name(string nam) {
    name = nam;
}

string Gene::get_name() const {
    return name;
}

void Gene::set_chrom(string ch) {
    chrom = ch;
}

string Gene::get_chrom() const {
    return chrom;
}

void Gene::set_start(int s) {
    start = s;
}

int Gene::get_start() const {
    return start;
}

void Gene::set_end(int e) {
    end = e;
}

int Gene::get_end() const {
    return end;
}

void Gene::set_strand(char c) {
    strand = c;
}

char Gene::get_strand() const {
    return strand;
}

void Gene::describe() const {
    cout << "Gene " << name
         << " (" << chrom << ":"
         << start << "-" << end
         << ", " << strand << ")"
         << endl;
}

// ================= Main =================

int main() {

    Protein p1("ENSP1234", "PTEN",
               "MTAIIKEIVSRNKRRYQEDGFDLDLTYIYPNIIAMGFPA");

    Protein p2("ENSP5678", "TP53",
               "MEEPQSDPSVEPPLSQETFSDLWKLLPEN");
               
    Protein *p3= new Protein("EAKFLWDALF", "GTFH",
                "SKDAKSGFKWFDKWAENDMSDAJOFPOKEAFJMPTEFGH");

    Gene g1("ENSG1234", "BRCA1", "chr17",
            43044295, 43170245, '+');

    Gene g2("ENSG5678", "PTEN", "chr10",
            87863114, 87971930, '-');
    
    Gene *g3= new Gene("ENGJAOSLP", "BRAP3", "chr12",
            345023421, 891208, '+');
            
            
    cout << "\n In main" << endl;

    cout << "\n--- Proteins ---" << endl;

    p1.describe();
    p2.describe();
    p3->describe();

    cout << "\n Genes " << endl;

    g1.describe();
    g2.describe();
    g3->describe();
    
    cout << "\n Deleting objects in heap\n" << endl;
    
    delete p3;
    delete g3;

    cout << "\n End of main " << endl;

    return 0;
}
