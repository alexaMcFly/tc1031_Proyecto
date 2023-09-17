#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

class CCancion{
    public:
        string nombre;
        string autor;
        string genero;
        string lanzamiento;//año de publicación
        string album;
    private:
        int duracion;//duracion en min
};

class lista{
    public:
        vector <CCancion> canciones;    
};

int main(){

    lista miLista;
    ifstream archivo("datos.txt");//abre el archivo
    if(!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
    }
    else{ 
        string linea;
        string aux;
        CCancion miCancion;
        vector <string> generos;
        generos.push_back("Rock");
        generos.push_back("Pop");
        generos.push_back("Rock en español");
        generos.push_back("Clásica");
        int g_counter=-1;

        while(getline(archivo,linea)){
            
            if(linea.empty()){
                getline(archivo, linea);//ignorar una linea
                g_counter++;
                continue;
            }

            for(int i=0; i<linea.length();i++){
                if(linea[i]=='-'){
                    miCancion.nombre=linea.substr(0,i+1);
                    miCancion.autor=linea.substr(i+1,linea.length()-i+2);
                    miCancion.genero=generos[g_counter];
                    break;
                }
            }
        
            miLista.canciones.push_back(miCancion);
        }
    archivo.close(); // Cierra el archivo

    for(int i = 0; i<miLista.canciones.size(); i++){
        cout<<miLista.canciones[i].nombre<<"--"<<miLista.canciones[i].autor<<endl;
        cout<<miLista.canciones[i].genero<<endl;
    }

}
}
