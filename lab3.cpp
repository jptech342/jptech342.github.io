
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ================= Sequence =================

class Sequence {
private:
    string type;
    string data;

public:
    Sequence(string, string);
    ~Sequence();

    void set_type(string);
    string get_type() const;

    void set_data(string);
    string get_data() const;

    void describe() const;
    int length() const;
};

// ================= Isoform =================

class Isoform {
private:
    string id;
    string name;
    Sequence seq;

public:
    Isoform(string, string, Sequence);
    ~Isoform();

    void set_id(string);
    string get_id() const;

    void set_name(string);
    string get_name() const;

    void describe() const;
};

// ================= Protein =================

class Protein {
private:
    string id;
    string name;
    string aminoacid;
    static int protein_count;

public:

    Protein(string, string, string);
    ~Protein();

    void set_id(string);
    string get_id() const;

    void set_name(const string);
    string get_name() const;

    void set_aminoacid(string);
    string get_aminoacid() const;

    void describe() const;
};

// ================= Gene =================

class Gene {
private:
    string id;
    string name;
    string chrom;

    vector<Isoform> isoforms;

    int start;
    int end;
    char strand;

    static int gene_count;

public:

    Gene(string, string, const string,
         vector<Isoform>, int, int, char);

    ~Gene();

    void createIsoform(const string& isoform_id,
                       const string& isoform_name,
                       const Sequence& seq);

    void addIsoform(const Isoform& isoform);

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

// ================= Static Variables =================

int Protein::protein_count = 0;
int Gene::gene_count = 0;


// ================= Protein =================

// Constructor
Protein::Protein(string i, string n, string amin)
    : id(i), name(n), aminoacid(amin) {

    cout << "Protein " << id << " "
         << name << " created" << endl;

    protein_count++;

    cout << "Active proteins: "
         << protein_count << endl;
}

// Destructor
Protein::~Protein() {

    cout << "Protein " << id << " "
         << name << " destroyed" << endl;

    protein_count--;
}

void Protein::set_id(string a) {
    id = a;
}

string Protein::get_id() const {
    return id;
}

void Protein::set_name(const string n) {
    name = n;
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


// ================= Sequence =================

// Constructor
Sequence::Sequence(string t, string d)
    : type(t), data(d) {

    cout << "Sequence " << type
         << " created" << endl;
}

// Destructor
Sequence::~Sequence() {

    cout << "Sequence " << type
         << " destroyed" << endl;
}

void Sequence::set_type(string t) {
    type = t;
}

string Sequence::get_type() const {
    return type;
}

void Sequence::set_data(string d) {
    data = d;
}

string Sequence::get_data() const {
    return data;
}

void Sequence::describe() const {

    cout << "Sequence type: "
         << type << endl;

    cout << "Sequence data: "
         << data << endl;

    cout << "Sequence length: "
         << length() << endl;
}

int Sequence::length() const {
    return data.length();
}


// ================= Isoform =================

// Constructor
Isoform::Isoform(string i, string n, Sequence s)
    : id(i), name(n), seq(s) {

    cout << "Isoform " << name
         << " (" << id << ") created" << endl;
}

// Destructor
Isoform::~Isoform() {

    cout << "Isoform " << name
         << " (" << id << ") destroyed" << endl;
}

void Isoform::set_id(string a) {
    id = a;
}

string Isoform::get_id() const {
    return id;
}

void Isoform::set_name(string b) {
    name = b;
}

string Isoform::get_name() const {
    return name;
}

void Isoform::describe() const {

    cout << "\nIsoform " << name
         << " (" << id << ")" << endl;

    seq.describe();
}


// ================= Gene =================

// Constructor
Gene::Gene(string i, string n, string c,
           vector<Isoform> isos,
           int s, int e, char st)

    : id(i), name(n), chrom(c),
      isoforms(isos), start(s), end(e), strand(st) {

    cout << "Gene " << id << " "
         << name << " " << chrom << " "
         << start << " " << end << " "
         << strand << " created" << endl;

    gene_count++;

    cout << "Active Genes: "
         << gene_count << endl;
}

// Destructor
Gene::~Gene() {

    cout << "Gene " << id << " "
         << name << " destroyed" << endl;

    gene_count--;
}

// Create Isoform
void Gene::createIsoform(const string& isoform_id,
                         const string& isoform_name,
                         const Sequence& seq) {

    Isoform newIsoform(isoform_id, isoform_name, seq);

    addIsoform(newIsoform);
}

// Add Isoform
void Gene::addIsoform(const Isoform& isoform) {
    isoforms.push_back(isoform);
}

// Setters and Getters

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

// Describe Gene
void Gene::describe() const {

    cout << "\nGene " << name
         << " (" << chrom << ":"
         << start << "-" << end
         << ", " << strand << ")"
         << endl;

    cout << "Number of isoforms: "
         << isoforms.size() << endl;

    for (const auto& isoform : isoforms) {
        isoform.describe();
    }
}


// ================= Main =================

int main() {

    cout << "\n========== PROGRAM STARTED ==========\n"
         << endl;

    // Create Proteins

    Protein p1("ENSP1234", "PTEN",
        "MTAIIKEIVSRNKRRYQEDGFDLDLTYIYPNIIAMGFPA");

    Protein p2("ENSP5678", "TP53",
        "MEEPQSDPSVEPPLSQETFSDLWKLLPEN");

    Protein *p3 = new Protein(
        "EAKFLWDALF", "GTFH",
        "SKDAKSGFKWFDKWAENDMSDAJOFPOKEAFJMPTEFGH"
    );

    // Create Genes

    Gene g1("ENSG1234", "BRCA1", "chr17",
            vector<Isoform>(), 43044295, 43170245, '+');

    Gene g2("ENSG5678", "PTEN", "chr10",
            vector<Isoform>(), 87863114, 87971930, '-');

    Gene *g3 = new Gene(
        "ENGJAOSLP", "BRAP3", "chr12",
        vector<Isoform>(), 345023421, 891208, '+'
    );

    // Create Sequences

    Sequence s1("RNA", "AUGGCCAUGGCGCCC");
    Sequence s2("RNA", "AUGGCCAAUGGCU");
    Sequence s3("RNA", "AUGCCCAUGGAA");
    Sequence s4("RNA", "AUGGCUAUGCCCGG");

    // Add Isoforms to Gene g1

    cout << "\n========== ADD ISOFORMS TO BRCA1 =========="
         << endl;

    g1.createIsoform("ISO001", "BRCA1-202", s1);
    g1.createIsoform("ISO002", "BRCA1-203", s2);

    // Add Isoforms to Gene g2

    cout << "\n========== ADD ISOFORMS TO PTEN =========="
         << endl;

    g2.createIsoform("ISO003", "PTEN-201", s3);
    g2.createIsoform("ISO004", "PTEN-202", s4);

    // Describe Proteins

    cout << "\n========== PROTEINS ==========\n"
         << endl;

    p1.describe();
    p2.describe();
    p3->describe();

    // Describe Genes and Isoforms

    cout << "\n========== GENES ==========\n"
         << endl;

    g1.describe();
    g2.describe();
    g3->describe();

    // Delete dynamically allocated objects

    cout << "\n========== DELETING HEAP OBJECTS ==========\n"
         << endl;

    delete p3;
    delete g3;

    // Create another Gene

    Gene g4("ENSG9999", "MYC", "chr8",
            vector<Isoform>(), 128748315, 128753680, '+');

    g4.describe();

    cout << "\n========== END OF MAIN ==========\n"
         << endl;

    return 0;
}
