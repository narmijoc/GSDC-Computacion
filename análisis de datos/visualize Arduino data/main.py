import tkinter as tk

import button_functions as bf
import graphic

# Crear ventana principal
ventana = tk.Tk()
ventana.title("Gráfica con Tkinter")

# Configurar ventana principal
ventana.state('zoomed')
ventana.wm_minsize(500, 500)

# Crear instancia de GraphUpdater
graph = graphic.GraphUpdater()

# Crear canvas utilizando la clase GraphUpdater
canvas = graph.create_canvas(ventana)
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)

# Crear marco para los botones
marco_botones = tk.Frame(ventana)
marco_botones.pack(side=tk.BOTTOM, pady=10)

# Crear botones
boton1 = tk.Button(marco_botones, text="Calibrar", command=bf.calibrate, width=10, height=2)
boton2 = tk.Button(marco_botones, text="Iniciar Prueba", command=bf.start_Test, width=10, height=2)
boton1.pack(side=tk.LEFT, padx=5)
boton2.pack(side=tk.LEFT, padx=5)

# Ejecutar ventana principal
ventana.mainloop()
