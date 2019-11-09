
/**
 * \brief Inicializa un array con un valor
 * \param El array a inicializar
 * \param La capacidad de dicho array
 * \param El valor con el que sera inicializado
*/
void inicializarArray(int elArray[], int capacidad, int valor);

/**
 * \brief Recorre el array en busca de un valor
 * \param El array a recorrer
 * \param La capacidad de dicho array
 * \param El valor que se buscara
 * \return La posicion del array donde hubo ocurrencia o
           -1 si no hubo ocurrencia
*/
int buscarLugarLibre(int elArray[], int capacidad);

/**
 * \brief Busca dentro de un array en base al criterio ingresado
 * \param El array a recorrer
 * \param La capacidad de dicho array
 * \param El valor que se buscara
 * \return La posicion del array donde hubo ocurrencia o
           -1 si no hubo ocurrencia
*/
 int buscarPorCodigo(int elArray[], int capacidad, int criterio);

 /**
 * \brief Ordena en base a un criterio, si este es igual, en base a otro
 * \param El array a recorrer
 * \param La capacidad de dicho array
*/
 void ordenarPorCriterio(int elArray[], int capacidad);

 /**
 * \brief Carga el array con datos
 * \param El array a recorrer
 * \param La posicion a setear
 * \param Un int a copiar
 * \param Un char/string a copiar
 //Pueden agregarse mas parametros de ser necesario
*/
 void cargarArray(int elArray[], int posicion, int criterioAux, char criterioStringAux[]);

 /**
 * \brief Muestra una serie de datos de un array
 * \param El array a mostrar
 * \param La capacidad de dicho array
*/
 void mostrarArray (int elArray[], int capacidad);
