#include <iostream>
#include <unistd.h>  
#include <sys/wait.h>  
#include <vector>
#include <cstdlib>  
#include <ctime>    
/*
╔══════════════════════════════════╗
║     Vector global que no se      ║
║     comparte entre procesos      ║
╚══════════════════════════════════╝
*/
using namespace std; 
vector<string> nombres; 

int main() {
    int N;
    cout << "Ingresa la cantidad de procesos a crear: ";
    cin >> N;

    nombres.push_back("Juan");
    nombres.push_back("Maria");
    nombres.push_back("Carlos");

/*
╔══════════════════════════════════════╗
║     Genera número aleatorios         ║
║     basados en el tiempo actual      ║
╚══════════════════════════════════════╝
*/

    srand(time(0));
/*
╔════════════════════════════════════════════════════╗
║     Iteración para crear procesos                  ║
║     y ejecutar el código del proceso hijo          ║
╚════════════════════════════════════════════════════╝
*/
    for (int i = 0; i < N; i++) {
        pid_t pid = fork(); 

        if (pid == 0) {  
            string nuevoNombre;
            cout << "Proceso hijo " << getpid() << ": Ingresa un nombre para añadir al vector: ";
            cin >> nuevoNombre;
            
            nombres.push_back(nuevoNombre);  

            // Seleccionar aleatoriamente un nombre del vector
            int idxAleatorio = rand() % nombres.size();
            cout << "Proceso hijo " << getpid() << ": Escogí a " << nombres[idxAleatorio] << endl;

            exit(0);  
        }
    }
/*
╔═══════════════════════════════════════════╗
║     El proceso padre espera               ║
║     a que terminen todos los hijos        ║
╚═══════════════════════════════════════════╝
*/
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    cout << "Proceso padre: Todos los procesos hijos han terminado." << endl;
    return 0;
}
