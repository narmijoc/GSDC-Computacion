
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


class GraphUpdater:
    def __init__(self):
        self.fig = Figure(figsize=(5, 4), dpi=100)
        self.ax = self.fig.add_subplot(111)
        self.line, = self.ax.plot([], [])
        self.ax.set_xlabel("Tiempo (s)")
        self.ax.set_ylabel("Peso (kg)")
        self.ax.set_title("Gráfica de Peso vs Tiempo")

        self.data_x = []
        self.data_y = []

    def create_canvas(self, master):
        return FigureCanvasTkAgg(self.fig, master=master)

    def update_data(self):
        # actualizar gráfica
        pass