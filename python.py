import tkinter as tk
import time

class Stopwatch:
    def __init__(self, root):
        self.root = root
        self.root.title("Stopwatch")
        self.root.geometry("300x200")
        
        self.running = False
        self.start_time = 0
        self.elapsed_time = 0

        self.label = tk.Label(root, text="00:00:00", font=("Helvetica", 40))
        self.label.pack(pady=20)

        tk.Button(root, text="Start", command=self.start).pack(side="left", padx=20)
        tk.Button(root, text="Stop", command=self.stop).pack(side="left")
        tk.Button(root, text="Reset", command=self.reset).pack(side="left", padx=20)

        self.update_timer()

    def update_timer(self):
        if self.running:
            now = time.time()
            self.elapsed_time = now - self.start_time
        mins, secs = divmod(int(self.elapsed_time), 60)
        hours, mins = divmod(mins, 60)
        self.label.config(text=f"{hours:02}:{mins:02}:{secs:02}")
        self.root.after(100, self.update_timer)

    def start(self):
        if not self.running:
            self.start_time = time.time() - self.elapsed_time
            self.running = True

    def stop(self):
        self.running = False

    def reset(self):
        self.running = False
        self.elapsed_time = 0
        self.label.config(text="00:00:00")

root = tk.Tk()
app = Stopwatch(root)
root.mainloop()
