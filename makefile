# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Werror
LDFLAGS =

SRCDIR = src
OBJDIR = obj
BINDIR = bin
EXECUTABLE = $(BINDIR)/mercadoFInger
CASOSDEUSODIR = $(SRCDIR)/system/useCases


# Archivos fuente
MAIN = main.cpp

CPP_DATATYPES_FILES := $(SRCDIR)/datatypes/CategoriaProducto.cpp \
	$(SRCDIR)/datatypes/DataComentario.cpp \
	$(SRCDIR)/datatypes/DataCompra.cpp \
	$(SRCDIR)/datatypes/DataEnvio.cpp \
	$(SRCDIR)/datatypes/DataFecha.cpp \
	$(SRCDIR)/datatypes/DataProducto.cpp \
	$(SRCDIR)/datatypes/DataProductoCompra.cpp \
	$(SRCDIR)/datatypes/DataPromoProducto.cpp \
	$(SRCDIR)/datatypes/DataPromocion.cpp \
	$(SRCDIR)/datatypes/DataInfoProducto.cpp \
	$(SRCDIR)/datatypes/DataInfoPromo.cpp \
	$(SRCDIR)/datatypes/DataUsuario.cpp \
	$(SRCDIR)/datatypes/DataExpediente.cpp \
	$(SRCDIR)/datatypes/DataClienteCompra.cpp \

CPP_CLASSES_FILES := $(SRCDIR)/classes/Cliente.cpp \
	$(SRCDIR)/classes/Comentario.cpp \
	$(SRCDIR)/classes/Compra.cpp \
	$(SRCDIR)/classes/CompraProducto.cpp \
	$(SRCDIR)/classes/Producto.cpp \
	$(SRCDIR)/classes/Promocion.cpp \
	$(SRCDIR)/classes/PromoProducto.cpp \
	$(SRCDIR)/classes/Usuario.cpp \
	$(SRCDIR)/classes/Vendedor.cpp \

CPP_CONTROLLERS_FILES := $(SRCDIR)/controllers/ControladorComentario.cpp \
	$(SRCDIR)/controllers/ControladorCompra.cpp \
	$(SRCDIR)/controllers/ControladorProducto.cpp \
	$(SRCDIR)/controllers/ControladorPromocion.cpp \
	$(SRCDIR)/controllers/ControladorUsuario.cpp \

CPP_SYSTEM_FILES := $(SRCDIR)/system/Sistema.cpp \
	$(SRCDIR)/system/useCases/AltaUsuario.cpp \
	$(SRCDIR)/system/useCases/CargarDatos.cpp \
	$(SRCDIR)/system/useCases/SetearFechaActual.cpp \
	$(SRCDIR)/system/useCases/AltaProducto.cpp \
	$(SRCDIR)/system/useCases/ConsultarProducto.cpp \
	$(SRCDIR)/system/useCases/ConsultarPromocion.cpp \
	$(SRCDIR)/system/useCases/ConsultaDeNotificaciones.cpp \
	$(SRCDIR)/system/useCases/EliminarSuscripciones.cpp \
	$(SRCDIR)/system/useCases/SuscribirseANotificaciones.cpp \
	$(SRCDIR)/system/useCases/CrearPromocion.cpp \
	$(SRCDIR)/system/useCases/RealizarCompra.cpp \
	$(SRCDIR)/system/useCases/ListadoUsuarios.cpp \
	$(SRCDIR)/system/useCases/ExpedienteDeUsuario.cpp \
	$(SRCDIR)/system/useCases/EnviarProducto.cpp \
	$(SRCDIR)/system/useCases/EliminarComentario.cpp \
	$(SRCDIR)/system/useCases/DejarComentario.cpp \
	$(SRCDIR)/system/Operaciones.cpp \
	$(SRCDIR)/system/FechaSistema.cpp \
	

CPP_FACTORY_FILES := $(SRCDIR)/factory/Fabrica.cpp \

CPP_FILES := $(MAIN) \
	$(CPP_DATATYPES_FILES) \
	$(CPP_CLASSES_FILES) \
	$(CPP_CONTROLLERS_FILES) \
	$(CPP_INTERFACES_FILES) \
	$(CPP_FACTORY_FILES) \
	$(CPP_SYSTEM_FILES) \




# Objetos
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CPP_FILES))

# Regla principal
rebuild: clean build

build: $(EXECUTABLE)

# Regla para el ejecutable
$(EXECUTABLE): $(OBJECTS)
	@clear
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Regla para los objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -rf $(OBJDIR) $(EXECUTABLE) $(BINDIR)

run: $(EXECUTABLE)
	@clear
	@./$(EXECUTABLE)

valgrind: $(EXECUTABLE)
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXECUTABLE)