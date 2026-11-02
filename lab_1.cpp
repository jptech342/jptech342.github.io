#include <iostream>
#include <string>

using namespace std;

class Protein {
private:
    string id;
    string name;
    string aminoacid;

public:
    void set_id(string);
    string get_id() const;

    void set_name(string);
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

public:
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

    Protein p1,p2;
    p1.set_id("ENSP1234");
    p1.set_name("PTEN");
    p1.set_aminoacid("MTAIIKEIVSRNKRRYQEDGFDLDLTYIYPNIIAMGFPA");

    p2.set_id("ENSP5678");
    p2.set_name("TP53");
    p2.set_aminoacid("MEEPQSDPSVEPPLSQETFSDLWKLLPEN");

    Gene g1,g2;
    g1.set_id("ENSG1234");
    g1.set_name("BRCA1");
    g1.set_chrom("chr17");
    g1.set_start(43044295);
    g1.set_end(43170245);
    g1.set_strand('+');

    g2.set_id("ENSG5678");
    g2.set_name("PTEN");
    g2.set_chrom("chr10");
    g2.set_start(87863114);
    g2.set_end(87971930);
    g2.set_strand('-');

    p1.describe();
    p2.describe();

    cout << endl;

    g1.describe();
    g2.describe();

    return 0;
}
