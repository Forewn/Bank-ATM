
Introducción 

La temática más exitosa en arquitectura de software en los últimos tiempos es, sin lugar a duda, la de los estilos y patrones, tanto en lo que concierne a los patrones arquitectónicos como a patrones de diseño.

En este trabajo se trata una aplicación que, de un modo didáctico, sirva para la comprensión y utilización tanto de patrones arquitectónico como patrones de diseño de forma clara y correcta en la construcción de software.

El proyecto está dividido en dos partes fundamentales, una introducción teórica 
a la Arquitectura de Software, Estilos, Patrones Arquitectónicos y Patrones de Diseño 
y un caso práctico donde se plasma el análisis y aplicación de dichos patrones
El proceso del desarrollo de sistemas de software ha ido en aumento en los últimos años, demandando la construcción de grandes y complejos sistemas que requieren la combinación de diferentes tecnologías y plataformas de hardware y software para alcanzar la funcionalidad requerida. El diseño e implementación ha pasado de una concepción monolítica y uniforme a una visión heterogénea y distribuida.



























Requerimientos no funcionales


Cuando desarrolla un proyecto, se habla del planteamiento de soluciones ante un problema o requerimiento existente, y pues dependiendo de cada proyecto, y las personas y organizaciones implicadas en el mismo, los requerimientos grupales e individuales van a ser distintos, pero el fin del proyecto no cambia, que es el crear una herramienta que facilite y cumpla con las necesidades expuestas, si bien, se ha dicho que los requerimientos varían según el contexto en el que emergen también se pueden clasificar dependiendo de su naturaleza: Existen los requerimientos funcionales y no funcionales, y según el autor también se pueden incluir los requerimientos del dominio y del autor,

A manera de contraste, los requerimientos funcionales se refieren a las características del software que se está desarrollando y que tienen un impacto directo dentro del funcionamiento del mismo, como lo dice su nombre, es decir, que forman parte del algoritmo del proyecto  y describen los componentes que requiere el software, mientras que por su parte, los requerimientos no funcionales, se refieren a las restricciones y necesidades del proyecto, que no están intrínsecamente relacionadas con el proyecto, más si con otros aspectos del mismo, que especifican la calidad del software y su rentabilidad a futuro, algunos ejemplos de requisitos no funcionales son:

Seguridad: se refiere a la capacidad del sistema para protegerse contra accesos no autorizados y garantizar la privacidad y confidencialidad de los datos.
Actuación: se refiere a la capacidad del sistema para responder rápidamente a las solicitudes del usuario y procesar grandes cantidades de datos.
Escalabilidad: se refiere a la capacidad del sistema para manejar un aumento en la cantidad de usuarios o datos sin afectar su rendimiento.
Accesibilidad: se refiere a la capacidad del sistema para ser utilizado por personas con discapacidades físicas o cognitivas.
Adaptabilidad: se refiere a la capacidad del sistema para adaptarse a diferentes entornos y situaciones.
Capacidad: se refiere a la cantidad de usuarios o datos que el sistema puede manejar al mismo tiempo.
Integridad de datos: se refiere a la precisión y consistencia de los datos almacenados en el sistema.
Documentación: se refiere a la disponibilidad y calidad de la documentación del sistema.
Operabilidad: se refiere a la facilidad con que el sistema puede ser operado y administrado por el personal técnico.
Mantenibilidad: se refiere a la facilidad con que el sistema puede ser mantenido y mejorado por el personal técnico






Conformidad: se refiere al cumplimiento de los estándares y regulaciones aplicables al sistema.
Auditabilidad: se refiere a la capacidad del sistema para registrar y rastrear las acciones realizadas por los usuarios y el personal técnico.
Portabilidad: se refiere a la capacidad del sistema para ser transferido entre diferentes plataformas o entornos sin necesidad de modificaciones significativas.
Eficiencia: se refiere al uso eficiente de los recursos del sistema, como el procesador, la memoria y el almacenamiento.

