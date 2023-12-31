#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declaración de variables globales
int cant_p = 0;
char nombres[100][50];
float precios[100];
int cantidad[100];
int produ_ele[100];

// Función para agregar un producto al inventario
void agregarProducto() {
    if (cant_p >= 100) {
        printf("El inventario está lleno\n");
        return;
    }
    printf("Producto %d\n", cant_p+1);

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres[cant_p]);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precios[cant_p]);

    printf("Ingrese la cantidad del producto: ");
    scanf( "%d", &cantidad[cant_p]);
  

    cant_p++;

    printf("Producto agregado con éxito\n");
}

// Función para mostrar todos los productos del inventario
void mostrarInventario() {
    float vent_t=0,venta=0;
    printf("\nInventario de productos disponibles:\n");

    for (int i = 0; i < cant_p; i++) {
      if(cantidad[i]>0){	
        printf("Producto %d:\n", i + 1);
        printf("Nombre: %s\n", nombres[i]);
        printf("Precio: $%.2f\n", precios[i]);
        printf("Cantidad: %d\n", cantidad[i]);
        printf("\n");
      }
    }
    printf("Inventario de productos no disponibles:\n");
    for (int i = 0; i < cant_p; i++) {
        if (produ_ele[i] > 0 || cantidad[i]==0) {
            printf("\nProducto %d:\n", i + 1);
            printf("Nombre: %s\n", nombres[i]);
            printf("Cantidad eliminada: %d\n", produ_ele[i]);
            venta=produ_ele[i]*precios[i];
            printf("El producto %d dio una venta de %.2f\n",i+1,venta);
            printf("\n");
            vent_t+=venta;
        }
    }
  printf("La venta total generada es de %.2f\n",vent_t);
}

void eliminarproducto(){
  if(cant_p<=0){
    printf("No hay productos en el inventario\n");
    return;
  }
  printf("Ingrese el número de producto a eliminar: ");
  int num_produ;
  scanf("%d", &num_produ);

  if (num_produ >= 1 && num_produ <= cant_p) { 
      printf("Ingrese la cantidad a eliminar: ");
      int cant_el;
      scanf("%d", &cant_el);
      if(cant_el>0 && cant_el<=cantidad[num_produ-1]){
        cantidad[num_produ-1]-=cant_el;
        
        produ_ele[num_produ-1]+=cant_el;
        printf("Cantidad eliminada con exito\n");

  } else {
      printf("cantidad a eliminar inválido\n");
  }
  }else{
    printf("producto no encontrado\n");
  }
}

void buscarProducto() {
  char a[10];
  int find=0;
  printf("Que producto gusta buscar: ");
  scanf("%s", &a);
  for (int i = 0; i < 10; i++) {
      if(strcmp(nombres[i],a)==0){
      printf("Producto %d:\n", i + 1);
      printf("Precio: %.2f\n", precios[i]);
      printf("Cantidad: %d\n", cantidad[i]);
      find=1;
      printf("\n");
      break;
      }
  }
  if(find==0){
    printf("\nNo hay producto %s\n",a);
  }
}

int main() {
    int opcion;
    do {
        printf("----------------Electrónica Alambrito-----------");
        printf("\nMenu de accion:\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Sacar producto: \n");
        printf("4. Buscar producto: \n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                mostrarInventario();
                break;
            case 3:
                eliminarproducto();
                break;
            case 4:
              buscarProducto();
              break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}