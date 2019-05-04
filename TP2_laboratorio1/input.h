/** \brief pide el ingreso de un numero
 *
 * \param [] char mensaje que se mostrara para pedir el ingreso
 * \return numero ingresado
 *
 */
int getInt(char []);


/** \brief pide el ingreso de un numero flotante
 *
 * \param [] char mensaje que se mostrara para pedir el ingreso
 * \return float numero ingresado
 *
 */
float getFloat(char []);


/** \brief pide el ingreso de un caracter
 *
 * \param [] char mensaje que se mostrara para pedir el caracter
 * \return char caracter ingresado
 *
 */
char getChar(char []);


/** \brief pide el ingreso de una cadena de caracteres
 *
 * \param [] char mensaje que se mostrara para pedir la cadena de caracteres
 * \param [] char array de cadena de caracteres donde se guardara la cadena ingresada
 * \return void
 *
 */
void getString(char  [], char []);


/** \brief pide al sistema un numero random
 *
 * \param int menor valor en el que puede convertirse
 * \param int mayor valor en el que puede convertirse
 * \param int flag en 1 para inicializar
 * \return int numero random
 *
 */
int getRandomNumber(int , int , int);


/** \brief pide al usuario una cadena de caracteres verificando que los caracteres sean todos letras o espacios
 *
 * \param [] char  mensaje que se mostrara para pedir la cadena de solo letras y espacios
 * \param [] char  array de cadena de caracteres donde se guardara lo ingresado
 * \return int bandera que permite ver si se cargo (era solo letras y espacios)
 *
 */
int getStringJustLetters(char [], char []);


/** \brief pide al usuario un numero flotante como cadena de caracteres verificando que sea flotante
 *
 * \param char[] mensaje que se mostrara para pedir el numero flotante
 * \param char[] array de cadena de caracteres donde se guardara el numero flotante
 * \return int bandera que permite ver si se cargo (era flotante)
 *
 */
int getStringFloatNumber(char[], char[]);


/** \brief pide al usuario un numero como cadena de caracteres verificando que sea solo numerico
 *
 * \param [] char mensaje que se mostrara para pedir el numero
 * \param char[] array de cadena de caracteres donde se guardara el numero
 * \return int bandera que permite ver si se cargo (era solo numeros)
 *
 */
int getStringNumbers(char [], char[]);


/** \brief pide al usuario que ingrese un sexo verificando que sea f o m, para luego pasarlo a mayusculas
 *
 * \param char caracter donde se guardara el sexo ingresado por el usuario
 * \return void
 *
 */
void getSex(char);

/** \brief pide al usuario que se ingrese un numero como cadena de caracteres, valida  que sea solo numero, maximos y minimos, y lo devuelve como int
 *
 * \param [] char mensaje para pedir al usuario el ingreso del numero
 * \param int valor minimo que se puede ingresar
 * \param int valor maximo que se puede ingresar
 * \return int devuelve el numero
 *
 */
int getValidInt(char [], int, int);


/** \brief pide al usuario que ingrese una cadena de caracteres, valida largo, valida que sea solo letras y espacios
 *
 * \param mensaje para pedir el ingreso de la cadena de caracteres
 * \param array de cadena de caracteres donde se guardara lo ingresado por el usuario
 * \param tamanio maximo que podra tener la cadena de caracteres
 * \return void
 *
 */
void getValidString (char [], char [], int);


/** \brief pide al usuario que ingrese un numero flotante, valida largo, valida que sea solo numeros y puntos
 *
 * \param  char mensaje para pedir el ingreso del numero flotante
 * \param  float valor minimo que podra tener el numero ingresado
 * \param float valor maximo que podra tener el numero ingresado
 * \return float el numero flotante ingresado
 *
 */
float getValidFloat(char [], float, float);

/** \brief pide al usuario un sexo validado
 *
 * \param char caracter donde se guardara el sexo ingresado
 * \return void
 *
 */
void getValidSex(char);
