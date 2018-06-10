# remoteshellCPP
He creado un cliente que se coecta a un servidor y desde el servidor podemos enviarle comandos. 
Debido a que al parecer los procesos de sistema son efimeros, los comandos que produzcan un cambio de ubicacion no tendran efecto, ya que el cambio de ubicación se produce pero en la siguiente linea de comandos volveriamos a estar en la ubicación inicial. 
Por ejemplo: 
   Supongamos que nos encontramos en Desktop y hay una carpeta llamada "Fotos" que contiene los archivos "picture1.jpg" y     "picture2.jpg". Si ejecutamos el comando "cd Fotos" presionamos enter y luego ejecutamos el comando "ls" nos listará lo que se encuentra en el escritorio y no en la carpeta Fotos. Si queremos listar el contenido de la carpeta Fotos deberiamos ejecutar el siguiente comando "cd Fotos && ls".
Es la primera vez que programo sockets y algo de este tipo asi que cualquier consejo es bien recibido. Gracias :)
