///Autor: Danilo Abellá.
///Carrera: Licenciatura en Ciencias de la Computación (LCC).
///Profesora: Rosa Berrero.
///Windows 8.0 / SO de 64 bits.
///Compilador: Code-Blocks.
#include <iostream>

using namespace std;

/// TDA ///
struct arbol
{
    int dato;
    arbol *izq;
    arbol *der;
};

/// Declaracion ///
arbol* ing_arbol(arbol *A,int x);
void internos_inorden(arbol *A , int &cant );
int elemento(arbol *A , int n );
void inorden(arbol *A, int cont );
void inorden_e(arbol *A , int cont , int dato );

/// Promgrama principal ///---------------------------------------------------------------------------///

int main (){
arbol *A = NULL;
int y , h=1 , n , cant=0 , u , d , p ;
int cont = -1;

cout<<"\n\tBienvienido."<<endl;

while (h == 1)
{
    cout<<"\n\tSeleccione una Tarea:"<<endl;
    cout<<"\t(1)Ingresar Datos."<<endl;
    cout<<"\t(2)Mostrar Nodos Internos."<<endl;
    cout<<"\t(3)Ver si un Elemento se encuentra en el Arbol."<<endl;
    cout<<"\t(4)Mostrar Datos con sus respectivos niveles."<<endl;
    cout<<"\t(5)Salir."<<endl;
    cout<<"\tTarea #:";
    cin>>y;

    switch (y)
    {
        case 1:
    /// Ingreso ///------------------------------------------------------------------------------------------///

        cout<<"\n\tCuantos datos quiere ingresar?:";
        cin>>u;
        cout<<"\n\tIngrese los datos a agregar al arbol ( numero ):"<<endl;
        for ( int i=0 ; i < u ; i ++)
        {   cout<<"\t";
            cin>>n;
            A = ing_arbol ( A , n );
        }

        break;
        case 2:
    /// Mostrar ///------------------------------------------------------------------------------------------///

        cout<<"\n\tDatos:"<<endl;
        cant = 0;
        internos_inorden( A , cant );


        cout<< "\n\tSon " << cant << " nodos internos en total.\n " <<endl;

        break;
        case 3:
    /// Buscar Elemento ///----------------------------------------------------------------------------------///

        cout<<"\n\tIngrese dato a buscar ( numero ):";
        cin>> d;
        p = elemento( A , d );

        if ( p == 1) {  cout<<"\n\tEl elemento se encuentra en la lista.\n"<<endl;  }
        else
        {   cout<<"\n\tEl elemento NO se encuentra en la lista.\n"<<endl;
        }

        inorden_e( A , cont , d );

        break;
        case 4:

    /// Niveles ///-----------------------------------------------------------------------------------///

        cout<<"\n\tDatos: "<<endl;
        inorden( A , cont );

        break;
    /// Salir   ///------------------------------------------------------------------------------------------///
        default :
            h = 0;
            break;
    }
}
return 0;
}


///     Funciones   ///

/// Internos ///

void internos_inorden(arbol *A, int &cant ){
if(A)
{
    internos_inorden(A->izq , cant );
    if ( A->der != NULL || A->izq != NULL)
    {
        cout << "\t" << A->dato;
        cant ++;
    }
    internos_inorden(A->der , cant );
}
}

/// Dato ///--------------------------------------------------------------///
/// Ver si esta ///
int elemento(arbol *A, int n ){
if(!A)
{   return 0;
}
if( A->dato == n)
{   return 1;
}
return ( elemento(A->izq , n) +  elemento(A->der , n ));
}


/// Ingreso ///

arbol* ing_arbol(arbol *A,int x)
{   if(A==NULL)
    {   A= new arbol;
        if(!A)
        {   cout << "\n\tNO HAY SUFICIENTE MEMORIA ";
            return A;
        }
        A->dato=x;
        A->izq=A->der=NULL;
    }
    else if(A->dato < x)
    A->der=ing_arbol(A->der,x);
    else if (A->dato > x)
    A->izq=ing_arbol(A->izq,x);
    else
    {   cout << "\n\tEL ELEMENTO YA EXISTE, NO PUEDE ESTAR REPETIDO";
        cin.get();
    }
    return A;
}

/// Niveles ///

void inorden(arbol *A , int cont ){
if(A)
{   cont++;
    cout <<"\tDato: "<< A->dato << "\tNivel: " << cont <<endl;
    inorden(A->izq , cont );
    inorden(A->der , cont );
}
cont--;
}

/// Nivel Elemento ///
void inorden_e(arbol *A , int cont , int dato ){
if(A)
{   cont++;
    if ( A->dato == dato )
    {   cout <<"\tDato: "<< A->dato << "\tNivel: " << cont <<endl;
    }
    inorden_e(A->izq , cont , dato );
    inorden_e(A->der , cont , dato );
}
cont--;
}



