import tkinter as tk
from tkinter import messagebox

# Sample questions and answers
questions = [
    {
        "question": "What is the capital of France?",
        "options": ["Berlin", "Madrid", "Paris", "Lisbon"],
        "answer": "Paris"
    },
    {
        "question": "Which planet is known as the Red Planet?",
        "options": ["Earth", "Mars", "Jupiter", "Saturn"],
        "answer": "Mars"
    },
    {
        "question": "Who wrote 'Romeo and Juliet'?",
        "options": ["Mark Twain", "Charles Dickens", "William Shakespeare", "Jane Austen"],
        "answer": "William Shakespeare"
    },
    {
        "question": "What is the largest ocean on Earth?",
        "options": ["Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"],
        "answer": "Pacific Ocean"
    },
    {
        "question": "What is the smallest prime number?",
        "options": ["0", "1", "2", "3"],
        "answer": "2"
    }
]

class QuizGame:
    def __init__(self, master):
        self.master = master
        self.master.title("Quiz Game")
        self.current_question = 0
        self.score = 0
        
        self.question_label = tk.Label(master, text="", wraplength=300)
        self.question_label.pack(pady=20)

        self.var = tk.StringVar()
        self.options = []

        for i in range(4):
            option = tk.Radiobutton(master, variable=self.var, value="")
            option.pack(anchor="w")
            self.options.append(option)

        self.submit_button = tk.Button(master, text="Submit", command=self.submit_answer)
        self.submit_button.pack(pady=20)

        self.next_button = tk.Button(master, text="Next", command=self.next_question)
        self.next_button.pack(pady=20)
        self.next_button.config(state="disabled")

        self.load_question()

    def load_question(self):
        question_data = questions[self.current_question]
        self.question_label.config(text=question_data["question"])
        self.var.set(None)  # Reset the selection
        
        for i, option in enumerate(self.options):
            option.config(text=question_data["options"][i], value=question_data["options"][i])

    def submit_answer(self):
        selected_answer = self.var.get()
        correct_answer = questions[self.current_question]["answer"]
        
        if selected_answer == correct_answer:
            self.score += 1
            messagebox.showinfo("Result", "Correct!")
        else:
            messagebox.showinfo("Result", f"Wrong! The correct answer was: {correct_answer}")
        
        self.submit_button.config(state="disabled")
        self.next_button.config(state="normal")

    def next_question(self):
        self.current_question += 1
        
        if self.current_question < len(questions):
            self.load_question()
            self.submit_button.config(state="normal")
            self.next_button.config(state="disabled")
        else:
            messagebox.showinfo("Quiz Completed", f"You scored {self.score} out of {len(questions)}")
            self.master.quit()

if __name__ == "__main__":
    root = tk.Tk()
    quiz_game = QuizGame(root)
    root.mainloop()