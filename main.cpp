#include <iostream> //LIBRERIA QUE PERMITE LA CAPTURA E IMPRESIÓN DE DATOS
#include <cstdlib> //LIBRERIA QUE PERMITE EL USO DE "CLS" PARA BORRAR LO QUE ESTÉ EN PANTALLA
#include <conio.h> //LIBRERIA QUE PERMITE EL USO DEL GETCH() PARA LA ENCRIPTACIÓN DE LA CONTRASEÑA
#include <string.h> //LIBRERIA QUE PERMITE EL USO DE LA FUNCION STRSTR PARA VERIFICAR SI EL CORREO CONTIENE LA TERMINACIÓN CORRECTA
using namespace std;
//**CREACIÓN DE CONSTANTES**
const int catusu = 100; //CONSTANTE USADA PARA DAR UN LÍMITE A LA CANTIDAD DE DISPOSITIVOS
const int usu = 1; //CONSTANTE USADA PARA DAR UN LÍMITE A LA CANTIDAD DE USUARIOS
//**CREACIÓN DE ESTRUCTURAS**
struct registro_usuario{ //ESTRUCTURA QUE CONTIENE LOS DATOS DEL USUARIO;
    char usuario[50];
    string contrasena;
    string nombre;
    string carrera;
    char genero;
    string fecha_nacimiento;
};
struct Dispositivo{ //ESTRUCTURA QUE CONTIENE LOS DATOS DE LOS DISPOSITIVOS;
    int codigo;
    string tipo;
    string nombre;
    string marca;
    string ubicacion;
    int volumen;
    int canal;
    string estado;
    int luminosidad;
};
//**DEFINICIÓN DE LAS FUNCIONES QUE SE UTILIZARÁN**
void registraeus(registro_usuario usuariosr[], Dispositivo disposi[], int cantidispoto);
void login_usuario(registro_usuario usuariosr[], Dispositivo disposi[], int cantidispoto);
void menu_principal_adm(registro_usuario usuariosr[],Dispositivo disposi[],int cantidispoto);
int agregar_dispositivos(Dispositivo disposi[], int cantidispoto);
void listar_dispositivos(Dispositivo disposi[], int cantidispoto);
void modificar_caracteristicas(Dispositivo disposi[], int cantidispoto);
void modificar_funcionalidad(Dispositivo disposi[], int cantidispoto);
int eliminar_dispositivo(Dispositivo disposi[], int cantidispoto);
int main(){
    int cantidispoto = 0;  //VARIABLE QUE REPRESENTA LA CANTIDAD DE DISPOSITIVOS REGISTRADOS
    Dispositivo disposi[catusu]; //ARREGLO QUE CONTIENE LA INFORMACION DE DISPOSITIVOS
    registro_usuario usuariosr[usu]; //ARREGLO QUE CONTIENE LA INFORMACION DEL USUARIO

    //LLAMADO A LAS FUNCIONES QUE SE DEFINIERON
    registraeus(usuariosr,disposi,cantidispoto);
    login_usuario(usuariosr,disposi,cantidispoto);
    menu_principal_adm(usuariosr,disposi,cantidispoto);
}
//**IMPLEMENTACION DE LAS FUNCIONES**
//FUNCIÓN UTILIZADA PARA EL REGISTRO DEL USUARIO
void registraeus(registro_usuario usuariosr[], Dispositivo disposi[], int cantidispoto){
    for(int i =0 ; i<usu ; i++){
        //VARIABLE QUE CONTIENE LA CADENA EN LA CUAL DEBE TERMINAR EL CORREO
        char termina_correo2[] = "@javeriana.edu.co";
        string contrasenac1; //VARIABLE PARA VERIFICAR QUE LAS CONTRASEÑAS COINCIDEN
        system("cls");
        cout << "\n\t\tFORMULARIO REGISTRO DE USUARIOS";
        cout << "\n\t\t-------------------------------" << endl;
        cout << endl;
        //EL USUARIO INGRESA SU CORREO
        cout << "\tDigite el correo electronico de la universidad del usuario:" << endl;
        cout << "\t";
        cin >> usuariosr[i].usuario;
        //SE HACE EL USO DE LA FUNCION STRSTR PARA VERÍFICAR SI EL CORREO QUE INGRESA EL USUARIO
        //CONTIENE LA TERMINACION CORRESPONDIENTE A LA DEL CORREO DE LA UNIVERSIDAD
        //CUANDO ES IGUAL A 0 QUIERE DECIR QUE LA CADENA INGRESADA POR EL USUARIO NO CONTIENE LA CADENA 2 (INICIALIZADA)
        //EL CICLO SE EJECUTA HASTA QUE SEA != 0 QUE QUIERE DECIR QUE LO QUE INGRESA EL USUARIO SI CONTIENE LA CADENA 2
        while(strstr(usuariosr[i].usuario,termina_correo2) == 0){
            cout << endl;
            cout << "\tERROR! El correo debe tener la terminacion de '@javeriana.edu.co'" << endl;
            cout << endl;
            cout << "\tDigite el correo electronico de la universidad del usuario:" << endl;
            cout << "\t";
            cin >> usuariosr[i].usuario;
        }
        cout << endl;
        cout << "\tDigite la contrasena:" << endl;//EL USUARIO INGRESA SU CONTRASEÑA
        //INICIO DE ENCRIPTACIÓN DE LA CONTRASEÑA 1.
        char caracter; //VARIABLE QUE EVALUA CADA CARÁCTER DE LA CONTRASEÑA
        //ESTA FUNCIÓN LEE EL PRIMER CARÁCTER SIN MOSTRARLO EN PANTALLA,
        //TRAS LA LECTURA LO REEMPLAZA POR UN ASTERISCO
        caracter = getch();
        //ES NECESARIO HACER ESTA INICIALIZACIÓN EN VACIO, PORQUE EN CADA INTERACCIÓN
        //DEL BUCLE SE ALMACENAN CARACTERES A LA VARIABLE, ES NECESARIO BORRARLOS
        usuariosr[i].contrasena = "";
        cout << "\t";
        //CICLO QUE SE EJCUTA MIENTRAS QUE EL CARACTER SEA DIFERENTE DE 13
        //EN CODIGO ASCII EL 13 ES ENTER
        while(caracter != 13){
            //ENTRA A ESTE CONDICIONAL SI EL CARACTER ES DIFERENTE DE 8
            //EN CODIGO ASCII EL 8 ES RETROCESO
            if(caracter != 8){
                //SE LEE CARACTER A CARACTER Y SE AGREGA A LA VARIABLE CONTRASENA
                usuariosr[i].contrasena.push_back(caracter);
                //Y SE HACE LA IMPRESION DE LOS ASTERISTICOS DEIBIDO A QUE LA FUNCION GETCH() NO MUESTRA NADA EN LA PANTALLA
                cout << "*";
            }
            else //EN CASO DE QUE EL CARACTER SEA RETROCESO
            {
                //SI LA LONGITUD DE LA CONTRASENA ES MAYOR A 0
                if(usuariosr[i].contrasena.length() > 0){
                    //ESTO HACE QUE EL CURSOR RETROCEDA UN ESPACIO, LUEGO AGREGUE UN ESPACIO Y VUELVA AL ESPACIO ORIGINAL
                    //BORRANDO ASI EL CARACTER MAL DIGITADO
                    cout << "\b \b";
                    //ESTA FUNCION PERMITE QUE SE ELIMINE EL ULTIMO CARACTER QUE SE INGRESO
                    usuariosr[i].contrasena.pop_back();
                }
            }
            //TOMA LOS SIGUIENTES CARACTERES HASTA QUE EL USUARIO TECLEE "ENTER"
            caracter = getch();
        }
        //FINALIZA INCRIPTACIÓN CONTRASEÑA 1.
        cout << endl;
        cout << endl;
        cout << "\tDigite la contrasena nuevamente:" << endl;
        //INICIA EL PROCESO DE ENCRIPTACIÓN DE LA CONTRASEÑA 2.
        char caracter1;
        caracter1 = getch();
        contrasenac1 = "";
        cout << "\t";
        while(caracter1 != 13){
            if(caracter1 != 8){
                contrasenac1.push_back(caracter1);
                cout << "*";
            }
            else{
                if(contrasenac1.length() > 0){
                    cout << "\b \b";
                    contrasenac1 = contrasenac1.substr(0, contrasenac1.length() - 1);
                }
            }
            caracter1 = getch();
        }
        //FINALIZA EL PROCESO DE ENCRIPTACIÓN DE LA CONTRASEÑA 2.
        cout << endl;
        cout << endl;
        //IGNORA LOS SALTOS DE LINEA QUE SE HAN QUEDADO EN EL BUFFER (ESPACIO EN MEMORIA) DE ENTRADA
        cin.ignore();
        cout << "\tDigite el nombre del usuario:" << endl; //EL USUARIO INGRESA SU NOMBRE
        cout << "\t";
        //PERMITE GUARDAR LO QUE EL USUARIO INGRESA INCLUYENDO ESPACIOS
        getline(cin, usuariosr[i].nombre);
        cout << endl;
        cout << "\tDigite el nombre de la carrera a la cual pertenece:" << endl;//EL USUARIO INGRESA SU CARRERA
        cout << "\t";
        //PERMITE GUARDAR LO QUE EL USUARIO INGRESA INCLUYENDO ESPACIOS
        getline(cin, usuariosr[i].carrera);
        cout << endl;
        cout << "\tDigite su genero (F/M):" << endl;//EL USUARIO INGRESA SU GENERO
        cout << "\t";
        cin >> usuariosr[i].genero;
        while(usuariosr[i].genero != 'F' && usuariosr[i].genero != 'M'){
            cout << "\tERROR: Debe ingresar 'F' o 'M'" << endl;
            cout << "\t"; cin >> usuariosr[i].genero;
        }
        cout << endl;
        cout << "\tDigite su fecha de nacimiento (DD/MM/AA):" << endl;//EL USUARIO INGRESA SU FECHA DE NACIMIENTO
        cout << "\t";
        cin >> usuariosr[i].fecha_nacimiento;
        cout << endl;
        bool ingreso = true;
        //CICLO PARA VALIDAR SI LAS 2 CONTRASEÑAS COINCIDEN
        while (usuariosr[i].contrasena != contrasenac1 || ingreso == true){
            //AL SER CORRECTO IMPRIMIRA LOS DATOS Y CONFIRMARA EL REGISTRO
            if(usuariosr[i].contrasena == contrasenac1){
                system("cls");
                cout << "\n\t\tREGISTRO SATISFACTORIO";
                cout << "\n\t\t----------------------" << endl;
                cout << endl;
                //IMPRESION DATOS INGRESADOS
                cout << "\tSUS DATOS DE REGISTRO SON:" << endl;
                cout << "\tUsuario: " << usuariosr[i].usuario << endl;
                cout << "\tContrasena: " << usuariosr[i].contrasena << endl;
                cout << "\tNombre: " << usuariosr[i].nombre << endl;
                cout << "\tCarrera: " << usuariosr[i].carrera << endl;
                cout << "\tGenero: " << usuariosr[i].genero << endl;
                cout << "\tFecha de nacimiento: " << usuariosr[i].fecha_nacimiento << endl;
                cout << endl;
                cout << "\n\tSU USUARIO Y CONTRASENA LE PERMITIRAN ACCEDER AL SISTEMA, NO LO OLVIDE!***" << endl; //**SE LE INFORMA AL USUARIO LA IMPORTANCIA DE LA CONTRASEÑA Y CORREO **
                cout << "\n\t---------------------------------------------------------------------------" << endl;
                cout << endl;
                system("pause");
                //LLAMADO A LA FUNCION PARA INGRESAR AL SISTEMA
                login_usuario(usuariosr,disposi,cantidispoto);
                ingreso = false;
            }
            //AL NO COINCIDIR SE LE PIDE AL USUARIO REINGRESAR LAS CONTRASEÑAS
            //SERÁN SOLICITADAS HASTA QUE AMBAS CONTRASEÑAS COINCIDEN
            else{
                system("cls");
                cout << "\n\t\tLAS CONTRASENAS NO COINCIDEN, INTENTELO NUEVAMENTE**";
                cout << "\n\t\t---------------------------------------------------" << endl;
                cout << endl;
                cout << "\tDigite la contrasena, los datos que digito anteriormente ya están registrados:" << endl;
                cout << "\t";
                cout << "\t";
                cin >> usuariosr[i].contrasena;
                cout << endl;
                cout << "\tDigite la contrasena nuevamente:" << endl;
                cout << "\t";
                cout << "\t";
                cin >> contrasenac1;
                ingreso = true;
                cout <<  endl;
            }
        }
    }
}
//ESTA FUNCION LE PERMITIRA AL USUARIO INGRESAR AL SISTEMA
void login_usuario(registro_usuario usuariosr[], Dispositivo disposi[], int cantidispoto){
    for (int i=0; i < usu ; i++){
        string usuarioc1, contrasenac1;  //VARIABLES PARA EL INGRESO DE USUARIO Y CONTRASEÑA
        int contador = 0;  //CONTADOR QUE LLEVA LA CANTIDAD DE INTENTOS DE INGRESO AL SISTEMA
        bool acceso = false;  //VARIABLE QUE LE DA EL INGRESO AL SISTEMA AL USUARIO
        do{ //CICLO MIENTRAS QUE LOS ERRORES(CONTADOR)SEAN MENORES A 3 Y EL ACCESO SEA FALSO
            system("cls");
            cout << "\t\tINGRESO AL SISTEMA" << endl;
            cout << "\n\t\tLOGIN DE USUARIO";
            cout << "\n\n\t----------------" << endl;
            cout << "\tUsuario:" << endl; //INGRESA EL USUARIO(CORREO) QUE SUSMINISTRO EN EL REGISTRO
            cout << "\t";
            cin >> usuarioc1;
            cout << endl;
            cout << "\tContrasena:" << endl; //INGRESA LA CONTRASEÑA QUE SUMINISTRO EN EL REGISTRO
            //INICIO DE LA ENCRIPTACIÓN DE LA CONTRASEÑA
            char caracter;
            caracter = getch();
            contrasenac1 = "";
            cout << "\t";
            while(caracter != 13){
                if(caracter != 8){
                    contrasenac1.push_back(caracter);
                    cout << "*";
                }
                else{
                    if(contrasenac1.length() > 0){
                        cout << "\b \b";
                        contrasenac1 = contrasenac1.substr(0, contrasenac1.length() - 1);
                    }
                }
                caracter = getch();
            }
            //FINALIZA PROCESO DE ENCRIPTACIÓN DE LA CONTRASEÑA
            //SE VERIFICA QUE EL USUARIO Y CONTRASEÑA SEAN LAS MISMAS QUE SE INGRESARON EN EL REGISTRO
            if (usuarioc1 == usuariosr[i].usuario && contrasenac1 == usuariosr[i].contrasena){
                acceso = true;  //SI ESTO ES CORRECTO PODRA INGRESAR AL SISTEMA
                menu_principal_adm(usuariosr,disposi,cantidispoto);  //LLAMADO A LAS FUNCION QUE MOSTRARA EL MENU
            }
            else{
                contador++;  //AL SER ERRONEO AUMENTA EL CONTADOR
            }
        } while (acceso == false && contador < 3);
        char contrasenaop;  //VARIABLE PARA RESTAURAR CONTRASEÑA
        if (acceso == false){
            cout << endl;
            cout << endl;
            cout << "\tLo sentimos, usted excedió el número de intentos, no puede ingresar. Desea restaurar su contrasena? (S/N)" << endl;
            cout << "\t";
            cin >> contrasenaop;
            if(contrasenaop == 's' || contrasenaop== 'S'){ //SI EL USUARIO DESEA RESTAURAR LA CONTRASEÑA
                bool acceso1 = true; //VALIDAR LAS 2 CONTRASEÑAS CORRECTAS
                string contrac; //VARIABLE CONTRASEÑA RESPALDO
                //CICLO QUE SE EJECUTA MIENTRAS QUE LAS CONTRASEÑAS NO COINCIDAN
                while(usuariosr[i].contrasena != contrac || acceso1 == false){
                    system("cls");
                    cout << "\tDigite la nueva contraseña" << endl; //INGRESO NUEVA CONTRASEÑA
                    //INICIO PROCESO DE ENCRIPTACIÓN DE CONTRASEÑA
                    char caracter;
                    caracter = getch();
                    usuariosr[i].contrasena = "";
                    cout << "\t";
                    while(caracter != 13){
                        if(caracter != 8){
                            usuariosr[i].contrasena.push_back(caracter);
                            cout << "*";
                        }
                        else{
                            if(usuariosr[i].contrasena.length() > 0){
                                cout << "\b \b";
                                usuariosr[i].contrasena = usuariosr[i].contrasena.substr(0, usuariosr[i].contrasena.length() - 1);
                            }
                        }
                        caracter = getch();
                    }
                    //FINALIZA PROCESO DE ENCRIPTACIÓN DE CONTRASEÑA
                    cout << endl;
                    cout << endl;
                    cout << "\tDigite la contrasena nuevamente:" << endl; //INGRESO VERIFICACION CONTRASEÑA
                    //INICIO PROCESO DE ENCRIPTACIÓN DE CONTRASEÑA
                    char caracter1;
                    caracter1 = getch();
                    contrac = "";
                    cout << "\t";
                    while(caracter1 != 13){
                        if(caracter1 != 8){
                            contrac.push_back(caracter1);
                            cout << "*";
                        }
                        else{
                            if(contrac.length() > 0){
                                cout << "\b \b";
                                contrac = contrac.substr(0, contrac.length() - 1);
                            }
                        }
                        caracter1 = getch();
                    }
                    //FINALIZA PROCESO DE ENCRIPTACIÓN DE CONTRASEÑA
                    cout << endl;
                    cout << endl;
                    //SI LAS CONTRASEÑAS COINCIDEN EL USUARIO TENDRAR QUE INICIAR SESION DE NUEVO
                    if(usuariosr[i].contrasena == contrac){
                        cout << "\tSU CONTRASENA HA SIDO ACTUALIZADA DE MANERA EXITOSA" << endl;
                        cout << "\tDEBE INICIAR SESIÓN NUEVAMENTE" << endl;
                        cout << "\tRECUERDE SUS DATOS DE ACCESO**" << endl;
                        cout << "\t------------------------------" << endl;
                        cout << endl;
                        cout << usuariosr[i].usuario << endl;
                        cout << endl;
                        cout << usuariosr[i].contrasena << endl;
                        cout << endl;
                        system("pause");
                        system("cls");
                        login_usuario(usuariosr,disposi,cantidispoto);
                        acceso1 = true;
                    }
                    else{
                        cout << "Las contraseñas ingresadas no coinciden, inténtelo nuevamente" << endl;
                        acceso1 = false;
                    }
                }
            }
            //EN CASO DE NO QUERER RESTAURAR SU CONTRASEÑA, EL PROGRAMA FINALIZARÁ
            else{
                cout << endl;
                cout << "\tEl programa ha finalizado, gracias!" << endl;
                exit(-1);
            }
        }
    }
}
//ESTA FUNCION MOSTRARA EL MENU
void menu_principal_adm(registro_usuario usuariosr[], Dispositivo disposi[], int cantidispoto){
    bool repite = true; //VARIABLE QUE PERMITE QUE SE MUESTRE EL MENU
    int opcion; // VARIABLE INGRESADA POR EL USUARIO DE LA FUNCION QUE DESEA VER
    do{
        system("cls");
        cout << "\t\tBIENVENIDO A LA PLATAFORMA JANA" << endl;
        cout << "\n\t\tMENU DE OPCIONES:";
        cout << "\n\t\t\----------------------" << endl;
        cout << "\t1. Agregar dispositivos" << endl;;
        cout << "\t2. Listar dispositivos" << endl;
        cout << "\t3. Modificar caracteristicas dispositivo" << endl;
        cout << "\t4. Modificar funcionalidades dispositivo"<< endl;
        cout << "\t5. Eliminar dispositivos"<< endl;
        cout << "\t6. Cerrar sesion"<< endl;
        cout << "\t7. Finalizar la ejecución del programa"<< endl;
        cout << endl;
        cout << "\tOPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            //LLAMADO A LA FUNCION QUE AGREGAR DISPOSITIVOS
            cantidispoto = agregar_dispositivos(disposi,cantidispoto);
            break;
        case 2:
            //LLAMADO A LA FUNCION QUE MUESTRA LOS DISPOSITIVOS INGRESADOS
            listar_dispositivos(disposi,cantidispoto);
            break;
        case 3:
            //LLAMADO A LA FUNCION QUE MODIFICA LAS CARACTERISTICAS DE LOS DISPOSITIVOS
            modificar_caracteristicas(disposi,cantidispoto);
            break;
        case 4:
            //LLAMADO A LA FUNCION QUE MODIFICA LAS FUNCIONALIDADES DE LOS DISPOSITIVOS
            modificar_funcionalidad(disposi,cantidispoto);
            break;
        case 5:
            //LLAMADO A LA FUNCION QUE  ELIMINA LOS DISPOSITIVOS
            cantidispoto = eliminar_dispositivo(disposi,cantidispoto);
            break;
        case 6:
            //LLAMADO A LA FUNCION PARA QUE EL USUARIO INGRESE NUEVAMENTE A LA SESION
            login_usuario(usuariosr,disposi,cantidispoto);
            break;
        case 7:
            //OPCION PARA FINALIZAR EL PROGRAMA
            cout << endl;
            cout << "\tEl programa ha finalizado, gracias!" << endl;
            exit(-1);
            break;
        default:
            //EN CASO DE QUE LA OPCION INGRESADA NO EXISTA
            opcion=0;
            cout << "Esta opcion no está disponible, ingrese una opcion disponible" << endl;
            system("pause");
            break;
        }
    }
    while (repite);
}
//ESTA FUNCION LE PERMITIRA AL USUARIO AGREGAR DISPOSITIVOS
int agregar_dispositivos(Dispositivo disposi[], int cantidispoto){
    char valido = 'S' ; //VARIABLE VERIFICADORA DE INGRESO DE DISPOSITIVOS
    system("cls");
    while(valido=='S' || valido =='s'){ //CICLO QUE SE EJECUTARÁ MIENTRAS LA RESPUESTA SEA S
        //GUARDA EL CODIGO DEL DISPOSITIVO. ES EL MISMO QUE EL NÚMERO DEL REGISTRO DEL DISPOSITIVO (CANTIDISPOTO)
        disposi[cantidispoto].codigo = cantidispoto;
        cout << "\n\tFORMULARIO REGISTRO DE DISPOSITIVOS";
        cout << "\n\t-----------------------------------" << endl;
        cout << "\n\tDISPOSITIVOS DISPONIBLES";
        cout << "\n\t------------------------" << endl;
        cout << "\n    *TELEVISION: TV "<< endl;
        cout << "\n    *CERRADURA: CER " << endl;
        cout << "\n    *CORTINA: COR " << endl;
        cout << "\n    *LAMPARAS: LAM " << endl;
        cout << endl;
        cout << "\n\tEscriba las inciales del tipo de dispositivo (Es importante el uso de mayúsculas):" << endl;
        cout << "\t";
        cin >> disposi[cantidispoto].tipo; //EL USUARIO DIGITA QUE TIPO DE DISPOSITIVO REGISTRARÁ
        //SE REALIZARA SI LO INGRESADO NO COINCIDE CON LAS OPCIONES
        //SE REPETIRA HASTA QUE INGRESE UNA OPCION VALIDA
        while(disposi[cantidispoto].tipo != "TV" && disposi[cantidispoto].tipo != "CER" && disposi[cantidispoto].tipo != "COR" && disposi[cantidispoto].tipo != "LAM"){
            cout << "ERROR! El tipo de dispositivo no corresponde!" << endl;
            cout << "\n\tEscriba las inciales del tipo de dispositivo (Es importante el uso de mayúsculas):" << endl;
            cout << "\t";
            cin >> disposi[cantidispoto].tipo;
        }
        cin.ignore();
        cout << "\n\tDigite el nombre del dispositivo:" << endl;//EL USUARIO INGRESA EL NOMBRE DEL DISPOSITIVO
        cout << "\t";
        getline(cin,disposi[cantidispoto].nombre);
        cout << "\n\tDigite la marca del dispositivo:" << endl; //EL USUARIO INGRESA LA MARCA DEL DISPOSITIVO
        cout << "\t"; cin >> disposi[cantidispoto].marca ;
        cout << "\tDigite la ubicacion del dispositivo:" << endl; //EL USUARIO INGRESA LA UBICACION DEL DISPOSITIVO
        cout << "\t"; cin >> disposi[cantidispoto].ubicacion;
        //SI EL USUARIO INGRESA COMO OPCION TV, SE LE SOLICITARAN LOS SIGUIENTES DATOS
        if(disposi[cantidispoto].tipo == "TV"){
            cout << "\n\tDigite el volumen del dispositivo (0-10):" << endl; //EL USUARIO INGRESA EL VOLUMEN DEL DISPOSITIVO
            cout << "\t"; cin >> disposi[cantidispoto].volumen;
            //EL VOLUMEN DEL DISPOSITIVO NO PUEDE SER MENOR A 0 NI SUPERIOR A 10
            //SE REPETIRÁ HASTA QUE INGRESE UN VALOR PERMITIDO
            while(disposi[cantidispoto].volumen < 0 || disposi[cantidispoto].volumen > 10){
                cout << "ERROR! El volúmen debe estar en un rango entre 0 y 10" << endl;
                cout << "\n\tDigite el volumen del dispositivo (0-10):" << endl; //EL USUARIO INGRESA NUEVAMENTE EL VOLUMEN DEL DISPOSITIVO
                cout << "\t"; cin >> disposi[cantidispoto].volumen;
            }
            cout << "\n\tDigite el canal del dispositivo (1-125):" << endl; //EL USUARIO INGRESA EL CANAL DEL DISPOSITIVO
            cout << "\t"; cin >> disposi[cantidispoto].canal;
            //EL CANAL DEL DISPOSITIVO NO PUEDE SER MENOR A 1 NI SUPERIOR A 125
            //SE REPETIRÁ HASTA QUE INGRESE UN VALOR PERMITIDO
            while(disposi[cantidispoto].canal < 1 || disposi[cantidispoto].canal > 125){
                cout << "\n\tERROR! El canal debe estar en un rango entre 1 y 125" << endl;
                cout << "\n\tDigite el canal del dispositivo:" << endl; //EL USUARIO INGRESA NUEVAMENTE EL CANAL DEL DISPOSITIVO
                cout << "\t"; cin >> disposi[cantidispoto].canal;
            }
        }
        else{ //SI LA OPCION ES DIFERENTE A TV EL VOLUMEN Y CANAL SERAN IGUAL A -1
            disposi[cantidispoto].volumen = -1;
            disposi[cantidispoto].canal = -1;
        }
        cout << "\n\tDigite el estado del dispositivo:" << endl; //EL USUARIO INGRESA EL ESTADO DEL DISPOSITIVO
        cout << "\t"; cin >> disposi[cantidispoto].estado ;
        //SI LA OPCION DE DISPOSITIVO ES IGUAL A TV O LAMP PERO LO INGRESADO POR EL USUARIO PARA EL ESTADO ES DIFERENTE A LAS OPCIONES POSIBLES SE LE PIDE VOLVERLO A INGRESAR
        //SE REPETIRÁ HASTA QUE INGRESE UN VALOR PERMITIDO
        while((disposi[cantidispoto].tipo == "TV" || disposi[cantidispoto].tipo == "LAM") && disposi[cantidispoto].estado != "APAGADO" && disposi[cantidispoto].estado != "apagado" && disposi[cantidispoto].estado != "ENCENDIDO" && disposi[cantidispoto].estado != "encendido"){
            cout << "\n\tERROR! El estado debe ser 'Apagado' o 'Encendido'" << endl;
            cout << "\n\tDigite el estado del dispositivo:" << endl; //** EL USUARIO INGRESA NUEVAMENTE EL ESTADO DEL DISPOSITIVO**
            cout << "\t"; cin >> disposi[cantidispoto].estado;
        }
        //SI LA OPCION DE DISPOSITIVO ES IGUAL A CER O COR PERO LO INGRESADO POR EL USUARIO PARA EL ESTADO ES DIFERENTE A LAS OPCIONES POSIBLES SE LE PIDE VOLVERLO A INGRESAR
        //SE REPETIRÁ HASTA QUE INGRESE UN VALOR PERMITIDO
        while((disposi[cantidispoto].tipo == "CER" || disposi[cantidispoto].tipo == "COR") && disposi[cantidispoto].estado != "ABIERTO" && disposi[cantidispoto].estado != "abierto" && disposi[cantidispoto].estado != "CERRADA" && disposi[cantidispoto].estado != "cerrada")        {
            cout << "\n\tERROR! El estado debe ser 'Abierto' o 'Cerrada'" << endl;
            cout << "\n\tDigite el estado del dispositivo:" << endl;//** EL USUARIO INGRESA NUEVAMENTE EL ESTADO DEL DISPOSITIVO**
            cout << "\t"; cin >> disposi[cantidispoto].estado;
        }
        //SI LA OPCION DE DISPOSITIVO ES IGUAL A LAM EL USUARIO INGRESA LA LUMINOSIDAD
        if(disposi[cantidispoto].tipo == "LAM"){
            cout << "\n\tDigite la luminosidad del dispositivo (0-10):" << endl;//EL USUARIO INGRESA LA LUMINOSIDAD DEL DISPOSITIVO**
            cout << "\t"; cin >> disposi[cantidispoto].luminosidad;
            //LA LUMINOSIDAD DEL DISPOSITIVO NO PUEDE SER MENOR A 0 NI SUPERIOR A 10
            //SE REPETIRÁ HASTA QUE INGRESE UN VALOR PERMITIDO
            while(disposi[cantidispoto].luminosidad < 0 || disposi[cantidispoto].luminosidad > 10){
                cout << "\n\tERROR! La luminosidad debe estar en un rango entre 0 y 10" << endl;
                cout << "\n\tDigite la luminosidad del dispositivo:" << endl;
                cout << "\t"; cin >> disposi[cantidispoto].luminosidad;
            }
        }
        //SI LA OPCION ES DIFERENTE A LAM LA LUMINOSIDAD SERA IGUAL A -1
        else {
            disposi[cantidispoto].luminosidad = -1;
        }
        cout << "\tEL DISPOSITIVO SE HA REGISTRADO DE MANERA SATISFACTORIA";
        cout << "\t-------------------------------------------------------" << endl;
        cout << "\t¿Desea ingresar otro dispositivo? (S/N):" << endl; //SE LE PREGUNTA SI DESEA INGRESAR MAS DISPOSITIVOS
        cout << "\t";
        cin >> valido;
        cantidispoto++; //INCREMENTO DE LA CANTIDAD DE DISPOSITIVOS
        system("cls");
    }
    return cantidispoto;
}
//ESTA FUNCION LE PERMITIRA AL USUARIO LISTAR LOS DISPOSITIVOS
void listar_dispositivos(Dispositivo disposi[], int cantidispoto){
    system("cls");
    //SE HARA MIENTRAS QUE EL ITERADOR SEA MENOR A LA CANTIDAD DE DISPOSITIVOS REGISTRADOS
    for(int i=0; i<cantidispoto; i++){
        //IMPRESION DE LOS DISPOSITIVOS
        cout <<"\n\t   DISPOSITIVO "<< disposi[i].codigo + 1 << " **";
        cout <<"\n\t   TIPO  ->  " <<disposi[i].tipo;
        cout <<"\n\t   ------------------" << endl;
        cout <<"\n\t   CARACTERISTICAS:";
        cout << endl;
        cout <<"\n\tNombre  ->  " <<disposi[i].nombre;
        cout <<"\n\tMarca  ->  " <<disposi[i].marca;
        cout <<"\n\tUbicacion  ->  " <<disposi[i].ubicacion << endl;
        cout <<"\n\t   FUNCIONALIDADES:";
        cout << endl;
        //SI EL VOLUMEN DEL DISPOSITIVO ES IGUAL -1 SE IMPRIMIRA N/A
        if(disposi[i].volumen == -1){
            cout <<"\n\tVolumen  ->  N/A";
        }
        //SINO SE IMPRIME LO QUE EL USUARIO REGISTRÓ
        else{
            cout <<"\n\tVolumen  ->  " <<disposi[i].volumen;
        }
        //SI EL CANAL DEL DISPOSITIVO ES IGUAL -1 SE IMPRIMIRA N/A
        if(disposi[i].canal == -1){
            cout <<"\n\tCanal  ->  N/A";
        }
        //SINO SE IMPRIME LO QUE EL USUARIO REGISTRÓ
        else{
            cout <<"\n\tCanal  ->  " <<disposi[i].canal;
        }
        cout <<"\n\tEstado  ->  " <<disposi[i].estado;
        //SI LA LUMINOSIDAD DEL DISPOSITIVO ES IGUAL -1 SE IMPRIMIRA N/A
        if(disposi[i].luminosidad == -1)
        {
            cout <<"\n\tLuminosidad  ->  N/A";
        }
        //SINO SE IMPRIME LO QUE EL USUARIO REGISTRÓ
        else{
            cout <<"\n\tLuminosidad  ->  " <<disposi[i].luminosidad;
        }
        cout << endl;
        cout <<"\n\t---------------------------------------"<< endl;
    }
    system("pause");
}
//ESTA FUNCION LE PERMITIRA AL USUARIO MODIFICAR LAS CARACTERISTICAS DE LOS DISPOSITIVOS INGRESADOS
void modificar_caracteristicas(Dispositivo disposi[], int cantidispoto){
    cout << endl;
    cout << "\n\t**TENGA PRESENTE EL CODIGO DEL DISPOSITIVO A MODIFICAR DE LA SIGUIENTE LISTA" << endl;
    system("pause");
    listar_dispositivos(disposi, cantidispoto); //SE LE PRESENTA LA LISTA DE DISPOSITIVOS DISPONIBLES
    system("cls");
    int caracteristica ; //VARIABLE DE LA OPCION DE CARACTERISTTICA
    int dispositivo; //VARIABLE CODIGO DEL DISPOSITIVO
    cout << endl;
    cout << "\tDIGITE EL CODIGO DEL DISPOSITIVO A MODIFICAR:" << endl; //DIGITA EL CODIGO DEL DISPOSITIVO A MODIFICAR
    cout << endl;
    cout << "\t";
    cout << "CÓDIGO: "; cin >> dispositivo;
    cout << endl;
    cout << "\tDIGITE EL NUMERO DE LA CARACTERISTICA A MODIFICIAR:" << endl; //DIGITA  LA OPCION DE LA CARACTERISTICA DEL DISPOSITIVO A MODIFICAR
    cout << "\t1. Nombre"<< endl;
    cout << "\t2. Marca"<< endl;
    cout << "\t3. Ubicacion"<< endl;
    cout << endl;
    cout << "\t";
    cout << "CARACTERÍSTICA: "; cin >> caracteristica;
    cout << endl;
    //SE REALIZARA MIENTRAS QUE EL ITERADOR SEA MENOR A LA CANTIDAD DE DISPOSITIVOS
    for(int i=0; i<cantidispoto; i++){
        if(dispositivo==i+1){
            //SI LA OPCION ES IGUAL A 1 SE MODIFICARA EL NOMBRE Y SE REMPLAZARA CON EL NUEVO NOMBRE INGRESADO POR EL USUARIO
            if(caracteristica == 1){
                cout << "\tDIGITE EL NOMBRE QUE TENDRA EL DISPOSITIVO:" << endl;
                cout << "\t";
                cin.ignore();
                getline(cin,disposi[i].nombre);
                cout << endl;
                cout << "\tEL NOMBRE DEL DISPOSITIVO HA SIDO MODIFICADO** " << endl;
                cout << "\tLA INFORMACION SE HA ACTUALIZADO: " << endl; //SE ACTUALIZA LA INFORMACION Y SE IMPRIME LA LISTA DE DISPOSITIVOS
                system("pause");
                system("cls");
                listar_dispositivos(disposi, cantidispoto);
            }
            else{
                //SI LA OPCION ES IGUAL A 2 SE MODIFICARA LA MARCA Y SE REMPLAZARA CON LA NUEVA MARCA INGRESADO POR EL USUARIO
                if (caracteristica == 2){
                    cout << "\tDIGITE LA NUEVA MARCA QUE TENDRA EL DISPOSITIVO:" << endl;
                    cout << "\t";
                    cin >> disposi[i].marca;
                    cout << endl;
                    cout << "\tLA MARCA DEL DISPOSITIVO HA SIDO MODIFICADA** " << endl;
                    cout << "\tLA INFORMACION SE HA ACTUALIZADO: " << endl; //SE ACTUALIZA LA INFORMACION Y SE IMPRIME LA LISTA DE DISPOSITIVOS
                    system("pause");
                    system("cls");
                    listar_dispositivos(disposi, cantidispoto);
                }
                else{
                    //SI LA OPCION ES IGUAL A 3 SE MODIFICARA LA UBICACION Y SE REMPLAZARA CON LA NUEVA UBICACION INGRESADO POR EL USUARIO
                    if (caracteristica == 3) {
                        cout << "\tDIGITE LA NUEVA UBICACION QUE TENDRA EL DISPOSITIVO" << endl;
                        cout << "\t";
                        cin >> disposi[i].ubicacion;
                        cout << endl;
                        cout << "\tLA UBICACION DEL DISPOSITIVO HA SIDO MODIFICADA** " << endl;
                        cout << "\tLA INFORMACION SE HA ACTUALIZADO: " << endl; //SE ACTUALIZA LA INFORMACION Y SE IMPRIME LA LISTA DE DISPOSITIVOS
                        system("pause");
                        system("cls");
                        listar_dispositivos(disposi, cantidispoto);
                    }
                    else{
                        cout << "\tEsta opcion no esta disponible. Intentelo nuevamente." << endl;
                        while(caracteristica < 1 || caracteristica > 3){
                            cout << "\tDIGITE EL CODIGO DEL DISPOSITIVO A MODIFICAR:" << endl; //DIGITA EL CODIGO DEL DISPOSITIVO A MODIFICAR
                            cout << endl;
                            cout << "\t";
                            cout << "CÓDIGO: "; cin >> dispositivo;
                            cout << endl;
                            cout << "\tDIGITE EL NUMERO DE LA CARACTERISTICA A MODIFICIAR:" << endl; //DIGITA  LA OPCION DE LA CARACTERISTICA DEL DISPOSITIVO A MODIFICAR
                            cout << "\t1. Nombre"<< endl;
                            cout << "\t2. Marca"<< endl;
                            cout << "\t3. Ubicacion"<< endl;
                            cout << endl;
                            cout << "\t";
                            cout << "CARACTERÍSTICA: "; cin >> caracteristica;
                            cout << endl;
                        }
                    }
                }
            }
        }
    }
}
//ESTA FUNCION LE PERMITIRA AL USUARIO MODIFICAR LAS FUNCIONALIDADES DE LOS DISPOSITIVOS INGRESADOS
void modificar_funcionalidad(Dispositivo disposi[], int cantidispoto){
    cout << endl;
    cout << "\n\t**TENGA PRESENTE EL CODIGO DEL DISPOSITIVO A MODIFICAR DE LA SIGUIENTE LISTA" << endl;
    system("pause");
    listar_dispositivos(disposi, cantidispoto); //SE LE PRESENTA LA LISTA DE DISPOSITIVOS DISPONIBLES
    system("cls");
    int funcionalidad; //** VARIABLE DE LA OPCION DE CARACTERISTTICA
    int dispositivo; // VARIABLE CODIDO DEL DISPOSITIVO
    cout << endl;
    cout << "\tDIGITE EL CODIGO DEL DISPOSITIVO A MODIFICAR:" << endl; //DIGITA EL CODIGO DEL DISPOSITIVO A MODIFICAR
    cout << endl;
    cout << "\t";
    cout << "CODIGO: "; cin >> dispositivo;
    cout << endl;
    cout << "\tDIGITE EL NUMERO DE LA FUNCIONALIDAD A MODIFICAR:" << endl; //DIGITA  LA OPCION DE LA CARACTERISTICA DEL DISPOSITIVO A MODIFICAR
    cout << "\t1. Volumen"<< endl;
    cout << "\t2. Canal"<< endl;
    cout << "\t3. Estado"<< endl;
    cout << "\t4. Luminosidad"<< endl;
    cout << endl;
    cout << "\t";
    cout << "FUNCIONALIDAD: "; cin >> funcionalidad;
    cout << endl;
    //SE REALIZARA MIENTRAS QUE EL ITERADOR SEA MENOR A LA CANTIDAD DE DISPOSITIVOS
    for(int i=0; i<cantidispoto; i++){
        if(dispositivo == i+1){
            //SI LA OPCION ES IGUAL A 1 SE MODIFICARA EL VOLUMEN Y SE REMPLAZARA CON EL NUEVO VOLUMEN INGRESADO POR EL USUARIO
            if(funcionalidad == 1) {
                cout << "\tDIGITE EL VOLUMEN QUE TENDRA EL DISPOSIVITO" << endl;
                cout << "\t";
                cin >> disposi[i].volumen;
                cout << endl;
                cout << "\tEL VOLUMEN DEL DISPOSITIVO HA SIDO MODIFICADO** " << endl;
                cout << "\tLA INFORMACION SE HA ACTUALIZADO " << endl; //SE ACTUALIZA LA INFORMACION Y SE IMPRIME LA LISTA DE DISPOSITIVOS
                system("pause");
                system("cls");
                listar_dispositivos(disposi, cantidispoto);
            }
            else{
                //SI LA OPCION ES IGUAL A 1 SE MODIFICARA EL CANAL Y SE REMPLAZARA CON EL NUEVO CANAL INGRESADO POR EL USUARIO
                if (funcionalidad == 2){
                    cout << "\tDIGITE EL CANAL QUE TENDRA EL DISPOSIVITO" << endl;
                    cout << "\t";
                    cin >> disposi[i].canal;
                    cout << endl;
                    cout << "\tEL CANAL DEL DISPOSITIVO HA SIDO MODIFICADO** " << endl;
                    cout << "\tLA INFORMACION SE HA ACTUALIZADO " << endl; //SE ACTUALIZA LA INFORMACION Y SE IMPRIME LA LISTA DE DISPOSITIVOS
                    system("pause");
                    system("cls");
                    listar_dispositivos(disposi, cantidispoto);
                }
                else{
                    //SI LA OPCION ES IGUAL A 3 SE MODIFICARA EL ESTADO Y SE REMPLAZARA CON EL NUEVO ESTADO INGRESADO POR EL USUARIO
                    if (funcionalidad == 3){
                        cout << "\tDIGITE EL ESTADO QUE TENDRA EL DISPOSIVITO" << endl;
                        cout << "\t";
                        cin >> disposi[i].estado;
                        cout << endl;
                        cout << "\tEL ESTADO DEL DISPOSITIVO HA SIDO MODIFICADO** " << endl;
                        cout << "\tLA INFORMACION SE HA ACTUALIZADO " << endl; //SE ACTUALIZA LA INFORMACION Y SE IMPRIME LA LISTA DE DISPOSITIVOS
                        system("pause");
                        system("cls");
                        listar_dispositivos(disposi, cantidispoto);
                    }
                    else{
                        //SI LA OPCION ES IGUAL A 4 SE MODIFICARA LA LUMINOSIDAD Y SE REMPLAZARA CON LA NUEVA LUMINOSIDAD INGRESADO POR EL USUARIO
                        if(funcionalidad == 4) {
                            cout << "\tDIGITE LA LUMINOSIDAD QUE TENDRA EL DISPOSIVITO" << endl;
                            cout << "\t";
                            cin >> disposi[i].luminosidad;
                            cout << endl;
                            cout << "\tLA LUMINOSIDAD DEL DISPOSITIVO HA SIDO MODIFICADO** " << endl;
                            cout << "\tLA INFORMACION SE HA ACTUALIZADO " << endl; //SE ACTUALIZA LA INFORMACION Y SE IMPRIME LA LISTA DE DISPOSITIVOS
                            system("pause");
                            system("cls");
                            listar_dispositivos(disposi, cantidispoto);
                        }
                        else{
                            cout << "\tEsta opcion no esta disponible. Intentelo nuevamente." << endl;
                            while(funcionalidad < 1 || funcionalidad > 4){
                                 cout << "\tDIGITE EL CODIGO DEL DISPOSITIVO A MODIFICAR:" << endl; //DIGITA EL CODIGO DEL DISPOSITIVO A MODIFICAR
                                cout << endl;
                                cout << "\t";
                                cout << "CODIGO: "; cin >> dispositivo;
                                cout << endl;
                                cout << "\tDIGITE EL NUMERO DE LA FUNCIONALIDAD A MODIFICAR:" << endl; //DIGITA  LA OPCION DE LA CARACTERISTICA DEL DISPOSITIVO A MODIFICAR
                                cout << "\t1. Volumen"<< endl;
                                cout << "\t2. Canal"<< endl;
                                cout << "\t3. Estado"<< endl;
                                cout << "\t4. Luminosidad"<< endl;
                                cout << endl;
                                cout << "\t";
                                cout << "FUNCIONALIDAD: "; cin >> funcionalidad;
                                cout << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
//ESTA FUNCION LE PERMITIRA AL USUARIO ELIMANAR ALGUNO DE LOS DISPOSITIVOS INGRESADOS
int eliminar_dispositivo(Dispositivo disposi[], int cantidispoto){
    system("cls");
    int nume_dispo = 0; //VARIABLE CON EL CODIGO DEL DISPOSITIVO A ELIMINAR
    listar_dispositivos(disposi, cantidispoto);
    cout << "Digite el código del dispositivo que quiere eliminar" << endl;
    cout << "\t";
    cout << "CODIGO: "; cin >> nume_dispo;
    //VERIFICA SI EL CODIGO INGRESADO POR EL USUARIO COINCIDE CON UNO DEL VECTOR DE DISPOSITIVOS
    if(disposi[nume_dispo-1].codigo == nume_dispo -1)
    {
        //SE EMPIEZA A REVISAR DESDE EL CODIGO INGRESADO POR EL USUARIO HASTA LA CANTIDAD TOTAL DE DISPOSITIVOS REGISTRADOS
        for(int j=nume_dispo-1; j < cantidispoto; j++)
        {
            //TODOS LOS DATOS DEL VECTOR DISPOSI EN LA POSICIÓN ACTUAL SE REEMPLAZAN
            //POR LO DATOS DEL MISMO VECTOR DE LA CASILLA INMEDIATAMENTE SIGUIENTE
            disposi[j].codigo = j;
            disposi[j].tipo = disposi[j+1].tipo;
            disposi[j].nombre = disposi[j+1].nombre;
            disposi[j].marca = disposi[j+1].marca;
            disposi[j].ubicacion = disposi[j+1].ubicacion;
            disposi[j].volumen = disposi[j+1].volumen;
            disposi[j].canal = disposi[j+1].canal;
            disposi[j].estado = disposi[j+1].estado;
            disposi[j].luminosidad = disposi[j+1].luminosidad;
        }
        nume_dispo++; //SE AUMENTA LA VARIABLE PARA LOGRAR QUE TODOS LOS DATOS DEL VECTOR SE CORRAN UNA CASILLA
    }
    cantidispoto -- ; //LA CANTIDAD TOTAL DE DISPOSITIVOS REGISTRADOS DISMINUYE EN 1
    cout << "EL DISPOSITIVO HA SIDO ELIMINADO, PUEDE LISTAR LOS DISPOSITIVOS EN EL MENU**" << endl;
    system("pause");
    return cantidispoto;
}
