// System.h
#include "../../../include/system/Sistema.h"
#include "../../../include/classes/Comentario.h"

/* Este caso de uso se utiliza para inicializar el sistema con valores para poder realizar las pruebas de los casos de uso. */

void Sistema::cargarDatos()
{
    // Obtengo Controladores
    Fabrica *fabrica = Fabrica::getInstancia();
    IUsuario *controlUsuario = fabrica->getIUsuario();
    IProducto *controlProducto = fabrica->getIProducto();
    IPromocion *controlPromocion = fabrica->getIPromocion();
    ICompra *controlCompra = fabrica->getICompra();
    IComentario *controlComentario = fabrica->getIComentario();
    FechaSistema *fechaSistema = FechaSistema::getInstance();

    print("--------------------- Cargar Datos Prueba ---------------------");
    saltoConsola();

    int vendedor = getInputInt("Desea ingresar 5 vendedores? No-0 , Si-1 : ");
    if (vendedor == 1)
{
        // Crear Vendedores 5
        controlUsuario->crearVendedor("ana23", "qwer1234", DataFecha(15, 5, 1988), "212345678001");
        controlUsuario->crearVendedor("carlos78", "asdfghj", DataFecha(18, 6, 1986), "356789012345");
        controlUsuario->crearVendedor("diegom", "zxcvbn", DataFecha(28, 7, 1993), "190123456789");
        controlUsuario->crearVendedor("maria01", "5tgb6yhn", DataFecha(25, 3, 1985), "321098765432");
        controlUsuario->crearVendedor("sofia25", "1234asdf", DataFecha(7, 12, 1983), "445678901234");
        print("Se crean 5 vendedores.");
    }

    saltoConsola();

    int cliente = getInputInt("Desea ingresar 5 clientes? No-0 , Si-1 : ");
    if (cliente == 1) {
        // Crear Clientes 5
        controlUsuario->crearCliente("juan87", "1qaz2wsx", DataFecha(20, 10, 1992), "Av.18 de Julio", 456, "Melo");
        controlUsuario->crearCliente("laura", "3edc4rfv", DataFecha(22, 9, 1979), "Rondeau", 1617, "Montevideo");
        controlUsuario->crearCliente("natalia", "poiuyt", DataFecha(14, 4, 1982), "Paysandu", 2021, "Salto");
        controlUsuario->crearCliente("pablo10", "lkjhgv", DataFecha(30, 11, 1995), "Av. Rivera", 1819, "Mercedes");
        controlUsuario->crearCliente("roberto", "mnbvcx", DataFecha(12, 8, 1990), "Av. Brasil", 1011, "Montevideo");
        print("Se crean 5 clientes.");
    }

    saltoConsola();

    int productos = getInputInt("Desea ingresar 5 productos? No-0 , Si-1 : ");
    if (productos == 1) {
        // Crear Productos 15
        controlProducto->seleccionarVendedor("carlos78");
        controlProducto->crearProducto("Camiseta Azul", 1400, 50, "Camiseta de poliester, color azul", ropa);

        controlProducto->seleccionarVendedor("ana23");
        controlProducto->crearProducto("Televisor LED", 40500, 30, "Televisor LED 55 pulgadas", electrodomestico);

        controlProducto->seleccionarVendedor("carlos78");
        controlProducto->crearProducto("Chaqueta de Cuero", 699.99, 20, "Chaqueta de cuero, color negro", ropa);

        controlProducto->seleccionarVendedor("ana23");
        controlProducto->crearProducto("Microondas Digital", 1199.99, 15, "Microondas digital, 30L", electrodomestico);

        controlProducto->seleccionarVendedor("diegom");
        controlProducto->crearProducto("Luz LED", 599.99, 40, "Luz Bluetooth LED", otros);

        controlProducto->seleccionarVendedor("carlos78");
        controlProducto->crearProducto("Pantalones Vaqueros", 60, 25, "Pantalones vaqueros, talla 32", ropa);

        controlProducto->seleccionarVendedor("diegom");
        controlProducto->crearProducto("Auriculares Bluetooth", 199.99, 35, "Auriculares bluethooth para celular", otros);

        controlProducto->seleccionarVendedor("ana23");
        controlProducto->crearProducto("Refrigerador", 15499, 10, "Refrigerador de doble puerta", electrodomestico);

        controlProducto->seleccionarVendedor("ana23");
        controlProducto->crearProducto("Cafetera", 23000, 50, "Cafetera de goteo programable", electrodomestico);

        controlProducto->seleccionarVendedor("carlos78");
        controlProducto->crearProducto("Zapatillas Deportivas", 5500, 20, "Zapatillas para correr, talla 42", ropa);

        controlProducto->seleccionarVendedor("carlos78");
        controlProducto->crearProducto("Mochila", 9000, 30, "Mochila de viaje, 40L", otros);

        controlProducto->seleccionarVendedor("diegom");
        controlProducto->crearProducto("Plancha de Ropa", 2534, 25, "Plancha a vapor, 1500W", electrodomestico);

        controlProducto->seleccionarVendedor("sofia25");
        controlProducto->crearProducto("Gorra", 200, 50, "Gorra para deportes, color rojo", ropa);

        controlProducto->seleccionarVendedor("diegom");
        controlProducto->crearProducto("Tablet", 15000, 15, "Tablet Android de 10 pulgadas", electrodomestico);

        controlProducto->seleccionarVendedor("sofia25");
        controlProducto->crearProducto("Reloj de Pared", 150.50, 20, "Reloj de pared vintage", otros);
        print("Se crean 15 productos.");
    }

    saltoConsola();

    int promociones = getInputInt("Desea ingresar 4 promociones? No-0 , Si-1 : ");
    if (promociones == 1)
    {
        // Crear Promociones 4
        controlPromocion->ingresarPromocion("Casa Nueva", "Para que puedas ahorrar en la casa nueva", 30, DataFecha(25, 10, 2024));
        controlPromocion->seleccionarVendedor("ana23");
        controlPromocion->agregarProducto(2, 1);
        controlPromocion->agregarProducto(4, 1);
        controlPromocion->agregarProducto(8, 1);
        controlPromocion->darAltaPromocion();

        controlPromocion->ingresarPromocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", 20, DataFecha(26, 10, 2024));
        controlPromocion->seleccionarVendedor("carlos78");
        controlPromocion->agregarProducto(3, 2);
        controlPromocion->agregarProducto(6, 3);
        controlPromocion->darAltaPromocion();

        controlPromocion->ingresarPromocion("Domotica", "Para modernizar tu casa", 10, DataFecha(26, 10, 2024));
        controlPromocion->seleccionarVendedor("diegom");
        controlPromocion->agregarProducto(5, 2);
        controlPromocion->darAltaPromocion();

        controlPromocion->ingresarPromocion("Liquidacion", "Hasta agotar stock", 10, DataFecha(26, 3, 2024));
        controlPromocion->seleccionarVendedor("diegom");
        controlPromocion->agregarProducto(14, 1);
        controlPromocion->darAltaPromocion();
        print("Se crean 4 promociones");
    }

    saltoConsola();

    int compras = getInputInt("Desea ingresar 9 compras? No-0 , Si-1 : ");
    if (compras == 1) {
        // Crear Compras 9
        fechaSistema->setearFechaSistema(DataFecha(1, 5, 2024));
        controlCompra->seleccionarCliente("juan87");
        controlCompra->agregarProductoCompra(2, 2);
        controlCompra->agregarProductoCompra(4, 1);
        controlCompra->agregarProductoCompra(8, 1);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();

        fechaSistema->setearFechaSistema(DataFecha(1, 5, 2024));
        controlCompra->seleccionarCliente("juan87");
        controlCompra->agregarProductoCompra(5, 1);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();

        fechaSistema->setearFechaSistema(DataFecha(15, 5, 2024));
        controlCompra->seleccionarCliente("laura");
        controlCompra->agregarProductoCompra(14, 10);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();

        fechaSistema->setearFechaSistema(DataFecha(25, 4, 2024));
        controlCompra->seleccionarCliente("natalia");
        controlCompra->agregarProductoCompra(11, 1);
        controlCompra->agregarProductoCompra(12, 1);
        controlCompra->agregarProductoCompra(13, 1);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();

        fechaSistema->setearFechaSistema(DataFecha(20, 5, 2024));
        controlCompra->seleccionarCliente("juan87");
        controlCompra->agregarProductoCompra(3, 2);
        controlCompra->agregarProductoCompra(6, 3);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();

        fechaSistema->setearFechaSistema(DataFecha(12, 5, 2024));
        controlCompra->seleccionarCliente("laura");
        controlCompra->agregarProductoCompra(1, 2);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();

        fechaSistema->setearFechaSistema(DataFecha(13, 5, 2024));
        controlCompra->seleccionarCliente("natalia");
        controlCompra->agregarProductoCompra(1, 3);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();

        fechaSistema->setearFechaSistema(DataFecha(14, 5, 2024));
        controlCompra->seleccionarCliente("pablo10");
        controlCompra->agregarProductoCompra(1, 4);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();

        fechaSistema->setearFechaSistema(DataFecha(15, 5, 2024));
        controlCompra->seleccionarCliente("roberto");
        controlCompra->agregarProductoCompra(1, 5);
        controlCompra->mostrarCompra();
        controlCompra->confirmarCompra();
        print("Se crean 9 compras.");
    }

    saltoConsola();
    // Crear Comentarios
    int comentarios = getInputInt("Desea ingresar 25 comentarios? No-0 , Si-1 : ");
    if (comentarios == 1) {
        Producto *prod1 = controlProducto->obtenerProducto(1);
        map<int, Comentario *> comentarios1 = prod1->getComentarios();

        Producto *prod2 = controlProducto->obtenerProducto(2);
        map<int, Comentario *> comentarios2 = prod2->getComentarios();

        Producto *prod3 = controlProducto->obtenerProducto(3);
        map<int, Comentario *> comentarios3 = prod3->getComentarios();

        Producto *prod4 = controlProducto->obtenerProducto(4);
        map<int, Comentario *> comentarios4 = prod4->getComentarios();

        Producto *prod5 = controlProducto->obtenerProducto(5);
        map<int, Comentario *> comentarios5 = prod5->getComentarios();

        controlComentario->seleccionarUsuario("juan87");
        controlComentario->seleccionarProducto(prod1->getCode());
        controlComentario->nuevoComentario("¿La camiseta azul esta disponible en talla M?", DataFecha(1, 6, 2024));

        controlComentario->seleccionarUsuario("carlos78");
        controlComentario->seleccionarProducto(prod1->getCode());
        comentarios1 = prod1->getComentarios();
        int com = (comentarios1.find(2)->first);
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("Si, tenemos la camiseta azul en talla M.", DataFecha(1, 6, 2024));

        controlComentario->seleccionarUsuario("laura");
        controlComentario->seleccionarProducto(prod1->getCode());
        comentarios1 = prod1->getComentarios();
        com = (comentarios1.find(2)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("¿Es de buen material? Me preocupa la durabilidad.", DataFecha(2, 6, 2024));

        controlComentario->seleccionarUsuario("juan87");
        controlComentario->seleccionarProducto(prod1->getCode());
        comentarios1 = prod1->getComentarios();
        com = (comentarios1.find(2)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("He comprado antes y la calidad es buena", DataFecha(2, 6, 2024));

        controlComentario->seleccionarUsuario("natalia");
        controlComentario->seleccionarProducto(prod1->getCode());
        controlComentario->nuevoComentario("¿Como es el ajuste? ¿Es ajustada o holgada?", DataFecha(2, 6, 2024));

        controlComentario->seleccionarUsuario("laura");
        controlComentario->seleccionarProducto(prod2->getCode());
        controlComentario->nuevoComentario("¿Cual es la resolucion del TelevisorLED?", DataFecha(2, 6, 2024));

        controlComentario->seleccionarUsuario("ana23");
        controlComentario->seleccionarProducto(prod2->getCode());
        comentarios2 = prod2->getComentarios();
        com = (comentarios2.find(6)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("El televisor LED tiene una resolucion de 4K UHD.", DataFecha(2, 6, 2024));

        controlComentario->seleccionarUsuario("pablo10");
        controlComentario->seleccionarProducto(prod2->getCode());
        controlComentario->nuevoComentario("¿Tiene soporte para HDR10?", DataFecha(3, 6, 2024));

        controlComentario->seleccionarUsuario("ana23");
        controlComentario->seleccionarProducto(prod2->getCode());
        comentarios2 = prod2->getComentarios();
        com = (comentarios2.find(8)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("Si, soporta HDR10.", DataFecha(3, 6, 2024));

        controlComentario->seleccionarUsuario("natalia");
        controlComentario->seleccionarProducto(prod3->getCode());
        controlComentario->nuevoComentario("¿La chaqueta de cuero es resistente al agua?", DataFecha(3, 6, 2024));

        controlComentario->seleccionarUsuario("carlos78");
        controlComentario->seleccionarProducto(prod3->getCode());
        comentarios3 = prod3->getComentarios();
        com = (comentarios3.find(10)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("No, la chaqueta de cuero no es resistente al agua.", DataFecha(3, 6, 2024));

        controlComentario->seleccionarUsuario("laura");
        controlComentario->seleccionarProducto(prod3->getCode());
        comentarios3 = prod3->getComentarios();
        com = (comentarios3.find(10)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("¿Viene en otros colores?", DataFecha(4, 6, 2024));

        controlComentario->seleccionarUsuario("carlos78");
        controlComentario->seleccionarProducto(prod3->getCode());
        comentarios3 = prod3->getComentarios();
        com = (comentarios3.find(12)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("Si, tambien esta disponible en marron.", DataFecha(4, 6, 2024));

        controlComentario->seleccionarUsuario("roberto");
        controlComentario->seleccionarProducto(prod3->getCode());
        comentarios3 = prod3->getComentarios();
        com = (comentarios3.find(10)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("¿Es adecuada para climas frios? ", DataFecha(4, 6, 2024));

        controlComentario->seleccionarUsuario("pablo10");
        controlComentario->seleccionarProducto(prod4->getCode());
        controlComentario->nuevoComentario("¿El microondas digital tiene funcion de descongelacion rapida?", DataFecha(4, 6, 2024));

        controlComentario->seleccionarUsuario("ana23");
        controlComentario->seleccionarProducto(prod4->getCode());
        comentarios4 = prod4->getComentarios();
        com = (comentarios4.find(15)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("Si, el microondas digital incluye una funcion de descongelacion rapida.", DataFecha(4, 6, 2024));

        controlComentario->seleccionarUsuario("natalia");
        controlComentario->seleccionarProducto(prod4->getCode());
        comentarios4 = prod4->getComentarios();
        com = (comentarios4.find(15)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("¿Cuantos niveles de potencia tiene? ", DataFecha(5, 6, 2024));

        controlComentario->seleccionarUsuario("ana23");
        controlComentario->seleccionarProducto(prod4->getCode());
        comentarios4 = prod4->getComentarios();
        com = (comentarios4.find(17)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("Tiene 10 niveles de potencia.", DataFecha(5, 6, 2024));

        controlComentario->seleccionarUsuario("roberto");
        controlComentario->seleccionarProducto(prod4->getCode());
        comentarios4 = prod4->getComentarios();
        com = (comentarios4.find(15)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("¿Es facil de limpiar? ", DataFecha(5, 6, 2024));

        controlComentario->seleccionarUsuario("roberto");
        controlComentario->seleccionarProducto(prod5->getCode());
        controlComentario->nuevoComentario("¿La luz LED se puede controlar con una aplicacion movil?", DataFecha(5, 6, 2024));

        controlComentario->seleccionarUsuario("diegom");
        controlComentario->seleccionarProducto(prod5->getCode());
        comentarios5 = prod5->getComentarios();
        com = (comentarios5.find(20)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("Si, la luz LED se puede controlar a traves de una aplicacion movil.", DataFecha(5, 6, 2024));

        controlComentario->seleccionarUsuario("pablo10");
        controlComentario->seleccionarProducto(prod5->getCode());
        comentarios5 = prod5->getComentarios();
        com = (comentarios5.find(20)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("¿Es compatible con Alexa o Google Home?", DataFecha(6, 6, 2024));

        controlComentario->seleccionarUsuario("diegom");
        controlComentario->seleccionarProducto(prod5->getCode());
        comentarios5 = prod5->getComentarios();
        com = (comentarios5.find(22)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("Si, es compatible con ambos.", DataFecha(6, 6, 2024));

        controlComentario->seleccionarUsuario("natalia");
        controlComentario->seleccionarProducto(prod5->getCode());
        comentarios5 = prod5->getComentarios();
        com = (comentarios5.find(20)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("¿Cuanto dura la bateria?", DataFecha(6, 6, 2024));

        controlComentario->seleccionarUsuario("pablo10");
        controlComentario->seleccionarProducto(prod5->getCode());
        comentarios5 = prod5->getComentarios();
        com = (comentarios5.find(20)->second)->getId();
        controlComentario->seleccionarComentario(com);
        controlComentario->realizarRespuesta("¿La aplicacion movil es facil de usar?", DataFecha(7, 6, 2024));

        print("Se crean 25 comentarios.");
    }
    saltoConsola();
    print("--------------------  Fin de caso de uso   --------------------");
}