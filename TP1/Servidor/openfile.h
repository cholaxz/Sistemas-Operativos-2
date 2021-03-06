#define tam_base 20000
#define tam_char 30
#define tam_line 1024

struct datos{
	char numero[tam_char];/**< Numero de ID de la estacion */
	char estacion[tam_char];/**< Nombre de la estacion */
	char idlocalidad[tam_char];/**< ID Localidad de la estacion */
	char fecha[tam_char];/**< Fecha y hora en que se tomaron los datos */
	char temperatura[tam_char];/**< Temperatura medida */
	char humedad[tam_char];/**< Humedad medida */
 	char rocio[tam_char];/**< Punto de rocio [C]*/
	char precipitacion[tam_char];/**< Precipitacion [mm] */
	char vel_viento[tam_char];/**< Velocidad del viento [Km/h] */
	char dir_viento[tam_char];/**< Direccion del viento */
	char rafaga_max[tam_char];/**< Rafaga maxima [Km/h] */	
	char presion[tam_char];/**< Presion [hPa] */
	char d12[tam_char];/**< Radiacion solar */
	char d13[tam_char];/**< Temperatura Suelo 1 */
	char d14[tam_char];/**< Temperatura Suelo 2 */
	char d15[tam_char];/**< Temperatura Suelo 3 */
	char d16[tam_char];/**< Humedad Suelo 1 */
	char d17[tam_char];/**< Humedad Suelo 2 */
	char d18[tam_char];/**< Humedad Suelo 3 */
	char d19[tam_char];/**< Humedad de Hoja */
	char * punteros[20];/**< Arreglo de punteros a los otros chars. Se utiliza para implementar las funciones */
};



void freememory();
/**
 * @brief Funcion que libera la memoria alocada.
 *
 * 
 */
void openfile();
/**
 * @brief Funcion que arma la base de datos en la memoria de programa, tomandola del archivo csv.
 *
 * 
 */



struct datos * base;/**< Puntero que apunta al comienzo de la base de datos guardada en memoria de la aplicacion */
struct datos nombre_columnas;/**< Estructura que guarda los nombres de las variables */
