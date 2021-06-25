#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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
	LinkedList* this;
	this=(LinkedList*)malloc(sizeof(LinkedList));//reservar espacio para el size de un ll
	if(this!=NULL)
	{
		this->size=0;
		this->pFirstNode=NULL;//apunta a nada porque aca empieza y no tengo nada en la lista
	}
	return this;
}



/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)//es un getter que devuelve el size
{
	int returnAux=-1;//si llego a null
	if(this!=NULL)
	{
		returnAux=this->size;//retorno el size de la lista
	}
	return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodeAux=NULL;
    int i;
    int len;

    len=ll_len(this);//verifico la lista

	if(this!=NULL && nodeIndex<len && nodeIndex>=0)// sino viene en null o index>0 y menor size de la lista
													//o el si el indice es mayor o igual que cero
	{

		if(nodeIndex==0)//si es el primero
		{
			pNodeAux=this->pFirstNode;//guardo el primer nodo en el aux
		}
		else
		{
			pNodeAux=this->pFirstNode;//obtengo el primer nodo de la lista
			 for(i=0; i<nodeIndex; i++)//tiewne que llegar al node index
			 {
				 pNodeAux=pNodeAux->pNextNode;//asigno la dir de mem del siguiente al aux
			 }
		}
	}
	return pNodeAux;
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
	Node* pNewNode;
	Node* pNodeAux;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))//siempre corroborar
    {
    	pNewNode=(Node*)malloc(sizeof(Node));//reservo espacio
    	if(pNewNode!=NULL)
    	{
    		pNewNode->pElement=pElement;//asigno la dir al dato

			if(nodeIndex==0)
			{
				pNewNode->pNextNode=this->pFirstNode;// al primer nodo le asigno el primer previo nodo
				this->pFirstNode=pNewNode;//la lista apuntara al nuevo primer nodo.
			}
			else//si no es el primero
			{
				pNodeAux=getNode(this, nodeIndex-1);//obtengo el nodo anterior
				pNewNode->pNextNode=pNodeAux->pNextNode;//y se lo asigno al aux
				pNodeAux->pNextNode=pNewNode;// el nodo anterior queda guardado en el nuevo nodo
			}
			this->size++;//aumenta el size de la lista
			returnAux=0;
    	}

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
    int returnAux=-1;

	if(this!=NULL)
	{
		returnAux=addNode(this, ll_len(this), pElement);//paso la liosta, eñ size y el puntero al elemento que voy a agregar
	}
    return returnAux;
}