Estilos Arquitectónicos


	Cuando se habla de arquitectura, la mente colectiva suele pensar en la arquitectura dentro de la construcción, aunque el término etimológicamente se refiere al acto de abstraer y darle solución a los problemas anteriormente presentados como requerimientos, el área de la arquitectura de software es acotada en los años 60´s, y desde entonces con el paso de los años y el cambio de las tecnologías han surgido distintos modelos y estilos arquitectónicos, que contienen una serie de componentes que realizan una función requerida por el sistema, que posibilitan la comunicación, la coordinación y la cooperación entre sus componentes y de qué manera se pueden integrar dichos componentes, son fundamentales para producir una guía de diseño que lleve el proyecto a la implementación de dicho estilo, los estilos arquitectónicos más comunes son:

Arquitectura basada en eventos:

Es un patrón de diseño que permite a una organización detectar “eventos” o momentos comerciales importantes, y actuar en consecuencia en tiempo real, lo que permite mayor flexibilidad y menor tiempo de respuesta; un evento es un cambio de estado o una actualización de un elemento: llámese momentos comerciales las transacciones de compra-venta, visitas al sitio, el mecanismo principal de comunicación entre los componentes es mediante el envío y recepción de eventos, es decir, sus servicios están desacoplados cuando no hay eventos concurriendo. Es común su presencia en aplicaciones modernas creadas con microservicios. Un ejemplo de la vida real en el que se aplica una arquitectura basada en eventos es el sistema de alerta temprana de terremotos. En este caso, los eventos sísmicos se detectan y se envían a través de un sistema de eventos que se comunica con otros sistemas para proporcionar alertas tempranas.
.







Arquitectura basada en capas:

Es un estilo que separa el sistema en capas lógicas o niveles de abstracción. Cada una de las capas es construida y superpuesta sobre la anterior y el mecanismo principal es que las capas inferiores proporcionan servicios a las capas superiores. Es utilizado principalmente para separar las áreas sensibles del sistema, y así mejorar el modularidad del mismo, es de los estilos de uso más frecuente debido a su bajo costo de implementación, un ejemplo dentro del mundo laboral es la complementación de los servicios de backend a cargo del desarrollador backend, los cuales hacen de capa inferior que proporciona servicios a la capa superior la cual sería el frontend, desarrollado por el diseñador de UI


-Arquitectura basada en servicios y microservicios:

El fundamento de la arquitectura basada en servicios es la capacidad de crear servicios reutilizables. Viendo los servicios como componentes autónomos que se comunican entre si mediante protocolos estándar. Es bastante compatible con la arquitectura basada en capas, y utilizado para mejorar la autonomía de las distintas partes del sistema y la interoperabilidad de las mismas. la principal diferencia de la arquitectura basada en microservicios con respecto a la arquitectura basada en servicios es que la arquitectura basada en servicios se trabaja con capas y tiene mayor tamaño y alcance mientras que la arquitectura basada en microservicios busca construir aplicaciones como un conjunto de pequeños microservicios los cuales se relacionan con otros independientes tanto internos como externos, que se ejecuten al mismo tiempo y se enfoquen en un tarea específica, dentro de la arquitectura de microservicios se utilizan las API para conectar los microservicios. Un ejemplo de la vida real en el que se aplica una arquitectura basada en servicios es el sistema de reservas de una aerolínea. En este caso, los servicios se dividen en diferentes componentes, como el servicio de reservas de vuelos, el servicio de reservas de hoteles y el servicio de reservas de coches Cada uno de estos servicios se comunica con otros servicios a través de una API para proporcionar una experiencia de usuario integrada y sin problemas.













Los Patrones Arquitectónicos

Los patrones arquitectónicos son soluciones generales que pueden ser reutilizadas en la arquitectura de software, su ubicación en el contexto de la arquitectura de software es la siguiente: Mientras que los estilos arquitectónicos tienen una mayor escala y un nivel de abstracción más altos, por su parte los patrones arquitectónicos se encuentran a un nivel más bajo, y son la forma de aplicación de los estilos; como lo dice su nombre, el término patrón se refiere a la repetición lógica y esquematizada de ciertas características, he de ahí que se hable de la reutilización de aspectos del sistema, en otras palabras, los patrones arquitectónicos son soluciones a problemas de arquitectura de software dentro del desarrollo de software que ofrecen una descripción de sus elementos y el tipo de relación que tienen junto con un conjunto de restricciones sobre como pueden ser usados. Los 10 patrones arquitectónicos más usados son los siguientes:

