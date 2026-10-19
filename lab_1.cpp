#include <iostream>
#include <cstring>

class Protein {
    int id;
    char* name;
    char* aminoacid;
 public:
     void set_id(int);
     int get_id() const;
     void set_name(const char *);
     char* get_name() const;
     void set_aminoacid(const char*);
     char* get_aminoacid() const;
     void describe() const;
};



class Gene{
    int id;
    char* name;
    char* chrom;
    int start;
    int end;
    char strand;
    
   public:
     void set_id(int);
     int get_id() const;
     void set_name(char *);
     char* get_name() const;
     void set_chrom(char *);
     char* get_chrom() const;
     void set_start(int);
     int get_start() const;
     void set_end(int);
     int get_end() const;
     void set_strand(char);
     char get_strand() const;
     void describe() const;
};


void Protein::set_id(int a) {
    id=a;
}

void Protein::set_name(const char* str) {
    name = new char(strlen(str)+1);
    strcpy(name,str);
}

void Protein::set_aminoacid(char *amin){
    aminoacid= new char(strlen(amin)+1);
    strcpy(aminoacid,amin);
}

int Protein::get_id() const
{
     return id;
}

char* Protein::get_aminoacid() const
{
     return aminoacid;
}

void Protein::describe() const 
{
 cout << "protein" << name << aminoacid << endl;
}

void Gene::set_id(int b) {
    id=b;
}

void Gene::set_name(char *nam) {
    name = new char(strlen(nam)+1);
    strcpy(name,nam);
}

void Gene::set_chrom(char* ch)) {
    chrom = new char(strlen(ch)+1);
    strcpy(chrom,ch);
}

 void Gene::set_start(int s) {
    start=s;
}

void Gene::set_end(int e) {
    end=e;
}

void Gene::set_strand(char c) {
    strand=c;
}

int Gene::get_id() const
{
    return id;
}

char * Gene::get_name() const 
{
    return name;
}

char * Gene::get_chrom() const
{
    return chrom;
}

int Gene::get_start() const 
{
    return start;
}

int Gene::get_end() const 
{
    return end;
}

char Gene::get_strand() const
{
    return strand;
}

void Gene::desribe() {
 cout << "Gene" << name << "(" << chrom << ":" << start << "-" << end << "," << strand << ")" << endl;      
}

int main() {
    Protein p;
    p.set_id(10);
    p.set_name("PTEN");
    p.set_aminoacid("UJFAHJKRPEALADPNALWMKEA");
    p.describe();
    
    Gene g;
    g.set_id(543);
    g.set_name("BRCA");
    g.set_strand("+");
    g.set_start(895380543290);
    g.set_end(21404239240245);
    g.describe();      
    return 0;
}
