import tkinter as tk
from tkinter import messagebox

class QuizApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Quiz Game")
        
        self.score = 0
        self.question_index = 0
        
        self.questions = [
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
                "options": ["Mark Twain", "William Shakespeare", "Charles Dickens", "J.K. Rowling"],
                "answer": "William Shakespeare"
            },
        ]

        self.question_label = tk.Label(self.root, text="", wraplength=400)
        self.question_label.pack(pady=20)

        self.var = tk.StringVar()
        self.options_frame = tk.Frame(self.root)
        self.options_frame.pack()

        self.options = []
        for i in range(4):
            option = tk.Radiobutton(self.options_frame, text="", variable=self.var, value="")
            option.pack(anchor='w')
            self.options.append(option)

        self.submit_button = tk.Button(self.root, text="Submit", command=self.check_answer)
        self.submit_button.pack(pady=20)

        self.load_question()

    def load_question(self):
        if self.question_index < len(self.questions):
            question = self.questions[self.question_index]
            self.question_label.config(text=question["question"])
            self.var.set("")  # Reset the selection
            
            for i, option in enumerate(self.options):
                option.config(text=question["options"][i], value=question["options"][i])
        else:
            self.end_quiz()

    def check_answer(self):
        selected_option = self.var.get()
        correct_answer = self.questions[self.question_index]["answer"]
        
        if selected_option == correct_answer:
            self.score += 1
        
        self.question_index += 1
        self.load_question()

    def end_quiz(self):
        messagebox.showinfo("Quiz Finished", f"Your score: {self.score}/{len(self.questions)}")
        self.root.quit()

if __name__ == "__main__":
    root = tk.Tk()
    quiz_app = QuizApp(root)
    root.mainloop()