Patrón de capas:

    Es utilizado para estructurar programas compuestos en subtareas, agrupadas en distintos subniveles de abstracción, la división y clasificación es fundamental en este patrón, ya que propone un modelo de capas, donde cada capa proporciona servicios a la capa superior, usadas mayoritariamente para el desarrollo de Aplicaciones de escritorio de carácter general o aplicaciones de comercio online.

   Es posible diseñar e implementar modelos propios de capas, aunque el más habitual es el siguiente:

-Capa de presentación (UI)
	
-Capa de aplicación (servicios)
	
-Capa de lógica de negocios (Dominio)

-Capa de acceso a datos (Persistencia de data)

	Sus principales ventajas son que una misma capa inferior puede ser utilizada por distintas capas en niveles más altos, y esto hace más sencillo el proceso de estandarización del sistema, dados sus niveles definidos, por lo que los cambios pueden ser aplicados a una sola capa sin afectar a las demás, como en la programación modular, aunque, por otro lado, No pueden ser aplicados universalmente y es posible que ciertas capas deban ser saltadas en una situación dada.









Patrón cliente-servidor

	Este patrón presenta tan solo dos capas y una relación unilateral, un cliente y un servidor, el cliente le solicita al servidor de sus servicios, y el segundo se los proporciona al primero, son usados en la mayoría de aplicaciones online, por ejemplo las bancas online, o el almacenamiento en iCloud, su mayor ventaja es que es útil para modelar un conjunto de servicios los cuales pueden ser solicitados por los clientes, aunque su desventaja es que las solicitudes son manejadas en hilos separados en el servidor, y pueden llegar a tener problemas ante las solicitudes concurrentes.
	

 Patrón maestro-esclavo:

	Constituido fundamentalmente por el maestro y los esclavos, siendo el primero quien ha de distribuir el trabajo entre los componentes segundos, y ha de realizar los cálculos finales con los resultados retornados por los esclavos. Por ejemplo, la función principal (maestro) de un programa ha de enviar parámetros y órdenes a sus funciones secundarias (esclavos), quienes ejecutarán sus instrucciones y regresarán resultados que serán acumulados e interpretados por la función principal.

	Su principal ventaja es la precisión, y la posibilidad de implementar esclavos distintos para diversificar las tareas del sistema, pero los esclavos están aislados entre sí, y es posible que haya un retraso en la distribución de la información, lo que puede ser un problema para sistemas de ejecución y cálculo en tiempo real.

Patrón de filtro de tubería.

	Útil para la estructuración de sistemas que procesan secuencias de datos para convertirlos en información. Su principal característica es que entre cada sección de procesamiento se ha ubicado un filtro los cuales retienen la información irrelevante que no se desea que llegue a la sección final, los métodos de impresión en pantalla y lectura de documentos de los ordenadores los utilizan, siendo conocido como el búfer, quien retiene temporalmente la información para ser entregada sistemáticamente, también es aplicada en los compiladores, donde los filtros realizan el análisis sintáctico y las redes neuronales

	Se suele preferir un patrón de filtros, gracias a que genera sistemas de escalabilidad viable, y es sencillo añadir y reutilizar filtros de información, aunque el proceso de filtrado consume capacidad de procesamiento, lo que ralentiza en sistema.

Patrón de agente o Broker:

	La principal funcionalidad del Broker es conectar componentes que se encuentran desacoplados entre sí, habiendo un cliente quien solicita los datos, pero nunca a los componentes mismos, sino al Broker, quien será el encargado de solicitar los servicios al componente correspondiente, haciendo funciones de intermediario.

	
Permite cambiar dinámicamente los componentes del sistema, añadir, eliminar o reubicar componentes, además de ser transparente el traspaso de datos desde la perspectiva del desarrollador, en caso de desear aplicarlo, es de carácter menester estandarizar la descripción de los servicios del sistema para que todos puedan ser interpretados por un mismo broker.

