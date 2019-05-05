#define EMPTY 1
#define BUSY 0

struct
{
    int id;
    char description[40];
} typedef eSector;

struct
{
     int id;
     char name[51];
     char lastName[51];
     float salary;
     int sector;
     int isEmpty;
}typedef eEmployee;

/** \brief desencadena un menu de opciones generico
 *
 * \param [] char mensaje que mostraran las opciones del menu
 * \param int valor menor que puede ingersarse para entrar en un switch del menu
 * \param int valor mayor que puede ingresarse para entrar en un switch del menu
 * \return int valor que ingreso el usuario para entrar a una opcion referida a el mensaje elegido
 *
 */
int employees_optionsMenu(char [], int, int);

/** \brief inicializa el estado de un array de estructuras en -1
 *
 * \param array a inicializar
 * \param tamanio del array
 * \return void
 */
void employees_initEmployees (eEmployee [], int);

/** \brief permite que el usuario cargue una estructura dentro de un array
 *
 * \param tamanio del array de estructuras
 * \param estructura con relacion uno a muchos y foreign key
 * \param tamanio de la estructura relacionada
 * \param primary key del array original
 * \return 1 si guardo, -1 si no se guardo
 *
 */
int employees_addEmployees (eEmployee [], int, eSector [], int, int);

/** \brief busca un espacio vacio en un array de estructuras
 *
 * \param array de estructuras
 * \param tamanio del array
 * \return id del espacio vacio si lo encontro, -1 si no lo encontro
 *
 */
int employees_emptyPlace (eEmployee [], int);

/** \brief permite el ingreso de uno o mas nombres validados
 *
 * \param [] char
 * \param int tamanio maximo que puede ocupar el nombre
 * \param [] char mensaje de ingreso de datos
 * \return void
 *
 */
void employees_inputName(char [], int, char []);

/** \brief permite al usuario elegir si guardar o no los datos ingresados
 *
 * \param mensaje de verificacion
 * \param mensaje de cancelacion
 * \return 1 si guardo, -1 si no guardo
 *
 */
int employees_verifyConformity (char [], char []);

/** \brief permite que el usuario ingrese y elija una estructura con relacion uno a muchos
 *
 * \param [] eSector    array de estructura relacion
 * \param int   tamanio del array de estructura relacion
 * \param eEmployee[]   array de estructuras principal
 * \return eSector sector   elegido por el usuario
 *
 */
eSector sectors_getSector(eSector [], int, eEmployee[]);

/** \brief muestra una lista de arrays de estructuras con los campos guardados en las estructuras que fueron cargadas
 *
 * \param array de estructuras
 * \param tamanio del array de estructuras
 * \param array de estructura relacion uno a muchos
 * \param tamanio del array relacion uno a muchos
 * \return void
 *
 */
void employees_showList (eEmployee [], int, eSector [], int);

/** \brief envia al usuario al submenu de informes
 *
 * \param array de estructuras
 * \param tamanio del array de estructuras
 * \param array de estructuras con relacion uno a muchos
 * \param tamanio del array de estructuras con relacion uno a muchos
 * \param ultimo id cargado para que las subopciones procedan a mostrar datos de estructuras cargadas
 * \return void
 *
 */
void employees_subMenuReports (eEmployee [], int, eSector [], int, int);

/** \brief funcion de programador. Permite pre cargar datos en los arrays de estructuras creadas
 *
 * \param [] eEmployee array de estructuras
 * \param int tamanio equivalente o menor al de los datos escritos, mientras que sea menor que el tamanio del array de estructuras
 * \return void
 *
 */
void employees_hcData(eEmployee [], int);

/** \brief permite al usuario entrar al submenu de modificaciones
 *
 * \param array de estructuras
 * \param tamanio del array de estructuras
 * \param array de estructuras con relacion uno a muchos
 * \param tamanio del array de estructuras con relacion uno a muchos
 * \param menor valor que puede ingresarse como id para encontrar una estructura activa
 * \param mayor valor que puede ingresarse como id para encontrar una estructura activa
 * \return void
 *
 */
void employees_subMenuModify (eEmployee [], int, eSector[], int, int, int);

/** \brief permite encontrar una estructura por primary key
 *
 * \param array de estructuras
 * \param tamanio del array de estructuras
 * \param array relacion uno a muchos
 * \param tamanio del array relacion uno a muchos
 * \param menor valor que puede ingresarse como primary key para encontrar una estructura activa
 * \param mayor valor que puede ingresarse como primary key para encontrar una estructura activa
 * \return el indice del array donde se encuentra el primary key ingresado
 *
 */
int employees_findEmployeeById (eEmployee [], int, eSector [], int, int, int);

/** \brief permite borrar una estructura
 *
 * \param array de estructuras
 * \param tamanio del array de estructuras
 * \param array relacion uno a muchos
 * \param tamanio del array relacion uno a muchos
 * \param menor valor que puede ingresarse como primary key para encontrar una estructura activa
 * \param mayor valor que puede ingresarse como primary key para encontrar una estructura activa
 * \return void
 *
 */
void employees_removeEmployee (eEmployee [], int, eSector [], int, int, int);

/** \brief permite ordenar el array de estructuras por apellido alfabeticamente en forma ascendente
 *
 * \param [] eEmployee array de estructuras
 * \param int tamanio del array de estructuras
 * \param eSector[] array relacion uno a muchos
 * \param int tamanio del array relacion uno a muchos
 * \return void
 *
 */
void employees_sortEmployeesByLastName(eEmployee [], int, eSector[], int);

/** \brief permite mostrar un array de estructuras ordenada segun el array de estructuras con relacion uno a muchos
 *
 * \param [] eEmployee array de estructuras
 * \param int tamanio del array de estructuras
 * \param eSector[] array relacion uno a muchos
 * \param int tamanio del array relacion uno a muchos
 * \return void
 *
 */
void employees_printEmployees(eEmployee [], int, eSector[], int);

/** \brief calcula el valor total de la suma de todos los valores float de un campo float de un array de estructuras y lo muestra
 *
 * \param array de estructuras
 * \param tamanio del array de estructuras
 * \return valor total de la suma de los valores del campo float elegido
 *
 */
float employees_salaryAcum (eEmployee [], int);

/** \brief calcula el valor promedio de un campo float de un array de estructuras y muestra las estructuras cuyos campos sobrepasan el valor
 *
 * \param array de estructuras
 * \param tamanio del array de estructuras
 * \return promedio del campo float del array de estructuras
 *
 */
void employees_averageSalary (eEmployee [], int);