//primero preguntar por null this
//tomo el index(tomar ultima poscicion CON FUNCION LEN) que seria del nuevo nodo y lo llamo a addNode()
//adentro de addNode, creamos el nodo(antes valido si la lista esta vacia)
//si esta vacia, creo un nuevo nodo y lo engancho al pFirtNode
//sino esta vacia, tomar el ultimo nodo de la lista y enlazo el nuevo nodo al ultimo, y este nuevo apunta a pElement, y este ultimo nodo apunta a null




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
    Node* node;

    if(this!=NULL && index>=0 && index<=ll_len(this))//verifico que no venga null
    {
    	node=getNode(this, index);//obtengo nodo de la lista
    	if(node!=NULL)
    	{
        	returnAux=node->pElement;//retorno el elemento a ese nodo que tome
    	}
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
    Node* pNodeAux;

    if(this!=NULL && index>=0 && index<=ll_len(this))//verifico que no venga null
    {
    	 pNodeAux=getNode(this, index);//tomo el nodo de la lista al cual le voy a modificar el elemento
    	 if(pNodeAux!=NULL)//verifico que no venga en null
    	 {
    		 pNodeAux->pElement=pElement;//apunto el elemento al puntero a nuevo elemento
    		 returnAux=0;
    	 }
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
    Node* pNodeBaja;

   if(this!=NULL && index>=0 && index<ll_len(this))//verifico que no venga null
   {
	   pNodeBaja=getNode(this, index);//tomo el nodo a eliminar
	   if(index==0)//si es el primero
	   {
		   this->pFirstNode=pNodeBaja->pNextNode;
		   //apunto el primer nodo no al que quiero borrar, sino al siguiente luego de borrar el nodo
	   }
	   else
	   {
		   pNodeBaja=getNode(this, index-1);//tomo el anterior al que quiero borrar
		   this->pFirstNode=pNodeBaja->pNextNode;//engancho el nodo al que le sigue del de baja, es decir el siguiente al que elimine
	   }
	   free(pNodeBaja);//libero el espacio que ocupaba ese nodo
	   this->size--;//decrementa el tamaño de la lista
	   returnAux=0;

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
    int i;
    int len;
    len=ll_len(this);

    if(this!=NULL && len>=0)
    {
    	for(i=0; i<len; i++)//recorro la lista
    	{
    		ll_remove(this, i);//al remove le paso la lista y la poscicion que quiero eliminar
    	}
    	returnAux=0;
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

    if(this!=NULL)
    {
    	ll_clear(this);//vacio la lista
    	free(this);//libero el espacio de mem de la lista

    	returnAux=0;
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
    Node* pNodeAux;
    int i;
    int len;

    len=ll_len(this);

    if(this!=NULL)
    {
    	for (i=0; i<len; i++) //recorro la lista buscando el indice pasado por parametro
    	{
			pNodeAux=getNode(this, i);//tomo el indice del elemento que estoy buscando con el get node
			if(pNodeAux->pElement==pElement)// si encontre el elemneto que buscaba
			{
				returnAux=i;//devuelvo el indice
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
    int len;

    len=ll_len(this);

    if(this!=NULL)
    {
    	if(len>0)//si el size de la lista es mayor que 0
    	{
    		returnAux=0;//no esta vacia
    	}
    	else
    	{
    		returnAux=1;//esta vacia
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
    int len;

    len=ll_len(this);

    if(this!=NULL && index>=0 && index<=len)//verifico
    {
    	addNode(this, index, pElement);
    	//sino hay errores, agrego un elemento, pasandole la poscicion en que quiero agregarlo
    	returnAux=0;
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
    Node* pNode;
    int len;

    len=ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
    	pNode=getNode(this, index);//tomo el elemento que quiero eliminar
    	returnAux=pNode->pElement;//asigno el elemnto al retorno
    	ll_remove(this, index);//lo elimino
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

    if(this!=NULL)
    {
    	ll_indexOf(this, pElement);//busco en la lista por el elemento pasado como parametro
    	if(pElement>0)
    	{
    		returnAux=1;//contiene el elemento
    	}
    	else
    	{
    		returnAux=0;//no contiene el elemento
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
    Node* pNode=NULL;
    int i;
    int verify;

    if(this!=NULL &&this2!=NULL)
    {

    	for(i=0; i<ll_len(this2); i++)//recorro la lista 2
    	{
    		pNode=ll_get(this2, i);//obtengo todos los elemento de la lista 2
    		verify=ll_contains(this, pNode);
    		if(verify!=1)//me fijo si los elemento no estan contenidos en la lista uno
    		{
    			returnAux=0;//la lista no esta contenida
    		}

    	}
    	returnAux=1;
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
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNewNodes;
    int i;

    if(this!=NULL && from >=0 && from<to && to<=ll_len(this))//verificacion
    {
    	cloneArray=ll_newLinkedList();//creo la nueva lista
    	for(i=from; i<to; i++)
    	{
    		pNewNodes=ll_get(this, i);//tomo los elementos que quiero en la new list
    		if(pNewNodes!=NULL)
    		{
        		ll_add(cloneArray, pNewNodes);//agrego los elementos a la lista generada
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
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray=ll_subList(this, 0, ll_len(this));
    	//voy a clonar la lista, desde 0(poscicion inicial) hasta el largo de size de la lista
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    int len;
    Node* pElement1;
    Node* pElement2;
    Node* pElementAux;//puntero al elemento aux

    len=ll_len(this);

    if(this!=NULL && len>0 && pFunc!=NULL && (order==1 || order==0))
    {
		if(order==0)//descendente
		{
			for(i=0; i<len; i++)//recorro la lista
			{
				pElement1=ll_get(this, i); //tomo los elementos de cada poscicion en la lista

				for(j=i+1; j<len; j++)
				{
					pElement2=ll_get(this, j);//recorri nuevamente la lista y tomo los elem de cada poscicion
					if((*pFunc) (pElement1->pElement, pElement2->pElement))// comparo segun criterio de ordenamiento
					{
						pElementAux=pElement1->pElement;
						pElement1->pElement=pElement2->pElement;
						pElement1->pElement=pElement2->pElement;
						//hice el sort descendente
					}
				}

			}

		}
		if(order==1)//ascendente
		{
			for(i=0; i<len; i++)//recorro la lista
			{
				pElement1=ll_get(this, i); //tomo los elementos de cada poscicion en la lista

				for(j=i+1; j<len; j++)
				{
					pElement2=ll_get(this, j);//recorri nuevamente la lista y tomo los elem de cada poscicion
					if((*pFunc) (pElement1->pElement, pElement2->pElement))// comparo segun criterio de ordenamiento
					{
						pElementAux=pElement1->pElement;
						pElement1->pElement=pElement2->pElement;
						pElement1->pElement=pElement2->pElement;
						//hice el sort ascendente
					}
				}

			}
		}
		returnAux=0;
	}

    return returnAux;

}