Patrón de igual a igual (peer to peer)

	A los componentes individuales se les conoce como pares (peer) y pueden ejercer funciones tanto de servidor como de cliente dependiendo de los requerimientos del contexto, y su rol cambia dinámicamente con el tiempo, es utilizado en protocolos de multimedia en streaming y redes de intercambio de archivos, donde destaca el mayor software de piratería de archivos multimedia en todo el planeta Utorrent.

	Permite el alojamiento descentralizado de información, cuenta con bastante robustez ante fallas en cualquiera de sus nodos (gracias a su redundancia de datos), aunque cierto elemento no se encuentre alojado en su totalidad en ningún servidor, si sus partes complementarias están repartidas parcialmente en varios servidores es posible restablecerlo, su lado negativo, es que al depender de los mismos clientes como servidores es un sistema que depende de la voluntad de los clientes, por lo que no se puede garantizar la calidad del servicio, y el rendimiento depende del número de nodos.

Patrón de bus de evento.

	Trabaja con eventos, y utiliza principalmente 4 componentes: la fuente de evento, la escucha de evento, el canal de transmisión y el bus de evento. Donde existe un canal (fuente de evento) para que las fuentes publiquen sus mensajes, y otro para que sean escuchados por los oyentes (escucha de evento), este patrón es utilizado principalmente en el desarrollo móvil, específicamente en Android, sobre todo en el sistema de notificaciones.

	Se pueden añadir con facilidad nuevas fuentes, suscriptores y conexiones, aunque la escalabilidad del sistema puede ser problemática, ya que todos los mensajes viajan por un mismo bus de eventos.

Patrón de modelo-vista-controlador

	Compuesto por las siglas MVC (modelo, vista, controlador) siendo el modelo quien contiene las funciones y los datos básicos, la vista el medio por el que se puede observar la información del usuario y el controlador quien maneja los datos de entrada del usuario. Al desacoplar el código en bloques es fácilmente reutilizable, lo que ha popularizado este patrón para el desarrollo web, especialmente en los frameworks.

	Esta división permite tener múltiples vistas de un mismo modelo, el cual puede ser conectado y desconectado en tiempo de ejecución, aunque incrementa la complejidad de un sistema, y puede llevar a actualizaciones innecesarias para permitir acciones del usuario.




Patrón de pizarra.

	Es un patrón flexible, aplicable cuando no se puede abarcar una solución determinística, se divide en tres componentes fundamentales: la pizarra, donde se alojan los objetos del espacio de solución de manera estructurada en global; la fuente de conocimiento, la cual contiene módulos especializados; y el componente de control, el cual selecciona, configura y ejecuta los módulos requeridos, se le llama pizarra porque todos los componentes tienen acceso a la pizarra en la cual pueden escribir los nuevos objetos particulares que se necesiten y buscar componentes en la misma, es utilizado en el reconocimiento de voz.

	Permite crear aplicaciones dinámicas en las que se añadan nuevas aplicaciones y se extienda la estructura del espacio de datos, pero es difícil manejar la memoria a deseo el 100% de las veces, ya que todas las aplicaciones son afectadas por los cambios, y es necesario que los componentes se sincronicen


Patrón de intérprete

	Este modelo se utiliza para diseñar un elemento que interpreta programas escritos en un lenguaje especializado. Especifica principalmente cómo calcular las líneas de programas, conocidas como frases o expresiones escritas en un idioma específico. se utiliza en los lenguajes como SQL para consultar bases de datos, o para describir protocolos de comunicación.

	Es posible desarrollar un comportamiento altamente dinámico, y mejora la flexibilidad del sistema, porque es sencillo reemplazar un programa interpretado, pero a costo de una mayor velocidad de ejecución comparado con un lenguaje compilado.










Conclusión

       Como conclusión y en base a nuestra experiencia podemos decir que diseñar con patrones no es aplicar todos los patrones que se conocen en el diseño del software, sino resolver cada problema de diseño que surge con un patrón apropiado, teniendo en cuenta que un uso excesivo de patrones fácilmente terminará en una arquitectura compleja