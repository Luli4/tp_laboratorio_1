#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this; ///declaro un putnero a linked list
    this = (LinkedList *)malloc(sizeof(LinkedList));///le asigno memoria dinamica al linked list
    if(this != NULL)///evaluo que se haya podido asignar la memoria
    {
        this->size=0;///seteo size en 0 porque no posee nodos
        this->pFirstNode = NULL;///seteo primer nodo en null ya que no posee primer nodo
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)///me fijo que el linked list no sea nulo
    {
        returnAux = this->size;///guardo en el retorno el tamanio del linkedlist
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;///declaro un puntero a nodo auxiliar
    int i;

    if (nodeIndex>=0)///me fijo que el indice pasado como parametro sea mayor o igual a 0
    {
        if (nodeIndex < ll_len(this))///me fijo que el indice pasado como parametro sea menor al tamanio del linked list
        {
            if (this != NULL);///me fijo que el linked list no sea nulo
            {
                pNode = this->pFirstNode;///guardo en un nodo auxiliar el primer nodo del linked list

                for (i=0; i<ll_len(this); i++)///recorro el linked list
                {
                    if ( i == nodeIndex)///si el indice del for es relativo al indice pasado como parametro
                    {
                        break;///salgo del for
                    }
                    pNode = pNode->pNextNode;///el nodo auxiliar pasa a ser el siguiente nodo del linked list
                }
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode = (Node*) malloc (sizeof(Node));///declaro un puntero a nodo auxiliar (que se agregara) y le asigno memoria dinamica
    Node* pLeftNode = NULL;///declaro un puntero a nodo auxiliar que estara a la izquieda del nodo que se agregara

    if (this != NULL && nodeIndex<=ll_len(this) && nodeIndex>=0)///me fijo que el linked list no sea nulo, y que el indice
        ///se encuentre dentro del rango del linked list
    {
        pNode->pElement = pElement;///guardo el elemento en el nodo auxiliar

        if (nodeIndex == 0)///si el indice pasado es 0
        {
            pNode->pNextNode = this->pFirstNode;///guardo el primer nodo en el nodo auxiliar que se agregara
            this->pFirstNode = pNode;///apunto el primer elemento al nodo auxiliar que se agregara
        }
        else if (nodeIndex>0 && nodeIndex<ll_len(this))///si el indice pasado es mayora a 0 pero menor al ultimo
        {
            pLeftNode = getNode(this, nodeIndex-1);///pido de linked list el nodo aux que se encontrara a la izquierda del nuevo nodo
            pNode->pNextNode = pLeftNode->pNextNode;///el nodo siguiente del nodo a agregar, sera al que apuntaba previamente el nodo
            ///que pasara a estar a la izquierda
            pLeftNode->pNextNode = pNode;///el nodo que esta a la izquierda pasa a apuntar al nuevo nodo
        }
        else///si se desea agregar el nodo al final de la lista
        {
            pLeftNode = getNode(this, nodeIndex-1);///pido el nodo que se encontrara a la izquierda del nuevo nodo
            pLeftNode->pNextNode = pNode;///hago que apunte al nodo que se agregara
            pNode->pNextNode = NULL;///el nodo agregado apunta a null, ya que es el ultimo del linked list
        }
        this->size++;///aumento el tamanio de la lista
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if (this != NULL)///verifico que la lista pasada como parametro no sea nula
    {
        addNode(this, ll_len(this), pElement);///llamo a la funcion add node con el ultimo index para que se agregue al final
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;///declaro un puntero a nodo auxiliar

    if (this != NULL && index>=0 && index<ll_len(this))///verifico que el linked listpasado no sea nulo y que el index se encuentre
    ///dentro del rango de la lista
    {
        pNode = getNode(this, index);///pido un nodo con otra funcion y le paso el index del parametro
        returnAux = pNode->pElement;///guardo en el return el elemento del nodo conseguido con getnode
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;///declaro un puntero a nodo auxiliar

    if (this != NULL && index>=0 && index<ll_len(this))///verifico que el linked list no sea nulo y que el index pasado este dentro
        ///del rango del linked list
    {
        pNode = getNode(this, index);///consigo un nodo con getnode
        pNode->pElement = pElement;///cambio el elemento del nodo conseguido
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;///declaro un puntero a nodo auxiliar
    Node* pLeftNode = NULL;///declaro un puntero al nodo anterior al que voy a eliminar

    if (this != NULL && index >= 0 && index < ll_len(this))///verifica que la lista pasada no sea nula y que el indice se encuentre
        ///dentro del rango disponible del linked list
    {
        if (index == 0)///si el indice pasado es 0
        {
            pNode = this->pFirstNode;///pnode pasa a apuntar a la direccion de memoria del primer nodo
            this->pFirstNode = pNode->pNextNode;///el primer nodo pasa a apuntar a la direccion de memoria del que sigue al nodo
    ///que tome
        }
        else if (index>=0 && index<ll_len(this))///si el indice es mayor a 0 y menor al size del linked list
        {
            pNode = getNode(this, index);///pnode toma la direccion de memoria del nodo del indice pasado
            pLeftNode = getNode(this, index-1);///pido la direccion de memoria del nodo a su izquierda
            pLeftNode->pNextNode = pNode->pNextNode;///el nodo a su izquierda pasa a apuntar al siguiente nodo
        }
        else///si el indice pasado es el ultimo del linked list
        {
            pLeftNode = getNode(this, ll_len(this)-1);///pido el nodo a la izquierda del indice
            pLeftNode->pNextNode = NULL;///el nodo a la izquierda pasa a apuntar a NULL
        }
        free(pNode);///libero al memoria del nodo que saque
        this->size--;///disminuyo el tamanio del linked list
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)///verifico que la lista no sea nula
    {
        int i;
        for (i = 0; i < ll_len(this); i++)///recorro la lista
        {
            ll_remove(this, i);///elimino el nodo
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)///verifico que la lista pasada no sea nula
    {
        ll_clear(this);///elimino todos los nodos de la lista
        free(this);///libero la memoria del linked list
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pAuxElement = NULL;///puntero a auxiliar de elemento

    if (this != NULL)///verifico que la lista pasada no sea nula
    {
        int i;
        for (i=0; i<ll_len(this); i++)///recorro toda la lista
        {
            pAuxElement = ll_get(this, i);///guardo el elemento de la posicion i en el auxiliar

            if (pAuxElement == pElement)///si el auxiliar es igual al elemento pasado como parametro
            {
                returnAux = i;///retorno el indice
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)///verifica que la lista pasada no sea nula
    {
        returnAux = 1;

        if (this->size != 0)///verifica que el tamanio sea distinto a 0
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this != NULL && index >= 0 && index <= ll_len(this))///verifica que la lista no sa nula, y que el indice este dentro del rango
        ///del linked list
    {
        if (addNode(this, index, pElement) == 0)///agrega un nodo en la posicion pasada como parametro
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if (this != NULL && index >= 0 && index < ll_len(this))///verifica que la lista no sea nula y que el indice este dentro del rango
        ///del linked list
    {
        returnAux = ll_get(this, index);///guardo la direccion de memoria en el retorno auxiliar
        ll_remove(this, index);///remuevo el nodo con el indice pasado como parametro
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pAuxElement = NULL;///puntero a elemento auxiliar

    if (this != NULL)///verifico que la lista pasada no sea nula
    {
        returnAux = 0;
        int i;
        for (i=0; i < ll_len(this); i++)///recorro la lista
        {
            pAuxElement = ll_get(this, i);///guardo el elemento del indice pasado en el auxiliar
            if (pAuxElement == pElement)///si el elemento guardado es igual al pasado como parametro
            {
                returnAux = 1;
                break;///salgo del for
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pAuxElement = NULL;///puntero a elemento auxiliar

    if (this != NULL && this2 != NULL)///verifico que las listas no sean nulas
    {
        returnAux = 1;
        int i;
        for (i=0; i < ll_len(this2); i++)///recorro la lista 2
        {
            pAuxElement = ll_get(this2, i);///guardo en el auxiliar el elemento i de this2
            if (ll_contains(this, pAuxElement) == 0)///verifico que el elemento i de this2 este en la lista this
            {
                returnAux = 0;///si no esta, guarda el retorno
                break;///sale del for
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                                *-*
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;///creo un puntero a la lista que clonara
    void* pElement = NULL;///creo un puntero a elemento auxiliar

    if (this != NULL && from >= 0 && from <= ll_len(this))///verifico que la lista pasada como parametro no sea nula y que el rango
///de from sea valido (este dentro del linked list original)
    {
        if (to <= ll_len(this) && to >= from)///verifico que el rango de to sea valido y este dentro del linked list original
        {
            cloneArray = ll_newLinkedList();///le asigno memoria dinamica a la lista que se clonara

            int i;
            for (i = from ; i < to ; i++)///recorro la lista desde y hasta los parametros pasados
            {
                pElement = ll_get(this, i);///guardo el elemento de indice i en un auxiliar
                addNode(cloneArray, i, pElement);///agrego el nodo con el elemento i a la lista clon
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;///creo una puntero a lista clon
    if (this != NULL)///verifico que la lista pasada como parametro no sea nula
    {
        cloneArray = ll_subList(this, 0, ll_len(this));///llamo a la funcion que clonara desde el index 0 hasta el tamanio de this
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAuxElement = NULL;///declaro un elemento aux
    void* pElement1 = NULL;///declaro un elemento 1
    void* pElement2 = NULL;///declaro un elemento 2
    int swapAux = -1;///declaro un int que guardara el retorno de pfunc


    if (this != NULL && pFunc != NULL && (order == 0 || order == 1))///verifica que la lista pasada no sea nula, que pfunc no sea nulo
        ///y que el orden sea valido
    {
        int i, j;
        for (i = 0 ; i < ll_len(this)-1 ; i++)///recorro la lista con bubblesort
        {
            pElement1 = ll_get(this, i);///consigo el elemento i de la lista

            for (j = i + 1 ; j < ll_len(this) ; j++)///recorro la lista con bubblesort
            {
                pElement2 = ll_get(this, j);///consigo el elemento j de la lista

                swapAux = pFunc(pElement1, pElement2);///guardo el retorno del criterio de ordenamiento

                if (order == 1)///si se ordena de forma ascendente
                {
                    if (swapAux == 1)///si la funcion retorna 1
                    {
                        pAuxElement = pElement1;///hago el swap
                        pElement1 = pElement2;
                        pElement2 = pAuxElement;
                    }
                }
                if (order == 0) ///si se ordena de forma descendente
                {
                    if (swapAux == -1)///si la funcion retorna -1
                    {
                        pAuxElement = pElement2;///hago el swap
                        pElement2 = pElement1;
                        pElement1 = pAuxElement;
                    }
                }
                ll_set(this, i, pElement1);///seteo el elemento en la lista
                ll_set(this, j, pElement2);///seteo el elemento en la lista
            }
        }
        returnAux = 0;
    }
    return returnAux;
}
