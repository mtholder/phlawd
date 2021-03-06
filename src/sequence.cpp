/*
 * This is an extremely stripped down sequence class that is just meant to be
 * transparent and lightweight. As functionality increases, so will the 
 * complexity of the class.
 *
 */

#include <string>

#include <iostream>


using namespace std;

#include "sequence.h"

Sequence::Sequence():id(),seq(),aligned(){}

Sequence::Sequence(string _id, string _seq, bool _aligned):id(_id),seq(_seq),aligned(_aligned),name(""),comment(""),ncbi_gi("0"),ncbi_tax("0"){}
Sequence::Sequence(string _id, string _seq):id(_id),seq(_seq),aligned(false),name(""),comment(""),ncbi_gi("0"),ncbi_tax("0"){}

bool Sequence::is_aligned(){
	return aligned;
}

string Sequence::get_sequence(){
	return seq;
}

string Sequence::get_aligned_seq(){
    return al_seq;
}

void Sequence::set_aligned_seq(string inseq){
    al_seq = inseq;
}

string Sequence::get_id(){
	return id;
}

string Sequence::get_name(){
    return name;
}

string Sequence::get_comment(){
    return comment;
}

void Sequence::set_sequence(string _seq){
	seq = _seq;
}

void Sequence::set_id(string _id){
	id = _id;
}

void Sequence::set_aligned(bool _aligned){
	aligned = _aligned;
}

void Sequence::set_name(string _name){
    name = _name;
}

void Sequence::set_comment(string _comment){
    comment = _comment;
}

void Sequence::set_ncbi_tax_id(string _tid){
    ncbi_tax = _tid;
}

void Sequence::set_ncbi_gi_id(string _tid){
    ncbi_gi = _tid;
}

string Sequence::get_ncbi_tax_id(){
    return ncbi_tax;
}

string Sequence::get_ncbi_gi_id(){
    return ncbi_gi;
}

//this one is private
//it should eventually be generalized for both nucleotide and protein, 
//but for now it is just nucleotide for simplicity
string Sequence::reverse(string charin){
	string ret;
	if (charin == "-")
		ret = "-";
	if (charin == " ")
		ret = " ";
	if (charin == "A" || charin == "a"){
		ret = "T";
	}else if(charin == "T" || charin == "t"){
		ret = "A";
	}else if(charin == "C" || charin == "c"){
		ret = "G";
	}else if (charin == "G" || charin == "g"){
		ret = "C";
	}else if(charin == "U" || charin == "u"){
		ret = "A";
	}else if(charin == "m" || charin == "M"){
		ret = "K";
	}else if(charin == "r" || charin == "R"){
		ret = "Y";
	}else if(charin == "y" || charin == "Y"){
		ret = "R";
	}else if(charin == "k" || charin == "K"){
		ret = "M";
	}else if(charin == "v" || charin == "V" ){
		ret = "B";
	}else if(charin == "h" || charin == "H" ){
		ret = "D";
	}else if(charin == "d" || charin == "D" ){
		ret = "H";
	}else if(charin == "b" || charin == "B" ){
		ret = "V";
	}else if (charin == "n" || charin == "N" || charin == "x" || charin == "X"){
		ret = "N";
	}
	return ret;
}

string Sequence::reverse_complement(){
	string rcomp = seq;
	for (unsigned int i=0 ;i < rcomp.size(); i++){
		rcomp.replace(i,1,reverse(seq.substr(seq.size()-i-1,1)));
	}
	return rcomp;
}

void Sequence::perm_reverse_complement(){
	string rcomp = seq;
	for (unsigned int i=0 ;i < rcomp.size(); i++){
		rcomp.replace(i,1,reverse(seq.substr(seq.size()-i-1,1)));
	}
	seq = rcomp;
}

void Sequence::set_sqlite_id(int iid){
    sqlite_id = iid;
}

int Sequence::get_sqlite_id(){
    return sqlite_id;
}

bool Sequence::operator==(const Sequence &other) const{
	bool ret = true;
	if(other.ncbi_gi != ncbi_gi){
		ret = false;
		return ret;
	}
	if(other.ncbi_tax != ncbi_tax){
		ret = false;
		return ret;
	}
	if(other.name != name){
		ret = false;
		return ret;
	}
	return ret;
}
