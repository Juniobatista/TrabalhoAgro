#include <iostream>
#include <string>
using namespace std;

int retornaNumMes(string mes){
	if(mes=="jan"){
		return 1;
	}
	else if(mes=="fev"){
		return 2;
	}
	else if(mes=="mar"){
		return 3;
	}
	else if(mes=="abr"){
		return 4;
	}
	else if(mes=="mai"){
		return 5;
	}
	else if(mes=="jun"){
		return 6;
	}
	else if(mes=="jul"){
		return 7;
	}
	else if(mes=="ago"){
		return 8;
	}
	else if(mes=="set"){
		return 9;
	}
	else if(mes=="out"){
		return 10;
	}
	else if(mes=="nov"){
		return 11;
	}
	else if(mes=="dez"){
		return 12;
	}
}

int calculaPlantio(string &message, int nummes){
	int flag=0;
	if(nummes==2 || nummes==3){
		message+=" Amendoim,";
		flag++;
	}
	if(nummes>=8 || nummes==1){
		message+=" Arroz,";
		flag++;
	}
	if(nummes>=1 && nummes<=4){
		message+=" Feijao,";
		flag++;
	}
	if(nummes>=1 && nummes<=3){
		message+=" Milho,";
		flag++;
	}
	if(nummes>=9){
		message+=" Centeio, Soja,";
		flag++;
	}
	if(nummes>=2 && nummes<=4){
		message+=" Sorgo,";
		flag++;
	}
	if(nummes>=10){
		message+=" Cevada,";
		flag++;
	}
	if(nummes>=8){
		message+=" Trigo,";
		flag++;
	}
	return flag;
}

int calculaGerminacao(string &message, float temp){
	int flag=0;
	if(temp>=32 && temp<=34){
		message+=" Amendoim,";
		flag++;
	}
	if(temp>=20 && temp<=35){
		message+=" Arroz,";
		flag++;
	}
	if(temp>=8 && temp<=11){
		message+=" Feijao,";
		flag++;
	}
	if(temp>=25 && temp<=30){
		message+=" Milho,";
		flag++;
	}
	if(temp>=20 && temp<=30){
		message+=" Soja,";
		flag++;
	}
	if(temp>=26 && temp<=30){
		message+=" Sorgo,";
		flag++;
	}
	if(temp>=3 && temp<=5){
		message+=" Centeio,";
		flag++;
	}
	if(temp>=15 && temp<=25){
		message+=" Cevada,";
		flag++;
	}
	if(temp==15){
		message+=" Trigo,";
		flag++;
	}
	return flag;
}

int calculaDesenvolvimento(string &message, float temp){
	int flag=0;
	if(temp>=25 && temp<=35){
		message+=" Amendoim,";
		flag++;
	}
	if(temp>=20 && temp<=33){
		message+=" Arroz,";
		flag++;
	}
	if(temp>=18 && temp<=30){
		message+=" Feijao,";
		flag++;
	}
	if(temp>=24 && temp<=30){
		message+=" Milho,";
		flag++;
	}
	if(temp>=20 && temp<=30){
		message+=" Soja,";
		flag++;
	}
	if(temp>=26 && temp<=30){
		message+=" Sorgo,";
		flag++;
	}
	if(temp>= 25&& temp<=31){
		message+=" Centeio,";
		flag++;
	}
	if(temp<=80){
		message+=" Cevada,";
		flag++;
	}
	if(temp>=15 && temp<=20){
		message+=" Trigo,";
		flag++;
	}
	return flag;
}

int calculaColheita(string &message, int nummes){
	int flag=0;
	if(nummes>=5 && nummes<=6){
		message+=" Amendoim,";
		flag++;
	}
	if(nummes>=1 && nummes<=5){
		message+=" Arroz,";
		flag++;
	}
	if(nummes>=4 && nummes<=8){
		message+=" Feijao,";
		flag++;
	}
	if(nummes>=5 && nummes<=9){
		message+=" Milho,";
		flag++;
	}
	if(nummes>=1 && nummes<=4){
		message+=" Soja,";
		flag++;
	}
	if(nummes>=6 && nummes<=9){
		message+=" Sorgo,";
		flag++;
	}
	if(nummes>=4 && nummes<=7){
		message+=" Centeio,";
		flag++;
	}
	if(nummes>=5 && nummes<=7){
		message+=" Cevada,";
		flag++;
	}
	if(nummes>=4 && nummes<=7){
		message+=" Trigo,";
		flag++;
	}
	return flag;
}

bool validaMes(string mes){
	if(mes!="jan"&&mes!="fev"&&mes!="mar"&&mes!="abr"&&mes!="mai"&&mes!="jun"&&mes!="jul"&&mes!="ago"&&mes!="set"&&mes!="out"&&mes!="nov"&&mes!="dez"){
		return false;
	}
	else{
		return true;
	}
}

int main(){
	string mes, message1="As sementes boas para plantio sao:", message2="As sementes boas para germinacao sao:",message3="As culturas boas para desenvolvimento sao:", message4="As culturas boas para colheita sao:";
	double temp;
	int nummes, flag1=0;
	cout<<"Digite o mes atual: ";
	cin>>mes;
	getchar();
	while(!validaMes(mes)){
		cout<<"Mes invalido, digite o mes atual: ";
		cin>>mes;
		getchar();
	}
	cout<<"Digite a temperatura atual: ";
	cin>>temp;
	getchar();
	nummes=retornaNumMes(mes);
	if(!calculaPlantio(message1,nummes)){
		message1+=" Nenhuma.";
	}
	else{
		message1[message1.size()-1]='.';
	}
	if(!calculaGerminacao(message2,temp)){
		message2+=" Nenhuma.";
	}
	else{
		message2[message2.size()-1]='.';
	}
	if(!calculaDesenvolvimento(message3,temp)){
		message3+=" Nenhuma.";
	}
	else{
		message3[message3.size()-1]='.';
	}
	if(!calculaColheita(message4,nummes)){
		message4+=" Nenhuma.";
	}
	else{
		message4[message4.size()-1]='.';
	}
	cout<<message1<<endl<<message2<<endl<<message3<<endl<<message4<<endl;
	return 0;
}
